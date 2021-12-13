/*
 * File: main.cpp
 * Author: Alex Katrompas
 *
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#include "main.h"

void make_test_cases(int *ids, char **data, int num_cases) {
    for(int index = 0; index < num_cases; index++){
        ids[index] = rand() % MAX_ID + 1;
        for (int index2 = 0; index2 < BUFFER_SIZE - 1; index2++) {
            data[index][index2] = 'a' + index;
        }
        data[index][BUFFER_SIZE - 1] = '\0';
    }
}

void display_test_cases(int *ids, char **data, int num_cases) {
    cout << "Displaying test cases..." << endl;
    for (int index = 0; index < num_cases; index++) {
        cout << ids[index] << ": " << data[index] << endl;
    }
}

int main(){
    //create data
    int ids[TEST_CASES];
    char* data[TEST_CASES];
    for (int index = 0; index < TEST_CASES; index++) {
        data[index] = new char[BUFFER_SIZE];
    }

    make_test_cases(ids, data, TEST_CASES);
    display_test_cases(ids, data, TEST_CASES);
    //create fifo
    Fifo myList;
}