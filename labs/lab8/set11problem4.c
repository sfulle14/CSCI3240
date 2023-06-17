#include <stdio.h>

int main(int argc, char* argv[]) {
   FILE* fp;
   char* filename;
   int numStudents;
   int num;
   char c;
   char* str;

   if(argc == 2){
      filename = argv[1];

      fp = open(filename, "r");

      num = fgetc(fp);

      str = (char*)malloc(num * sizeof(char));

      while((c = fgetc(fp)) != EOF){
         
      }
   }
   

   
   return 0;
}