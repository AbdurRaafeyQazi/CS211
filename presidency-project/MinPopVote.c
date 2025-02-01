#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "MinPopVote.h"

int totalEVs(State* states, int szStates) {
    int electoral_Votes = 0;

    for(int i = 0; i < szStates; ++i)
    {   
        // State struct at the ith position, access it then get its value 
        electoral_Votes += states[i].electoralVotes;
    }      

    return electoral_Votes;
}

int totalPVs(State* states, int szStates) {

    int popular_Votes = 0;
    
    for(int i = 0; i < szStates; ++i)
    {   
        // State struct at the ith position, access it then get its value.
        popular_Votes += states[i].popularVotes;

    }
    return popular_Votes;
}

bool setSettings(int argc, char** argv, int* year, bool* fastMode, bool* quietMode) {
    // There is going to be the argument count 
    // There is going to be the actual argument, in which you enter the specific inputs
    // It takes in a pointer value to year, fastmode, and quitemode
    // -f for fast mode, cannot have -y after it, and if nothing then set to false
    // -q for quiet mode, cannot have -q after it and if nothing then set to false
    // -y 1999, default is 0 meaning false exit, if year is invalid then set it to 0, and only if years had election
    // also for -y if there is nothing inputted after the -y but -f or -q then dont count them and just ignore but set to default 0
    // only return true if all args are valid and false if even a single one is invalid
    // 
    // 

    // Initialize to default values 
    *year = 0; 
    *quietMode = false; 
    *fastMode = false; 

    // Create a function in order to minimize clutter. Which checks if the year entered had presidential elections.
    bool validYear(int y)
    {
        return (y % 4 == 0 && y >= 1828 && y <= 2020);
    }

    for(int i = 1; i < argc; ++i)
    {
        if(strcmp(argv[i], "-y") == 0) // Compare to check if the user input is -y and also if the input after is a year.
        {
            if(i + 1 < argc) // Checks to see if there is a year number after "-y"
            {
                int tempYear = atoi(argv[i + 1]); // Since Command line arguments are passed in as strings, you will need to convert any string-numbers to strings.
                if(validYear(tempYear)) // calls helper function to check if the year entered is valid.
                {
                    *year = tempYear; // if so then update the value
                }else{
                    *year = 0; // else set the value to 0
                }
                i++; // After checking for -y and year, increment to the next argument
            }else{
                return false;
            }
        }

        else if(strcmp(argv[i], "-f") == 0) // Checks if the argument is -f
        {
            if(i > 0 && strcmp(argv[i - 1], "-y") != 0) // Make sure that you are in a position that is not the 0th place, and if there is a -f after -y
            {
                *fastMode = true; // If the conditional fails then the code executes to set fast mode to true.
            }
        }

        else if(strcmp(argv[i], "-q") == 0) // Checks if the argument is -q
        {
            if(i > 0 && strcmp(argv[i - 1], "-y") != 0) // Make sure that you are in a position that is not the 0th place, then does the same thing of checking if there is a -f after -y
            {
                *quietMode = true; // If the conditional fails then the code executes to set quiet mode to true.
            }
            
        }else{
            return false; // Returns false if none of the rules apply
        }
    }
    return true; // And returns true if user input was successful
}

void inFilename(char* filename, int year) {

    // store the value in filename, printing out, and the value to print
    sprintf(filename, "data/%d.csv", year); 

}

void outFilename(char* filename, int year) {
     // store the value in filename, printing out, and the value to print
    sprintf(filename, "toWin/%d_win.csv", year);
    
}

bool parseLine(char* line, State* myState) {
    
    int length = strlen(line);
    if(length > 0 && line[length - 1] == '\n')
    {
        line[length - 1] = '\0'; // if There is a new line character at the end, Then replace it with a null character.
    }

    // Split the words by commas
    char* word = strtok(line, ",");
    int count = 0;

    // Temp variables to hold parsed values 
    char stateName[100];
    char postalCode[3];
    int electoralVotes = 0;
    int popularVotes = 0;

    // Start parsing in the 4 parts.
    while(word != NULL)
    {
        if(count == 0)
        {
            strcpy(stateName, word); // Sets the first word to state name
        }

        else if(count == 1)
        {
            strcpy(postalCode, word);
        }

        else if(count == 2)
        {
            // Since third word has integers we need it in int form 
            electoralVotes = atoi(word);
        }

        else if(count == 3)
        {
            popularVotes = atoi(word);
        }else{
            return false;
        }
        word = strtok(NULL, ",");
        count++;
    }

    if(count != 4)
    {
        return false;
    }

    // Set the value to the state struct 
    strcpy(myState->name, stateName);
    strcpy(myState->postalCode, postalCode);
    myState->electoralVotes = electoralVotes;
    myState->popularVotes = popularVotes;

    return true;


}

