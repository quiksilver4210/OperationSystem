#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
    printf("TEST 1 (5 bytes)\n");
    system("./lab6-task1 ../../lab6/tests/t1.txt");
    system("./lab6-task2 ../../lab6/tests/t1.txt");
    system("./lab6-task3 ../../lab6/tests/t1.txt");

    printf("TEST 2 (149873 bytes)\n");
    system("./lab6-task1 ../../lab6/tests/t2.txt");
    system("./lab6-task2 ../../lab6/tests/t2.txt");
    system("./lab6-task3 ../../lab6/tests/t2.txt");
    return 0;
}