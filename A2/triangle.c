#include <stdio.h>

int main(void) {
  //i, j, k are all declared for building the triangles with for loops
  int rows, i, j, k;
  
  //prompting user for a row number
  printf("Enter the number of rows in the triangle; keep it within 1 and 20 (inclusive):");
  scanf("%d/n", &rows);
  
  //reading the input; assuming that the input in within the valid range
  printf("Rows: %d\n", rows);
  
  //building the triangle excluding the bottom row
  for (i = 0; i < rows - 1; i++) {
    //printing spaces before the first *
    for (j = 0; j < rows - i - 1; j++) {
      printf(" ");
    }
    //first *
    printf("*");
    //printing spaes before the second * (if it exists)
    for (k = 0; k < 2*i - 1; k++) {
      printf(" ");
    }
    //as long as its not the first row, will print second *
    if (i > 0) {
      printf("*");
    }
    //indent for the next row to start on a seperate line
    printf("\n");
  }
  
  //printing bottom row
  for (i = 0; i < 2*rows - 1; i++) {
    printf("*");
  }

  //indent at the end so that the next line in the terminal doesnt follow the bottom row
  printf("\n");
  return 0;
}
