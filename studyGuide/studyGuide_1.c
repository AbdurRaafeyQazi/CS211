#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Q 1

// int main() {
// char d[] = "=0";
// int a = 3; int b = 2; int c = 1;
// char s = '-';
// printf("%d%c%d%c%d%s",b,s,c,s,c,d);
// return 0;
// }

// Q 2

// int main(int argc, char* argv[]) {
// printf("%s\n", argv[2]); // line A
// printf("%c\n", argv[1][0]); // line B
// printf("%d\n", argc); // line C
// printf("%d\n", atoi(argv[3])); // line D
// return 0;
// }

// Q 3

// int main(){
//     char message[] = "impossible";
//     printf("It’s %s!", message + 2);
// }

// Q 4

    // int increase(int* x, int y){
    //     *x = *x + 2;
    //     y = y + 1;
    // return *x + y;
    // }
    
    // int main() {
    // int a = 3, b = 6;
    // int c = increase(&a,b);
    // printf("%d %d %d", a , b , c);
    // return 0;
    // }



// Q 5

// typedef struct Lake_struct {

//     char* name; //string for full Lake name, e.g. Lake Michigan
//     char state[3]; //state abbreviation for lake, e.g. IL
//     bool boatsOK; //true if boats are allowed on the lake
//     int maxDepth; //maximum depth in whole feet

// }Lake;


// int main() {

// Lake headwater;

// strcpy(headwater.state,"MN");
// headwater.name = (char*)malloc(30*sizeof(char));
// strcpy(headwater.name,"Lake Itasca");
// headwater.boatsOK = true;
// printf("%c",headwater.name[5]);

// Lake crater;
// crater.maxDepth = 1949;
// strcpy(crater.state,"OR");

// Lake* deepwaters = (Lake*)malloc(100*sizeof(Lake));

// deepwaters[0] = crater;
// deepwaters[99].name = (char*)malloc(30*sizeof(char));
// strcpy(deepwaters[99].name,"Hyalite Reservoir");
// printf("%s",deepwaters[0].state);
// return 0;
// }

// Q6

// int main (){

// char str1[81] = "magicwands";
// char str2[81] = "magician";

//     if (strcmp(str1, str2) != 0) printf("NOT ");
//     printf("the same.");

// }


// Q7

// int main() {
// char myMessage[50]="CS211\nExam: 2/21/24";
// printf("%c\n",*myMessage); // (a)
// printf("%c\n",*myMessage + 1); // (b)
// printf("%c\n",*(myMessage + 1)); // (c)
// char* myCharPtr = myMessage + 9;
// printf("%c\n",*myCharPtr); // (d)
// printf("%s\n",myCharPtr); // (e)
// int count = 0;
// for (int i=0; i<(int)strlen(myMessage); ++i) {
// if (isdigit(myMessage[i])) {
// count++;
// }
// }
// printf("%d\n", count); // (f)
// }

// Q 8

// int main(){

// int x = 211;
// int* px = &x;
// int** ppx = &px;
// printf("%p %d %p", &x, *px, *ppx);
// }
//     void growArray(int** pArr, int* cap) {
//  int* pNew = malloc(((*cap)*2) * sizeof(int));
//  for (int i=0; i<(*cap); ++i) {
//  pNew[i] = (*pArr)[i];
//  }
//  (*cap) *= 2;

//  pArr = *pNew;
//  free(pNew);

 
//  // write code here for question (31)
//  // write code here for question (32)
//  }

// int main(){

//     double d1 = 4.668430;
//     double d3 = 4.668430;
//     double d2 = 55.0;
//     int i1 = 99;

//     float scannium;

//     scanf("%f" , &scannium);


//     printf("just 1 decimal place: %.1lf \n", d1);
//     printf("sci notation: %.1e \n", d3);
//     printf("Just the decimal: %.1lf \n" , d2);
//     printf("Just an int: %d \n" , i1);




// }

// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

// int main(void) {
//    const int USER_TEXT_LIMIT = 1000;    // Limit input size
//    char userText[USER_TEXT_LIMIT];      // Holds input
//    char firstName[50];                  // First name
//    char lastName[50];                   // Last name
//    int userAge;                         // Age
//    int valuesRead;                      // Holds number of inputs read
//    bool inputDone;                      // Flag to indicate next iteration
   
//    inputDone = false;

//    // Prompt user for input
//    printf("Enter \"firstname lastname age\" on each line\n");
//    printf("(\"Exit\" as firstname exits).\n\n");
   
//    // Grab data as long as "Exit" is not entered
//    while (!inputDone) {
      
