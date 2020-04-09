#include <stdlib.h>
#include <stdio.h>

int main() {
    int *arr = (int *) malloc(100 * sizeof(int));
    arr[0] = 5;
    free(arr);

    printf("arr[0] = %d", arr[0]);
    return 0;
}