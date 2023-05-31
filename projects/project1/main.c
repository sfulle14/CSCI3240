#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   //declare variables
   char file[1000]; //this will hold the file name
   char letter;
   int counter=0;
   char dot = '.';
   int line=0;



   //open file in command line
   FILE *inFile = fopen(argv[1], "r");

   //loops throught the file while it reads a char from the file and it has not reached the end of the file 
   while(fscanf(inFile, "%c", &letter) && !feof(inFile)){
      //enters a new line every 16 loops
      if(counter==16){
         line++;
         printf("\n");
         counter=0;
      }
      //if if is the start of a new line print the hex of the line number
      if(counter==0){
         printf("%07x0: ", line);
      }
      if(counter%2==0){
         printf(" ");
      }
      //print out the hex of the value read in
      if(isprint(letter)){
         printf("%x", letter);
         counter++;
      }
      //if the value read in is unprintable print the hex of "."
      else{
         printf("%x", dot);
         counter++;
      }
      
   }

   /*
   //print out the hex of the file.
   for(int i=0; i<sizeof file; i++){
      printf("%2x", file[i]);
   }
   */

   fclose(inFile);
   return 0;
}