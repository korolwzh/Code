LMP1: I/O and Filesystems
=========================

Welcome to LMP1, the first long MP.  LMP1 is the first stage of a project aimed
at creating a simple yet functional networked filesystem.  In this MP, you will
learn about and use POSIX file system calls, while subsequent LMPs will
introduce memory management, messaging, and networking functionality.  If you
implement all parts of this MP correctly, you will be able to reuse your code
for future MPs.

This first LMP concentrates on the file I/O portion of the project.
Specifically, you will implement a custom filesystem and test its performance
using a filesystem benchmark.  A benchmark is an application used to test the
performance of some aspect of the system.  We will be using Bonnie, a real
filesystem benchmark, to test various performance aspects of the filesystem we
implement.

LMP1 consists of four steps:

1. Read the code; run the Bonnie benchmark and the LMP1 test suite.

2. Implement Test Suite 1 functionality, encompassing basic file I/O operations.

3. Implement Test Suite 2-4 functionality (directory operations, file
creation/deletion, and recursive checksumming).

4. Modify Bonnie to use your client-server file I/O methods.


Code structure
--------------

The code for this project is structured according to the client-server
model.  The client code (filesystem benchmark) will interact with the
server (filesystem) only through interface functions defined in
fileio.h:

int file_read(char *path, int offset, void *buffer, size_t bufbytes);
int file_info(char *path, void *buffer, size_t bufbytes);
int file_write(char *path, int offset, void *buffer, size_t bufbytes);

int file_create(char *path,char *pattern, int repeatcount);
int file_remove(char *path);

int dir_create(char *path);
int dir_list(char *path,void *buffer, size_t bufbytes);

int file_checksum(char *path);
int dir_checksum(char *path);

These functions represent a simple interface to our filesystem.  In Steps 2 and
3 of this MP, you will write the code for functions implementing this interface,
replacing the stub code in fileio.c.  In Step 4, you will modify a Bonnie method
to use this interface, rather than calling the normal POSIX I/O functions
directly.  The purpose of Step 4 is to help test our implementation.


Step 1: Understanding the code
------------------------------

1. Compile the project, execute Bonnie and the test framework.

Note: you may need to add execute permissions to the .sh files using
the command "chmod +x *.sh".

Try the following:
make
./lmp1
(this runs the Bonnie benchmark - it may take a little while)
./lmp1 -test suite1
(run Test Suite 1 - this has to work for stage1)
make test
(run all tests - this has to work for stage2)

2. Read through the provided .c and .h files and understand how this
project is organized:
bonnie.c - a version of the filesystem benchmark
fileio.c - file I/O functions to be implemented
fileio.h - declaration of file I/O functions
restart.c - restart library (available for use in fileio.c)
restart.h - declaration of restart library functions
util.c - useful utility functions
util.h - declaration of useful utility functions and macros

In particular, pay close attention to the comments in fileio.h and
bonnieb.c.  You should understand what each of the following functions
in bonnie.c does before undertaking the remainder of the MP:

fill_file_char()
file_read_rewrite()
file_read_rewrite_block()
fill_file_block()
fill_read_getc()
file_read_chunk()
newfile()


Step 2: Basic I/O operations
----------------------------

Implement file_read, file_write and file_info operations in fileio.c.

If done correctly, your code should pass all suite1 tests:
./lmp1 -test suite1
Running tests...
 1.read                ::pass
 2.info                ::pass
 3.write               ::pass

Test Results:3 tests,3 passed,0 failed.

IMPORTANT: fileio.c is the only file you should modify for this step.


Step 3: More filesystem operations
----------------------------------

Implement file and directory operations for suite2 (dir_create and
dir_list), suite3 (file_create and file_remove), and suite4
(file_checksum and dir_checksum).

You can test each operation and test suite individually:
./lmp1 -test dirlist
./lmp1 -test suite2

All tests should now pass:
make test
Running tests...
 1.read                ::pass
 2.info                ::pass
 3.write               ::pass
 4.dirlist             ::pass
 5.dircreate           ::pass
 6.remove              ::pass
 7.create              ::pass
 8.filechecksum        ::pass
 9.dirchecksum         ::pass

Test Results:9 tests,9 passed,0 failed.


Step 4: Performance testing
---------------------------

In this step, we will change parts of Bonnie to use our filesystem
interface.

Make the function file_read_rewrite_block() in bonnie.c to call your
fileio.c functions instead of POSIX I/O operations.  When answering the
questions below, use this modified version of bonnie.c.

Before making this change, it's a good idea to write pseudocode comments
for what each part of file_read_rewrite_block() does, so that you
understand the code and can perform the change correctly.  There may
not be an exact one-to-one correspondence between our filesystem
interface and the POSIX commands.

Note: In future LMPs, we will be using the fileio.h interface in a
similar manner, but we will call the functions remotely, via a message
queue.


Questions
---------

Q1.  Briefly explain what the following code from bonnie.c does:
if ((words = read(fd, (char *) buf, Chunk)) == -1) ...

Read Chunk bytes of date from file to buffer, if read succeeds then do something

Q2. Is the above an example of a block read or a character read?  What
is the value of the variable 'words' if the read succeeds?  Fails?

The example is for block read. words is the bytes has been read if read succeeds, and word is negtive number if read Fails. 

Q3.  Explain the meaning of the flag value (O_CREAT | O_WRONLY |
O_APPEND) for the POSIX function open().

If file exists,open the file, read and write at the end. if file does not exist creat the file and read and write at the end.

Q4. Run Bonnie. What is being measured by each test function?

