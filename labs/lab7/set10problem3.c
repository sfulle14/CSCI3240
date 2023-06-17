#include <stdio.h>
#include <string.h>


int main() {
   char s[10] = "abcde";
   char* cptr;
   int len = strlen(s);

   // prints the characters in a string in reverse order.
   for(int i=len; i>=0; i--){
      cptr = &s[i];
      printf("%c", *cptr);
   }
   
   return 0;
}
