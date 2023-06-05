#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 1000

int main() {
   FILE *filePtr;
   char fileName[MAX_INPUT];
   char userInput[2];
   char userString[MAX_INPUT] = "";
   bool indicator = true;
   char token[2] = ",";

   //get file name from user
   printf("Enter file name: ");
   fgets(fileName, MAX_INPUT, stdin);
   
   //open file
   filePtr = fopen(fileName, "w");

   //get characters from user
   //printf("Enter a character: ");
   while(indicator){
      printf("Enter a character: ");
      scanf("%c", &userInput[0]);
      if(userInput[0] == token[0]){
         indicator = false;
      }
      strcat(userString, &userInput[0]);
      //printf("Enter a character: ");
   }
   
   //print out to file
   fprintf(filePtr, "%s", userString);

   //close file
   fclose(filePtr);
   return 0;
}