//       // Grab entire line, store in userText
//       fgets(userText, USER_TEXT_LIMIT, stdin);
      
//       // Parse the line and check for correct number of entries.
//       valuesRead = sscanf(userText, "%49s %49s %d", firstName, lastName, &userAge);
//       if (valuesRead >= 1 && strcmp(firstName, "Exit") == 0) {
//          printf("Exiting.\n");
//          inputDone = true;
//       }
//       else if (valuesRead == 3) {
//          printf("   First name: %s\n", firstName);
//          printf("   Last  name: %s\n", lastName);
//          printf("   Age: %d\n", userAge);
//          printf("\n");
//       }
//       else {
//          printf("Invalid entry. Please try again.\n\n");
//       }
//    }
   
//    return 0;
// }


//------------------------------------------------------------------------------------------------------------------------------------------------
// Dynamically Allocates memeory for and array.

// int dymem(int** oldArr, int* count){
//     int* newArr = (int*) malloc((*count + 1) * sizeof(int));
//     for(int i = 0; i < *count; i++){
//         newArr[i] = (*oldArr)[i];
//     }
//     // I have now copied all the old array values into the new array.
//     // Now the old array needs to be freed

//     free(*oldArr);
//     // now point the old array to the new array.
//     *oldArr = newArr;

//     (*count)++;
// }


// int main(){

    
//     //If you want to dynamically allocate mememory 
//     // then you will have to create a temp array that ill temp store all the variable 
//     // Untill you can resize the array 
    
//     int count = 5;
//     // int* oldArr = (int*) malloc()
//     int* oldArr = (int*) malloc((count) * sizeof(int));

//     for(int i = 0; i < count; i++){
//         oldArr[i] = i + 1; 
//     }

//     dymem(&oldArr, &count);

//     oldArr[count - 1] = count;

//     for(int i = 0; i < count; i++){
//     printf("%d" , oldArr[i]);
//     }

//     printf("\n");

//     free(oldArr);

// }


//---------------------------------------------------------------------------------------------------------------------------------------
// Pointer Arithmetic 

// int sumArray(int* arr, int n){
//     int sum = 0;
//     for(int* p = arr; p < arr + n; p++) sum += *p;
//     return sum;
// }

// int main() {
//     int myArray[] = {1, 2, 3, 4, 5}; // An array of integers
//     int size = sizeof(myArray) / sizeof(myArray[0]); // Calculate the size of the array
//     int total = sumArray(myArray, size); // Call sumArray with the array and its size
//     printf("Sum of the array is: %d\n", total); // Print the result
//     return 0;
// }


// void sumArray(int* arr, int* sum, int size){
    
//     int* tempArr = arr;
//     for(int i = 0; i < size; i++){
//         *sum += *tempArr;
//         tempArr++;
//     }
//     printf("%d", *sum);
// }

// int main(){

//     int sum = 0;
//     int size = 10;
//     int arr[10] = {2, 3, 5};

//     sumArray(arr, &sum, size);

    
// }



// typedef struct struct_boi{

//     int man;
//     int bam;
//     int* can;
//     bool boi;

// }boi;

// int cli(int argc, int* argv[], int num1, int num2){


// }

// int main(){
// boi brother;

// boi* cutter = (boi*) malloc(sizeof(boi));

// brother.man = 10;

// cutter->can = (int*) malloc(sizeof(int));


// *(cutter->can) = 30;

// cutter->can = (int*) malloc(sizeof(int));


// int* ptr = NULL;

// ptr = 10;

// int** pptr = &ptr;

// printf("%d", **pptr);






// }


// int main(){

//     int val1 = 200;

//     double* prt = &val1;

//     printf("%p\n" , &val1);
//     printf("%p\n" , prt);
    
    

    

    

    

// }

//  int* growArr(int** oldarray, int* size) {
//      int* newArray = (int*) malloc((*size * 2) * sizeof(int));

//      for (int i = 0; i < *size; ++i) {
//          newArray[i] = (*oldarray)[i];
//      }

//      (*size) *= 2;

//      free(*oldarray);

//      *oldarray = newArray;

//      return newArray;
//  }


// typedef struct city_Struct{

//     char name;
//     int lati;
//     int longi;
//     int ele;



// }city;

// int distance(city ){

// }





// Define a struct named `Person`
typedef struct Person_struct {
    char name[50];
    int age;
}Person;

int main() {
    // Create a struct variable
    Person person1 = {"Alice", 30};

    // Declare a pointer to the struct
    Person* ptr = &person1;

    // Access struct members using the pointer
    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);

    return 0;
}

