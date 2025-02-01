#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



// typedef struct Sample_struct {
//    double temperature;
// 	int days;
// } Sample;

// void Sample_PrintSample(Sample* ptrToSample) {
//    if (ptrToSample == NULL) return;
// 	printf("Sample: Temperature is %.1lf", ptrToSample->temperature);
// 	printf("F after %d days.\n", ptrToSample->days);
// }

// int main(void) {
// 	Sample* sample1 = NULL; // is a instance of a struct?
// 	double temperatureChange;
// 	int daysChange;
	
// 	sample1 = (Sample*) malloc(sizeof(Sample));
	
// 	scanf("%lf", &sample1->temperature);
// 	scanf("%d", &sample1->days);
// 	scanf("%lf", &temperatureChange);
// 	scanf("%d", &daysChange);
	
// 	Sample_PrintSample(sample1);

//    sample1->temperature += temperatureChange;
//    sample1->days += daysChange;


// 	Sample_PrintSample(sample1);
	
// 	free(sample1);
   
//    return 0;
// }


/*
Relation	Returns	Expression to detect
str1 less than str2	  Negative number	  strcmp(str1, str2) < 0
str1 equal to str2	  0	  strcmp(str1, str2) == 0
str1 greater than str2	  Positive number	  strcmp(str1, str2) > 0


*/

// int main(void){

//    char userString[50];

//    scanf("%s", userString);

//    if(strcmp(userString, "Quit") == 0){
//       printf("Goodbye\n");
//    }else{
//       printf("Hello\n");
//    }

// }





// int main(void) {
//    char firstString[50];
//    char secondString[50];

//    scanf("%s", firstString);
//    scanf("%s", secondString);

   

//    return 0;
// }



// int strCmpCnt(char* word1, char* word2) {

 
//    int count = 0;
//    int w1len = strlen(word1);
//    int w2len = strlen(word2);
//    int diff;

//    if(w1len > w2len){
//       diff = w1len - w2len;
//    }
   
//    else if(w2len > w1len){
//       diff = w2len - w1len;
//    }


//    int i = 0;


//    if(w1len > w2len){
//       while(i < w2len){
//          if(word1[i] == word2[i]){
//             i++;
//          }else{
//             count++;
//             i++;
//          }
//       }
//       return count += diff;
//    }
   
//    else if(w2len > w1len){
//       while(i < w1len){
//          if(word1[i] == word2[i]){
//             i++;
//          }else{
//             count++;
//             i++;
//          }
//       }
//       return count += diff;
//    }
   

//    else if (w1len == w2len){
//       while(i < w1len && w2len){
//          if(word1[i] == word2[i]){
//             i++;
//          }else{
//             count++;
//             i++;
//          }
//       }
//       return count;
//    }
// //---------------------------------------------------------------------------- Another easier way to do this.
//    while(*word1 != '\0' && *word2 != '\0'){
//       if(*word1 != *word2){
//          count++;
//       }
//       word1++;
//       word2++;
//    }

//    while(*word1 != '\0'){
//       count++;
//       word1++;
   
//    }  

//    while(*word2 != '\0'){
//       count++;
//       word2++;
//    }

//    return count;
  
// }





// int strCmpInd(char* word1, char* word2) {
//    int w1len = strlen(word1);
//    int w2len = strlen(word2);
//    int count = 0;

//    while(*word1 != '\0' && *word2 != '\0'){
//       if(*word1 == *word2){
//          count++;
//          word1++;
//          word2++;
         
//       }else{
//          break; 
//       }  
      
//    }

//    if(w1len == count && w2len == count){
//       return -1;
//    }else{
//       return count;
//    }


// //-------------------------------------------------------------------
// // TODO - Task II: write the strCmpInd() function, which returns the
// //                 index of the character where two strings first 
// //                 differ, & returns -1 if there are no differences
// // Exs: word1 = magic, word2 = magic, returns -1
// //      word1 = wands, word2 = wants, returns 3
// //      word1 = magic, word2 = wands, returns 0
// //      word1 = magic, word2 = mag, returns 3
// //      word1 = magic, word2 = magicwand, returns 5
// //      word1 = magic, word2 = darkmagic, returns 0
// //-------------------------------------------------------------------
   
   
// }


