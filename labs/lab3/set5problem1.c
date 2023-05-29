#include <stdio.h>
#include <stdbool.h>

//function declaration
void swap(int* x, int* y);
void bubbleSort(int arr[], int n);


int main() {
   //declare variables
   int n=0;
   int minIndex=0;
   int temp=0;
   
   //get the number of numbers from user
   printf("Enter the number of numbers: ");
   scanf("%d", &n);

   int arr[n]; //declare the array of numbers

   //get numbers
   for(int i=0; i<n; i++){
      printf("Enter a number for the array: ");
      scanf("%d", &arr[i]);
   }

   //print out unsorted array
   for(int i=0; i<n; i++){
      printf("%d", arr[i]);
   }

   
   //selection sort the numbers
   bubbleSort(arr, n);

   printf("\n");
   //print out sorted array
   for(int i=0; i<n; i++){
      printf("%d", arr[i]);
   }
   
   
   return 0;
}

void swap(int* x, int* y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

//selection sort
void bubbleSort(int arr[], int n){
   bool swapped;

   for(int i=0; i < n-1; i++){
      swapped =false;
      for(int j=0; j < n-i-1; j++){
         if(arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            swapped=true;
         }
      }
      //if no elements swapped then break
      if(swapped ==false) break;
   }


}
