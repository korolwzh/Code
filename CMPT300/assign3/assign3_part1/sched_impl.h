#ifndef	__SCHED_IMPL__H__
#define	__SCHED_IMPL__H__

#include <semaphore.h>
#include <pthread.h>

#include "list.h"
#include "scheduler.h"

struct thread_info {
  sched_queue_t* queue;
  list_elem_t* queue_elem;
  pthread_mutex_t* has_cpu, * yield_cpu;
};

struct sched_queue {
  list_t* list;
  sem_t* production, * consumption;
  pthread_mutex_t* access_mutex;
};

#endif /* __SCHED_IMPL__H__ */