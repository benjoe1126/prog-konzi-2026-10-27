#include <stdio.h>
#include <stdbool.h>

//straight to predicate function, no generics this time tho :cc
// iterate over arr and if the predicate function fv matches, return true, if no matching elements found return false
bool decision(const int* arr, const size_t len, bool (*fv)(int)){
    for(size_t i = 0; len > i; i++){
        if(fv(arr[i])) return true;
    }
    return false;
}

bool is_even(const int a){
    return a % 2 == 0;
}

// dont wanna include anything else rn
int abs(const int a){
    if(a > 0) return a;
    return -a;
}

// regular, dumb prime check, just for example
bool is_prime(const int a){
    const int as_positive = abs(a);
    if(as_positive < 2) return false;
    for(int i = 2; as_positive > i; i++){
        if(as_positive % i == 0) return false;
    }
    return true;
}

int main(void){
    const int arr[15] = {42, 17, 89, 3, 56, 24, 71, 8, 63, 35, 91, 12, 48, 67, 29};
    bool contains_even_number = decision(arr, 15, is_even);
    bool contains_prime_number = decision(arr, 15, is_prime);
    printf("%s tartalmaz paros szamot\n", contains_even_number ? "Igen," : "Nem");
    printf("%s tartalmaz prim szamot\n", contains_prime_number ? "Igen," : "Nem");
    return 0;
}