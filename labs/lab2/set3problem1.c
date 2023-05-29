#include <stdio.h>

int main() {
   //declare variables
   int num=0;
   int sum=0;
   int count=0;
   float avg=0;

   //loop to do code while input is not equal to 0
   do{
      //gets user input
      printf("Enter an integer: ");
      scanf("%d", &num);

      //adds user input to total and increments count if input is even
      if(num %2 ==0 && num != 0){
         sum += num;
         count++;
      }

   }while(num != 0);

   //finds the average of all the even user inputs
   avg = sum / count;

   //prints out the result
   printf("The average of the even numbers is: %f", avg);

   return 0;
}