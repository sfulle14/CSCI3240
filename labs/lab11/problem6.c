//
//Implement a parallel radix sort algorithm in C using pthreads.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5
#define NUMTHREADS 2

//gloabl variables
pthread_mutex_t mutex;
int arr[LENGTH] = {3,1,4,5,2};



//thread function
void *my_thread_function(void *arg)
{
   
   return NULL; 
}


int main() {
   pthread_t my_thread1, my_thread2;

   pthread_mutex_init(&mutex, NULL);

   pthread_create(&my_thread1, NULL, my_thread_function, NULL);
   pthread_create(&my_thread2, NULL, my_thread_function, NULL);

   pthread_join(my_thread1, NULL);
   pthread_join(my_thread2, NULL);

   printf("Final value of counter: %d\n", counter);

   pthread_mutex_destroy(&mutex);
   return 0;
}