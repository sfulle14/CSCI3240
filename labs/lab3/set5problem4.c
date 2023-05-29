#include <stdio.h>

int main() {
   //declare variables
   int size1=0;
   int size2=0;
   int size3=0;
   int size4=0;

   //get size of matrix
   printf("Enter the order of Matrix A: ");
   scanf("%d %d", size1, size2);
   printf("Enter the order of Matrix B: ");
   scanf("%d %d", size3, size4);

   //declare matrix
   int A[size1][size2];
   int B[size3][size4];

   //load data in matrix A
   printf("Enter elements of Matrix A: ");
   for(int i=0; i< size1; i++){
      for(int j=0; j<size2; j++){
         scanf("%d", A[i][j]);
      }   
   }

   //load data in matrix B
   printf("Enter elements of Matrix B: ");
   for(int i=0; i< size3; i++){
      for(int j=0; j<size4; j++){
         scanf("%d", B[i][j]);
      }   
   }  
   
   //print matrix A
   printf("A:\n");
   for(int i=0; i< size1; i++){
      for(int j=0; j<size2; j++){
         printf("%d", A[i][j]);
      }   
   }

   //print matrix B
   printf("B:\n");
   for(int i=0; i< size3; i++){
      for(int j=0; j<size4; j++){
         printf("%d", B[i][j]);
      }   
   }  

   printf("The product of matrices A and B is: \n");
   
   return 0;
}