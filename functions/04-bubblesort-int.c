#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// regular bubble_sort with asc ordering, or descending if reversed is true
void bubble_sort(int* elements, const size_t len, const bool reversed){
    int tmp;
    bool should_switch, should_switch_reversed, should_switch_regular;
    for(size_t i = 0; len > i; i++){
        for(size_t j = i; len > j; j++){
            should_switch = false;
            should_switch_regular = !reversed && elements[j] < elements[i];
            should_switch_reversed = reversed && elements[i] < elements[j];
            should_switch = should_switch_regular || should_switch_reversed;
            if(should_switch){
                tmp = elements[i];
                elements[i] = elements[j];
                elements[j] = tmp;
            }
        }
    }
}

void print_arr(const int* elements, const size_t len){
    for(size_t i = 0; len > i; i++){
        printf("%d\n",elements[i]);
    }
}

int main(void) {
    int elements[] = {32,11,22,-11,-132,5,8881,12333};
    size_t len = sizeof(elements) / sizeof(int);
    printf("len is: %llu\n",len);
    bubble_sort(elements, len , true);
    print_arr(elements, len);
    return 0;
}