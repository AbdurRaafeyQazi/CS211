#include <stdio.h>



int sum(int* a, int* b){

      *a = 20;
      return (*a + *b);
}


void swap(int* v1, int* v2){

   int temp = *v1;
   *v1 = *v2;
   *v2 = temp;


}


int main() {
   
   // int i = 6;

   // int* j = &i; // J is a pointer pointing to i
   
   // int** k = &j;

   // printf("The adress of i %p \n", &i);
   // printf("The adress of i %p \n", j);

   // printf("The value at address j is %p\n", *(&j));

   // printf("The value of i %d \n", **(&j)); 
 
   // int x = 1, y = 6;
   // printf("The sum of 1(replaced by 20) and 20+6 is %d\n", sum(&x, &y));

   int x = 0, y = 1;
   printf("The initial values are: %d %d\n", x , y);
   swap(&x, &y);
   printf("The values after running the function are: %d %d \n", x , y);

}