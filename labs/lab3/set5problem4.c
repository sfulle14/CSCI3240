#include <stdio.h>

int matrixMult(int A, int B);

int main() {
   //declare variables
   int size1;
   int size2;
   int size3;
   int size4;

   //get size of matrix
   
   printf("Enter the order of the Matrix A: ");
   scanf("%d %d", &size1, &size2);

   printf("Enter the order of the Matrix B: ");
   scanf("%d %d", &size3, &size4);
   
   /*
   //constants for testing
   size1=3, size2=3, size3=3, size4=4;
   int A[3][3] = {{1,2,8},{1,2,3},{6,8,6}};
   int B[3][4] = {{5,6,2,4},{1,8,0,7},{4,5,1,8}};
   int C[size1][size4];
   */
   
   //declare matrix
   int A[size1][size2];
   int B[size3][size4];
   int C[size1][size4];
   
   
   //load data in matrix A
   printf("Enter elements of Matrix A: ");
   for(int i=0; i< size1; i++){
      for(int j=0; j<size2; j++){
         scanf("%d", &A[i][j]);
      }   
   }

   //load data in matrix B
   printf("Enter elements of Matrix B: ");
   for(int i=0; i< size3; i++){
      for(int j=0; j<size4; j++){
         scanf("%d", &B[i][j]);
      }   
   }  
   

   //print matrix A
   printf("A:\n");
   for(int i=0; i< size1; i++){
      for(int j=0; j<size2; j++){
         printf("%d ", A[i][j]);
      }   
      printf("\n");
   }
   printf("\n");

   //print matrix B
   printf("B:\n");
   for(int i=0; i< size3; i++){
      for(int j=0; j<size4; j++){
         printf("%d ", B[i][j]);
      }   
      printf("\n");
   }  
   printf("\n");

   //matrix multiplication
   for(int i=0; i<size1; i++){
      for(int j=0; j<size4; j++){
         C[i][j] = 0;
         for(int k=0; k<size3; k++){
            C[i][j] += matrixMult(A[i][k], B[k][j]);
            //C[i][j] += A[i][k]* B[k][j];
         }
      }
   }
   
   printf("The product of matrices A and B is: \n");
   
   for(int i=0; i<size1; i++){
      for(int j=0; j<size4; j++){
         printf("%d ",C[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   
   return 0;
}

//function to do the multiplication
int matrixMult(int A, int B){
   return A * B;
}