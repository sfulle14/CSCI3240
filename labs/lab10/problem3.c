#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   //forking process
   pid_t pid = fork();
   int num;
   int factorial=1;

   /* error occurred */
   if (pid < 0) { 
      perror("Fork failed");
   }

   /*child process*/
   if (pid == 0) { 
      printf("Enter an integer: ");
      scanf("%d", &num);

      for(int i=1; i<=num; i++){
         factorial*=i;
      }

      printf("The factorial of %d is: %d\n", num, factorial);

      exit(0); 
   }

   /* parent process */
   wait(NULL);
   printf("parent process is exiting\n");
   return(0); 
}