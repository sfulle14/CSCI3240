#include <pthread.h>
#include <stdio.h>

#define LENGTH 5
#define THREADS 2

//gloabl variables
typedef struct qsort_starter{
   int *arr;
   int low;
   int high;
   int depthOfThread;
} quicksort_parameters;

int arr[LENGTH] = {3,1,4,5,2};

void swap(int *a, int*b);
int partition(int *arr, int low, int high, int pivot);
void c_quickSort(int *arr, int low, int high, int depthOfThread);
void quickSort(int *arr, int low, int high);

//thread function
void *my_thread_function(void *arg)
{
   quicksort_parameters* parameters = arg;
   c_quickSort(parameters->arr, parameters->low, parameters->high, parameters->depthOfThread);
   return NULL; 
}


int main() {
   int depthOfThread = THREADS;

   c_quickSort(arr, 0, LENGTH-1, depthOfThread);

   printf("Sorted arr: ");
   for(int i=0; i<LENGTH; i++){
      printf("%d", arr[i]);
   }

   return 0;
}

//function to swap variables
void swap(int *a, int*b){
   int t= *a;
   *a = *b;
   *b = t;
}

//function to find the array partition
int partition(int *arr, int low, int high, int pivot){
   int pivotValue = arr[pivot];
   swap(&arr[pivot], &arr[high]);
   int s = low;

   for(int i=low; i<high; i++){
      if(arr[i] <= pivotValue){
         swap(&arr[i], &arr[s]);
         s++;
      }
   }
   swap(&arr[s], &arr[high]);
   return s;
}

//concurrent quicksort funciton
void c_quickSort(int *arr, int low, int high, int depthOfThread){
   if(low<high){
      int pivotPos = low + (high-low) / 2;
      pivotPos = partition(arr, low, high, pivotPos);
      pthread_t thread;

      if(depthOfThread > 0){
         quicksort_parameters thread_param = {arr, low, pivotPos-1, depthOfThread};
         int result;
         result = pthread_create(&thread, NULL, my_thread_function, &thread_param);
         c_quickSort(arr, pivotPos+1, high, depthOfThread);

         pthread_join(thread, NULL);
      }
      else{
         quickSort(arr, low, pivotPos-1);
         quickSort(arr, pivotPos+1, high);
      }
   }
}

//sequencial quicksort function
void quickSort(int *arr, int low, int high){
   if(low<high){
      int pivotPos = low + (high-low) / 2;
      pivotPos = partition(arr, low, high, pivotPos);
      quickSort(arr, low, pivotPos-1);
      quickSort(arr, pivotPos+1, high);
   }
}