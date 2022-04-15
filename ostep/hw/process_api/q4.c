// Question
// ---
// Write a program that calls fork() and then calls some form of exec() to run the program /bin/ls.
// See if you can try all the variants of exec(), including (on Linux) execl(), execle(), execlp(),
// execv(), execvp() and execvpe(). Why do you think there are so many variants of the same basic
// call.
//
// Answer
// ---
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    char *args[3];
    args[0] = "ls";
    args[1] = ".";
    args[2] = NULL;
    execvp(args[0], args);
    fprintf(stderr, "exec failed\n");
    exit(1);
  } else {
    int rc_wait = wait(NULL);
  }
  return 0;
}
