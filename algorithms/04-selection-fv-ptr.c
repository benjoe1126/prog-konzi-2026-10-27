#include <stdio.h>
#include <stdbool.h>

// find first element matching predicate fv, if no element found return -1 (although I believe the Kiválasztás tétele expect that at least one element matches)
int selection_indicies(const int* arr, const size_t len, bool (*fv)(int)){
    for(size_t i = 0; len > i; i++){
        if(fv(arr[i])) return i;
    }
    return -1;
}

// we can also just return a pointer to the matching element, or NULL if no matching element is found :O
const int* selection_ptr(const int* arr, const size_t len, bool (*fv)(int)){
    for(size_t i = 0; len > i; i++){
        if(fv(arr[i])) return arr + i;
    }
    return NULL;
}

bool is_even(const int a){
    return a % 2 == 0;
}

bool is_gt_50(const int a){
    return a > 50;
}


int main(void){
    const int arr[15] = {41, 17, 89, 3, 56, 24, 71, 8, 63, 35, 91, 12, 48, 67, 29};
    int idx_of_first_even = selection_indicies(arr, 15, is_even);
    const int* ptr_to_first_element_gt_50 = selection_ptr(arr,15 , is_gt_50);
    printf("Index of first even: %d\n",idx_of_first_even);
    printf("Ptr to first gt 50: %p\n",ptr_to_first_element_gt_50);
    return 0;
}