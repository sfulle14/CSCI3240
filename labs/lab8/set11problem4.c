#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   FILE* fp;
   char* filename;
   int numStudents;
   int num;
   char c;
   float* str;
   int count = 0;
   float tmp;

   if(argc == 2){
      filename = argv[1];

      //open file
      fp = fopen(filename, "r");

      //get first line of file
      c = fgetc(fp);
      num = atoi(&c);

      //dynamically allocate space based on first line of file
      str = (float*)malloc(num * sizeof(float));

      //read in scores into array
      while(fscanf(fp,"%f", &tmp) != EOF){
         str[count] = tmp;
         count++;
      }

      //sort list of scores
      for(int i=0; i<num; i++){
         for(int j=i; j<num; j++){
            if(str[i]>str[j]){
               tmp=str[i];
               str[i] = str[j];
               str[j] = tmp;
            }
         }
      }

      //print out sorted list of scores
      for(int i=0; i<num; i++){
         printf("%f, ", str[i]);
      }
      
   }
   
   //close file
   fclose(fp);
   return 0;
}