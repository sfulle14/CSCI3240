#include <stdio.h>

#define PIE 3.1416

int main() {

    float radius;
    float circumference;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    circumference = 2.0 * PIE * radius;

    printf("The circumference of your circle is: %f", circumference);

   return 0;
}