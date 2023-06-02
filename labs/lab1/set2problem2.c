#include <stdio.h>



int main() {

   int salary;
   float taxes;

   printf("Enter salary: ");
   scanf("%d", &salary);
   

   if(salary < 100000){
      printf("Tax amount is: 0\n");
   }
   else if(salary < 175000){
      taxes = salary * 0.15;
      printf("Tax amount is: %f\n", taxes);
   }
   else{
      taxes = salary * 0.25;
      printf("Tax amount is: %f\n", taxes);
   }

   return 0;
}