#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "scheduler.h"
#include "sched_impl.h"


static void init_thread_info(thread_info_t *info, sched_queue_t *queue) {
  info->queue = queue;
  info->queue_elem = NULL;

  info->yield_cpu = malloc(sizeof(pthread_mutex_t));
  info->has_cpu = malloc(sizeof(pthread_mutex_t));
  
  pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
  *(info->yield_cpu) = m1;
  pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
  *(info->has_cpu) = m2;

  pthread_mutex_lock(info->has_cpu);
}

static void destroy_thread_info(thread_info_t *info) {
  info->queue = NULL;
  info->queue_elem = NULL;

  pthread_mutex_unlock(info->yield_cpu);
  
  free(info->has_cpu);
  free(info->yield_cpu);
  info->has_cpu = NULL;
  info->yield_cpu = NULL;
}

static void enter_sched_queue(thread_info_t *info) {

  info->queue_elem = malloc(sizeof(list_elem_t));
  list_elem_init(info->queue_elem, info);

  if(!sem_wait(info->queue->production)) {
    if(!pthread_mutex_lock(info->queue->access_mutex)) {
      list_insert_tail(info->queue->list, info->queue_elem);
      (sem_post(info->queue->consumption));
      (pthread_mutex_unlock(info->queue->access_mutex));
    }
  } 
}

static void leave_sched_queue(thread_info_t *info) {
  
  if(!sem_trywait(info->queue->consumption)) { 
    if(!pthread_mutex_lock(info->queue->access_mutex)) {
      list_remove_elem(info->queue->list, info->queue_elem);
      free(info->queue_elem);
      (sem_post(info->queue->production));
      (pthread_mutex_unlock(info->queue->access_mutex));
    } 
  } 
}

static void wait_for_cpu(thread_info_t *info) {
  (pthread_mutex_lock(info->has_cpu));
}

static void release_cpu(thread_info_t *info) {
  (pthread_mutex_unlock(info->yield_cpu));
}

static void wake_worker(thread_info_t *info) {
  (pthread_mutex_unlock(info->has_cpu));
}


static void init_sched_queue(sched_queue_t *queue, int queue_size) {
  queue->list = malloc(sizeof(list_t));
  list_init(queue->list);

  queue->production = malloc(sizeof(sem_t));
  queue->consumption = malloc(sizeof(sem_t));
  if(sem_init(queue->production, 0, queue_size) == -1
     || sem_init(queue->consumption, 0, 0) == -1) {
    exit(1);
  }

  queue->access_mutex = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
  *(queue->access_mutex) = m;
}

static void destroy_sched_queue(sched_queue_t *queue) {

  list_elem_t* e;
  while((e = list_get_head(queue->list))) {
    list_remove_elem(queue->list, e);
    destroy_thread_info((thread_info_t*) e->datum);
    free(e);
  }

  (pthread_mutex_destroy(queue->access_mutex));

  free(queue->access_mutex);
  free(queue->production);
  free(queue->consumption);
  free(queue->list);
}

static thread_info_t* next_worker(sched_queue_t *queue) {
  thread_info_t* next = NULL;
  
  if(!pthread_mutex_lock(queue->access_mutex)) {
    list_elem_t* head = list_get_head(queue->list);

    if(head) {
      next = (thread_info_t*) head->datum;
    }

    (pthread_mutex_unlock(queue->access_mutex));
  } 
  return next;
}

static void wait_for_queue(sched_queue_t *queue) {
  if(!sem_wait(queue->consumption)) {
    (sem_post(queue->consumption));
  } 
}


void fifo_wait(sched_queue_t *queue) {
  list_elem_t* head = list_get_head(queue->list);
  if(!head)
    return;
  thread_info_t* worker = (thread_info_t*) head->datum;

  (pthread_mutex_lock(worker->yield_cpu));
}


void rr_wait(sched_queue_t *queue) {
  list_elem_t *head;
  thread_info_t *worker;

  if(!pthread_mutex_lock(queue->access_mutex)) {
    head = list_get_head(queue->list);
    if(head) {
      worker = (thread_info_t*) head->datum;
      list_remove_elem(queue->list, head);
      list_insert_tail(queue->list, head);
    } else {
      pthread_mutex_unlock(queue->access_mutex);
      return;
    }
    pthread_mutex_unlock(queue->access_mutex);
  }
}


/* Static initialization of scheduling strategies */
sched_impl_t sched_fifo = {
  { init_thread_info, destroy_thread_info, enter_sched_queue, leave_sched_queue,
    wait_for_cpu, release_cpu }, 
  { init_sched_queue, destroy_sched_queue, wake_worker, fifo_wait,
    next_worker, wait_for_queue } },

sched_rr = {
  { init_thread_info, destroy_thread_info, enter_sched_queue, leave_sched_queue,
    wait_for_cpu, release_cpu },
  { init_sched_queue, destroy_sched_queue, wake_worker, rr_wait,
    next_worker, wait_for_queue } };