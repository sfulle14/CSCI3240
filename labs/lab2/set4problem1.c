#include <stdio.h>

int factorial(int num);

int main() {
   //declare variables
   int num;
   int fact;

   //get number from user
   printf("Enter an integer: ");
   scanf("%d", &num);
   
   fact = factorial(num);

   printf("The factorial of %d is: %d", num, fact);
   
   return 0;
}

//function to find the factorial of a user provided number
int factorial(int num){
   int sum=1;
   for(int i=1; i<=num; i++){
      sum *= i;
   }

   return sum;
}