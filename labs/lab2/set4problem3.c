#include <stdio.h>

//function declaration
float  permutation(int n, int r);
float  combination(int n, int r);
int factorial(int num);


int main() {
   //declare variables
   int n=0;
   int r=0;

   printf("Enter a value for n: ");
   scanf("%d", &n);
   printf("Enter a value for r: ");
   scanf("%d", &r);
   
   printf("The permutation is: %f\n", permutation(n, r));
   printf("The combination is: %f\n", combination(n, r));
   
   return 0;
}

//function to calculate permutation
float  permutation(int n, int r){
   return (factorial(n)/factorial(n-r));
}

//function to calculate combination
float  combination(int n, int r){  
   return (permutation(n,r)/factorial(r));
}

//function to find the factorial of a user provided number
int factorial(int num){
   int sum=1;
   for(int i=1; i<=num; i++){
      sum *= i;
   }
   return sum;
}