The running time and cpu have been measured for each function.

Q5. Look at the summary results from the Bonnie run in Q4. Does Bonnie
measure latency, throughput or something else?  Justify your answer.

By the look at the output [Seeker 2...Seeker 1...Seeker 3...start 'em...done...done...done..][MB K/sec %CPU ]
we can say the data transfer speed in k/sec and the cpu usage and latency and throughputhave been measured.

Q6. Compare character reads with block reads using Bonnie.  Which is
faster?  Why do you think this is the case?

the block read is faster,because the level of read() and write() are lower than getc() and putc(); moreover, write and read can process a block of data at once.

Q7. Copy and paste the performance measures output when running Bonnie
benchmarks in a local directory and again in an NFS-mounted directory.
Is one kind of disk access noticeably slower over the network, or are
all tests significantly slower?

File './LMP1.7816', size: 104857600
FUNCTION fill_file_char() start......done FUNCTION file_fill_char()
FUNCTION file_read_rewrite() start...Rewriting...done FUNCTION file_read_rewrite_block()
FUNCTION fill_file_block() start......done FUNCTION fill_file_block()
FUNCTION fill_read_getc() start......done FUNCTION file_read_getc()
FUNCTION file_read_chunk() start......done FUNCTION file_read_chunk()
Seeker 2...Seeker 1...Seeker 3...start 'em...done...done...done...
              -------Sequential Output-------- ---Sequential Input-- --Random--
              -Per Char- --Block--- -Rewrite-- -Per Char- --Block--- --Seeks---
Machine    MB K/sec %CPU K/sec %CPU K/sec %CPU K/sec %CPU K/sec %CPU  /sec %CPU
          100 224399 99.9 1940202 99.4 2578305 99.9 251914 99.9 6147934 100.0 118252.2 263.5


Your home directory may be an NFS mount, whereas /tmp and /scratch are local
disks.  To test your code in /tmp, do the following:
mkdir /tmp/your_username
cp lmp1 /tmp/your_username
cd /tmp/your_username
./lmp1
(record the output)
cd
rm -fr /tmp/your_username

File './LMP1.8159', size: 104857600
FUNCTION fill_file_char() start......done FUNCTION file_fill_char()
FUNCTION file_read_rewrite() start...Rewriting...done FUNCTION file_read_rewrite_block()
FUNCTION fill_file_block() start......done FUNCTION fill_file_block()
FUNCTION fill_read_getc() start......done FUNCTION file_read_getc()
FUNCTION file_read_chunk() start......done FUNCTION file_read_chunk()
Seeker 1...Seeker 2...Seeker 3...start 'em...done...done...done...
              -------Sequential Output-------- ---Sequential Input-- --Random--
              -Per Char- --Block--- -Rewrite-- -Per Char- --Block--- --Seeks---
Machine    MB K/sec %CPU K/sec %CPU K/sec %CPU K/sec %CPU K/sec %CPU  /sec %CPU
          100 215448 100.0 1940606 100.0 2623959 100.0 251497 100.0 5771940 100.0 110241.4 293.8

Accroding to the outputs, the read and write block is faster and the read and write character is slower. 


Q8. How does Bonnie handle incomplete reads, e.g., due to interruptions
from signals?  Justify why Bonnie's approach is good or bad for a
filesystem benchmark program.

It using open and close the pipe to handle the imcomplete reads. the approach is not very good, due to busy waitting.

Q9. By now you should be very familiar with the self-evaluation test
harness we provide for the MPs.  Examine the function test_file_read()
in lmp1_tests.c, which tests your file_read() function from Step 2.

What does this test check for, specifically?  You may want to copy and
paste the code for this function in your answer, and annotate each
quit_if or group of related quit_ifs with a comment.


    quit_if(IOERR_INVALID_ARGS != file_read(HELLO_FILE, 0, b, 0)); 
    1. fails if the buffer with size of 0.
    
    quit_if(IOERR_INVALID_ARGS != file_read(HELLO_FILE, 0, NULL, sizeof(b)));
    2.fails if the input is Null.
    
    quit_if(IOERR_INVALID_ARGS != file_read(HELLO_FILE, -1, b, sizeof(b)));
    3. fails if the offset point out of the file range. 
    
    quit_if(IOERR_INVALID_ARGS != file_read(NULL, 0, b, sizeof(b)));
    4. fails if the input is Null.
    
    quit_if(IOERR_INVALID_PATH != file_read(NO_SUCH_FILE, 0, b, sizeof(b)));
    5. fails if the file path does not exist.
    
    bytes_read = file_read(HELLO_FILE, 0, b, sizeof(b));   
    quit_if(bytes_read != 5);
    6. fails if the read bytes is not 5. 
    
    quit_if(strncmp("Hello", b, 5));
    7. fails if the data in buffer is not 'hello'.
    
    bytes_read = file_read(HELLO_FILE, 1, b, sizeof(b));
    quit_if(bytes_read != 4);
    8.fails if the read bytes is not 4. 
    
    quit_if(strncmp("ello", b, 4));
    9.fails if the data in buffer is not 'ello'.
    
    bytes_read = file_read(HELLO_FILE, -1, b, sizeof(b));
    quit_if(bytes_read >= 0);
    10.fails if the data read bigger than 0.

    bytes_read = file_read(BIG_FILE, 1, b, sizeof(b));
    quit_if(bytes_read != sizeof(b));
    11. fails if the max data in buffer is not the size of buffer. 
    
    quit_if(!memcmp(b, dots, sizeof(b)));
    12. fails if the data in buffer is not dots.



