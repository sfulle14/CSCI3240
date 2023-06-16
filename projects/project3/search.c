#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FILESIZE 1000
#define MAXSTRUCT 4
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


//Given a first and last name find all matching records
char* SearchByName(struct Struct_Employee_Info emp[], char firstName[], char lastName[]){
   //function variables
   int count = 0;
   static char str[FILESIZE];
   static char* p;
   char salary[SALARYLIMIT];

   //loop to compare all names to provided name
   for(int i=0; i<MAXSTRUCT; i++){
      //if names are equal then add to a string var
      //first,last,zip,department,salary
      if(!strcmp(firstName, emp[i].firstName) && !strcmp(lastName, emp[i].lastName)){
         strncat(str, firstName, strlen(firstName));
         strncat(str, ",", 1);
         strncat(str, lastName, strlen(lastName));
         strncat(str, ",", 1);
         strncat(str, emp[i].zipCode, strlen(emp[i].zipCode));
         strncat(str, ",", 1);
         strncat(str, emp[i].department, strlen(emp[i].department));
         strncat(str, ",", 1);
         sprintf(salary, "%d", emp[i].salary);
         strncat(str, salary, strlen(salary));
         strncat(str, "\n", 1);
      }
   }

   p = str;
   return p;
}


//Given a zipCode find all records with that zipCode
char* SearchByZipCode(struct Struct_Employee_Info emp[], char zipCode[ZIPLIMIT]){
   //function variables
   int count = 0;
   static char strZip[FILESIZE];
   static char* p2;
   char salary[SALARYLIMIT];

   //loop to compare all zipCodes to provided name
   for(int i=0; i<MAXSTRUCT; i++){
      //if zipCodes are equal then add to a string var
      //first,last,zip,department,salary
      if(!strcmp(zipCode, emp[i].zipCode)){
         strncat(strZip, emp[i].firstName, strlen(emp[i].firstName));
         strncat(strZip, ",", 1);

         strncat(strZip, emp[i].lastName, strlen(emp[i].lastName));
         strncat(strZip, ",", 1);

         strncat(strZip, emp[i].zipCode, strlen(emp[i].zipCode));
         strncat(strZip, ",", 1);

         strncat(strZip, emp[i].department, strlen(emp[i].department));
         strncat(strZip, ",", 1);

         sprintf(salary, "%d", emp[i].salary);
         strncat(strZip, salary, strlen(salary));
         strncat(strZip, "\n", 1);
      }
   }

   p2 = strZip;
   return p2;
}

//given a salary and comparison operator return all records corresponding with those values
char* SearchBySalary(struct Struct_Employee_Info emp[], int salary, char comparisonOperator[2]){
   //function variables
   int count = 0;
   static char strSal[FILESIZE];
   static char* p3;
   char strSalary[SALARYLIMIT];

   //loop through all comparison operators
   //then loop through all struct rows and compare their salary to provided salary
   //{“>”, “<”,”>=”, “<=”, “==”}
   if(!strcmp(comparisonOperator, ">")){
      for(int i=0; i<MAXSTRUCT; i++){
         if(emp[i].salary > salary && strcmp(emp[i].firstName, "")){
            strncat(strSal, emp[i].firstName, strlen(emp[i].firstName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].lastName, strlen(emp[i].lastName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].zipCode, strlen(emp[i].zipCode));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].department, strlen(emp[i].department));
            strncat(strSal, ",", 1);

            sprintf(strSalary, "%d", emp[i].salary);
            strncat(strSal, strSalary, strlen(strSalary));
            strncat(strSal, "\n", 1);
         }
      }
   }
   else if(!strcmp(comparisonOperator, "<")){
      for(int i=0; i<MAXSTRUCT; i++){
         if(emp[i].salary < salary && strcmp(emp[i].firstName, "")){
            strncat(strSal, emp[i].firstName, strlen(emp[i].firstName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].lastName, strlen(emp[i].lastName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].zipCode, strlen(emp[i].zipCode));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].department, strlen(emp[i].department));
            strncat(strSal, ",", 1);

            sprintf(strSalary, "%d", emp[i].salary);
            strncat(strSal, strSalary, strlen(strSalary));
            strncat(strSal, "\n", 1);
         }
      }
   }
   else if(!strcmp(comparisonOperator, ">=")){
      for(int i=0; i<MAXSTRUCT; i++){
         if(emp[i].salary >= salary && strcmp(emp[i].firstName, "")){
            strncat(strSal, emp[i].firstName, strlen(emp[i].firstName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].lastName, strlen(emp[i].lastName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].zipCode, strlen(emp[i].zipCode));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].department, strlen(emp[i].department));
            strncat(strSal, ",", 1);

            sprintf(strSalary, "%d", emp[i].salary);
            strncat(strSal, strSalary, strlen(strSalary));
            strncat(strSal, "\n", 1);
         }
      }
   }
   else if(!strcmp(comparisonOperator, "<=")){
      for(int i=0; i<MAXSTRUCT; i++){
         if(emp[i].salary <= salary && strcmp(emp[i].firstName, "")){
            strncat(strSal, emp[i].firstName, strlen(emp[i].firstName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].lastName, strlen(emp[i].lastName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].zipCode, strlen(emp[i].zipCode));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].department, strlen(emp[i].department));
            strncat(strSal, ",", 1);

            sprintf(strSalary, "%d", emp[i].salary);
            strncat(strSal, strSalary, strlen(strSalary));
            strncat(strSal, "\n", 1);
         }
      }
   }
   else if(!strcmp(comparisonOperator, "==")){
      for(int i=0; i<MAXSTRUCT; i++){
         if(emp[i].salary == salary && strcmp(emp[i].firstName, "")){
            strncat(strSal, emp[i].firstName, strlen(emp[i].firstName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].lastName, strlen(emp[i].lastName));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].zipCode, strlen(emp[i].zipCode));
            strncat(strSal, ",", 1);

            strncat(strSal, emp[i].department, strlen(emp[i].department));
            strncat(strSal, ",", 1);

            sprintf(strSalary, "%d", emp[i].salary);
            strncat(strSal, strSalary, strlen(strSalary));
            strncat(strSal, "\n", 1);
         }
      }
   }
   else{
      printf("Not a valid Comparison Operator.");
   }


   p3 = strSal;
   return p3;
}
