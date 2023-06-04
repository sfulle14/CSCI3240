#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LIMIT 1000

int main() {
   char chrArr[LIMIT];
   int vowel=0;
   int consonant=0;
   int whiteSpace=0;
   int digit=0;
   int specialChar=0;
   
   printf("Enter a line of text: ");
   fgets(chrArr, LIMIT, stdin);

   for(int i=0; i<strlen(chrArr); i++){
      if(isalpha(chrArr[i])){
         if(chrArr[i]=='a' || chrArr[i]=='A' || chrArr[i]=='e' || chrArr[i]=='E' || chrArr[i]=='i' || chrArr[i]=='I' || chrArr[i]=='o' || chrArr[i]=='O' || chrArr[i]=='u' || chrArr[i]=='U'){
            vowel++;
         }
         else{
            consonant++;
         }
      }
      else if(isdigit(chrArr[i])){
         digit++;
      }
      else if(isspace(chrArr[i])){
         whiteSpace++;
      }
      else if(ispunct(chrArr[i])){
         specialChar++;
      }
   }

   printf("Vowels: %d\n", vowel);
   printf("Consonant: %d\n", consonant);
   printf("Digit: %d\n", digit);
   printf("White Space: %d\n", whiteSpace);
   printf("Special characters: %d\n", specialChar);

   return 0;
}