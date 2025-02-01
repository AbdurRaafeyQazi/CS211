#include <stdio.h>

int main(){

    int x = 4; // x is an integer
    int* p = &x; // p is a pointer to x

    *p = 99; // The value of x is now 99

    int y = *p; // The value of y will be x 

    y = 10;

    *p = 45;



    printf("Prints the adress of the pointer p itself: %p", &p); // Prints the adress of the pointer p itself
    
    printf("\n \n");
    
    printf("Prints the adress stored in p (Which is the address of x): %p", p); // Prints the adress stored in p (Which is the address of x)

    printf("\n \n");

    printf("This prints out the actual value of x: %d", *p); // This prints out the actual value of x

    printf("\n \n");

    printf("This should be 10 due to updating it: %d", y); // This should be 10 due to updating it

    printf("\n \n");

    printf("After updating y will the value of x change ?: %d", x); // After updating y will the value of x change ?

    printf("\n \n");

    printf(" Can you update the value of p to 45 without using a pointer, and chance the value of x: %d", x); // No

}


