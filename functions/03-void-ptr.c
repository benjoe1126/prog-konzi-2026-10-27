#include <stdlib.h>

void* is_it_okey() {
    int a = 4;
    return (void*)(&a); //explicit cast, can be implicit as well
}


void* how_about_now(){
    return malloc(10);
}

int main(void){
    void* not_really = is_it_okey();
    void* now_cool = how_about_now();
    return 0;
}