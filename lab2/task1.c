#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int x = 100;
  int f = fork();
  if (f == 0) {
    printf("x = %d\n", x);
    x = 5;
    printf("new child x = %d\n", x);
  } else {
    printf("x = %d\n", x);
    x = 50;
    printf("new parent x = %d\n", x);
  }
  return 0;
}