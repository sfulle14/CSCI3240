//
//Implement a parallel merge sort algorithm in C using pthreads.
//
#include <pthread.h>
#include <stdio.h>

#define LENGTH 5
#define NUMTHREADS 2

//declare functions
void merge(int arr[], int left, int middle, int right);
void merge_sort(int arr[], int left, int right);
void merge_arrays(int arr[], int number, int aggregation);

//gloabl variables
pthread_mutex_t mutex;
const int NUMBERS_PER_THREAD = LENGTH / NUMTHREADS;
const int OFFSET = LENGTH % NUMTHREADS;
int arr[LENGTH] = {3,1,4,5,2};

//thread function
void *my_thread_function(void *arg)
{
   int thread_id = *(int*)arg;
   int left = thread_id * NUMBERS_PER_THREAD;
   int right = (thread_id+1) * NUMBERS_PER_THREAD - 1;
   int middle;

   if(thread_id == NUMTHREADS-1){
      right += OFFSET;
   }

   middle = left + (right-left) / 2;

   if(left < right){
      merge_sort(arr, left, right);
   }
   return NULL; 
}


int main() {
   pthread_t my_threads[NUMTHREADS];

   pthread_mutex_init(&mutex, NULL);


   //create threads
   for(int i=0; i<NUMTHREADS; i++){
      pthread_create(&my_threads[i], NULL, my_thread_function, &i);
   }
   
   //wait for threads to finish
   for(int i=0; i<NUMTHREADS; i++){
      pthread_join(my_threads[i], NULL);
   }

   //get sorted array
   merge_arrays(arr, NUMTHREADS, 1);

   printf("Sorted array: ");
   for(int i=0; i<LENGTH; i++){
      printf("%d ", arr[i]);
   }

   pthread_mutex_destroy(&mutex);
   return 0;
}

//standard merge sort code
void merge_sort(int arr[], int left, int right){
   if(left<right){
      int middle = left + (right - left) / 2;
      merge_sort(arr, left, middle);
      merge_sort(arr, middle+1, right);
      merge(arr, left, middle, right);
   }
}

//Function to merge data together
void merge(int arr[], int left, int middle, int right) {
   int i = 0;
   int j = 0;
   int k = 0;
   int left_length = middle - left + 1;
   int right_length = right - middle;
   int left_array[left_length];
   int right_array[right_length];
    
   // copy values to left array 
   for (int i = 0; i < left_length; i ++) {
      left_array[i] = arr[left + i];
   }
    
   // copy values to right array 
   for (int j = 0; j < right_length; j ++) {
      right_array[j] = arr[middle + 1 + j];
   }
    
   i = 0;
   j = 0;
   // chose from right and left arrays and copy 
   while (i < left_length && j < right_length) {
      if (left_array[i] <= right_array[j]) {
         arr[left + k] = left_array[i];
         i ++;
      } 
      else{
         arr[left + k] = right_array[j];
         j ++;
      }
      k ++;
   }
    
   // copy the remaining values to the array 
   while (i < left_length) {
     arr[left + k] = left_array[i];
     k++;
     i++;
   }
   while (j < right_length) {
      arr[left + k] = right_array[j];
      k++;
      j++;
   }
}

void merge_arrays(int arr[], int number, int aggregation){
   for(int i=0; i<number; i+=2){
      int left = i * NUMBERS_PER_THREAD * aggregation;
      int right = ((i+2) * NUMBERS_PER_THREAD * aggregation) - 1;
      int middle = left + NUMBERS_PER_THREAD * aggregation -1;
      if(right >= LENGTH){
         right = LENGTH-1;
      }
      merge(arr, left, middle, right);
   }
   if(number/2 >=1){
      merge_arrays(arr, number/2, aggregation*2);
   }
}