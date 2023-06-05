#include <stdio.h>

#define LIMIT 10

int main(int argc, char *argv[]) {
   //variable definition
   FILE *filePtr;
   char string[LIMIT];
   char* file;
   char c;
   int count=0;


   //open file given in command line
   if(argc == 2){
      file = argv[1];
      filePtr = fopen(file, "r");

      printf("%s\n", file);

      if(filePtr == NULL){
         printf("%s does not exist.\n", argv[1]);
         return 0;
      }

      while((c = fgetc(filePtr)) != EOF){
         if(count == 99){
            printf("%s", string);
            printf("\n");
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