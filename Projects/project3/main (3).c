#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int strCmpCnt(char* word1, char* word2) {

    // Use strcmp to check wether which ever string is greater - smaller. Look at files for all details.

    // First word is greater than second word, > 0 
    // First word is less than second word, < 0 
    // First word and second word at equal, == 0  

    

    int  count = 0;
    int w1len = strlen(word1); 
    int w2len = strlen(word2);
    int diff;

    if(w1len > w2len){
        diff = w1len - w2len;
    }

    else if(w2len > w1len){
        diff = w2len - w1len;

    }

    int i = 0;

    if(w1len > w2len){
        while(i < w2len){
            if(word1[i] == word2[i]){
                i++;
            }else{
                count++;
                i++;
            }
        }
        return count += diff;
    }
    
    else if(w2len > w1len){
        while(i < w1len){
            if(word1[i] == word2[i]){
                i++;
            }else{
                count++;
                i++;
            }
        }
        return count += diff;
    }

    else if (w1len == w2len){
      while(i < w1len && w2len){
         if(word1[i] == word2[i]){
            i++;
         }else{
            count++;
            i++;
         }
      }
      return count;
   }   
   
}

int strCmpInd(char* word1, char* word2) {
   int w1len = strlen(word1);
   int w2len = strlen(word2);
   int count = 0;

   while(*word1 != '\0' && *word2 != '\0'){
      if(*word1 == *word2){
         count++;
         word1++;
         word2++;
         
      }else{
         break; 
      }  
      
   }

   if(w1len == count && w2len == count){
      return -1;
   }else{
      return count;
   }   
   
}


