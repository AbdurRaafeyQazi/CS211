#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------
// getArgs() - Retrieve & store command line arguments
// inputs/outputs:
//    int argc          number of args, including program executable name
//    char* argv[]      array of strings
//    int* rowPtr       first command line parameter - integer number of rows
//    char* charPtr     second command line parameter - character symbol to use
//    bool* triTypePtr  third command line parameter - triangle type: 0=isosceles 1=right
// default: 5 rows, using '*', isosceles triangle
//    set to default values if any command line parameter is missing

void getArgs(int argc, char* argv[], int* rowPtr, char* charPtr, bool* triTypePtr) {

    /*
    Int argc just keeps a count of how many arguments are going in into the command line arguments (can you use argc as is without argv?)
    there are 4 arguments, argc does not count as one, but argv does count as an argument.
    the rest of them are also command line arguments that will be passed into argv[]
    since arv[] is a char type when you pass a value into argv it will go in as a char string, but needs to come out and get stored into the respective types 
    so for example rowPtr is a int which will go into argv as a int and will turn into a string and then will have to be converted into a int again 

    */


    //TODO: write getArgs()
    if(argc == 4){
        *rowPtr = atoi(argv[1]);
        *charPtr = argv[2][0];
        *triTypePtr = atoi(argv[3]);
    }else{
        *rowPtr = 5;
        *charPtr = '*';
        *triTypePtr = 0;
    }



    return;
}

//---------------------------------------------------------------------
int main(int argc, char* argv[]) {
    int rows;
    char myChar;
    bool triType;
    
    //TODO: call getArgs() to set rows, myChar, and triType
    getArgs(argc, argv, &rows, &myChar, &triType);
    //print a triangle - variables
    //   rows: height of triangle
    //   myChar: character to make triangle with
    //   triType: 0/false = isosceles, 1/true = right
    for (int i = 1; i <= rows; ++i) {
        int k = 0;
        for (int s = 1; s <= rows - i; ++s) {
            printf("  ");
        }
        
        int cap = 2 * i - 1;
        if (triType) {
            cap = i;
        }
        
        while (k < cap) {
            printf("%c ",myChar);
            ++k;
        }
        printf("\n");
    }

  return 0;
}


