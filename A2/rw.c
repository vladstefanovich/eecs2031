#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char area[10][10];
  int row, col, i, x, y, random;
  int dot = 46;
  //intialize the array to have 10 by 10 of .'s
  for (row = 0; row < 10; row++) {
    for (col = 0; col < 10; col++) {
      area[row][col] = dot;
    }
  }
  //set seed for time
  srand(time(0));
  
  //x and y make up the current position of the array
  x = 0;
  y = 0;
  //26 letters in the alphabet so 26 possible steps
  for (i = 0; i < 26; i++) {
    //always start at the top left corner or (0,0)
    if (i == 0) {
      area[x][y] = i + 65;
    } else {
      //checks if the current position is boxed off either by a wall(s) or by another value(s)
      if ((area[x+1][y] != dot || x+1 > 9) && (area[x-1][y] != dot || x-1 < 0) && (area[x][y+1] != dot || y+1 > 9) && (area[x][y-1] != dot || y-1 < 0)) {
	break;
      }
      //an infinite loop if the random number keeps picking a blocked off path if an open one exists
      for (;;) {
	random = rand() %4;
	//0 is up; 1 is right; 2 is down; 3 is left
	//deciding if its safe to travel upwards
	if (random == 0 && y-1 > -1) {
	  if (area[x][y-1] == dot) {
	    //taking current i and adding 65 to reach an ascii value of a capital letter
	    area[x][y-1] = i+65;
	    //since (0,0) is top left and (9,9) is bottom right, increment "downwards" to specify (0,1) (for example)
	    y=y-1;
	    //leave infintie loop
	    break;
	  }
	  //deciding if its safe to travels sideways to the right
	} else if (random == 1 && x+1 < 10) {
	  if (area[x+1][y] == dot) {
	    area[x+1][y] = i+65;
	    //incrementing "to the right" away from the y-axis
	    x=x+1;
	    break;
	  }
	  //deciding if its safe to travel downwards
	} else if (random == 2 && y+1 < 10) {
	  if (area[x][y+1] == dot) {
	    area[x][y+1] = i+65;
	    //increment "upwards" towards the x-axis
	    y=y+1;
	    break;
	  }
	} else {
	  //deciding if its safe to travel to the left
	  if(random == 3 && x-1 > -1) {
	    if (area[x-1][y] == dot) {
	      area[x-1][y] = i+65;
	      //increment "to the left" towards the y-axis
	      x=x-1;
	      break;
	    }
	  }
	}

      }
      
    }
    
  }
  //printing the area after the random walk
  for (row = 0; row < 10; row++) {
    for (col = 0; col < 10; col++) {
      printf("%c ", area[row][col]);
      if(col == 9) {
	printf("\n");
      }
    }
  }

  return 0;
}