// void appendWord(char*** pWords, int* pNumWords, int* pMaxWords, char* newWord) {
//---------------------------------------------------------------------
// TODO - Task III: write appendWord() function, which adds a new word
//      to a dynamic heap-allocated array of C-strings; heap-space must  
//      be allocated for the new word inside this function, then copy  
//      the chars from [newWord] to the newly allocated heap-space;
//      if adding a new word pushes *pNumWords greater than *pMaxWords, 
//      then realloate the *pWords array with double the capacity.
//      parameters: 
//          [char*** pWords] - array of C-strings passed-by-pointer
//              note: *pWords is an array of pointers
//                    **pWords is an array of chars
//                    ***pWords is a char  
//                    (*pWords)[0] is the 1st C-string in the array
//                    (*pWords)[1] is the 2nd C-string in the array
//                    (*pWords)[0][0] is 1st char of 1st C-string
//                    (*pWords)[1][2] is 3rd char of 2nd C-string
//                    etc.
//          [int* pNumWords] - current # of words in *pWords array
//               note: *pNumWords will increase by 1 here, 
//                     so it is passed-by-pointer
//          [int* pMaxWords] - current capacity of *pWords array
//               note: *pMaxWords may increase by x2 here, 
//                     so it is passed-by-pointer
//          [char* newWord] - C-string word to be added to *pWords
//               note: [newWord] is a C-string, naturally a pointer
//---------------------------------------------------------------------

}




// int main() {
   //  // Test cases
   //  char word1[] = "magic";
   //  char word2[] = "magic";
   //  printf("Test 1: %s vs %s -> %d (Expected: 0)\n", word1, word2, strCmpCnt(word1, word2));

   //  char word3[] = "wands";
   //  char word4[] = "wants";
   //  printf("Test 2: %s vs %s -> %d (Expected: 1)\n", word3, word4, strCmpCnt(word3, word4));

   //  char word5[] = "magic";
   //  char word6[] = "wands";
   //  printf("Test 3: %s vs %s -> %d (Expected: 4)\n", word5, word6, strCmpCnt(word5, word6));

   //  char word7[] = "magic";
   //  char word8[] = "mag";
   //  printf("Test 4: %s vs %s -> %d (Expected: 2)\n", word7, word8, strCmpCnt(word7, word8));

   //  char word9[] = "magic";
   //  char word10[] = "magicwand";
   //  printf("Test 5: %s vs %s -> %d (Expected: 4)\n", word9, word10, strCmpCnt(word9, word10));

   //  char word11[] = "magic";
   //  char word12[] = "darkmagic";
   //  printf("Test 6: %s vs %s -> %d (Expected: 8)\n", word11, word12, strCmpCnt(word11, word12));

//------------------------------------------------------------------------------------------------------------------

   //  // Test cases
   //  char word1[] = "magic";
   //  char word2[] = "magic";
   //  printf("Test 1: %s vs %s -> %d (Expected: -1)\n", word1, word2, strCmpInd(word1, word2));

   //  char word3[] = "wands";
   //  char word4[] = "wants";
   //  printf("Test 2: %s vs %s -> %d (Expected: 3)\n", word3, word4, strCmpInd(word3, word4));

   //  char word5[] = "magic";
   //  char word6[] = "wands";
   //  printf("Test 3: %s vs %s -> %d (Expected: 0)\n", word5, word6, strCmpInd(word5, word6));

   //  char word7[] = "magic";
   //  char word8[] = "mag";
   //  printf("Test 4: %s vs %s -> %d (Expected: 3)\n", word7, word8, strCmpInd(word7, word8));

   //  char word9[] = "magic";
   //  char word10[] = "magicwand";
   //  printf("Test 5: %s vs %s -> %d (Expected: 5)\n", word9, word10, strCmpInd(word9, word10));

   //  char word11[] = "magic";
   //  char word12[] = "darkmagic";
   //  printf("Test 6: %s vs %s -> %d (Expected: 0)\n", word11, word12, strCmpInd(word11, word12));





//     return 0;
// }


   
   
