#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILESIZE 1000
#define MAXSTRUCT 100
#define NAMELIMIT 100
#define ZIPLIMIT 6
#define DEPTLIMIT 100
#define SALARYLIMIT 10

struct Struct_Employee_Info{
   char firstName[NAMELIMIT];
   char lastName[NAMELIMIT];
   char zipCode[ZIPLIMIT];
   char department[DEPTLIMIT];
   int salary;
};



//function declaration
char* SearchByName(struct Struct_Employee_Info emp[], char firstName[NAMELIMIT], char lastName[NAMELIMIT]);
int SearchByZipCode(struct Struct_Employee_Info employeeStructure, char zipCode[ZIPLIMIT]);
int SearchBySalary(struct Struct_Employee_Info employeeStructure, int salary, char comparisonOperator[2]);

int main() {
   //variable declaration
   FILE *fp;
   char* filename = "records.csv";
   char buf[FILESIZE];
   char* token;
   int count = 0;
   char comparisonOperator[2];
   char * ch;

   struct Struct_Employee_Info emp[MAXSTRUCT];

   //open file
   fp = fopen(filename, "r+");

   //read in the csv into the struct
   while(fgets(buf, FILESIZE, fp) != NULL){
      sscanf(buf, "%[^,],%[^,],%[^,],%[^,] ,%d ", emp[count].firstName, emp[count].lastName, emp[count].zipCode, emp[count].department, &emp[count].salary);
      count++;
   }

   printf("%s %s %s %s %d", emp[1].firstName, emp[1].lastName, emp[1].zipCode, emp[1].department, emp[1].salary);

   //ch = SearchByName(emp, "Picasso", "Pablo");
   //printf("%s", ch);
   
   fclose(fp);
   return 0;
}
/*
char* SearchByName(struct Struct_Employee_Info emp[], char firstName[], char lastName[]){
   //function variables
   char name[200];
   char first[NAMELIMIT];
   char last[NAMELIMIT];
   char lastFirst[200];
   int count = 0;
   char *str[FILESIZE];



   //loop to compare all names to provided name
   for(int i=0; i<MAXSTRUCT; i++){
      //if names are equal then add to a string var
      if(!strcmp(firstName, emp[i].firstName) && !strcmp(lastName, emp[i].lastName)){
         strncpy(last, emp[i].lastName, strlen(emp[i].lastName));
         last[strlen(emp[i].lastName)-1] = '\0';
         strncpy(str[], emp[i].lastName, strlen(emp[i].lastName));

         strncat(str, ",", 1);

         strncpy(first, emp[i].firstName, strlen(emp[i].firstName));
         first[strlen(emp[i].firstName)-1] = '\0';
         strncpy(str, emp[i].firstName, strlen(emp[i].firstName));

         strncat(str, ",", 1);

         emp[i].zipCode[strlen(emp[i].zipCode)-1] = '\0';
         strncpy(str, emp[i].zipCode, strlen(emp[i].zipCode));

         strncat(str, ",", 1);

         strncpy(str, emp[i].department, strlen(emp[i].department));

         strncat(str, ",", 1);

         strncpy(str, emp[i].salary, strlen(emp[i].salary));
      }
   }

   printf("%s", str);

   return str;
}
*/
/*
int SearchByZipCode(struct Struct_Employee_Info employeeStructure, char zipCode[ZIPLIMIT]){

   return 0;
}

int SearchBySalary(struct Struct_Employee_Info employeeStructure, int salary, char comparisonOperator[2]){


   return 0;
}
*/