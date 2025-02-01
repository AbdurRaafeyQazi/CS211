#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*-------------------------------------------
Program 5: Link Lint List
Course: CS 211, Fall 2024, UIC
Author: Abdur Raafey Ahmed Qazi
------------------------------------------- */


typedef struct WordNode_struct {
    char* myWord;
    struct WordNode_struct* next; 
} WordNode;

typedef struct LadderNode_struct {
    WordNode* topWord;
    struct LadderNode_struct* next; 
} LadderNode;


/*
Counts the number of words in a file with exactly wordSize characters
Parameters:
filename - name of the file to read from 
wordSize - length of the words to count
Returns - the number of words with length wordSize if the file is found 
and returns -1 if the file cannot be opened
*/
int countWordsOfLength(char* filename, int wordSize) {

    FILE* fileptr = fopen(filename, "r"); // open the file in read mode
    char word[100]; // Array to hold each word read from the file
    int count = 0; // Counter for the number of words

    if(fileptr == NULL) // Checks if the file could not be opened
    {
        return -1;
    }

    // Read each word from the file and check its length
    while(fscanf(fileptr, "%99s", word) == 1) // Read a word from the file
    {
        if(strlen(word) == wordSize) // Check if the word matches the specified lenght
        {
            count++; // Increments if word len matches
        }
    }
    
    // Close the file after use
    fclose(fileptr);    
    return count;
}


/*
Reads words of length wordSize from a file and stores them in the provided word array
Parameters:
filename - name of the file to read from
words - an array of char pointer to store the words
numWords - the number of words expected to be read 
wordSize - the required length of the words
Returns - True if the file is successfully read and contains the correct number of words, false otherwise
*/
bool buildWordArray(char* filename, char** words, int numWords, int wordSize) { 

    FILE* fileptr = fopen(filename, "r"); // Opens the file for reading
    char line[99]; // Array to store each line/word
    int count = 0; // Counter for the number of words read
    
    // If file opening fails return false
    if(fileptr == NULL)
    {
        return false; // ie false
    }

    // Read each line from the file
    while(fgets(line, sizeof(line), fileptr)) 
    {   
        // Remove the newline character if it exists
        int len = strlen(line);
        if(len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0'; // Replace the newline with null terminator
        }

        // If the word has the correct length, store it in the words array
        if(strlen(line) == wordSize)
        {
            if(count < numWords) // dont exceed the number of words
            {
                strcpy(words[count], line); // Copy the word into the array
            }
            count++;
        }
    }

    fclose(fileptr); // close the file after reading

    // Check if correct number of words were read
    if((count) == numWords)
    {
        return true;
    }else{
        return false;
    }
}


/*
Performs a binary search on the array of words to find aWord between loInd and hiInd
Parameters:
words - array of words to search in 
aWord - the word to search for 
loInd - the lower bound fo the search range
hiInd - the upper bound of the search range
Returns - The index of aWord if found or -1 if not found
*/
int findWord(char** words, char* aWord, int loInd, int hiInd) { 

    // While the search range is valid
    while(hiInd >= loInd)
    {
        int mid = (hiInd + loInd) / 2; // Calculate the middle index
        int cmp = strcmp(words[mid], aWord); // Compare the word at mid with the target word

        if(cmp < 0) // If target word is greater than the curr word
        {
            loInd = mid + 1; // Search upper half
        }
        else if(cmp > 0) // if target word is less than the current word
        {
            hiInd = mid - 1; // Search the lower half
        }else{
            return mid; // Return the index of the word if matches
        }
    }
    return -1; // Return -1 if not found
}


/*
Frees all memeory allocated for an array of words
parameters: 
words - array of words pointers to be freed
numWords - number of words in the array
*/
void freeWords(char** words, int numWords) {

    for(int i = 0; i < numWords; i++) // Loop through each word in the array
    {
        free(words[i]); // Free the memory allocated for each word
    }
    free(words); // Free the array of word pointers
}


/*
Inserts a new word at the front of the word ladder linked list
parameters:
ladder - pointer to the pointer of the ladder head node
newWord - the word to insert at the front of the ladder
*/
void insertWordAtFront(WordNode** ladder, char* newWord) {

    WordNode* newNode = (WordNode*) malloc(sizeof(WordNode)); // Allocate memory for a new node 

    if(newNode == NULL) // Check if memory allocation fails
    {
        return; // If allocation fails, do nothing
    } 

    newNode->myWord = newWord; // Set the word for the new node
    newNode->next = *ladder; // Link the new node to the current ladder
    *ladder = newNode; // Make the new node the new head of the ladder
} 


