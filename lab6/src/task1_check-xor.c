
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 4096

char extention[] = ".xor_a";
#define SEC_TO_MICROSEC(x) (x * 1e6)

struct timeval start, end;

void print_dif(char func_name[], struct timeval t_s, struct timeval t_e) {
    long res = SEC_TO_MICROSEC(t_e.tv_sec) - SEC_TO_MICROSEC(t_s.tv_sec) +
               t_e.tv_usec - t_s.tv_usec;
    printf("time of %s = %ld\n", func_name, res);
}

int main(int argc, char *argv[]) {

    uint8_t check_sum = 0;
    uint8_t buf[BUF_SIZE];
    /*
     * генерируем имя файла с ответом
    */
    char *ans_file_name = malloc(strlen(argv[1]) + strlen(extention));
    strcpy(ans_file_name, argv[1]);
    strcpy(&ans_file_name[strlen(argv[1])], extention);;

    FILE *file = fopen(argv[1], "r");
    unsigned long readed;
    gettimeofday(&start, NULL); // Сохраняем время старта
    while ((readed = fread(buf, 1, BUF_SIZE, file)) != 0) { //Считываем поблочно
        for (int i = 0; i < readed; ++i) {
            check_sum ^= buf[i]; // Считаем сумму
        }
    }
    /*
    * Сверяем полученные ответ, с заранее известным
    */
    int answer = 0;
    FILE *ans_file = fopen(ans_file_name, "r");
    fscanf(ans_file, "%d", &answer);
    if (answer != check_sum) {
        return 1;
    }
    gettimeofday(&end, NULL); // Сохраняем время
    print_dif("XOR", start, end); // Выводим время, затраченное на вычисления хеш-суммы

    return 0;
}
