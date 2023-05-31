#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   //declare variables
   char letter;
   int counter=0;
   int row=0;
   char line[17];

   //open file in command line
   FILE *inFile = fopen(argv[1], "r+");

   //loops throught the file while it reads a char from the file and it has not reached the end of the file 
   while(fscanf(inFile, "%c", &letter) && !feof(inFile)){
      //enters a new line every 16 loops
      if(counter==16){
         row++;
         printf("  %*s", 2, line);
         printf("\n");
         counter=0;
      }
      //if if is the start of a new line print the hex of the line number
      if(counter==0){
         printf("%07x0: ", row);
      }
      if(counter%2==0){
         printf(" ");
      }
      //print out the hex of the value read in
      if(isprint(letter)){
         printf("%x", letter);
         line[counter] = letter;
         counter++;
      }
      //if the value read in is unprintable print the hex of "."
      else{
         printf("%x", '.');
         line[counter] = '.';
         counter++;
      }
   }
   //sets all the extra spaces to ' '
   for(int i=counter; i<16;i++){
      line[i]=' ';
   }

   //prints out the last line
   printf("  %*s",31, line);

   //closes the file
   fclose(inFile);

   return 0;
}