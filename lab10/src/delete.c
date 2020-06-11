#include <unistd.h>
#include <stdio.h>

int main() {
    if (unlink("f_link") != 0) {
        return 1;
    }
    return 0;
}