#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "xor_csum.h"

#define BUF_SIZE 4096

char extention[] = ".csum";

int check_csum(FILE *ans_file, uint8_t result) {
    char readed;
    fscanf(ans_file, "%c", &readed);
    if (result == readed) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    uint8_t buf[BUF_SIZE];
    char *ans_file_name = malloc(strlen(argv[1]) + strlen(extention));
    strcpy(ans_file_name, argv[1]);
    strcpy(&ans_file_name[strlen(argv[1])], extention);

    FILE *file = fopen(argv[1], "r");
    FILE *ans_file = fopen(ans_file_name, "r");
    unsigned long readed;
    while ((readed = fread(buf, 1, BUF_SIZE, file)) != 0) {
        if (check_csum(ans_file, check_xor(buf, readed)) == 1) { //Сверяем полученную чек сумма
            return 1;
        }
    }
    fclose(file);
    fclose(ans_file);
    return 0;
}