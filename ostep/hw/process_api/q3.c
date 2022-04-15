// Question
// ---
// Write another program using fork(). The child process should
// print "hello", and the parent "goodbye". Can you ensure that
// the child process always prints before the parent without
// calling wait() in the parent?
//
// Answer
// ---
// You could spin for a really long time and hope that a context
// switch occurs, or you could wait for the parent in the child?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t parent_pid = getpid();
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello\n");
  } else {
    for (int i = 0; i < 1000000; i++)
      ;
    printf("goodbye\n");
  }
  return 0;
}

