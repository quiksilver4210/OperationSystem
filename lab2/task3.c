#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int f = fork();
  if (f == 0) {
    execl("/bin/ls", "-l");
  } else {
    wait(NULL);
  }
  return 0;
}