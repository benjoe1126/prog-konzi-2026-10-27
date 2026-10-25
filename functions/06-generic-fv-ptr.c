#include <stdio.h>

// void* could be cast to anything we want, this could however be dangerous, try using specific types if possible
void* max_with_cmp_generic(void* a, void* b, int(*cmp)(void*,void*)){
    if(cmp(a,b) > 0) return a;
    return b;
}


typedef struct Time{
    size_t hours, minutes, seconds;
} Time;

size_t time_to_seconds(Time t){
    return t.hours * 60 * 60 + t.minutes * 60 + t.seconds;
}

// compare two timestampt, return 1 if the first is greater, 0 if eq, -1 if first is lesser (e.g 14:22:33 is lesser than 15:11:22)
// need to use void* so function matches the expected signature of int xy(void* a, void* b)
int compare_times(void* a, void* b){
    Time t1 = *((Time*) a); //kinda gross, but gotta do what we gotta do
    Time t2 = *((Time*) b);
    size_t t1_seconds = time_to_seconds(t1);
    size_t t2_seconds = time_to_seconds(t2);
    if(t1_seconds > t2_seconds) return 1;
    if(t1_seconds == t2_seconds) return 0;
    return -1;
}

void print_time(Time a){
    printf("%02zu:%02zu:%02zu", a.hours, a.minutes, a.seconds);
}

int main(void){
    Time noon = {.hours=12, .minutes=0, .seconds=0};
    Time nine_thirty = {.hours = 9, .minutes = 30, .seconds= 12}; //12 seconds for shits and giggles
    // any pointer can be cast to any other pointer implicitly (the are all the same size) but that does not mean it will be correct, it is your job as a programmer to make sure it doesent fuck up
    print_time(*((Time*)max_with_cmp_generic(&noon, &nine_thirty, compare_times)));
    return 0;
}