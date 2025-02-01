#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "MinPopVote.h"

bool test_totalEVs() {
    State aStates[10];
    int res;
    
    aStates[0].electoralVotes = 5;
    aStates[1].electoralVotes = 8;
    aStates[2].electoralVotes = 12;
    aStates[3].electoralVotes = 6;
    aStates[4].electoralVotes = 7;
    aStates[5].electoralVotes = 10;

    printf(" Checking totalEVs() for 5 States:\n");
    res = totalEVs(aStates,5);
    if (res != 38) {
        printf("  individual state EVs are 5, 8, 12, 6, 7\n");
        printf("  expected total EVs = 38, actual total EVs = %d\n",res);
        return false;
    }
    printf(" Checking totalEVs() for 6 States:\n");
    res = totalEVs(aStates,6);
    if (res != 48) {
        printf("  individual state EVs are 5, 8, 12, 6, 7, 10\n");
        printf("  expected total EVs = 48, actual total EVs = %d\n",res);
        return false;
    }

    printf(" Checking totalEVs() for states with 0 EVs:\n");
    for(int i = 0; i < 6; i++){
        aStates[i].electoralVotes = 0;
    }
    res = totalEVs(aStates,6);
    if (res != 0) {
        printf("  expected total EVs = 0, actual total EVs = %d\n",res);
        return false;
    }

    printf(" Checking totalEVs() for 0 States:\n");
    res = totalEVs(aStates,0);
    if (res != 0) {
        printf("  expected total EVs = 0, actual total EVs = %d\n",res);
        return false;
    }

    printf(" Checking totalEVs() for states with negative EVs:\n");
    aStates[0].electoralVotes = -5;
    aStates[1].electoralVotes = -8;
    res = totalEVs(aStates,2);
    if (res != -13) {
        printf("  individual state EVs are -5, -8\n");
        printf("  expected total EVs = -13, actual total EVs = %d\n",res);
        return false;
    }
    
    printf(" Checking totalEVs() for 10 States:\n");
    for(int i = 0; i < 10; i++){
        aStates[i].electoralVotes = 1;
    }
    res = totalEVs(aStates,10);
    if (res != 10) {
        printf("  expected total EVs = 10, actual total EVs = %d\n",res);
        return false;
    }



    

    //--------------------------------------------------------   
    // TODO: Task 1 - perform additional testing to make this 
    //                test case for totalEVs() more robust
    //--------------------------------------------------------   
    
    return true;
}

bool test_totalPVs() {

    State aStates[10];
    int res;
    
    aStates[0].popularVotes = 50;
    aStates[1].popularVotes = 80;
    aStates[2].popularVotes = 120;
    aStates[3].popularVotes = 60;
    aStates[4].popularVotes = 70;
    aStates[5].popularVotes = 100;

    printf(" Checking totalPVs() for 5 States:\n");
    res = totalPVs(aStates,5);
    if (res != 380) {
        printf("  individual state PVs are 50, 80, 120, 60, 70\n");
        printf("  expected total PVs = 380, actual total PVs = %d\n", res);
        return false;
    }
    printf(" Checking totalPVs() for 6 States:\n");
    res = totalPVs(aStates,6);
    if (res != 480) {
        printf("  individual state PVs are 50, 80, 120, 60, 70, 100\n");
        printf("  expected total PVs = 480, actual total PVs = %d\n", res);
        return false;
    }

    printf(" Checking totalPVs() for states with 0 PVs:\n");
    for(int i = 0; i < 6; i++){
        aStates[i].popularVotes = 0;
    }
    res = totalPVs(aStates,6);
    if (res != 0) {
        printf("  expected total PVs = 0, actual total PVs = %d\n", res);
        return false;
    }

    printf(" Checking totalPVs() for 0 States:\n");
    res = totalPVs(aStates,0);
    if (res != 0) {
        printf("  expected total PVs = 0, actual total PVs = %d\n", res);
        return false;
    }

    printf(" Checking totalPVs() for states with negative PVs:\n");
    aStates[0].popularVotes = -50;
    aStates[1].popularVotes = -80;
    res = totalPVs(aStates,2);
    if (res != -130) {
        printf("  individual state PVs are -50, -80\n");
        printf("  expected total PVs = -130, actual total PVs = %d\n", res);
        return false;
    }

    printf(" Checking totalPVs() for 10 States:\n");
    for(int i = 0; i < 10; i++){
        aStates[i].popularVotes = 15;
    }
    res = totalPVs(aStates,10);
    if (res != 150) {
        printf("  expected total PVs = 150, actual total PVs = %d\n", res);
        return false;
    }



    //--------------------------------------------------------   
    // TODO: Task 1 - write your own test case for totalPVs();
    //                use test_totalEVs() as a sample;
    //                make sure to test all components
    //--------------------------------------------------------
    return true; 
}

