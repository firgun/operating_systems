// Question
// ---
// Write a program that calls fork(). Before calling fork(), have the main process
// access a variable (e.g., x) and set it to something (e.g., 100). What is the
// value of the variable in the child process? What happens to the variable when
// both the child and parent change the value of x?
//
// Answer
// ---
// fork() creates a copy of the main process, which includes everything the process
// can read or write, e.g., the variable x, so x will have the same value in the
// parent and child processes. But after the call to fork(), x refers to different
// physical memory locations and any changes to it, in a particular process will only
// effect that process (things are not so simple when it comes to the processes file
// descriptors, however).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int x;
  x = 100;
  printf("before fork x:%d\n", x);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    x /= 2;
    printf("in child x:%d\n", x);
  } else {
    int rc_wait = wait(NULL);
    x *= 2;
    printf("in parent x:%d\n", x);
  }
  return 0;
}
