#include <stdio.h>
#include <math.h>

int main() {
   //declare variables
   int numTerms;
   int addTerm=2;
   int count=1;
   int x;

   //get number of terms from user
   printf("Enter the number of terms: ");
   scanf("%d", &numTerms);

   //get value of x from user
   printf("Enter x: ");
   scanf("%d", &x);

   //loop to compute 1–x^2 +x^4 –x^6 +x^8 -.........nth term
   for(int i=1; i<numTerms; i++){
      count -= pow(x, addTerm);
      addTerm+=2;

   }
   //prints out result
   printf("The nth term is: %d", count);
   
   return 0;
}