bool readElectionData(char* filename, State* allStates, int* nStates) {
    
    FILE* file = fopen(filename, "r"); // open the file in read mode

    if(file == NULL)
    {
        return false; // error handling if file cannot be opened.
    }

    *nStates = 0; // Initializes the number of states to 0

    char line[999]; // Buffer to hold each line

    while(fgets(line, sizeof(line), file)) // reads each of the lines
    {
        if(parseLine(line, &allStates[*nStates])) // Attempt to parse the line using parseLine()
        {
            (*nStates)++; // Increment the state coutn if the line was valid
        }else{
            continue; // Skip the line if it is not valid
        }
    }

    fclose(file); // close the file

    return true; // return to indicate success


}


MinInfo minPopVoteAtLeast(State* states, int szStates, int start, int EVs) {

MinInfo result;
result.subsetPVs = 0;
result.szSomeStates = 0;

if(start == szStates)
{
    
    result.sufficientEVs = EVs <= 0;
    return result; 
}

if(EVs <= 0)
{
    
    result.sufficientEVs = true;
    return result;
}

MinInfo exclude = minPopVoteAtLeast(states, szStates, start + 1, EVs);

MinInfo include = minPopVoteAtLeast(states, szStates, start + 1, EVs - states[start].electoralVotes);

if (include.sufficientEVs) 
{
    include.subsetPVs += states[start].popularVotes / 2 + 1;
    include.someStates[include.szSomeStates] = states[start];
    include.szSomeStates++;
}

if(include.sufficientEVs && (!exclude.sufficientEVs || include.subsetPVs < exclude.subsetPVs))
{
    return include;
}else{
    return exclude;
}
}

// Wrapper function
MinInfo minPopVoteToWin(State* states, int szStates) {
    int totEVs = totalEVs(states,szStates);
    int reqEVs = totEVs/2 + 1; // required EVs to win election
    return minPopVoteAtLeast(states, szStates, 0, reqEVs);
}

MinInfo minPopVoteAtLeastFast(State* states, int szStates, int start, int EVs, MinInfo** memo) {
    
    MinInfo result;
    result.subsetPVs = 0;
    result.szSomeStates = 0;

    if (start == szStates) {
        result.sufficientEVs = EVs <= 0;
        return result;
    }

    if (EVs <= 0) {
        result.sufficientEVs = true;
        return result;
    }

    if(memo[start][EVs].subsetPVs != -1)
    {
        return memo[start][EVs];
    }

    MinInfo exclude = minPopVoteAtLeastFast(states, szStates, start + 1, EVs, memo);
    MinInfo include = minPopVoteAtLeastFast(states, szStates, start + 1, EVs - states[start].electoralVotes, memo);

    if (include.sufficientEVs) {
        include.subsetPVs += states[start].popularVotes / 2 + 1;
        include.someStates[include.szSomeStates] = states[start];
        include.szSomeStates++;
    }

    if (include.sufficientEVs && (!exclude.sufficientEVs || include.subsetPVs < exclude.subsetPVs)) {
        result = include;
    } else {
        result = exclude;
    }

    memo[start][EVs] = result;
    return result;



}



MinInfo minPopVoteToWinFast(State* states, int szStates) {
    int totEVs = totalEVs(states,szStates);
    int reqEVs = totEVs/2 + 1; // required EVs to win election

    MinInfo** memo = (MinInfo**)malloc((szStates+1)*sizeof(MinInfo*));
    for (int i = 0; i < szStates+1; ++i) {
        memo[i] = (MinInfo*)malloc((reqEVs+1)*sizeof(MinInfo));
        for (int j = 0; j < reqEVs+1; ++j) {
            memo[i][j].subsetPVs = -1;
        }
    }
    MinInfo res = minPopVoteAtLeastFast(states, szStates, 0, reqEVs, memo);
    
    for(int i = 0; i < szStates + 1; ++i)
    {
        free(memo[i]);
    }
    free(memo);

    return res;
}

bool writeSubsetData(char* filenameW, int totEVs, int totPVs, int wonEVs, MinInfo toWin) {

    FILE* file = fopen(filenameW, "w");
    if (!file)
    {
        return false;
    }

    fprintf(file, "%d,%d,%d,%d\n", totEVs, totPVs, wonEVs, toWin.subsetPVs);

    for(int i = toWin.szSomeStates - 1; i >= 0; i--)
    {
        fprintf(file, "%s,%s,%d,%d\n", toWin.someStates[i].name, toWin.someStates[i].postalCode, toWin.someStates[i].electoralVotes, toWin.someStates[i].popularVotes / 2 + 1);
    }

    fclose(file);
    return true;


    
}
