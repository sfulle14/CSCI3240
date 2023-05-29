#include <stdio.h>

int main() {
   int num=0;
   int sum=0;

   printf("Enter an integer: ");
   scanf("%d", &num);

   for(int i=1; i < num; i++){
      sum +=i;
      printf("%d\n", sum);
      if(sum > num){
         printf("%d is not triangular", num);
         break;
      }
      if(sum==num){
         printf("%d is triangular", num);
         break;
      }
   }

   
   return 0;
}