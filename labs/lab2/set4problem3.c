#include <stdio.h>

//function declaration
float  permutation(float n, float r);
float  combination(float n, float r);
float factorial(float num);


int main() {
   //declare variables
   float n=0.0;
   float r=0.0;

   printf("Enter a value for n: ");
   scanf("%f", &n);
   printf("Enter a value for r: ");
   scanf("%f", &r);
   
   printf("The permutation is: %f\n", permutation(n, r));
   printf("The combination is: %f\n", combination(n, r));
   
   return 0;
}

//function to calculate permutation
float  permutation(float n, float r){
   return (factorial(n)/factorial(n-r));
}

//function to calculate combination
float  combination(float n, float r){  
   return (permutation(n,r)/factorial(r));
}

//function to find the factorial of a user provided number
float factorial(float num){
   float sum=1.0;
   for(float i=1.0; i<=num; i++){
      sum *= i;
   }
   return sum;
}