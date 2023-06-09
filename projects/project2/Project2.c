/* 
 * CSCI3240: Project 2
 * 
 * <Please put your name and userid here>
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


long MysteryFunction3(long *a, int n){
   //TODO
   //check assembly code for MysteryFunction3 in project2.s
}


int MysteryFunction4(unsigned long n)
{
      //TODO
   //check assembly code for MysteryFunction4 in project2.s

}



unsigned int MysteryFunction5(unsigned int A, unsigned int B)
{
  //TODO
   //check assembly code for MysteryFunction5 in project2.s

}

