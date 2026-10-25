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
    #if SUB_PART == 1
    {
        // BTW printf is a function too
        printf("%d\n",add(4,5));
        greet("Lajos");
        int arr[] = {1,2,3,4,5,6,7,8,9,10};
        int result = sum_array(arr,10);
        printf("The sum of the first 10 numbers is %d\n",result);
    }
    #elif SUB_PART == 2
    {
        //can I store it?
        printf("%zu\n",sizeof(void));
        //void ret = so_return(4); // Why not? :c
    }
    #elif SUB_PART == 3
    {
        void* well_yes_but_no = is_it_okey();
        printf("%p\n",well_yes_but_no);
    }
    #elif SUB_PART == 4
    {
        void* now_ok = how_about_now();
        printf("%p\n",now_ok);
        // dont forget
        free(now_ok);
    }
    #endif
    return 0; // why return 0?
}