#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void goodbye(){
  printf("goodbye\n");
}
int main() {
  int f = fork();
  if (f == 0) {
    printf("hello\n");
    kill(getppid(),SIGCONT);
  } else {
    signal(SIGCONT,goodbye);
    pause();
  }
  return 0;
}