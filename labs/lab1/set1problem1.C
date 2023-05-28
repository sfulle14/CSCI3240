#include <stdio.h>

int main() {
   int num;

   printf("Enter the integer value of an ASCII character: ");

   scanf("%d", &num);

   printf("Your ASCII character is: %c", num);
   
   return 0;
}