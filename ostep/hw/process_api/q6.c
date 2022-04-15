// Question
// ---
// Write a slight modification of the previous program, this time using waitpid()
// instead of wait(). When would waitpid() be useful?
//
// Answer
// ---
// waitpid() would be useful when a process has several children and must wait
// for one in particular.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (pid == 0) {
    printf("child (pid:%d)\n", (int) getpid());
  } else {
    int rc_wait = waitpid(pid);
    printf("parent (pid:%d)\n", (int) getpid());
  }
  return 0;
}