/*
Returns the number of words in the ladder lined list
parameters:
ladder - head node of the word ladder
Returns - The number of words in the ladder
*/
int getLadderHeight(WordNode* ladder) {

    int count = 0; // Counter for the number of nodes in the ladder
    WordNode* curr = ladder; // Pointer to traverse the ladder

    while(curr != NULL) // Traverse the ladder untill the end
    {   
        // Increment and move to the next node
        count++;
        curr = curr->next;
    }
    return count; // Return the total count of nodes
}


/*
Creates a full copy of the word ladder and returns it
parameters:
ladder - the original ladder to copy
Returns - A new word ladder that is a copy of the original
*/
WordNode* copyLadder(WordNode* ladder) {

    // Return null if the ladder is empty
    if (ladder == NULL) 
    {
        return NULL;
    }

    // Allocate memory for the new ladder
    WordNode* newLadder = (WordNode*)malloc(sizeof(WordNode));
    if (newLadder == NULL) 
    {
        return NULL; // Return null if memory allocation fails
    }

    newLadder->myWord = ladder->myWord; // copy the word of the first node
    newLadder->next = NULL; // The new ladder starts with a single node

    WordNode* currOriginal = ladder->next; // Pointer to traverse the original ladder
    WordNode* currCpy = newLadder; // Pointer to build the copied ladder

    while (currOriginal != NULL) 
    {
        WordNode* newNode = (WordNode*)malloc(sizeof(WordNode)); // Allocate memory for the new node
        if (newNode == NULL) 
        {
            return NULL; // Return null if memory allocation fails
        }

        newNode->myWord = currOriginal->myWord; // Copy the word
        newNode->next = NULL; // New node points to null
        currCpy->next = newNode; // link the new node to the copied ladder
        currCpy = newNode; // move to the next node in the copied ladder
        currOriginal = currOriginal->next; // move to the next node in the original ladder
    }

    return newLadder; // Return the copied ladder    
}


/*
Frees all the memory allocated for a word ladder linked list.
Parameters:
ladder - head node of the word ladder to free
*/
void freeLadder(WordNode* ladder) {

    WordNode* current = ladder; // Pointer to traverse the ladder
    WordNode* nextNode; // Pointer to hold the next node for safe deletion

    while(current != NULL) // Traverse the ladder
    {
        nextNode = current->next; // next node
        free(current); // Free current node
        current = nextNode; // Move to the next node
    }
}


/*
Inserts a new ladder at the back of the ladder list
parameters:
list - pointer to the pointer of the ladder list head node
newLadder - the word ladder to insert at the back of the list
*/
void insertLadderAtBack(LadderNode** list, WordNode* newLadder) {

    LadderNode* newNode = (LadderNode*)malloc(sizeof(LadderNode)); // Allocate memory for the new node
    if (newNode == NULL) 
    {
        return; // Handle memory allocation failure
    }

    newNode->topWord = newLadder;
    newNode->next = NULL;

    if (*list == NULL) 
    {
        *list = newNode; // If the list is empty, make the new node the head
    } 
    else 
    {
        LadderNode* current = *list;
        while (current->next != NULL) 
        {
            current = current->next; // Traverse to the end of the list
        }
        current->next = newNode; // Append the new node at the end
    }
}


/*
Removes and returns the word ladder from the front of the ladder list
parameters:
list - double pointer to the head of the ladder list
Returns - pointer to the head WordNode of the removed ladder, or null if the list is empty
*/
WordNode* popLadderFromFront(LadderNode** list) {

    if (*list == NULL) 
    {
        return NULL; // Return null if the list is empty
    } 

    LadderNode* temp = *list; // Temp to store the head of the node
    WordNode* ladder = temp->topWord; // Get the wordNode from the head

    *list = (*list)->next; // Update the head of the list to the next LadderNode
    free(temp); // Free the memory allocated for the original head node

    return ladder;
}


