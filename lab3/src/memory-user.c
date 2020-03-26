#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int size = 0;
    printf("process = %d\n", getpid()); // узнаем индекс текущего процесса
    scanf("%d", &size); // считываем количество мегабайт, которое нужно зарезервировать
    char *array = malloc(size * 1024 * 1024); // выделяем нужное количество, получаем адрес выделенной памяти
    while (1) {
        for (int i = 0; i < size * 1024 * 1024; ++i) {
            array[i] = 'c'; // перебираем все элементы в бесконечном цикле
        }
    }

    return 0;
}