#include <stdio.h>
#include <stdbool.h>

void partition(const int* arr, const size_t len, int* part_one, size_t* len_part_one,  int* part_two, size_t* len_part_two, bool (*fv)(const int)){
    size_t p1_idx = 0;
    size_t p2_idx = 0;
    for(size_t i = 0; len > i; i++){
        if(fv(arr[i])){
            part_one[p1_idx++] = arr[i];
        }else{
            part_two[p2_idx++] = arr[i];
        }
    }
    *len_part_one = p1_idx;
    *len_part_two = p2_idx;
}

void print_arr(const char* arr_name, const int* arr, const size_t len){
    printf(">>=================Printing array: %s==========================>>\n",arr_name);
    for(size_t i = 0; len > i; i++){
        printf("%d\n",arr[i]);
    }
    printf("<<=================Printing array: %s==========================<<\n\n\n", arr_name);
}

bool is_even(const int a){
    return a % 2 == 0;
}

int main(void){
    const int arr[15] = {41, 17, 89, 3, -56, 24, 71, -7, 63, 35, 91, 12, 48, -67, 29};
    {
        int positives[15] = {0};
        int negatives[15] = {0};
        size_t len_pos, len_neg;
        partition(arr, 15, negatives, &len_neg ,positives, &len_pos,is_even);
        print_arr("Negativ particio", negatives, len_neg);
        print_arr("Pozitiv particio", positives, len_pos);
    }
    return 0;
}