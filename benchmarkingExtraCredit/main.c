#include <stdio.h>



int main(){
    int arrarr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

    int mult1[3] = {1,2,3};
    int mult2[3] = {4,5,6};
    int mult3[3] = {7,8,9};

    int *mult[3] = {mult1, mult2, mult3};


    return 0;
}


