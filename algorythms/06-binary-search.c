#include <stdio.h>
#include <stdlib.h>


/**
The keypoint with binary search is that it assumes an ordered array of numbers, otherwise it won't work
To avoid this issue we will also use qsort, it is not too important for us what happens there, just accept that it sorts
*/
int binary_search(const int* sorted_arr, const size_t len, const int searched){
    int beg, end;
    beg = 0, end = len;
    int idx = (beg + end) / 2;
    while(sorted_arr[idx] != searched && beg < end){
        if(sorted_arr[idx] < searched){
            beg = idx + 1;
            idx = (beg + end) / 2;
        }else if(sorted_arr[idx] > searched){
            end = idx - 1;
            idx = (beg + end) / 2;
        }
    }
    if(sorted_arr[idx] != searched) return -1;
    return idx;
}

int comparator(const void* a, const void* b){
    int i1, i2;
    i1 = *((int*)a);
    i2 = *((int*)b);
    if(i1 > i2) return 1;
    if(i1 == i2) return 0;
    return -1;
}


int main(void){
    int arr[] = {10,12,8,22,-1,2-3,57 * 41, -78854};
    const size_t len = sizeof(arr) / sizeof(int);
    qsort(arr, len, sizeof(int), comparator);
    int searched_idx = binary_search(arr, len , -1);
    if(searched_idx == -1) printf("Element not found\n");
    else printf("Found element at idx: %d\n",searched_idx);
}
