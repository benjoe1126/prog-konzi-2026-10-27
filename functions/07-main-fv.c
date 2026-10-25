#include <stdio.h>

// if main is a function, does that mean it can have arguments :OO
// well yes, it can, argc and argv
// argc - number of cli arguments
// argv - cli arguments
int main(int argc, char** argv){
    printf("The number of cli args are: %d\n",argc);
    for(int i = 0; argc > i; i++){
        // first argument is the name of the program
        printf("Arg number [%d] is %s\n",i,argv[i]);
    }
}