/*
Frees all the memory allocated for a ladder list and its word ladders. frees each ladderNodeand the associated WordNode ladders
parameters:
myList - pointer to the head of the ladder list
*/
void freeLadderList(LadderNode* myList) {

    while(myList != NULL)
    {
        LadderNode* temp = myList; // Store the current ladderNode

        // Free the wordNode ladder associated with the current ladderNode
        freeLadder(temp->topWord);

        myList = myList->next; // Move to the next ladderNode
        free(temp); // Free the memory allocated for the current ladderNode
    }
}


/*
Finds the shortest word ladder from startWrod to finalWord using a word list. Implements a BFS approach using a list of partial ladders
Ensures that memory is properly freed before exiting
parameters:
words - array of strings representing the dictionary of words
usedWord - array of booleans indicating whether each owrd in 'words' has been used in a ladder
numWords - total number of words in the dictionary
wordSize - length of each word
startWord - the word to start the ladder
finalWord - the word to end the ladder
Returns - Pointer to the head WordNode of the shortest ladder if found, or Null if no ladder exists
*/
WordNode* findShortestWordLadder(char** words, bool* usedWord, int numWords, int wordSize, char* startWord, char* finalWord ) {

    // Creates initial ladder with start word and insert it into ladder list
    WordNode* startLadder = NULL;
    insertWordAtFront(&startLadder, startWord);

    LadderNode* ladderList = NULL;
    insertLadderAtBack(&ladderList, startLadder);

    // Mark startWord as used in the usedWord array
    int startIndex = findWord(words, startWord, 0, numWords - 1);
    if(startIndex >= 0)
    {
        usedWord[startIndex] = true;
    }

    // Process each ladder in the ladder list
    while(ladderList != NULL)
    {   
        // Remove the current ladder from the front of the ladder list
        WordNode* currentLadder = popLadderFromFront(&ladderList);
        char* lastWord = currentLadder->myWord;

        // Check if the last word in the ladder is the final word
        if(strcmp(lastWord, finalWord) == 0)
        {   
            // Free remaining ladders in the list and return the successful ladder 
            freeLadderList(ladderList);
            return currentLadder;
        }
        
        // Check each owrd in the dictionary to see if it is one letter away from lastWord
        for(int i = 0; i < numWords; i++)
        {
            if(!usedWord[i])
            {
                int diff = 0;

                // Count the number of character differences between lastWord and words[i]
                for(int j = 0; j < wordSize; j++)
                {
                    if(lastWord[j] != words[i][j])
                    {
                        diff++;
                    }
                }

                // If words[i] differs by only one character, create a new ladder with this word
                if(diff == 1)
                {
                    WordNode* newLadder = copyLadder(currentLadder); // Copy current ladder
                    insertWordAtFront(&newLadder, words[i]); // Add new word to the ladder
                    insertLadderAtBack(&ladderList, newLadder); // Insert updated ladder into list
                    usedWord[i] = true; // Mark word as used
                }
            }
        }
        freeLadder(currentLadder); // Free the memory allocated for the current ladder
    }
    return NULL; // Return null if no ladder is found
}


// interactive user-input to set a word; 
//  ensures sure the word is in the dictionary word array
void setWord(char** words, int numWords, int wordSize, char* aWord) {
    bool valid = false;
    printf("  Enter a %d-letter word: ", wordSize);
    int count = 0;
    while (!valid) {
        scanf("%s",aWord);
        count++;
        valid = (strlen(aWord) == wordSize);
        if (valid) {
            int wordInd = findWord(words, aWord, 0, numWords-1);
            if (wordInd < 0) {
                valid = false;
                printf("    Entered word %s is not in the dictionary.\n",aWord);
                printf("  Enter a %d-letter word: ", wordSize); 
            }
        } else {
            printf("    Entered word %s is not a valid %d-letter word.\n",aWord,wordSize);
            printf("  Enter a %d-letter word: ", wordSize);
        }
        if (!valid && count >= 5) { //too many tries, picking random word
            printf("\n");
            printf("  Picking a random word for you...\n");
            strcpy(aWord,words[rand()%numWords]);
            printf("  Your word is: %s\n",aWord);
            valid = true;
        }
    }
}

// helpful debugging function to print a single Ladder
void printLadder(WordNode* ladder) {
    WordNode* currNode = ladder;
    while (currNode != NULL) {
        printf("\t\t\t%s\n",currNode->myWord);
        currNode = currNode->next;
    }
}

