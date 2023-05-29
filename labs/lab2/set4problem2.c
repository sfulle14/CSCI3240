#include <stdio.h>

//define a global constant
#define PI 3.1416

//function declaration
int rectangle(int width, int length);
float circle(int radius);

int main() {
   //declare variables
   int radius=0;
   int width=0;
   int length=0;
   int areaR=0;
   float areaC=0;

   //get radius from user and call function
   printf("Enter a radius: ");
   scanf("%d", &radius);

   //print out the area
   printf("The area of the circle is: %f\n", circle(radius));


   //get length and width from user and call function
   printf("Enter a length: ");
   scanf("%d", &length);
   printf("Enter a width: ");
   scanf("%d", &width);

   //print out the area
   printf("The area of the rectangle is: %d\n", rectangle(width, length));
   
   return 0;
}

//function to find the area of a rectangle
int rectangle(int width, int length){
   return length * width;
}

//finction to find the area of a circle
float circle(int radius){
   return PI * radius * radius;
}
