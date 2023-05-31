#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//function declarartion
int* mergeArrays(int arr1[], int arr2[], int size1, int size2);
void swap(int* x, int* y);
void bubbleSort(int arr[], int n);

int main() {
   int size1 = 4;
   int size2 = 4;
   int arr1[size1];
   int arr2[size2];
   int* array;
   
   arr1[0]=1;
   arr1[1]=2;
   arr1[2]=4;
   arr1[3]=3;

   arr2[0]=2;
   arr2[1]=3;
   arr2[2]=6;
   arr2[3]=5;

   array = mergeArrays(arr1, arr2, size1, size2);

   
   printf("Main array: ");
   for(int i=0; i<sizeof(array); i++){
      printf("%d", array[i]);
   }
   
   return 0;
}

//
int* mergeArrays(int arr1[], int arr2[], int size1, int size2){
   int size = size1+size2;
   int result[size];

   //Concatenate arr1 and arr2 into result
   for(int i=0; i<size1; i++){
      result[i] = arr1[i];
   }
   for(int i=0; i<size2; i++){
      result[size1+i] = arr2[i];
   }

   //print out Concatenated array
   printf("Concatenated array: ");
   for(int i=0; i<size; i++){
      printf("%d",result[i]);
   }
   printf("\n");
   
   //remove duplicated values
   for(int i=0; i<size-1; i++){
      for(int j=i+1; j<size; j++){
         if(result[i] == result[j]){
            for(int k=j; k<size-1; k++){
               result[k]=result[k+1];
            }
            size--;
         }
      }
   }
   
   //print out array with removed duplicates
   for(int i=0; i<size; i++){
      printf("%d", result[i]);
   }
   printf("\n");

   //sort array in ascending order
   bubbleSort(result, size);

   //print out sorted array
   for(int i=0; i<size; i++){
      printf("%d", result[i]);
   }
   printf("\n");

   return result;
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
