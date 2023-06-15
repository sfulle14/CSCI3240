#include <stdio.h>

struct Length{
    int feet;
    int inches;
};

int main() {
    struct Length L1;
    struct Length L2;

    //get Length 1
    printf("Enter Length 1 feet and inches: ");
    scanf("%d", &L1.feet);
    scanf("%d", &L1.inches);

    //get Length 2
    printf("Enter Length 2 feet and inches: ");
    scanf("%d", &L2.feet);
    scanf("%d", &L2.inches);
   
   return 0;
}