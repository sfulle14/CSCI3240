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

struct Struct_Employee_Info emp[MAXSTRUCT];

//function declaration
const char* SearchByName(struct Struct_Employee_Info emp[], char firstName[NAMELIMIT], char lastName[NAMELIMIT]);
int SearchByZipCode(struct Struct_Employee_Info employeeStructure, char zipCode[ZIPLIMIT]);
int SearchBySalary(struct Struct_Employee_Info employeeStructure, char salary[SALARYLIMIT], char comparisonOperator[2]);

int main() {
   //variable declaration
   char comparisonOperator[2];
   FILE *fp;
   int count = 0;
   char buf[FILESIZE];
   char* token;

   //open file
   fp = fopen("records.csv", "a+");


   //read in the csv into the struct
   while(fgets(buf, FILESIZE, fp) != NULL){
      token = strtok(buf, ",");
      strncpy(emp[count].lastName, token, NAMELIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].firstName, token, NAMELIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].zipCode, token, ZIPLIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].department, token, DEPTLIMIT);
      token = strtok(NULL, ",");
      strncpy(emp[count].salary, token, SALARYLIMIT);
      count++;
   }

   printf("%s", SearchByName(emp, "Picasso", "Pablo"));
   
   return 0;
}

const char* SearchByName(struct Struct_Employee_Info emp[], char firstName[], char lastName[]){
   char name[200];
   char first[NAMELIMIT];
   char last[NAMELIMIT];
   char lastFirst[200];
   int count = 0;
   char *str;

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
         strncpy(str, emp[i].lastName, strlen(emp[i].lastName));
         strncat(str, ",", 1);
         strncpy(str, emp[i].firstName, strlen(emp[i].firstName));
         strncat(str, ",", 1);
         strncpy(str, emp[i].zipCode, strlen(emp[i].zipCode));
         strncat(str, ",", 1);
         strncpy(str, emp[i].department, strlen(emp[i].department));
         strncat(str, ",", 1);
         strncpy(str, emp[i].salary, strlen(emp[i].salary));
      }
   }

   return str;
}


int SearchByZipCode(struct Struct_Employee_Info employeeStructure, char zipCode[ZIPLIMIT]){

   return 0;
}

int SearchBySalary(struct Struct_Employee_Info employeeStructure, char salary[SALARYLIMIT], char comparisonOperator[2]){


   return 0;
}
