#include <stdio.h>

void so_return(int idc) {
    printf("IDK man...\n");
    return;
}

int main(void){
    so_return(4);
    //void a = so_return(5);
    // why no return 0?
}
