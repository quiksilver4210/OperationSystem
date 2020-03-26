
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int f = fork();
  if (f == 0) {
    close(STDOUT_FILENO);
    printf("child process\n");
  } else {
    wait(NULL);
    printf("parent process\n");
  }
  return 0;
}