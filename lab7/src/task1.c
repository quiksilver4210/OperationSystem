
#include <stdio.h>
#include <stdint.h>

#define OPTIMIZE_8 3
#define OPTIMIZE_4 2
#define OPTIMIZE_1 1

uint64_t bit = 1;

int can_change(char *str, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!(str[i] >= 'A' && str[i] <= 'z')) {
            break;
        }
        ++count;
    }
    if (count >= 8) {
        return OPTIMIZE_8;
    }
    if (count >= 4) {
        return OPTIMIZE_4;
    }
    if (count >= 1) {
        return OPTIMIZE_1;
    }
    return 0;
}

void change_case(char *str, int size) {
    uint64_t change_mask = 0;
    for (int i = 0; i < 64; i += 8) {
        change_mask |= bit << (5 + i); //Создаем 8 байтное число с измененными 6-ыми битами для смены регистра
    }

    for (int i = 0; i < size;) {
        int left = size - i;
        int optimize_type = 0;
        if (left >= 8) {
            optimize_type = can_change(str + i, 8); // Проверяем, можем ли оптимизировать (нет посторонних символов)
        } else if (left >= 4) {
            optimize_type = can_change(str + i, 4);
        } else {
            optimize_type = can_change(str + i, 1);
        }

        switch (optimize_type) {
            case OPTIMIZE_8: {
                *((uint64_t *) (str + i)) ^= change_mask; // Меняем регистр
                i += 8;
                continue;
            }
            case OPTIMIZE_4: {
                *((uint32_t *) (str + i)) ^= change_mask;
                i += 4;
                continue;
            }
            case OPTIMIZE_1: {
                *(str + i) ^= change_mask;
                ++i;
                continue;
            }
            default: {
                ++i;
            }
        }


    }
}

int main() {
    char c[] = "aaaaaaaaDDDDaaaaAaaaaabbbbbccccc32";
    printf("Original = %s\n", c);
    change_case(c, sizeof(c) - 1);
    printf("Changed  = %s\n", c);
    return 0;
}