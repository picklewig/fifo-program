/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file as needed for your main.cpp but do not
 * change the size of the test cases.
 */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand */
#include "fifo.h"

#define MAX_ID 100
#define TEST_CASES 20
#define BUFFER_SIZE 10

using std::cout;
using std::endl;

void make_test_cases(int*, char**, int);
void display_test_cases(int*, char**, int);

#endif /* MAIN_H */
