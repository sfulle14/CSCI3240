#include <stdio.h>

int main() {
   int *ptr = 30;
   int a = 10;
   *ptr = a;

   printf("%d\n",*ptr);
   
   return 0;
}

// D.Error