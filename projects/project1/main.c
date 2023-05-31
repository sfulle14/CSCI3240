#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   //declare variables
   char file[1000]; //this will hold the file name
   char letter;
   int counter =0;
   char dot = '.';

   printf("Variables created\n");

   //get the file to parce from the user.
   //scanf("%c", &file[1000]);
   //printf("File loaded\n");

   FILE *inFile = fopen(argv[1], "r");
   printf("File opened\n");


   while(fscanf(inFile, "%c", &letter)){
      if(counter==16){
         printf("\n");
         counter=0;
      }
      if(isprint(letter)){
         printf("%x", letter);
         counter++;
      }
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