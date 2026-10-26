#include <stdio.h>
#include <stdbool.h>

// find first even element
int selection_idx_even(const int* arr, const size_t len){
    for(size_t i = 0; len > i; i++){
        if(arr[i] % 2 == 0) return i;
    }
    return -1;
}

// we can also just return a pointer to the matching element, or NULL if no matching element is found :O
const int* selection_ptr_even(const int* arr, const size_t len){
    for(size_t i = 0; len > i; i++){
        if(arr[i] % 2 == 0) return arr + i;
    }
    return NULL;
}


int main(void){
    const int arr[15] = {41, 17, 89, 3, 56, 24, 71, 8, 63, 35, 91, 12, 48, 67, 29};
    int idx_of_first_even = selection_idx_even(arr, 15);
    const int* ptr_of_first_even = selection_ptr_even(arr,15);
    printf("Index of first even: %d\n",idx_of_first_even);
    printf("Ptr to first even: %p\n",ptr_of_first_even);
    // Dangerous because it could be negative or NULL, be careful
    printf("Value of first even: ptr: %d, idx: %d",*ptr_of_first_even, arr[idx_of_first_even]);
    return 0;
}