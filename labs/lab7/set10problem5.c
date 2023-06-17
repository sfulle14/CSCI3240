#include <stdio.h>
#include <string.h>

int main() {
   char str[] = "Hello world";
   char* cptr;
   int vowels=0;
   int consonants = 0;

   int len = strlen(str);

   for(int i=0; i<len; i++){
      cptr=&str[i];
      if(*(cptr)=='a' || *(cptr)=='A' || *(cptr)=='e' || *(cptr)=='E' || *(cptr)=='i' || *(cptr)=='I' || *(cptr)=='o' || *(cptr)=='O' || *(cptr)=='u' || *(cptr)=='U'){
         vowels++;
      }
      else if(*cptr != ' ' && *cptr != ',' && *cptr != '.'){
         consonants++;
      }
   }

   printf("Vowels: %d\n", vowels);
   printf("Consonants: %d\n", consonants);

   
   return 0;
}
