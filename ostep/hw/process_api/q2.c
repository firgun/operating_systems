// Question
// ---
// Write a program that opens a file (with the open() system call) and then calls
// fork() to create a new process. Can both the child and parent access the file
// descriptor returned by open(). What happens when they are writing to the file
// concurrently, i.e., at the same time.
//
// Answer
// ---
// Both parent and child can access the file descriptor. Writes to the file descriptor
// are interleaved.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  int fd = open("q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  if (fd < 0) {
    fprintf(stderr, "open failed\n");
    exit(1);
  }
  int n = 1000;
  char buf[2] = {'A','\n'};
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    for (int i = 0; i < n; i++) {
      buf[0] = 'C';
      write(fd, buf, sizeof(buf));
    }
  } else {
    for (int i = 0; i < n; i++) {
      buf[0] = 'P';
      write(fd, buf, sizeof(buf));
    }
  }
  return 0;
}
