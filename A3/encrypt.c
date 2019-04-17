#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  //converting shift amount to number
  char* s = (char*)argv[2];
  //return ascii of character so need to subtract the value of the number
  int shift = s[0] - 48;
  //declaring the files
  FILE *fr, *fw;
  //read file
  fr = fopen(argv[1], "r");
  //concatenating str for adding .enc after file name
  char *fileToChange = (char*)argv[1];
  char *cat = ".enc";
  char str[80];
  strcpy(str, fileToChange);
  strcat(str, cat);  
  //write file
  fw = fopen(str, "w");
  //getting first chara of read file
  int current = fgetc((FILE *)fr);
  //iterating until eof
  while(current != EOF){
    //check for capital and then shift
    if (current >= 65 && current <= 90) {
      current = current + shift;
      //wrap around
      if (current > 90)
	current = current - 26;
      //convert back to chara
      char toReturn = current;
      //write into write file
      fputc(toReturn, fw);
      //same as above but for lowercase
    } else if (current >= 97 && current <= 122) {
      current = current + shift;
      if (current > 122)
	current = current - 26;
      char toReturn = current;
      fputc(toReturn, fw);
      //leave other charas unchanged
    } else {
      char toReturn = current;
      fputc(toReturn, fw);
    }
    fputc(current, fw);
    //get next chara
    current = fgetc((FILE *)fr);
  }
  //close files
  fclose(fr);
  fclose(fw);
  return 0;
}
