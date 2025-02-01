#include <stdio.h>
#include <stdlib.h>

typedef struct Time_struct {
   int hours;
   int minutes;
   int seconds;
} Time;

// appendTime() - append a new Time to *timeArry
// parameters: 
//  Time** timeArr - double pointer, i.e. pointer to the array
//  int* n - pass-by-pointer size of array
//  int hrs - hours for the new Time
//  int mns - minutes for the new Time
//  int scs - seconds for the new Time
void appendTime(Time** timeArr, int* n, int hrs, int mns, int scs) {

    Time* newArr = (Time*) malloc((*n + 1) * sizeof(Time)); // enough memory to store the old struct + 1 ie new struct and then times size of so that you can effectly store that many time

    for(int i = 0; i < *n; i++){
        newArr[i] = *timeArr[i]; // to dereference double pointer use i pointer and []

    }

    free(*timeArr);

    newArr[*n].hours = hrs;
    newArr[*n].minutes = mns;
    newArr[*n].seconds = scs;

    (*n)++;

    *timeArr = newArr;

    
    //TODO: append a new Time to *timeArry, which requires
    //      (1) allocate a new array (with space for an additional Time)
    //      (2) copy all Times from the old array to the new array
    //      (3) free the old array
    //      (4) rewire the array name to the new array
    //      (5) assign the subitems for the additional Time using the inputs
    //      (6) update the size parameter for the array
    //  do NOT use realloc()

}


// TimeDifference() - set the fields for diff to the result of end - start;
//                    all subitems (hours, minutes, seconds) must be non-negative
// NOTE: diff, end, and start are all passed-by-pointer
//  inputs: *end & *start (should not be modified)
//  output: *diff (should be modified)
void TimeDifference(Time* diff, Time* end, Time* start) {
   
   //TODO: set the fields for *diff to the result of *end - *start;
   //      all subitems (hours, minutes, seconds) must be non-negative

}


// calcTimeDiffs() - allocate & build array of time differences
// parameters:
//  Time* timeArr - array of Times
//  int n - size of timeArr
// returns: Time array (i.e. a pointer) of size n, set as difference   
Time* calcTimeDiffs(Time* timeArr, int n) {

    //TODO: allocate & build array of time differences
    //      calculated as difference from first element
    //      i.e. diffArr[i] = timeArr[i] - timeArr[0]
    
    // this is a faulty allocation... fix/replace it...
    int* ptr = malloc(sizeof(Time));

    return NULL; //modify this
}

// formatted print for a Time
void PrintTime(Time* t) {
   printf("%02d:%02d:%02d", t->hours, t->minutes, t->seconds);
}


int main(void) {

    int numTimes = 0;
    
    Time* finishTimes = NULL;
    
    int hours;
    int minutes;
    int seconds;
    
    // scan in race times from user-input and store in a dynamically allocated array;
    // continually reallocate to the exact size needed
    printf("Enter race times in [hours] [minutes] [second] format\n");
    printf("Enter -1 -1 -1 when done:\n");
    scanf("%d %d %d", &hours, &minutes, &seconds);
    while (hours >= 0 && minutes >= 0 && minutes >= 0) {
        appendTime(&finishTimes, &numTimes, hours, minutes, seconds);
        scanf("%d %d %d", &hours, &minutes, &seconds);
    }

    // calculate and store times back from the winner
    Time* backTimes = calcTimeDiffs(finishTimes,numTimes);

    // print the race results: place# finishTime timeBack
    printf("Race Results:\n");
    printf("Place  Finish    Back\n");
    for (int i = 0; i < numTimes; ++i) {
        printf("%5d ",i+1);
        PrintTime(&finishTimes[i]);
        printf(" ");
        PrintTime(&backTimes[i]);
        printf("\n");
        
    }

   // TODO: Always free dynamically allocated memory when no longer needed
   
   return 0;
}