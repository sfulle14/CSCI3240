#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXARRAY 5

int main(int argc, char *argv[])
{
   //declare variables
   int arr[MAXARRAY];
   int sum=0;

   //forking process
   pid_t pid = fork();
   
   /* error occurred */
   if (pid < 0) { 
      perror("Fork failed");
   }

   /*child process*/
   if (pid == 0) { 
      for(int i=0; i<MAXARRAY; i++){
         printf("Enter integers %d of %d: ", i+1, MAXARRAY);
         scanf("%d", &arr[i]);
      }
      

      for(int i=0; i<MAXARRAY; i++){
         if(arr[i]%2 == 0){
            sum += arr[i];
         }
      }

      printf("The sum of the even numbers is: %d\n", sum);
      
      exit(0); 
   }

   /* parent process */
   wait(NULL);
   printf("parent process is exiting\n");
   return(0); 
}