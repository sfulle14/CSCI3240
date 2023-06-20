#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   
   pid_t pid1, pid2;

   //forking process
   (pid1 = fork()) && (pid2 = fork());
   


   /* error occurred */
   if (pid1 < 0 || pid2 < 0) { 
      perror("Fork failed");
   }

   /*child process*/
   if (pid1 == 0) { 
      printf("Child 1 talking.\n");
      exit(0); 
   }
   else if (pid2 == 0) { 
      printf("Child 2 talking.\n");
      exit(0); 
   }

   /* parent process */
   wait(NULL);
   wait(NULL);
   printf("parent process is exiting\n");
   return(0); 
}