#include <stdio.h>
#include <math.h>

int main() {
   int numTerms;
   int addTerm=2;
   int count=1;
   int x;

   printf("Enter the number of terms: ");
   scanf("%d", &numTerms);

   printf("Enter x: ");
   scanf("%d", &x);

   for(int i=1; i<numTerms; i++){
      count -= pow(x, addTerm);
      addTerm+=2;

   }

   printf("The nth term is: %d", count);
   
   return 0;
}