bool test_setSettings() {

    int year;
    bool fastMode, quietMode;

    char* args1[] = {"program", "-y", "2000"};
    if (!setSettings(3, args1, &year, &fastMode, &quietMode) || year != 2000 || fastMode || quietMode) {
        printf("Test case 1 failed\n");
        return false;
    }

    char* args2[] = {"program", "-f", "-y", "2004", "-q"};
    if (!setSettings(5, args2, &year, &fastMode, &quietMode) || year != 2004 || !fastMode || !quietMode) {
        printf("Test case 2 failed\n");
        return false;
    }

    char* args3[] = {"program", "-y", "1999"};
    if (setSettings(3, args3, &year, &fastMode, &quietMode) || year != 0) {
        printf("Test case 3 failed\n");
        return false;
    }

    char* args4[] = {"program", "-q", "-f"};
    if (!setSettings(3, args4, &year, &fastMode, &quietMode) || year != 0 || !fastMode || !quietMode) {
        printf("Test case 4 failed\n");
        return false;
    }

    char* args5[] = {"program", "-y", "2024"}; // Invalid year
    if (setSettings(3, args5, &year, &fastMode, &quietMode) || year != 0) {
        printf("Test case 5 failed\n");
        return false;
    }

    char* args6[] = {"program", "-y", "abc"}; // Invalid format
    if (setSettings(3, args6, &year, &fastMode, &quietMode) || year != 0) {
        printf("Test case 6 failed\n");
        return false;
}

    return true;

    //-----------------------------------------------------------   
    // TODO: Task 2 - write your own test case for setSettings();
    //                use test_totalEVs() as a sample;
    //                make sure to test all components
    //-----------------------------------------------------------
    
}

bool test_inFilename() {
    char filename[100];
    inFilename(filename, 2000);
    if (strcmp(filename, "data/2000.csv") != 0) {
        printf("  Expected filename 'data/2000.csv', got '%s'\n", filename);
        return false;
    }

    inFilename(filename, 1828);
    if (strcmp(filename, "data/1828.csv") != 0) {
        printf("  Expected filename 'data/1828.csv', got '%s'\n", filename);
        return false;
    }

    inFilename(filename, 2020);
    if (strcmp(filename, "data/2020.csv") != 0) {
        printf("  Expected filename 'data/2020.csv', got '%s'\n", filename);
        return false;
    }

    return true;
}

bool test_outFilename() {
    char filename[100];
    outFilename(filename, 2000);
    if (strcmp(filename, "toWin/2000_win.csv") != 0) {
        printf("  Expected filename 'toWin/2000_win.csv', got '%s'\n", filename);
        return false;
    }

    outFilename(filename, 1828);
    if (strcmp(filename, "toWin/1828_win.csv") != 0) {
        printf("  Expected filename 'toWin/1828_win.csv', got '%s'\n", filename);
        return false;
    }

    outFilename(filename, 2020);
    if (strcmp(filename, "toWin/2020_win.csv") != 0) {
        printf("  Expected filename 'toWin/2020_win.csv', got '%s'\n", filename);
        return false;
    }

    return true;
}

