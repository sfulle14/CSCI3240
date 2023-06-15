#include <stdio.h>
#include <string.h>

#define LIMIT 100

int main() {
   FILE *filePtr;
   char* filename = "userdata.txt";
   char username[LIMIT];
   char password[LIMIT];
   char fileUsername[LIMIT];
   char filePassword[LIMIT];
   char fileAmount[LIMIT];
   char* string;

   filePtr = fopen(filename, "r");


   printf("Username: ");
   scanf("%s", username);
   printf("\n");
   printf("Password: ");
   scanf("%s", password);
   printf("\n");
   
   while(fgets(string, LIMIT, filePtr) != NULL){
      sscanf(string, "%s %s %s", fileUsername, filePassword, fileAmount);
      if(strcmp(username, fileUsername) && strcmp(password, filePassword)){
         printf("The amount is: %s\n", fileAmount);
      }
      else{
         printf("username/password mismatch!!!\n");
      }
   }

   
   return 0;
}