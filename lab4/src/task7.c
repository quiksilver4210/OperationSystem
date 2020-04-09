#include <stdlib.h>
int main(){
    int *arr = (int*)malloc(100* sizeof(int));
    arr[100] = 0;
    return 0;
}