bool test_parseLine() {
    State myState;
    char line[999];

    strcpy(line, "California,CA,55,10000\n");
    if (!parseLine(line, &myState)) {
        printf("  Failed to parse valid line\n");
        return false;
    }
    if (strcmp(myState.name, "California") != 0 || 
        strcmp(myState.postalCode, "CA") != 0 || 
        myState.electoralVotes != 55 || 
        myState.popularVotes != 10000) {
        printf("  Parsed values do not match expected\n");
        return false;
    }

    strcpy(line, "Texas,TX,38,8000\n");
    if (!parseLine(line, &myState)) {
        printf("  Failed to parse valid line\n");
        return false;
    }

    strcpy(line, "InvalidLine");
    if (parseLine(line, &myState)) {
        printf("  Parsed invalid line as valid\n");
        return false;
    }

    strcpy(line, "Florida,FL,29,5000,extra\n");
    if (parseLine(line, &myState)) {
        printf("  Parsed line with too many fields as valid\n");
        return false;
    }

    strcpy(line, "New York,NY,29,0\n");
    if (!parseLine(line, &myState)) {
        printf("  Failed to parse valid line with zero popular votes\n");
        return false;
    }

    return true;
}

bool test_readElectionData() {
    State allStates[10];
    int nStates;

    // Create a temporary file
    FILE *file = fopen("test_data.csv", "w");
    fprintf(file, "California,CA,55,10000\n");
    fprintf(file, "Texas,TX,38,8000\n");
    fclose(file);

    if (!readElectionData("test_data.csv", allStates, &nStates) || nStates != 2) {
        printf("  Failed to read valid data\n");
        return false;
    }

    if (strcmp(allStates[0].name, "California") != 0 || 
        allStates[0].electoralVotes != 55 || 
        allStates[0].popularVotes != 10000) {
        printf("  First state data does not match expected\n");
        return false;
    }

    if (strcmp(allStates[1].name, "Texas") != 0 || 
        allStates[1].electoralVotes != 38 || 
        allStates[1].popularVotes != 8000) {
        printf("  Second state data does not match expected\n");
        return false;
    }

    // Clean up
    remove("test_data.csv");
    return true;
}

bool test_minPVsSlow() {
    State states[3] = {
        {"State1", "S1", 10, 100},
        {"State2", "S2", 15, 150},
        {"State3", "S3", 20, 200}
    };
    
    MinInfo result = minPopVoteAtLeast(states, 3, 0, 15);
    
    if (!result.sufficientEVs || result.subsetPVs != 101 || result.szSomeStates != 1) {
        printf("  Incorrect result for minPopVoteAtLeast\n");
        return false;
    }

    return true;
}

bool test_minPVsFast() {
    State states[3] = {
        {"State1", "S1", 10, 100},
        {"State2", "S2", 15, 150},
        {"State3", "S3", 20, 200}
    };
    
    MinInfo result = minPopVoteToWin(states, 3);
    
    if (!result.sufficientEVs || result.subsetPVs != 101 || result.szSomeStates != 1) {
        printf("  Incorrect result for minPopVoteToWin\n");
        return false;
    }

    return true;
}

int main() {
    printf("Welcome to the Popular Vote Minimizer Testing Suite!\n\n");
    
    printf("Testing totalEVs()...\n"); 
    if (test_totalEVs()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    printf("Testing totalPVs()...\n"); 
    if (test_totalPVs()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    printf("Testing setSettings()...\n"); 
    if (test_setSettings()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }
    
    printf("Testing inFilename()...\n"); 
    if (test_inFilename()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    printf("Testing outFilename()...\n"); 
    if (test_outFilename()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    printf("Testing parseLine()...\n"); 
    if (test_parseLine()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    printf("Testing readElectionData()...\n"); 
    if (test_readElectionData()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }
    
    printf("Testing minPopVoteToWin()...\n"); 
    if (test_minPVsSlow()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    printf("Testing minPopVoteToWinFast()...\n"); 
    if (test_minPVsFast()) {
        printf("  All tests PASSED!\n");
    } else {
        printf("  test FAILED.\n");
    }

    return 0;
}
