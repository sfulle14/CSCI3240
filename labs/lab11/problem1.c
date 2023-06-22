#include <pthread.h>
#include <stdio.h>

#define ARRSIZE 5

//global variables
int sum=0;
pthread_mutex_t mutex;

//thread to do calculation
void *my_thread_function(void *arg)
{
    int *my_arg = (int*)arg;

    for(int i=0; i<ARRSIZE; i++){
      pthread_mutex_lock(&mutex);
      sum += my_arg[i];
      pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main() {
    pthread_t my_thread;
    int arg[ARRSIZE] = {1,2,3,4,5};
    pthread_create(&my_thread, NULL, my_thread_function, &arg);
    pthread_join(my_thread, NULL);

    printf("Sum: %d\n", sum);

    pthread_mutex_destroy(&mutex);
    return 0;
}