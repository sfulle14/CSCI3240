#include <stdio.h>
#include <stdbool.h>

//function declaration
void swap(int* x, int* y);


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

   //print out original array
   for(int i=0; i<n; i++){
      printf("%d", arr[i]);
   }

   
   //switch order of array
   for(int i=0, j=n-1; i< n/2; i++,j--){
      swap(&arr[i], &arr[j]);
   }

   printf("\n");
   //print out swapped array
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