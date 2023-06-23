//
//Implement a parallel merge sort algorithm in C using pthreads.
//
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 6
#define NUMTHREADS 2

//declare functions
void merge(int low, int middle, int high);
void merge_sort(int* arr, int low, int high);


//gloabl variables
pthread_mutex_t mutex;
int arr[LENGTH] = {3,1,4,5,2,6};
int part=0;

//thread function
void *my_thread_function(void *arg)
{
   int thread_part = part++;

   int low = thread_part * (LENGTH / NUMTHREADS);
   int high = (thread_part + 1) * (LENGTH / NUMTHREADS) - 1;
   int middle = low + (high - low) / 2;

   if(low < high){
      merge_sort(arr, low, middle);
      merge_sort(arr, middle, high);
      merge(low, middle, high);
   }
   return NULL; 
}


int main() {
   pthread_t my_threads[NUMTHREADS];

   pthread_mutex_init(&mutex, NULL);


   //create threads
   for(int i=0; i<NUMTHREADS; i++){
      pthread_create(&my_threads[i], NULL, my_thread_function, NULL);
   }
   
   //wait for threads to finish
   for(int i=0; i<NUMTHREADS; i++){
      pthread_join(my_threads[i], NULL);
   }

   merge(0, (LENGTH / 2-1) /2, LENGTH / 2 -1);
   merge(LENGTH/2, LENGTH/2 + (LENGTH - 1 - LENGTH/2)/2, LENGTH-1);
   merge(0, (LENGTH-1)/2, LENGTH-1);

   printf("Sorted array: ");
   for(int i=0; i<LENGTH; i++){
      printf("%d ", arr[i]);
   }

   pthread_mutex_destroy(&mutex);
   return 0;
}

//standard merge sort code
void merge_sort(int* arr, int low, int high){
   int middle = low + (high - low) / 2;

   if(low < high){
      merge_sort(arr, low, middle);

      merge_sort(arr, middle+1, high);

      merge(low, middle, high);
   }
}

//Function to merge data together
void merge(int low, int middle, int high) {
   int i,j;
   int n1 = middle - low + 1;
   int n2 = high - middle;
   int* left = (int*)malloc(sizeof(int) * n1);
   int* right = (int*)malloc(sizeof(int) * n2);

   /*
   int lint = middle - low + 1;
   int rint = high - middle;
   left = &lint;
   right = &rint;
   */

   for(i=0; i<n1; i++){
      left[i] = arr[i + low];
   }
   
   for(i=0; i<n2; i++){
      right[i] = arr[i + middle + 1];
   }
   
   int k = low;
   i=j=0;

   while(i<n1 && j<n2){
      if(left[i] <= right[j]){
         arr[k++] = left[i++];
      }
      else{
         arr[k++] = right[j++];
      }
   }

   while(i<n1){
      arr[k++] = left[i++];
   }

   while (j<n2){
      arr[k++] = right[j++];
   }
   free(left);
   free(right);
}