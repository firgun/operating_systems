// Question:
// ---
// Write a program that creates two children and connects the standard
// output of one to the standard input of another, using the pipe
// system() call.
//
// Answer:
// ---
// Use the close() and followed by dup() to reallocate the standard
// input/output of a process.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fildes[2];
  if (pipe(fildes) == -1) {
    fprintf(stderr, "pipe failed\n");
    exit(1);
  }
  
  pid_t pid;

  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (pid == 0) {
    close(STDOUT_FILENO);
    dup(fildes[1]);
    printf("Hello, world!\n");
    exit(0);
  }

  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed (2)\n");
    exit(1);
  } else if (pid == 0) {
    close(STDIN_FILENO);
    dup(fildes[0]);
    char msg[1024];
    msg[1023] = '\0';
    fgets(msg, sizeof(msg), stdin);
    printf("message recieved:\n\t%s\n", msg);
    exit(0);
  }

  while (wait(NULL) != -1)
    ;

  printf("done\n");
}
