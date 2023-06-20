#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
   //forking process
   pid_t pid = fork();
   char str[100];
   int i=0;


   /* error occurred */
   if (pid < 0) { 
      perror("Fork failed");
   }

   /*child process*/
   if (pid == 0) { 
      //get user input as string
      printf("Enter an string: ");
      fgets(str, sizeof(str), stdin);

      //loop over input and convert
      while(str[i] != '\0'){
         str[i] = toupper(str[i]);
         i++;
      }

      //print out converted input
      printf("%s", str);
      
      exit(0); 
   }

   /* parent process */
   wait(NULL);
   printf("parent process is exiting\n");
   return(0); 
}