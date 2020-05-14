
#include <stdint.h>

uint8_t check_xor(const char* buf, int size){
    uint8_t check_sum = 0;
    for (int i = 0; i < size; ++i) {
        check_sum ^= buf[i];
    }
    return check_sum;
}