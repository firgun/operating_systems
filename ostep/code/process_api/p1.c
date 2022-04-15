#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process goes down this path
    printf("hello, I am the child process (pid:%d)\n", (int) getpid());
  } else { // parent process goes down this path
    printf("hello, I am the parent process (pid:%d)\n", (int) getpid());
  }
  return 0;
}
