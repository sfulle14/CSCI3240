#include <stdio.h>
#include <string.h>

#define LIMIT 25

int main(int argc, char *argv[]) {
   //variable definition
   FILE *filePtr;
   char string[LIMIT];
   char* filename;
   char c;
   int count=0;


   //open file given in command line
   if(argc == 2){
      filename = argv[1];

      filePtr = fopen(filename, "r");

      printf("%s\n", filename);

      if(filePtr == NULL){
         printf("%s does not exist.\n", argv[1]);
         return 0;
      }
      while((c = fgetc(filePtr)) != EOF){
         if(count == LIMIT-1){
            printf("%s\n", string);
            memset(string, '\0', strlen(string));
            count = 0;
            string[count] = c;
            count++;
         }
         else{
            string[count] = c;
            count++;
         }
      }
      printf("%s", string);
   }


   
   return 0;
}