
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (pid == 0) {
    close(STDOUT_FILENO);
    printf("child, \"Hello, world!\"\n");
  } else {
    wait(NULL);
    printf("parent, \"Hello, world!\"\n");
  }
  return 0;
}
