#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

// why const, why size_t?
int sum_array(const int* arr, const size_t len){
    int result = 0;
    for(size_t i = 0; len > i; i++) result += arr[i];
    return result;
}

void greet(const char* name) {
    printf("Hello %s\n",name);
    // so no return?
}


// main is a function too :O
int main(void) {
  
    // BTW printf is a function too
    printf("%d\n",add(4,5));
    greet("Lajos");
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int result = sum_array(arr,10);
    printf("The sum of the first 10 numbers is %d\n",result);
    return 0; // why return 0?
}