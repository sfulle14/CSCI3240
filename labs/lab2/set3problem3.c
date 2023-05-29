#include <stdio.h>

int main() {
   //declare variables
   int numTerms;
   int addTerm=1;
   int count=1;

   //gets input from the user.
   printf("Enter the number of terms: ");
   scanf("%d", &numTerms);

   //loops from 1 to numTerms provided by user
   //adds addTerm to count and increments addTerm
   for(int i=1; i<numTerms; i++){
      count += addTerm;
      addTerm+=2;
   }
   
   //prints out the result
   printf("The nth term is: %d", count);
   
   return 0;
}