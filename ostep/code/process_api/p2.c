#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed; exiting\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, I am child (pid:%d)\n", (int) getpid());
  } else {
    int rc_wait = wait(NULL);
    printf("I am parent of %d (pid:%d, rc_wait:%d)\n", rc, (int) getpid(), rc_wait);
  }
  return 0;
}
