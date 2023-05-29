#include <stdio.h>


int main() {

   int n;

   printf("Enter an integer: ");
   scanf("%d", &n);

   switch (n%2)
   {
   case 0:
      printf("%d is an even number.\n", n);
      break;
   
   default:
      printf("%d is an odd number.\n", n);
      break;
   }

   return 0;
}