// helpful debugging function to print the entire list of Ladders
void printList(LadderNode* list) {
    printf("\n");
    printf("Printing the full list of ladders:\n");
    LadderNode* currList = list;
    while (currList != NULL) {
        printf("  Printing a ladder:\n");
        printLadder(currList->topWord);
        currList = currList->next;
    }
    printf("\n");
}


//-----------------------------------------------------
// The primary application is fully provided in main(); 
//  no changes should be made to main()
//-----------------------------------------------------



int main() {
    srand((int)time(0));
    
    printf("\nWelcome to the CS 211 Word Ladder Generator!\n\n");

    // set word length using interactive user-input
    int wordSize;
    printf("Enter the word size for the ladder: ");
    scanf("%d",&wordSize);
    printf("\n");

    printf("This program will make the shortest possible\n"); 
    printf("word ladder between two %d-letter words.\n\n",wordSize);
    
    // interactive user-input sets the dictionary file;
    //  check that file exists; if not, user enters another file
    //  if file exists, count #words of desired length [wordSize]
    char dict[100];
    printf("Enter filename for dictionary: ");
    scanf("%s", dict);
    printf("\n");
    int numWords = countWordsOfLength(dict,wordSize);
    while (numWords < 0) {
        printf("  Dictionary %s not found...\n",dict);
        printf("Enter filename for dictionary: ");
        scanf("%s", dict);
        printf("\n");
        numWords = countWordsOfLength(dict,wordSize);
    }
    
    // allocate heap memory for the word array; only words with desired length
    char** words = (char**)malloc(numWords*sizeof(char*));
    for (int i = 0; i < numWords; ++i) {
        words[i] = (char*)malloc((wordSize+1)*sizeof(char));
    }

    // end program if file does not have at least two words of desired length
    if (numWords < 2) {
        printf("  Dictionary %s contains insufficient %d-letter words...\n",dict,wordSize);
        printf("Terminating program...\n");
        return -1;
    }
    
    // [usedWord] bool array has same size as word array [words];
    //  all elements initialized to [false];
    //  later, usedWord[i] will be set to [true] whenever 
    //      words[i] is added to ANY partial word ladder;
    //      before adding words[i] to another word ladder,
    //      check for previous usage with usedWord[i] 
    bool* usedWord = (bool*)malloc(numWords*sizeof(bool));
    for (int i = 0; i < numWords; ++i) {
        usedWord[i] = false;
    }
    
    // build word array (only words with desired length) from dictionary file
    printf("Building array of %d-letter words... ", wordSize); 
    bool status = buildWordArray(dict,words,numWords,wordSize);
    if (!status) {
        printf("  ERROR in building word array.\n");
        printf("  File not found or incorrect number of %d-letter words.\n",wordSize);
        printf("Terminating program...\n");
        return -1;
    }
    printf("Done!\n"); 

    // set the two ends of the word ladder using interactive user-input
    //  make sure start and final words are in the word array, 
    //  have the correct length (implicit by checking word array), AND
    //  that the two words are not the same
    char startWord[30];
    char finalWord[30];
    printf("Setting the start %d-letter word... \n", wordSize);
    setWord(words, numWords, wordSize, startWord);
    printf("\n");
    printf("Setting the final %d-letter word... \n", wordSize);
    setWord(words, numWords, wordSize, finalWord);
    while (strcmp(finalWord,startWord) == 0) {
        printf("  The final word cannot be the same as the start word (%s).\n",startWord);
        printf("Setting the final %d-letter word... \n", wordSize);
        setWord(words, numWords, wordSize, finalWord);
    }
    printf("\n");

    // run the algorithm to find the shortest word ladder
    WordNode* myLadder = findShortestWordLadder(words, usedWord, numWords, wordSize, startWord, finalWord);

    // display word ladder and its height if one was found
    if (myLadder == NULL) {
        printf("There is no possible word ladder from %s to %s\n",startWord,finalWord);    
    } else {
        printf("Shortest Word Ladder found!\n");
        printLadder(myLadder);
    }
    printf("Word Ladder height = %d\n",getLadderHeight(myLadder));
    
    // free the heap-allocated memory for the shortest ladder
    freeLadder(myLadder);
    // free the heap-allocated memory for the words array
    freeWords(words,numWords);
    free(usedWord);
    
    return 0;
}