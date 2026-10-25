#include <stdio.h>

void partition_pos_neg(const int* arr, const size_t len, int* negatives, size_t* len_neg,  int* positives, size_t* len_pos){
    size_t pos_idx = 0;
    size_t neg_idx = 0;
    for(size_t i = 0; len > i; i++){
        if(arr[i] > 0){
            // heh? :O
            positives[pos_idx++] = arr[i];
        }else {
            negatives[neg_idx++] = arr[i];
        }
    }
    *len_pos = pos_idx;
    *len_neg = neg_idx;
}

void partition_even_odd(const int* arr, const size_t len, int* evens,size_t* len_even, int* odds, size_t* len_odd){
    size_t even_idx = 0;
    size_t odd_idx = 0;
    for(size_t i = 0; len > i; i++){
        if(arr[i] % 2 == 0){
            // heh? :O
            evens[even_idx++] = arr[i];
        }else {
            odds[odd_idx++] = arr[i];
        }
    }
    *len_even = even_idx;
    *len_odd = odd_idx;
}

void print_arr(const char* arr_name, const int* arr, const size_t len){
    printf(">>=================Printing array: %s==========================>>\n",arr_name);
    for(size_t i = 0; len > i; i++){
        printf("%d\n",arr[i]);
    }
    printf("<<=================Printing array: %s==========================<<\n\n\n", arr_name);
}

int main(void){
    const int arr[15] = {41, 17, 89, 3, -56, 24, 71, -7, 63, 35, 91, 12, 48, -67, 29};
    {
        int positives[15] = {0};
        int negatives[15] = {0};
        size_t len_pos, len_neg;
        partition_pos_neg(arr, 15, negatives, &len_neg ,positives, &len_pos);
        print_arr("Negativ particio", negatives, len_neg);
        print_arr("Pozitiv particio", positives, len_pos);
    }
    {
        int evens[15] = {0};
        int odds[15] = {0};
        size_t len_even, len_odd;
        partition_even_odd(arr, 15, evens, &len_even ,odds, &len_odd);
        print_arr("Paros particio", evens, len_even);
        print_arr("Paratlan particio", odds, len_odd);
    }
    return 0;
}