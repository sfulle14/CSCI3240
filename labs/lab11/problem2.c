#include <pthread.h>
#include <stdio.h>

//global variables
pthread_mutex_t mutex;
int counter = 0;
int size1=3;
int size2=3;
int size3=3;
int size4=4;
int C[3][4];
int A[3][3] = {{1,2,8},{1,2,3},{6,8,6}};
int B[3][4] = {{5,6,2,4},{1,8,0,7},{4,5,1,8}};

void *my_thread_function(void *arg)
{
   //get row/column from function  input
   int k = *(int*)arg;

   //matrix multiplication
   for(int i=0; i<size1; i++){
      for(int j=0; j<size4; j++){
         pthread_mutex_lock(&mutex);
         C[i][j] += A[i][k] * B[k][j];
         pthread_mutex_unlock(&mutex);
      }
   }
   return NULL; 
}

int main() {
   //declare variables
   pthread_t my_thread1, my_thread2, my_thread3;

   //row declaration
   int k1 = 0;
   int k2 = 1;
   int k3 = 2;

   //set all elements to 0
   for(int i=0; i<size1; i++){
      for(int j=0; j<size4; j++){
         C[i][j] = 0;
      }
   }

   pthread_mutex_init(&mutex, NULL);

   //create a thread for each set of calculations
   pthread_create(&my_thread1, NULL, my_thread_function, &k1);
   pthread_create(&my_thread2, NULL, my_thread_function, &k2);
   pthread_create(&my_thread3, NULL, my_thread_function, &k3);

   //wiat for each thread to end
   pthread_join(my_thread1, NULL);
   pthread_join(my_thread2, NULL);
   pthread_join(my_thread3, NULL);

   //print out result
   printf("The product of matrices A and B is: \n");
   for(int i=0; i<size1; i++){
      for(int j=0; j<size4; j++){
         printf("%d ",C[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   pthread_mutex_destroy(&mutex);
   return 0;
}