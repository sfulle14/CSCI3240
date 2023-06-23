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

int getMax(int arr[], int n);
void countingSort(int arr[], int size, int place);
void radixSort(int arr[], int size);



//thread function
void *my_thread_function(void *arg)
{
   radixSort(arr, LENGTH);
   return NULL; 
}


int main() {
   pthread_t my_thread1, my_thread2;

   pthread_mutex_init(&mutex, NULL);

   pthread_create(&my_thread1, NULL, my_thread_function, NULL);

   pthread_join(my_thread1, NULL);

   int n = sizeof(arr) / sizeof(arr[0]);
   
   for (int i = 0; i < n; ++i) {
      printf("%d  ", arr[i]);
   }
   printf("\n");

   pthread_mutex_destroy(&mutex);
   return 0;
}


// Function to get the largest element from an arr
int getMax(int arr[], int n) {
   int max = arr[0];
   for (int i = 1; i < n; i++){
      if (arr[i] > max){
         max = arr[i];
      }
   }
   return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int arr[], int size, int place) {
   int output[size + 1];
   int max = (arr[0] / place) % 10;

   for (int i = 1; i < size; i++) {
      if (((arr[i] / place) % 10) > max)
      max = arr[i];
   }
   int count[max + 1];

   for (int i = 0; i < max; ++i){
      count[i] = 0;
   }

   // Calculate count of elements
   for (int i = 0; i < size; i++){
      count[(arr[i] / place) % 10]++;
   }
    
   // Calculate cumulative count
   for (int i = 1; i < 10; i++){
      count[i] += count[i - 1];
   }

   // Place the elements in sorted order
   for (int i = size - 1; i >= 0; i--) {
      output[count[(arr[i] / place) % 10] - 1] = arr[i];
      count[(arr[i] / place) % 10]--;
   }

   for (int i = 0; i < size; i++){
      arr[i] = output[i];
   }
}

// Main function to implement radix sort
void radixSort(int arr[], int size) {
   // Get maximum element
   int max = getMax(arr, size);

   // Apply counting sort to sort elements based on place value.
   for (int place = 1; max / place > 0; place *= 10)
      countingSort(arr, size, place);
}
