/**************
 * author: Isaac Shepherd
 * file: main.h
 * holds utilities and constants used in main, holds function prototypes
 **************/

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
