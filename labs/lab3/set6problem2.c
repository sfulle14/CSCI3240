#include <stdio.h>
#include <ctype.h>
#include <string.h>

//define the limit for the string length
#define LIMIT 1000
#define WORDLIMIT 100

int main() {
   //declare variables
   char chrArr[LIMIT];
   char vowelWords[WORDLIMIT];
   char testList[100][WORDLIMIT];
   char tmp[WORDLIMIT]="";
   const char t[2] = " ";
   char *token;
   int wordCount=0;
   int vowelCount=0;

   //get a string of text from user
   printf("Enter text: ");
   fgets(chrArr, LIMIT, stdin);

   //get the first token
   token = strtok(chrArr, t);

   //loop through the tokens
   while(token != NULL){   
      //check if letter after token is a vowel
      if(token[0] =='a' || token[0] =='A' || token[0] =='e' || token[0] =='E' || token[0] =='i' || token[0] =='I' || token[0] =='o' || token[0] =='O' || token[0] =='u' || token[0] =='U'){
         //add word to array of strings
         strcpy(testList[vowelCount], token);
         vowelCount++;
      }
      //increase wordCount
      wordCount++;
      
      //get next token
      token = strtok(NULL, t);
   }

   //print out number of words
   printf("There are %d words.\n", wordCount);

   //converts string to all upper case
   for(int i=0; i<vowelCount; i++){
      for(int j=0; j<strlen(testList[i]); j++){
         testList[i][j] = toupper(testList[i][j]);
      }
   }

   //loop to sort the vowel words in ascending order
   for(int i=0; i<vowelCount-1; i++){
      for(int j=i+1; j<vowelCount-1; j++){
         if((strcmp(testList[i],testList[j]))>0){
            strcpy(tmp,testList[i]);
            strcpy(testList[i], testList[j]);
            strcpy(testList[j], tmp);
         }
      }
   }


   //print out the list of words with vowels in ascending order
   //need to loop over array length minus 1 to exclude null ending character.
   printf("Words starting with a vowel in ascending order:\n");
   for(int i=0; i<vowelCount-1; i++){
      printf("%s\n",testList[i]);
   }

   return 0;
}