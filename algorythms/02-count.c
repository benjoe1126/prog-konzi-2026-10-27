#include <stdio.h>
#include <stdbool.h>

// count how many times searched appears in arr
int count_int_concrete_number(const int* arr,const size_t len, int searched){
    int count = 0;
    for(size_t i = 0; len > i; i++){
        if(arr[i] == searched) count++;
    }
    return count;
}

// count how many elements in arr match the predicate function fv
int count_int_predicate_func(const int* arr,const size_t len, bool (*fv)(int)){
    int count = 0;
    for(size_t i = 0; len > i; i++){
        if(fv(arr[i])) count++;
    }
    return count;    
}

// end level, everything is generic now, THIS IS INSANE
int count_generic_with_predicate_func(const void* arr,const size_t len, bool (*fv)(const void*)){
    int count = 0;
    for(size_t i = 0; len > i; i++){
        if(fv(arr + i)) count++;
    }
    return count;    
}

bool is_negative(const int a){
    return a < 0;
}

// doesent make any sense really, as only whole numbers can be even or odd, don't have a better idea atm
bool is_even_generic(const void* num){
    return *((int*)num) % 2 == 0;
}

int main(void){
    int arr[] = {-1,22,1,55,111,-16,-537,657,-14,44, 10,1};
    size_t len = sizeof(arr) / sizeof(int);
    int num_occurrences_of_one = count_int_concrete_number(arr, len, 1);
    int num_negative = count_int_predicate_func(arr, len, is_negative);
    int num_even_generic = count_generic_with_predicate_func(arr, len, is_even_generic);
    printf("Number of times one appears: %d\n", num_occurrences_of_one);
    printf("Number of negative numbers: %d\n", num_negative);
    printf("Number of even numbers (with generic approach): %d\n", num_even_generic);
    return 0;
}
