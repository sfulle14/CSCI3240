#include <stdio.h>
#include <stdlib.h>
/*
int * p1 (void) {
  int x= 10;
return (&x);
}

int * p2 (void) {
  int * px;
  *px= 10;
  return px;
}
*/
int *p3 (void) {
   int *px;
   px = (int *) malloc (sizeof(int));
   *px= 10;
   return px;
}

int main() {
   int* n;
   n =p3();
   return 0;
}


//D. P1 and P2