void appendWord(char*** pWords, int* pNumWords, int* pMaxWords, char* newWord) {

    

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


int linSearchForWord(char** words, int numWords, char* findWord) { 
//-------------------------------------------------------------------
// TODO - Task V: write the linSearchForWord() function that returns 
//      the index in the [words] C-string array where a match to the 
//      C-string [findWord] is found, using a linear search; 
//      return -99 if [findWord] is NOT found in [words] array;
//      note: [words] is an array of pointers to [numWords] C-strings 
//-------------------------------------------------------------------

    return 0; // modify this
}


bool checkForValidWord(char** words, int numWords, int wordLen, char** ladder, int ladderHeight, char* aWord) {
//-------------------------------------------------------------------
// TODO - Task VI: write the checkForValidWord() function, which checks 
//      if [aWord] is valid for the next word in the word ladder;
//
//      return TRUE for the following cases:
//        - [aWord] is "DONE" beacuse the user wants to stop;
//              this case takes highest precedence;
//              before returning TRUE, first print: 
//                  "Stopping with an incomplete word ladder..."
//        - [aWord] is valid and will be added to the word ladder
//              before returning TRUE, first print: 
//                  "Entered word is valid and will be added to the word ladder."
//
//      return FALSE for the following cases
//      (precedence for invalidity measures follows the order given here):
//        - [aWord] is invalid because it has the wrong word length;
//              before returning FALSE, first print: 
//                  "Entered word does NOT have the correct length. Try again..."
//        - [aWord] is invalid because it is not in the words array,  
//              i.e. not in the dictionary;
//              before returning FALSE, first print: 
//                  "Entered word NOT in dictionary. Try again..."
//        - [aWord] is invalid because it is NOT a single-char 
//              difference from the previous word in the ladder; 
//              e.g. previous word is "code" and [aWord] is "cave";
//              e.g. previous word is "code" and [aWord] is "code";
//              before returning FALSE, first print: 
//                  "Entered word is NOT a one-character change from the previous word. Try again..."
//
//      [words] is an array of [numWords] C-strings that contains all 
//              words in the dictionary of word length [wordLen]
//      [ladder] is an array of [ladderHeight] C-strings that 
//              represents an incomplete word ladder
//      [aWord] is a C-string that must be checked for validity here
//
//  HINT: call linSearchWord(), strCmpCnt(), & string.h function(s)
//-------------------------------------------------------------------

    return false; // modify this
}


bool isLadderComplete(char** ladderWords, int height, char* finalWord) {
//-------------------------------------------------------------------
// TODO - Task VII: write the isLadderComplete() Boolean function, 
//      which should simply check for a completed word ladder, i.e.
//      return true if the final word in [ladderWords] is a match to 
//      [finalWord]; otherwise, return false; the number of words in
//      the word ladder is [height]
//-------------------------------------------------------------------

    return false; // modify this
}


void displayIncompleteLadder(char** ladderWords, int height) {
//-------------------------------------------------------------------
// TODO - Task IX: write the displayIncompleteLadder() function, 
//      which should display the C-strings in the [ladderWords] 
//      array with the first word at the bottom of the ladder, and 
//      each successive C-string one rung higher on the ladder. 
//      The ladder [height] is the number of words it contains.  
//      To signify the ladder as incomplete, display three lines of  
//      "..." at the top of the ladder. The ladder must be displayed 
//      with an indentation of two whitespaces on every line;
//      Ex: if the start word is "data" and final word is "code" and
//          the incomplete ladder is data->date->gate->gave, then the
//          output display should be as follows (where the quotation  
//          marks are NOT a part of the actual display):
//              "  ..."
//              "  ..."
//              "  ..."
//              "  gave"
//              "  gate"
//              "  date"
//              "  data" 
//-------------------------------------------------------------------


}


void displayCompleteLadder(char** ladderWords, int height) {
//-------------------------------------------------------------------
// TODO - Task X: write the displayCompleteLadder() function, 
//      which should display the C-strings in the [ladderWords] array 
//      with the first word at the bottom of the ladder, and each 
//      successive C-string one rung higher on the ladder. 
//      The ladder [height] is the number of words it contains.  
//      In between each ladder rung, display the symbol '^' to 
//      signify the character that changes between the two rungs of 
//      the ladder. The ladder should be displayed with an indentation 
//      of two whitespaces to the left of every word;
//
//      HINT: call strCmpInd() here
//
//      Ex: if the start word is "data" and final word is "code" 
//          then the output display for a complete ladder should be  
//          as follows (where the quotation marks are NOT a part of  
//          the actual display):
//              "  code"
//              "    ^ "
//              "  cove"
//              "   ^  "
//              "  cave"
//              "  ^   "
//              "  gave"
//              "    ^ "
//              "  gate"
//              "  ^   "
//              "  date"
//              "     ^"
//              "  data" 
//-------------------------------------------------------------------

}


int main(int argc, char* argv[]) {

    printf("\nProcessing command-line arguments...\n");

    int wordLen = 0;
    int maxLadder = 1;
    char dict[100] = "notAfile";     
    char startWord[30] = "notAword";
    char finalWord[30] = "notValid"; 

    //-------------------------------------------------------------------
    // TODO - Task XII: handle command-line arguments
    // command-line arguments:
    //  [-n wordLen] = sets word length for word ladder;
    //                 if [wordLen] is not a valid input 
    //                 (cannot be less than 2 or greater than 20),
    //                 or missing from command-line arguments, 
    //                 then let user set it using interactive user input
    // [-m maxLadder] = sets maximum word ladder height;
    //                  [maxLadder] must be at least 2;
    //                  if [maxLadder] is invalid or missing from 
    //                  command-line arguments, then let user set it 
    //                  using interactive user input
    // [-d dictFile] = sets dictionary file;
    //                 if [dictFile] is invalid (file not found) or 
    //                 missing from command-line arguments, then let
    //                 user set it using interactive user input
    // [-s startWord] = sets the starting word;
    //                  if [startWord] is invalid 
    //                  (not in dictionary or incorrect length) or 
    //                  missing from command-line arguments, then let
    //                  user set it using interactive user input
    // [-f finalWord] = sets the final word;
    //                  if [finalWord] is invalid  
    //                  (not in dictionary or incorrect length) or 
    //                  missing from command-line arguments, then let
    //                  user set it using interactive user input
    //-------------------------------------------------------------------


    printf("Interactively (re)setting invalid parameters:\n");

    // set word length using interactive user-input if necessary
    int numInputs = 1;
    while (numInputs > 0 && (wordLen < 2 || wordLen > 20)) {
        printf("Invalid word length = %d\n", wordLen);
        printf("Enter a valid word length (must be 2-20): ");
        numInputs = scanf("%d",&wordLen);
        printf("\n");
    }
    if (numInputs == 0) {
        printf("Invalid input. Cannot set program parameters. Terminating program...\n");
        return 0;
    }


    // set max ladder height using interactive user-input if necessary
    numInputs = 1;
    while (numInputs > 0 && maxLadder < 2) {
        printf("Invalid max ladder height = %d\n", maxLadder);
        printf("Enter a valid max ladder height (must be >1): ");
        numInputs = scanf("%d",&maxLadder);
        printf("\n");
    }
    if (numInputs == 0) {
        printf("Invalid input. Cannot set program parameters. Terminating program...\n");
        return 0;
    }

    // interactive user-input sets the dictionary file;
    //  check that file exists; if not, user enters another file
    FILE* fileTry = fopen(dict,"r");
    numInputs = 1;
    while (numInputs > 0 && fileTry == NULL) {
        printf("Dictionary file %s not found...\n", dict);
        printf("Enter filename for dictionary: ");
        numInputs = scanf("%s", dict);
        printf("\n");
        fileTry = fopen(dict,"r");
    }
    fclose(fileTry);
    if (numInputs == 0) {
        printf("Invalid input. Cannot set program parameters. Terminating program...\n");
        return 0;
    }
    
    // build the [words] array, a heap-allocated array of C-strings
    // where the words are a read-in from the dictionary file
    // and only those words of the desired length [wordLen] 

    int numWords = 0; // initially, no words in the array
    int maxWords = 4; // initially, capacity = 4

    char** words = (char**)malloc(maxWords*sizeof(char*));
    //-------------------------------------------------------------------
    // TODO - Task IV: file-read the word list from the dictionary file 
    //                 [dict], storing only words of length set by 
    //                 [wordLen] in [words], which is a dynamically 
    //                 growing heap-allocated array of C-strings:
    //                      - the word list should be a dynamic array of 
    //                        pointers, initially with capacity (i.e. 
    //                        maximum size) 4; the capacity doubles 
    //                        whenever more space is needed
    //                      - each element of the word list array should 
    //                        point to a heap-allocated C-string that 
    //                        can store a word containing exactly 
    //                        [wordLen] lower-case letters; don't forget
    //                        that there must be a single char at the 
    //                        end of the C-string for the null character
    //
    //                 HINT: open the file; loop to read words from the
    //                 file and check if the word has the correct length;
    //                 if so, add the word to the array using a call to 
    //                 appendWord(); lastly, close the file after all words 
    //                 have been scanned
    //-------------------------------------------------------------------
    

    printf("The dictionary contains %d words of length %d.\n",numWords,wordLen);
    printf("Max size of the dynamic words array is %d.\n",maxWords);
    printf("\n");

    // end program if file does not have at least two words of desired length
    if (numWords < 2) {
        printf("Dictionary %s contains insufficient %d-letter words...\n",dict,wordLen);
        printf("Terminating program...\n");
        return -1;
    }

    // resetting start word using interactive user-input if necessary
    numInputs = 1;
    while (numInputs > 0 && linSearchForWord(words,numWords,startWord) < 0) {
        printf("Start word %s is not valid...\n", startWord);
        printf("Enter a valid start word: ");
        numInputs = scanf("%s", startWord);
        printf("\n");
    }
    if (numInputs == 0) {
        printf("Invalid input. Cannot set program parameters. Terminating program...\n");
        return 0;
    }

    // resetting final word using interactive user-input if necessary
    numInputs = 1;
    while (numInputs > 0 && linSearchForWord(words,numWords,finalWord) < 0 ) {
        printf("Final word %s is not valid...\n", finalWord);
        printf("Enter a valid final word: ");
        numInputs = scanf("%s", finalWord);
        printf("\n");
    }
    if (numInputs == 0) {
        printf("Invalid input. Cannot set program parameters. Terminating program...\n");
        return 0;
    }


    printf("\nWelcome to the CS 211 Word Ladder Builder!\n");
    printf("\n"); 

    printf("Your goal is to make a word ladder between two ");
    printf("%d-letter words: \n  %s -> %s\n\n",wordLen, startWord,finalWord);  
    
    // Allocating the word ladder for the maximum allowed height
    char** ladder = (char**)malloc(maxLadder*sizeof(char*));

    int ladderHeight = 0; // initially, the ladder is empty
    
    // add the start word to the ladder, i.e. the "bottom rung"
    appendWord(&ladder,&ladderHeight,&maxLadder,startWord);
    
    char aWord[30] = "XYZ";
    printf("\n");

    // Let the user build a word ladder interactively & iteratively.
    // First, check that ladder is not too long AND not complete.
    //-------------------------------------------------------------------
    // TODO - Task VIII: modify the while loop condition such that the 
    //          word ladder building process continues only if ALL of  
    //          the following conditions are met:
    //              1. the ladder still has at least one available rung
    //                 before reaching the maximum allowed height
    //              2. the user is NOT attempting to stop the word ladder
    //                 building process, which occurs if the entered word 
    //                 [aWord] from the last iteration is "DONE"
    //              3. the ladder is still incomplete; i.e. the last word
    //                 added to ladder is not the final word; 
    //                 note: this should use a call to isLadderComplete() 
    //-------------------------------------------------------------------
    while ( false ) {   // modify this line 
        printf("The goal is to reach the final word: %s\n",finalWord);
        printf("The ladder is currently: \n");
        displayIncompleteLadder(ladder,ladderHeight);
        printf("Current ladder height: %d\n",ladderHeight);
        printf("Maximum ladder height: %d\n",maxLadder);
        printf("Enter the next word (or DONE to stop): ");
        scanf("%s",aWord);
        printf("\n");

        // Make sure the entered word is valid for the next ladder rung;
        // if not, repeatedly allow user to enter another word until one is valid
        while (!checkForValidWord(words, numWords, wordLen, ladder, ladderHeight, aWord)) {
            printf("Enter another word (or DONE to stop): ");
            scanf("%s",aWord);
            printf("\n");
        }

        // add the entered word to the ladder (unless it is "DONE")
        if (strcmp(aWord,"DONE") != 0) {
            appendWord(&ladder,&ladderHeight,&maxLadder,aWord);
        }
        printf("\n");

    }
    

    // Check if the built word ladder is complete and 
    // display the word ladder appropriately. 
    if (isLadderComplete(ladder, ladderHeight, finalWord)) {
        printf("Word Ladder complete!\n");
        displayCompleteLadder(ladder,ladderHeight);
        printf("Word Ladder height = %d. \n", ladderHeight);
        printf("Can you find a shorter Word Ladder next time??? \n");
    } else {
        if (ladderHeight == maxLadder) printf("The Word Ladder reached the maximum height.\n");
        printf("The final Word Ladder is incomplete:\n");
        displayIncompleteLadder(ladder,ladderHeight);
        printf("Word Ladder height = %d. \n", ladderHeight);
        printf("Can you complete the Word Ladder next time??? \n");
    }
    
    
    //-------------------------------------------------------------------
    // TODO - Task XI: free all heap-allocated memory to avoid potential 
    //                 memory leaks. Since the word length for the word 
    //                 ladder is variable (i.e. set by a command-line 
    //                 argument or interactive user-input) any array
    //                 whose size depends on the word length should be
    //                 dynamically heap-allocated, and thus, must be
    //                 tracked and freed before program termination
    //-------------------------------------------------------------------


    return 0;
}