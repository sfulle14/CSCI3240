#include <pthread.h>
#include <stdio.h>

//gloabl variables
pthread_mutex_t mutex;
int counter = 0;

//thread function
void *my_thread_function(void *arg)
{
   for (int i = 0; i < 1000000; i++) {
      pthread_mutex_lock(&mutex);
      counter++;
      pthread_mutex_unlock(&mutex);
   }
   return; 
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