/* 
 * CSCI3240: Project 2
 * 
 * Steven Fuller sf5g
 * 
 * Project2.c - Source file with your solutions to the Lab.
 *          This is the file you will submit in the D2L -> Project2 dropbox.
 *
 *   Make sure you have insightful comments in your code. 
 * 
 */
#include <math.h>

//power function a^b
long MysteryFunction1(long a, int b){
   return pow(a,b); 
}

//This function takes an input and returns the mirror of the inputs binary number
//ex if you input 2 (0010) you would get 4 (0100)
unsigned int MysteryFunction2(unsigned int num)
{
    //check assembly code for MysteryFunction2 in project2.s
    unsigned int x = -2147483648; //assing x = Tmin
    unsigned int result;  //variable to hold result
    unsigned int tmp = num;  //variable to save input
    
    //set our return var to input
    result = num;
    //left shift as long as out number is greater then unsigned Tmin
    while(num<x){
        result = result<<1;
        num = num<<1;
    }
    //right shift back until num & 1 is 1 to add leading 0s if needed
    if (!(tmp & 1)){
        result = result >>1;
    }
    
    return result;
}

//while i is less then the value a points to this function
//will miultiply i by 8 and add it to the address of a.
long MysteryFunction3(long *a, int n){
    //initialize the return value to 1
    long result = 1;
    //counter
    long i=1;
    //while i is less then the value a points to this function
    //will miultiply i by 8 and add it to the address of a
    while(i<*a){
        result = i * 8 + (long)&a;
        i++;
    }
    return result;
}

//this function counts the number of 1s in the binary of the input n.
int MysteryFunction4(unsigned long n){
    //initialize the return value to 0
    int result = 0;
    for(unsigned i=1 << 31; i>0; i = i/2){
        if(n&i){result++;}
    }

    return result;
}


//This function is taking 2 inputs and ORing their binary values
//It then takes that ORed value and counts the 1s
unsigned int MysteryFunction5(unsigned int A, unsigned int B){
    //initialize the return value to 0
    unsigned int result = 0;
    
    //looping through the binary for the 2 inputs and ORing them
    //incrementing result by 1 if only one of them has a 1 at that value
    for(unsigned i=1 << 31; i>0; i=i/2){
        if(A&i | B&i){
            result++;
        }
    }

    return result;
}
