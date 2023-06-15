#include <stdio.h>
#include <string.h>

#define FILESIZE 10000
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
   char salary[SALARYLIMIT];
};



int main() {
   struct Struct_Employee_Info emp[MAXSTRUCT];
   char comparisonOperator[2];
   FILE *fp;
   char *token;
   int count = 0;

   fp = fopen("records.csv", "a+");


   //get the first token
   token = strtok(fp, ",");

   //read in all the csv into the struct
   while(token != NULL){
      strncpy(emp[count].lastName, token, NAMELIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].firstName, token, NAMELIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].zipCode, token, ZIPLIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].department, token, DEPTLIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].salary, token, SALARYLIMIT);
      token = strtok(NULL, ",");
      count++;
   }


   
   
   return 0;
}

int SearchByName(struct Struct_Employee_Info emp, char firstName[NAMELIMIT], char lastName[NAMELIMIT]){
   char name[200];
   char first[NAMELIMIT];
   char last[NAMELIMIT];
   char lastFirst[200];

   firstName[strlen(firstName)-1] = '\0';
   lastName[strlen(lastName)-1] = '\0';

   strncpy(name, lastName, strlen(lastName));
   strncat(name, ",", 1);
   strncat(name, firstName, strlen(firstName));

   for(int i=0; i<MAXSTRUCT; i++){
      first[strlen(first)-1]='\0';
      last[strlen(last)-1]='\0';
      strncpy(lastFirst, last, strlen(last));
      strncat(lastFirst, ",", 1);
      strncat(lastFirst, first, strlen(first));

      if(!strcmp(name,lastFirst)){
         return i;
      }
   }
   return -1;
}


int SearchByZipCode(struct Struct_Employee_Info employeeStructure, char zipCode[ZIPLIMIT]){

   return 0;
}

int SearchBySalary(struct Struct_Employee_Info employeeStructure, char salary[SALARYLIMIT], char comparisonOperator[2]){


   return 0;
}
