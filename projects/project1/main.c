#include <stdio.h>

int main() {
   //declare variables
   char file[1000]; //this is an array of char since there is no string in C.
   char letter;

   //get the file to parce from the user.
   scanf("%c", &file[1000]);

   FILE *in_file = fopen(file, "r");

   while(fscanf(in_file, "%c", &letter)){
      printf("%2x", letter);
   }

   /*
   //print out the hex of the file.
   for(int i=0; i<sizeof file; i++){
      printf("%2x", file[i]);
   }
   */

   fclose(in_file);
   return 0;
}