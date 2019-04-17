#include <stdio.h>
#include <ctype.h>

int main(void) {
  
  char message[80];
  int i, current;
  int shift;
  
  //reading message and shift amount from user
  printf("Enter a message to be encrypted: ");
  scanf("%[^\n]s", message);
  
  //loop through user inputs until one that is in range in inputted
  for(;;) {
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);
    if(shift > 0 && shift < 26) {
      break;
    } else {
      printf("You have entered an invalid amount.\n");
    }
  }
  
  //encryptor
  for (i = 0; i < 80; i++) {
    //convert char to ascii value
    current = message[i];
    
    //encrypt when letter is a capital
    if(current > 64 && current < 91) {
      current = current + shift;
      
      //if after shift wrap around needed
      if(current > 90) {
	current = current - 26;
      }
      //convert ascii value back to character
      char temp = current;
      message[i] = temp;
      
      // encrypt when the letter is lowercase
    } else if (current > 96 && current < 123) {
      current = current + shift;
      
      //if after shift wrap around needed
      if (current > 122) {
	current = current - 26;
      }
      //convert ascii value back to character
      char temp = current;
      message[i] = temp;
      
      //encrpyt if the character is not a letter
    } else {
      message[i] = message[i];
    }
  }
  
  //new message
  printf("Encrypted message: %s\n", message);
  
  return 0;
}
