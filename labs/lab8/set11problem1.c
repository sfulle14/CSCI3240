#include <stdio.h>
#include <stdlib.h>

int main() {
   int *p;
   p = (int*) calloc(3,sizeof(int));

   printf("Enter first number\n");
   scanf("%d",p);

   printf("Enter second number\n");
   scanf("%d",p+2);

   printf("%d%d",*p,*(p+2));

   free(p);
   
   return 0;
}

// A. 27
