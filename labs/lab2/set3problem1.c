#include <stdio.h>

int main() {
   
   int num=0;
   int sum=0;
   int count=0;
   float avg=0;

   do{
      printf("Enter an integer: ");
      scanf("%d", &num);

      if(num %2 ==0 && num != 0){
         sum += num;
         count++;
      }

   }while(num != 0);

   avg = sum / count;

   printf("The average of the even numbers is: %f", avg);

   return 0;
}