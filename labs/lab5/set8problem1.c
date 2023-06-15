#include <stdio.h>

struct Length{
    int feet;
    int inches;
};

int main() {
   struct Length L1;
   struct Length L2;
   struct Length result;

   //get Length 1
   printf("Enter Length 1 feet and inches: ");
   scanf("%d", &L1.feet);
   scanf("%d", &L1.inches);

   //get Length 2
   printf("Enter Length 2 feet and inches: ");
   scanf("%d", &L2.feet);
   scanf("%d", &L2.inches);
   
   //sum
   result.feet = L1.feet + L2.feet;
   result.inches = L1.inches + L2.inches;

   if(result.inches>=12){
      result.feet += result.inches/12;
      result.inches = result.inches%12;
   }

   printf("Sum:\n");
   printf("Result feet: %d\n", result.feet);
   printf("Result inches: %d\n\n", result.inches);

   //difference
   result.feet = L1.feet - L2.feet;
   result.inches = L1.inches - L2.inches;

   if(result.inches < 0){
      result.feet -= 1;
      result.inches = result.inches + 12;
   }

   printf("Difference:\n");
   printf("Result feet: %d\n", result.feet);
   printf("Result inches: %d\n\n", result.inches);




   return 0;
}