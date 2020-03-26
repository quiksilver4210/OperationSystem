#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int f = fork();
  if (f == 0) {
    printf("return from wait() in child = %d\n", wait(NULL));
  } else {
    //    int w = wait(NULL);
    int w = waitpid(0, 0, 0);
    printf("return from wait() in parent = %d\n", w);
  }
  return 0;
}