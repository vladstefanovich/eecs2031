#include <stdio.h>
#include <ctype.h>

int main(void) {
  /*initiallizing the two words and an alphabet tracker
    to record the amount of times a letter has appeared */
  int alphaFirst[26];
  int alphaSecond[26];
  char first[1024];
  char second[1024];
  int i;
  
  //initiallizing both alphabet trackers to 0
  for (i = 0; i < 26; i++) {
    alphaFirst[i] = 0;
    alphaSecond[i] = 0;
  }
  
  //prompting and reading both words
  printf("Enter first word: ");
  scanf("%s", &first);
  printf("Enter second word: ");
  scanf("%s", &second);
  
  int current, size1, size2;
  
  //getting the size of both words without the null entries of the strings
  for (size1 = 0; first[size1] != '\0'; ++size1);
  for (size2 = 0; second[size2] != '\0'; ++size2);
	 
  //add 1 for every instance of a letter to the alphabet tracker for the first word
  for (i = 0; i < size1; i++) {
    //check if a valid character
    if ( isalpha(first[i]) ) {
      //return the value of the current character; a = 0, z = 25
      current = tolower(first[i]) - 97;
      //add 1 to the current character in the alphabet tracker
      alphaFirst[current]++;
    }
  }

  //same as above for the second word
  for (i = 0; i < size2; i++) {
    if ( isalpha(second[i]) ) {
      current = tolower(second[i]) - 97;
      alphaSecond[current]++;
    }
  }
  
  //checking if both words are equal
  int equality = 1;
  for (i = 0; i < 26; i++) {
    //if after comparing both alphabet trackers and the current position is not equal
    //say no and stop comparing
    if( alphaFirst[i] != alphaSecond[i]) {
      printf("The words are not anagrams.\n");
      equality = 0;
      break;
    }
  }

  //if equal say yes
  if (equality == 1) {
    printf("The words are anagrams.\n");
  }

  return 0;
}
