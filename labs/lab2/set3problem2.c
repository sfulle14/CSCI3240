#include <stdio.h>

int main() {
   //declare variables
   int num=0;
   int sum=0;

   //gets input from the user
   printf("Enter an integer: ");
   scanf("%d", &num);

   //loops from 1 to user input
   for(int i=1; i < num; i++){
      sum +=i; 
      printf("%d\n", sum);

      //checks to see if sum is larger than num and exits if it is
      if(sum > num){
         printf("%d is not triangular", num);
         break;
      }
      //checks to see if sum equals num and prints result if it is.
      if(sum==num){
         printf("%d is triangular", num);
         break;
      }
   }

   
   return 0;
}