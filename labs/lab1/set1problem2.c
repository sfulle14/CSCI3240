#include <stdio.h>

int main() {
   int num;
   int temp;

   printf("Enter tempurature in F: ");

   scanf("%d", &num);

   //F = (C*9/5) + 32
   temp = ((num-32) * 5) / 9;

   printf("The tempurature in Celsius is: %d", temp);
   
   return 0;
}