#include <stdio.h>
#include <string.h>

#define LIMIT 100

int main() {
   //declare variables
   FILE *filePtr;
   char* filename = "userdata.txt";
   char username[LIMIT];
   char password[LIMIT];
   char fileUsername[LIMIT];
   char filePassword[LIMIT];
   char fileAmount[LIMIT];
   char string[LIMIT*3];
   int trigger = 0;

   //open file
   filePtr = fopen(filename, "r");

   //get user input
   printf("Username: ");
   scanf("%s", username);
   printf("Password: ");
   scanf("%s", password);

   
   while(fgets(string, LIMIT, filePtr) != NULL){
      sscanf(string, "%s %s %s", fileUsername, filePassword, fileAmount);
      if(!strcmp(username, fileUsername) && !strcmp(password, filePassword)){
         printf("The amount is: %s\n", fileAmount);
         trigger = 1;
      }
   }
   if(trigger==0){
      printf("username/password mismatch!!!\n");
   }
   
   
   return 0;
}