/**************
 * author: Isaac Shepherd
 * file: main.cpp
 * testbed for fifo class methods ad functionality. includes only main.h
 **************/

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
    //start time
    srand(time(NULL));
    //create data
    int ids[TEST_CASES];
    char* data[TEST_CASES];
    for (int index = 0; index < TEST_CASES; index++) {
        data[index] = new char[BUFFER_SIZE];
    }
    make_test_cases(ids, data, TEST_CASES);
    display_test_cases(ids, data, TEST_CASES);
    //create fifo
    Fifo myList;//list object to to test
    Data myData;//Data structure to pass into fifo
    string tempChar;//temp variable to pass in push iteration
    int operationNum;//used in for loop switch statement

    cout << endl << "testing methods on empty fifo" << endl;
    if(myList.isEmpty()){
        cout << "fifo list is empty" << endl;
    } else {
        cout << "fifo list is not empty" << endl;
    }

    if(myList.peek(myData)){
        cout << myData.id << " was peeked from the end of fifo list" << endl;
        cout << myData.data << " was peeked from the end of fifo list" << endl;
    } else {
        cout << "can not peek empty fifo list" << endl;
    }

    if(myList.pop()){
        cout << "ending node of list was removed" << endl;
    } else {
        cout << "cannot pop form empty fifo list" << endl;
    }

    for(int index = 0; index < TEST_CASES; index++){
        tempChar = data[index];
        operationNum = (rand() % 4);
        switch(operationNum){
            case 0:
                cout << endl << "Calling push" << endl;
                if(myList.push(ids[index], &tempChar)){
                    cout << "adding number to stack" << endl;
                }
                else{
                    cout << "cannot push, stack is full or data is invalid" << endl;
                }
                break;
            case 1:
                cout << endl << "Calling pop" << endl;
                if(myList.pop()){
                    cout << "removed data struct from fifo list " << endl;
                }
                else{
                    cout << "can not pop from empty fifo list" << endl;
                }
                break;
            case 2:
                cout << endl << "Calling peek" << endl;
                if(myList.peek(myData)){
                    cout << myData.id << " was peeked from top of fifo list" << endl;
                    cout << myData.data << " was peeked from fifo list" << endl;
                }
                else{
                    cout << "can not peek empty fifo list" << endl;
                }
                break;
            case 3:
                cout << endl << "Calling isEmpty" << endl;
                if(myList.isEmpty()){
                    cout << "fifo list is empty" << endl;
                }
                else{
                    cout << "fifo list is not empty" << endl;
                }
                break;
        }
    }
    for(int index = 0; index < TEST_CASES; index++){
        tempChar = data[index];
        operationNum = (rand() % 4);
        switch(operationNum){
            case 0:
                cout << endl << "Calling push" << endl;
                if(myList.push(ids[index], &tempChar)){
                    cout << "adding " << ids[index] << " and " << tempChar << " to fifo list" << endl;
                }
                else{
                    cout << "cannot push, fifo list is full or data is invalid" << endl;
                }
                break;
            case 1:
                cout << endl << "Calling pop" << endl;
                if(myList.pop()){
                    cout << "removed data struct from fifo list " << endl;
                }
                else{
                    cout << "can not pop from empty fifo list" << endl;
                }
                break;
            case 2:
                cout << endl << "Calling peek" << endl;
                if(myList.peek(myData)){
                    cout << myData.id << " was peeked from top of fifo list" << endl;
                    cout << myData.data << " was peeked from fifo list" << endl;
                }
                else{
                    cout << "can not peek empty fifo list" << endl;
                }
                break;
            case 3:
                cout << endl << "Calling isEmpty" << endl;
                if(myList.isEmpty()){
                    cout << "fifo list is empty" << endl;
                }
                else{
                    cout << "fifo list is not empty" << endl;
                }
                break;
        }
    }

    //popping everything out of list
    for(int index = 0; index < TEST_CASES; index++){
        if(myList.pop()){
            cout << "ending node of list was removed" << endl;
        } else {
            cout << "cannot pop form empty fifo list" << endl;
        }
    }
    //checking list
    myList.printList();
    //pushing list to full
    for(int index = 0; index < TEST_CASES; index++){
        tempChar = data[index];
        if(myList.push(ids[index], &tempChar)){
            cout << "adding " << ids[index] << " and " << tempChar << " to fifo list" << endl;
        } else {
            cout << "cannot push, fifo list is full or data is invalid" << endl;
        }
    }
    //pushing one manually
    tempChar = data[0];
    if(myList.push(1000, &tempChar)){
        cout << "adding " << 1000 << " and " << tempChar << " to fifo list" << endl;
    } else {
        cout << "cannot push, fifo list is full or data is invalid" << endl;
    }

    myList.printList();

    if(myList.peek(myData)){
        cout << myData.id << " was peeked from the end of fifo list" << endl;
        cout << myData.data << " was peeked from the end of fifo list" << endl;
    } else {
        cout << "can not peek empty fifo list" << endl;
    }

    if(myList.isEmpty()){
        cout << "fifo list is empty" << endl;
    } else {
        cout << "fifo list is not empty" << endl;
    }

    return 0;
}