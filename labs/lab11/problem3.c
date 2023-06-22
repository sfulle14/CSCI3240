//
//Implement a parallel bubble sort algorithm in C using pthreads.
//
#include <pthread.h>
#include <stdio.h>

#define ARRSIZE 5

//gloabl variables
pthread_mutex_t mutex;
int arr[ARRSIZE]= {3,1,4,5,2};
int tmp;
int max_threads = (ARRSIZE + 1) / 2;


//thread function
void *my_thread_function(void *arg)
{
   int index = tmp;
   tmp = tmp+2;
   int holder;

   if((index+1<ARRSIZE) && (arr[index] > arr[index+1])){
      //swap
      holder = arr[index];
      arr[index] = arr[index+1];
      arr[index+1] = holder;
   }
   return NULL; 
}


int main() {
   
   pthread_t my_thread[max_threads];

   pthread_mutex_init(&mutex, NULL);

   for(int i=1; i<=ARRSIZE; i++){
      if(i%2==1){
         tmp=0;
         //creating thread
         for(int j=0; j<max_threads; j++){
            pthread_create(&my_thread[j], NULL, my_thread_function, NULL);
         }
         //waiting for thread to finish
         for(int j=0; j<max_threads; j++){
            pthread_join(my_thread[j], NULL);
         }
      }
      else{
         tmp=1;
         //creating thread
         for(int j=0; j<max_threads; j++){
            pthread_create(&my_thread[j], NULL, my_thread_function, NULL);
         }
         //waiting for thread to end
         for(int j=0; j<max_threads; j++){
            pthread_join(my_thread[j], NULL);
         }
      }
   }


   //Print Sorted list
   printf("Sorted array: ");
   for(int i=0; i<ARRSIZE; i++){
      printf("%d ", arr[i]);
   }

   pthread_mutex_destroy(&mutex);
   return 0;
}