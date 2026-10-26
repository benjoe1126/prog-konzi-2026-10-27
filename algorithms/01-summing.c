#include <stdio.h>
#include <stdbool.h>

int sum_int(const int* arr,const size_t len){
    int ret = 0;
    for(size_t i = 0; i < len; i++){
        ret += arr[i];
    }
    return ret;
}

double sum_double(const double* arr, const size_t len){
    double ret = 0;
    for(size_t i = 0; i < len; i++){
        ret += arr[i];
    }
    return ret;   
}

int main(void){
    int arr_int[] = {22,1,2,5,-1,2234};
    double arr_double[] = {1.1,2.2,-3.1,5};
    printf("Int arr sum: %d\n", sum_int(arr_int, 6));
    printf("Double arr sum: %.2lf\n", sum_double(arr_double, 4));
    return 0;
}