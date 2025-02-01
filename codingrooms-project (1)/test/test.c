#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

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
WordNode* findShortestWordLadder(   char** words, 
                                    bool* usedWord, 
                                    int numWords, 
                                    int wordSize, 
                                    char* startWord, 
                                    char* finalWord ) {


    WordNode* startLadder = NULL;
    insertWordAtFront(&startLadder, startWord);

    LadderNode* ladderList = NULL;
    insertLadderAtBack(&ladderList, startLadder);

    int startIndex = findWord(words, startWord, 0, numWords - 1);
    if(startIndex >= 0)
    {
        usedWord[startIndex] = true;
    }

    while(ladderList != NULL)
    {
        WordNode* currentLadder = popLadderFromFront(&ladderList);
        char* lastWord = currentLadder->myWord;

        if(strcmp(lastWord, finalWord) == 0)
        {
            freeLadderList(ladderList);
            return currentLadder;
        }
        
        for(int i = 0; i < numWords; i++)
        {
            if(!usedWord[i])
            {
                int diff = 0;

                for(int j = 0; j < wordSize; j++)
                {
                    if(lastWord[j] != words[i][j])
                    {
                        diff++;
                    }
                }

                if(diff == 1)
                {
                    WordNode* newLadder = copyLadder(currentLadder);
                    insertWordAtFront(&newLadder, words[i]);
                    insertLadderAtBack(&ladderList, newLadder);
                    usedWord[i] = true;
                }
            }
        }
        freeLadder(currentLadder);
    }
    return NULL;
}


void test_countWordsOfLength() {
    // Create a temporary file to test this function
    FILE* file = fopen("testfile.txt", "w");
    assert(file != NULL);
    fprintf(file, "hello world this is a test hello programming world\n");
    fclose(file);

    // Test: count words of length 5
    int result = countWordsOfLength("testfile.txt", 5);
    assert(result == 4); // "hello", "world", "world", "hello"
    printf("test_countWordsOfLength passed.\n");

    // Clean up
    remove("testfile.txt");
}


void test_insertWordAtFront() {
    WordNode* ladder = NULL;
    insertWordAtFront(&ladder, "hello");
    insertWordAtFront(&ladder, "world");

    // Test: first word should be "world"
    assert(strcmp(ladder->myWord, "world") == 0);
    assert(strcmp(ladder->next->myWord, "hello") == 0);
    printf("test_insertWordAtFront passed.\n");

    freeLadder(ladder); // Free the ladder after test
}

void test_getLadderHeight() {
    WordNode* ladder = NULL;
    insertWordAtFront(&ladder, "hello");
    insertWordAtFront(&ladder, "world");

    int height = getLadderHeight(ladder);
    assert(height == 2); // Ladder has 2 words: "world", "hello"
    printf("test_getLadderHeight passed.\n");

    freeLadder(ladder); // Free the ladder after test
}

void test_copyLadder() {
    WordNode* ladder = NULL;
    insertWordAtFront(&ladder, "hello");
    insertWordAtFront(&ladder, "world");

    WordNode* copiedLadder = copyLadder(ladder);
    assert(strcmp(copiedLadder->myWord, "world") == 0);
    assert(strcmp(copiedLadder->next->myWord, "hello") == 0);
    printf("test_copyLadder passed.\n");

    freeLadder(ladder); // Free the original ladder
    freeLadder(copiedLadder); // Free the copied ladder
}


void test_insertLadderAtBack() {
    LadderNode* list = NULL;
    WordNode* ladder1 = NULL;
    insertWordAtFront(&ladder1, "hello");

    insertLadderAtBack(&list, ladder1);
    assert(strcmp(list->topWord->myWord, "hello") == 0);
    printf("test_insertLadderAtBack passed.\n");

    freeLadderList(list); // Free the ladder list after test
}

void test_popLadderFromFront() {
    LadderNode* list = NULL;
    WordNode* ladder1 = NULL;
    insertWordAtFront(&ladder1, "hello");

    insertLadderAtBack(&list, ladder1);
    WordNode* poppedLadder = popLadderFromFront(&list);

    assert(strcmp(poppedLadder->myWord, "hello") == 0);
    assert(list == NULL); // List should be empty after pop
    freeLadder(poppedLadder); // Free the popped ladder
    printf("test_popLadderFromFront passed.\n");
}

void test_findShortestWordLadder() {
    char* words[] = {"link", "lint", "list"};
    bool usedWords[] = {false, false, false};
    int numWords = 3;
    int wordSize = 4;
    
    // Test the ladder from "link" to "list"
    WordNode* resultLadder = findShortestWordLadder(words, usedWords, numWords, wordSize, "link", "list");
    
    // Verify the ladder: should be "link" -> "lint" -> "list"
    assert(resultLadder != NULL);
    assert(strcmp(resultLadder->myWord, "list") == 0);
    assert(strcmp(resultLadder->next->myWord, "lint") == 0);
    assert(strcmp(resultLadder->next->next->myWord, "link") == 0);
    assert(resultLadder->next->next->next == NULL);
    
    printf("test_findShortestWordLadder passed.\n");

    // Free the result ladder after testing
    freeLadder(resultLadder);
}


int main() {
    test_countWordsOfLength();
    test_insertWordAtFront();
    test_getLadderHeight();
    test_copyLadder();
    test_insertLadderAtBack();
    test_popLadderFromFront();
	test_findShortestWordLadder();

    printf("All tests passed!\n");
    return 0;

}