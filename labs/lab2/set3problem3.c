#include <stdio.h>

int main() {
   int numTerms;
   int addTerm=1;
   int count=1;

   printf("Enter the number of terms: ");
   scanf("%d", &numTerms);

   for(int i=1; i<numTerms; i++){
      count += addTerm;
      addTerm+=2;
   }
   printf("The nth term is: %d", count);
   
   return 0;
}