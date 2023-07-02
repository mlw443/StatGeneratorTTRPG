// preprocessor directives
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
#include <time.h>
#include "statGen.h"

#ifdef MAIN

int main(){
  // local declarations
  int target;
  int min;
  int max;
  int stats[SIZE][SIZE];

  // user inputs
  userInput(&min, &max, &target);

  // double check conditions
  if(checkNum(target, min, max) == false){
    printf("\nSolution Impossible\n");
    return EXIT_FAILURE;
  }

  // set seed using current time
  srand(time(NULL));

  // generate random array
  randomArr(stats, min, max);
  
  // alter array to match target
  generateStats(min, max, target, stats);

  //print results
  printStats(stats);

  return EXIT_SUCCESS;
}

#endif
