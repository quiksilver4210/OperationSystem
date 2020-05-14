#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "xor_csum.h"

#define BUF_SIZE 4096

char extention[] = ".csum";


int main(int argc, char *argv[]) {
    uint8_t check_sum = 0;
    uint8_t buf[BUF_SIZE];
    char *ans_file_name = malloc(strlen(argv[1]) + strlen(extention));
    strcpy(ans_file_name, argv[1]);
    strcpy(&ans_file_name[strlen(argv[1])], extention);

    FILE *file = fopen(argv[1], "r");
    FILE *ans_file = fopen(ans_file_name, "w+");
    unsigned long readed;
    while ((readed = fread(buf, 1, BUF_SIZE, file)) != 0) {
        fprintf(ans_file, "%c", check_xor(buf, readed)); // Считаем чек сумму и записываем ее в файл
    }

    fclose(ans_file);
    return 0;
}