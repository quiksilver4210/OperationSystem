#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);
  int f1 = fork();

  if (f1 == 0) {
    close(fd[0]);
    char msg[] = "child";
    write(fd[1], msg, 6);
    close(fd[1]);
  } else {
    wait(NULL);
    int f2 = fork();
    if (f2 == 0) {
      close(fd[1]);
      char buf[6];
      read(fd[0], buf, 6);
      close(fd[0]);
      printf("message from child1 = %s", buf);
    }
  }
  return 0;
}