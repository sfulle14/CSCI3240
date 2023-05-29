#include <stdio.h>



int main() {

   int salary;
   int taxes;

   printf("Enter salary: ");
   scanf("%d", &salary);
   

   if(salary < 100000){
      printf("Tax amount is: 0\n");
   }
   else if(salary < 175000){
      taxes = salary * 0.15;
      printf("Tax amount is: %d\n", taxes);
   }
   else{
      taxes = salary * 0.25;
      printf("Tax amount is: %d\n", taxes);
   }

   return 0;
}