#include <stdio.h>

int main() {
   int arr[]= {1,5,4,7,2};
   int* iptr;
   int smallest=arr[0];
   int largest=0;

   for(int i = 0; i<5; i++){
      iptr = &arr[i];
      if(*(iptr)>largest){
         largest = *(iptr);
      }
      else if(*(iptr)< smallest){
         smallest = *(iptr);
      }
   }
   
   printf("Largest: %d\n", largest);
   printf("Smallest: %d\n", smallest);

   return 0;
}
