SMP1: Simple Shell
==================

INSTRUCTIONS
============

In this MP, you will explore and extend a simple Unix shell interpreter.
In doing so, you will learn the basics of system calls for creating and
managing processes.


STEP 1:  Compile the shell
==========================

    chmod +x b.sh
    make
    make test   # Use in Step 5 to test your changes to the MP
    ./shell


STEP 2:  Try using the shell
============================

  Note: You need to specify the absolute paths of commands.

  Some commands to try:
    /bin/ls
    /bin/ls ..
    cd /
    /bin/pwd
    /bin/bash
    exit
    ./shell     (Note: You need to be in the smp1 directory.)
    ./shell&    (Note: You need to be in the smp1 directory.)
    ./b.sh      (Note: You need to be in the smp1 directory.)
    /bin/kill -s KILL nnnn      (Where nnnn is a process ID.)

  "./" means the current directory


STEP 3:  Study the implementation of the shell
==============================================

  In preparation for the questions in Step 4, please explore the source code
  for the shell contained in 'shell.c'.  You needn't understand every detail
  of the implementation, but try to familiarize yourself with the structure
  of the code, what it's doing, and the various library functions involved.
  Please use the 'man' command to browse the Unix manual pages describing
  functions with which you are unfamiliar.


STEP 4:  Questions
==================

  1. Why is it necessary to implement a change directory 'cd' command in
     the shell?  Could it be implemented by an external program instead?
	
	A: cd command is used to access the file in the working area or go to another working directory 
I think it can't implemented by an external program because it's on the OS. It's wired if we
call an external progarm for access the OS. 


  2. Explain how our sample shell implements the change directory command.

	A: we first check whether it's the cd command. Then we check its directory, 
whether the new direcoty under the current one. If we find it, we access it,
otherwise, we output "cd: failed to chdir".


  3. What would happen if this program did not use the fork function, but
     just used execv directly?  (Try it!)

     Try temporarily changing the code 'pid_from_fork = fork();'
     to 'pid_from_fork = 0;'

	A: When using fork() function and I input some invlaid command, like 1,2, the shell still compile
and output "parent says ' child process has benn forked...". However, if I change to pid_from_fork = 0,
when I input invilad command, it return "command not found" and I suppose the shell doesn't compile.
And the reason of that I think is the fork function will create a new process and this new process will
keep compile until we stop the process.


  4. Explain what the return value of fork() means and how this program
     uses it.

	A: Fistly, If fork() returns a negative value, the creation of a child process was unsuccessful.
Then if fork() returns a zero which will exit from the main, but the child process may successful.
And if the value > 0, fork() returns a positive value, the process ID of the child process, to the parent.
And the parent will continue around the loop.


  5. What would happen if fork() were called prior to chdir(), and chdir()
     invoked within the forked child process?  (Try it!)

     Try temporarily changing the code for 'cd' to use fork:

     if (fork() == 0) {
         if (chdir(exec_argv[1]))
             /* Error: change directory failed */
             fprintf(stderr, "cd: failed to chdir %s\n", exec_argv[1]);
         exit(EXIT_SUCCESS);
     }

	A: If fork() called prior to chdir(), the new process would be created before changing directory.
And if chdir() invoked within the forked child process which will make the new process is exact duplicate of process.
(this question is asked for my friend.)

  6. Can you run multiple versions of ./b.sh in the background?
     What happens to their output?

	A: yes, I can and the output is 10(71)..9(71)..8(71)..7(71)..6(71)..5(71)..4(71)..3(71)..2(71)..1(71)..Blastoff 71 Complete


  7. Can you execute a second instance of our shell from within our shell
     program (use './shell')?  Which shell receives your input?

	A: Yes, and I got "Parent says 'child process has been forked with pid=84'".


  8. What happens if you type CTRL-C while the countdown script ./b.sh is
     running?  What if ./b.sh is running in the background?

	A: It seems the running will be stop. And the process will kill itself I guess.


  9. Can a shell kill itself?  Can a shell within a shell kill the parent
     shell?

     ./shell
     ./shell
     /bin/kill -s KILL NNN      (Where NNN is the the parent's PID.)

	A: It's ok to kell the shell itself by using /bin/kill -s KILL NNN.
And when I try to use this command in a shell within a shell, I got
  "Parent says 'child process has been forked with pid=102'
   Parent says 'wait() returned so the child with pid=101 is finished.'"
and shell(pid=99) which is the pid before I called the second shell, so I guess I kill the parent shell.


  10. What happens to background processes when you exit from the shell?
      Do they continue to run?  Can you see them with the 'ps' command?

      ./shell
      ./b.sh&
      exit
      ps

	A: When I input exit command, it's will still counting down. But ps shows all the TIME CMD is 0.
So I suppose it already exit. So it seems when I exit from shell, all process will stop.



STEP 5:  Modify the MP
======================

  Please make the following modifications to the given file shell.c.  As in
  SMP0, we have included some built-in test cases, which are described along
  with the feature requests below.

  In addition to running the tests as listed individually, you can run
  "make test" to attempt all tests on your modified code.


  1. Modify this MP so that you can use 'ls' instead of '/bin/ls'
     (i.e. the shell searches the path for the command to execute.)

     Test: ./shell -test path

  2. Modify this MP so that the command prompt includes a counter that
     increments for each command executed (starting with 1).  Your
     program should use the following prompt format:
       "Shell(pid=%1)%2> "  %1=process pid %2=counter
     (You will need to change this into a correct printf format)
     Do not increment the counter if no command is supplied to execute.

     Test: ./shell -test counter

  3. Modify this MP so that '!NN' re-executes the n'th command entered.
     You can assume that NN will only be tested with values 1 through 9,
     no more than 9 values will be entered.

     Shell(...)1> ls
     Shell(...)2> !1     # re-executes ls
     Shell(...)3> !2     # re-executes ls
     Shell(...)4> !4     # prints "Not valid" to stderr

     Test: ./shell -test rerun

  4. Modify the MP so that it uses waitpid instead of wait.

  5. Create a new builtin command 'sub' that forks the program to create
     a new subshell.  The parent shell should run the imtheparent()
     function just as if we were running an external command (like 'ls').

     ./shell
     Shell(.n1..)1> sub
     Shell(.n2..)1> exit  # Exits sub shell
     Shell(.n1..)1> exit  # Exits back to 'real' shell

  6. Create a new global variable to prevent a subshell from invoking
     a subshell invoking a subshell (i.e., more than 3 levels deep):

     ./shell
     Shell(.n1..)1> sub
     Shell(.n2..)1> sub
     Shell(.n3..)1> sub   # prints "Too deep!" to stderr

     Test: ./shell -test sub
