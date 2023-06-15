#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STUDENTNUM 5
#define LIMIT 25
#define MAXSTRING 1000

struct Student{
    char studentId[LIMIT];
    char score[LIMIT];
    char name[LIMIT];
};

int main() {
   struct Student students[STUDENTNUM];
   FILE* fp;
   char* filename = "student.csv";
   double topScore = 0.00;
   int topStudent = 0;
   char studentName[LIMIT];
   char string[MAXSTRING];
   char *token;
   int count = 0;

   //open file
   fp = fopen(filename, "r");

   //get first line to ignore
   fgets(string, MAXSTRING, fp);

   //load file into struct
   while(feof(fp) != true){
    fgets(string, MAXSTRING, fp);
    token = strtok(string, ",");
    strncpy(students[count].name, token, LIMIT);
    token = strtok(NULL, ",");
    strncpy(students[count].studentId, token, LIMIT);
    token = strtok(NULL, ",");
    strncpy(students[count].score, token, LIMIT);
    count++;
   }

   //loop to find the top scoring student
   for(int i=0; i<STUDENTNUM; i++){
    if(atof(students[i].score) > topScore){
        topStudent = i;
        topScore = atof(students[i].score);
    }
   }

   printf("Top scorer: %s %s", students[topStudent].name, students[topStudent].studentId);
   
   return 0;
}
