#include <stdio.h>
#include <stdlib.h>


// Argc is the number of arguments
// Argv is an array of strings, and these are the arguments themselves
int main(int argc, char *argv[]){

    if(argc != 3){ // Because 1 arg is the program and the other 2 are user defined.
        printf("Two args required!\n");
        exit(-1);
    }

    int lower = atoi(argv[1]);
    int higher = atoi(argv[2]);


    // Converts string to number,
    // Then stores number into i
    // Loops from i lower to i higher, incrementing by 1 in order to print out everything.
    
    for(int i = lower; i <= higher; i++){
        printf("%d\n", i);

    }

    
    printf("argc: %d\n", argc); // Prints out the num of args
    
    // Does the same thing as below but for loop.
    for(int i = 0; i < argc; i++){
        printf("argv[%d]=%s\n",i,argv[i]);
    }

    // Prints out the arguments at each index of the array
    printf("argv[0]=%s\n", argv[0]);
    printf("argv[1]=%s\n", argv[1]);
    printf("argv[2]=%s\n", argv[2]);
    printf("argv[3]=%s\n", argv[3]);

    return 0;
 

}