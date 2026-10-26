#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_int_arr_ptr(const int** elements, const size_t len){
    for(size_t i = 0; len > i; i++){
        printf("%d\n",*elements[i]);
    }
}

void** clone(const void** arr, const size_t len){
    void** ret = malloc(len * sizeof(void*));
    for(size_t i = 0; len > i; i++){
        ret[i] = malloc(sizeof(void*));
        memcpy(ret[i], arr[i], sizeof(ret[i]));
    }
    return ret;
}

void free_cloned_arr(void** arr, const size_t len){
    for(size_t i = 0; len > i; i++) free(arr[i]);
    free(arr);
}

int main(void){
    int a = 0, b = 2, c = 3, d = 4, f = 5;
    int** arr = malloc(5 * sizeof(int*));
    arr[0] = &a, arr[1] = &b, arr[2] = &c, arr[3] = &d, arr[4] = &f;
    const int** cloned = (const int**) clone((const void**) arr,5);
    print_int_arr_ptr(cloned, 5);
    free(arr);
    free_cloned_arr((void**) cloned, 5);
    return 0;
}