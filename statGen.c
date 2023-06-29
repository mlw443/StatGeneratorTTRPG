// Preprocessor Directives
#include "statGen.h"

// check user defined conditions
bool checkNum(int target, int min, int max){
  if(ABS_MIN > ABS_MAX){
    return false;
  }
  if(min * SIZE > target){
    return false;
  }
  if(max * SIZE < target){
    return false;
  }
  if(min > max){
    return false;
  }
  if(min < ABS_MIN){
    return false;
  }
  if(max > ABS_MAX){
    return false;
  }
  return true;
}

// generate a number between min and max inclusively
int randomNum(int min, int max){
  int num;
  num = (rand() % (max - min + 1)) + min;
  return num;
}

// generate rough random array for preliminary stats
void randomArr(int arr[SIZE][SIZE], int min, int max){
  int i;
  int i2;

  for(i = 0; i < SIZE; i++){
    for(i2 = 0; i2 < SIZE; i2++){
      arr[i][i2] = randomNum(min, max);
    }
  }
}

// used if user misinputs
void empty_stdin(void){
  int var = getchar();

  while(var != '\n' && var != EOF){
    var = getchar();
  }

}

// double checks scanf function
bool getInput(int * value){
  int scanRTN;
  scanRTN = scanf("%d", value);
  if(scanRTN == EOF){
    return true; // will break loop if true
  } else if(scanRTN == 0){
    empty_stdin();
  }
  return false;
}

// get all user input
void userInput(int * min, int * max, int * target){
  do{
    printf("\n\nEnter your minimum stat value (between %d and %d): ", ABS_MIN, ABS_MAX);
    if(getInput(min)){
      break;
    }
    
  }while(*min < ABS_MIN || *min > ABS_MAX);

  do{
    printf("Enter your maximum stat value (between %d and %d): ", (*min), ABS_MAX);
    if(getInput(max)){
      break;
    }
  }while(*max < *min || *max > ABS_MAX);

  do{
    printf("Enter your stat value total (between %d and %d): ", (*min) * SIZE, (*max) * SIZE);
    if(getInput(target)){
      break;
    }
  }while(*target < (*min) * SIZE || *target > (*max) * SIZE);
}

// sees if the target stat generation has been met
bool checkStats(int target, int arr[SIZE][SIZE]){
  for(int i = 0; i < SIZE; i++){
    if(rowSum(i, arr) != target){
      return true;
    }
    if(colSum(i, arr) != target){
      return true;
    }
  }
  if(diagSum(0, 0, arr) != target){
    return true;
  }
  if(diagSum(0, SIZE - 1, arr) != target){
    return true;
  }
  
  return false;
}

// generates the stat array
void generateStats(int min, int max, int target, int arr[SIZE][SIZE]){
  int row;
  int col;
  int curRow;
  int curCol;
  int curDiag;
  int count = 0;

  // starts at a random row and column
  row = randomNum(0, SIZE - 1);
  col = randomNum(0, SIZE - 1);

  // keeps going till stat method is made
  while(checkStats(target, arr)){
    // gets current row, column, and (possibly) diagnol sum for current number
    curRow = rowSum(row, arr);
    curCol = colSum(col, arr);
    curDiag = diagSum(row, col, arr);

    // increments value if all sums are less then what they should be
    if(curRow < target && curCol < target && (curDiag < target || curDiag == 0)){
      if(arr[row][col] < max){
        arr[row][col] += 1;
	count = 0;
      }
    } 
    // decrements values if all sums are greater tahn what they should be
    else if(curRow > target && curCol > target && (curDiag > target || curDiag == 0)){
      if(arr[row][col] > min){
        arr[row][col] -= 1;
	count = 0;
      }
    } 
    // if no change has been made in over a full iteration of the array,
    // the current value will be randomized
    else{
      if(count++ > SIZE * SIZE){
        count = 0;
	arr[row][col] = randomNum(min, max);
      }
    }

    // increment column, and row if need be. Reset back to [0][0] if at the end
    col++;
    if(col == SIZE){
      col = 0;
      row++;
      if(row == SIZE){
        row = 0;
      }
    }
  }
}

// gives the row sum
int rowSum(int row, int arr[SIZE][SIZE]){
  int sum = 0;

  for(int i = 0; i < SIZE; i++){
    sum += arr[row][i];
  }
  return sum;
}

// gives the column sum
int colSum(int col, int arr[SIZE][SIZE]){
  int sum = 0;

  for(int i = 0; i < SIZE; i++){
    sum += arr[i][col];
  }
  return sum;
}

// gives the diagnol sum
int diagSum(int row, int col, int arr[SIZE][SIZE]){
  int sum = 0;

  if(row == col){
    for(int i = 0; i < SIZE; i++){
      sum += arr[i][i];
    }
  } else if(row + col == SIZE - 1){
    for(int i = 0; i < SIZE; i++){
      sum += arr[i][SIZE - 1 - i];
    }
  }
  return sum;
}

// prints out stat array
void printStats(int arr[SIZE][SIZE])
{
  int i;
  int i2;
  char row = 'A';
  
  // print diagnol and column header
  printf("\nΔ  ");
  for(i = 0; i < SIZE; i++){
    printf("  %2d ", i + 1);
  }
  printf("   Ω\n   ");
  
  // print top line  
  for(i = 0; i < SIZE; i++){
    printf("_____");
  }
  printf("_\n");

  // print out body of stats
  for(i = 0; i < SIZE; i++){
    
    // print row letter
    printf("%c  ", row++);
    
    // print and format stat numbers
    for(i2 = 0; i2 < SIZE; i2++){
      printf("|%3d ", arr[i][i2]);
    }
    printf("|");

    // prints out row sum if debug tag is added
    #ifdef DEBUG_SUM
    printf(" %d", rowSum(i, arr));
    #endif
    
    // prints out a line if not at the end
    if(i != SIZE - 1){
      horizontalLine();
    }
  }

  // prints out the bottom line
  printf("\n   ");
  for(i = 0; i < SIZE; i++){
    printf("¯¯¯¯¯");
  }
  printf("¯\n");

  // prints out diagnol and column sum if debug tag is added
  #ifdef DEBUG_SUM
  printf("%-3d", diagSum(0, SIZE - 1, arr));
  for(i = 0; i < SIZE; i++){
    printf(" %3d ", colSum(i, arr));
  }
  printf("  %d\n", diagSum(0, 0, arr));
  #endif

  printf("\n\n");
}

// prints out a horizontal line
void horizontalLine(void){
  printf("\n   ");
  for(int i = 0; i < SIZE; i++){
    printf("=====");
  }
  printf("=\n");
}
