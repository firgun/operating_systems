// Question
// ---
// Now write a program that uses wait() to wait for the child process to
// finish in the parent. What does wait() return? What happens if you use
// wait() in the child?
//
// Answer
// ---
// wait() returns -1 if called in the child because there are no child
// processes to wait for. wait() returns the pid of the process waited
// for if called in the parent.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PARENT_WAITS

int main(int argc, char **argv) {
  pid_t pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (pid == 0) {
#ifndef PARENT_WAITS
    int rc_wait = wait(NULL);
    printf("rc_wait: %d\n", rc_wait);
#endif
    printf("child (pid: %d)\n", (int) getpid());
  } else {
#ifdef PARENT_WAITS
    int rc_wait = wait(NULL);
    printf("rc_wait: %d\n", rc_wait);
#endif
    printf("parent (pid: %d)\n", (int) getpid());
  }
  return 0;
}
