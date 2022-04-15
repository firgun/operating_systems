#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  printf("hello, world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process
    printf("I am child (pid:%d)\n", (int) getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p3.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
    printf("this shouldn't print out!");
  } else { // parent process
    int rc_wait = wait(NULL);
    printf("parent of %d (pid:%d) (rc_wait:%d)\n", rc, (int) getpid(), rc_wait);
  }
  return 0;
}
