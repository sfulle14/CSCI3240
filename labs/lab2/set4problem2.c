#include <stdio.h>

//define a global constant
#define PI 3.1416

//function declaration
float rectangle(float width, float length);
float circle(float radius);

int main() {
   //declare variables
   float radius=0;
   float width=0;
   float length=0;
   float areaR=0;
   float areaC=0.0;

   //get radius from user and call function
   printf("Enter a radius: ");
   scanf("%f", &radius);

   //print out the area
   printf("The area of the circle is: %f\n", circle(radius));


   //get length and width from user and call function
   printf("Enter a length: ");
   scanf("%f", &length);
   printf("Enter a width: ");
   scanf("%f", &width);

   //print out the area
   printf("The area of the rectangle is: %f\n", rectangle(width, length));
   
   return 0;
}

//function to find the area of a rectangle
float rectangle(float width, float length){
   return length * width;
}

//finction to find the area of a circle
float circle(float radius){
   return PI * radius * radius;
}
