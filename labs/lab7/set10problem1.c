#include <stdio.h>

int main() {
   float a = 17.5;
   float b = 43.5;
   float *ptr = &a;
   (*ptr)++;
   *ptr =b;

   printf("%.02f %.02f %.02f\n", *ptr, a, b);
   
   return 0;
}

//B. 43.50 43.50 43.50
