#include <stdio.h>

// max function with a catch: compare logic is substitutable
int max_with_cmp(int a, int b, int(*cmp)(int,int)){
    if(cmp(a,b) > 0){
        return a;
    }
    return b;
}

int reversed_cmp(int a, int b){
    if(a > b) return -1;
    if(a == b) return 0;
    return 1;
}

int regular_cmp(int a, int b){
    if(a > b) return 1;
    if(a == b) return 0;
    return -1;
}

int main(void){
    printf("The max of (4,5) is: %d\n",max_with_cmp(4, 5, reversed_cmp));
    printf("The max of (4,5) is: %d\n",max_with_cmp(4, 5, regular_cmp));
    return 0;
}