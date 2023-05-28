#include <stdio.h>

int main() {
   float num;
   float temp;

   printf("Enter tempurature in F: ");

   scanf("%f", &num);

   //F = (C*9/5) + 32
   temp = ((num-32) * 5) / 9;

   printf("The tempurature in Celsius is: %f", temp);
   
   return 0;
}