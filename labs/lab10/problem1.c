#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   //forking process
   pid_t pid = fork();

   /* error occurred */
   if (pid < 0) { 
      perror("Fork failed");
   }

   /*child process*/
   if (pid == 0) { 
      printf("Hello World\n");
      exit(0); 
   }

   /* parent process */
   printf("I am the parent waiting for the child process to end\n");
   wait(NULL);
   printf("parent process is exiting\n");
   return(0); 
}