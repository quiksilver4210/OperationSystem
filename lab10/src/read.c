#include <stdio.h>
#include <unistd.h>
#include <memory.h>

#define BUF_SIZE 4096
char buf[BUF_SIZE];

int main() {
    FILE *f = fopen("f_link", "r");
    if (f == NULL) {
        return 1;
    }
    while (1) {
        fseek(f, 0, SEEK_SET);
        int size = 0;
        while (fread(buf, 1, BUF_SIZE, f) != 0);
        printf("%.*s\n", size - 1, buf);
        sleep(1);
    }
    return 0;
}