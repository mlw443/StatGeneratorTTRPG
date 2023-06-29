#ifndef HEADER
#define HEADER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// must be positive and it is not recommended increasing SIZE past 26
#define SIZE 6 // number of stats in array

// program will not work if ABS_MAX or ABS_MIN is set above 999 or below -999
#define ABS_MAX 18 // absolute possible maximum
#define ABS_MIN 1 // absolute possible minimum


// function declarations
bool checkNum(int target, int min, int max);
int randomNum(int min, int max);
void randomArr(int arr[SIZE][SIZE], int min, int max);
void userInput(int * min, int * max, int * target);
void generateStats(int min, int max, int target, int arr[SIZE][SIZE]);
int rowSum(int row, int arr[SIZE][SIZE]);
int colSum(int col, int arr[SIZE][SIZE]);
int diagSum(int row, int col, int arr[SIZE][SIZE]);
void printStats(int arr[SIZE][SIZE]);
void empty_stdin(void);
bool getInput(int * value);
bool checkStats(int target, int arr[SIZE][SIZE]);
void horizontalLine(void);

#endif
