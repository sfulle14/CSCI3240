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

//function declaration
char* SearchByName(struct Struct_Employee_Info emp[], char Name[NAMELIMIT]);
char* SearchByZipCode(struct Struct_Employee_Info emp[], char zipCode[ZIPLIMIT]);
char* SearchBySalary(struct Struct_Employee_Info emp[], char input[SALARYLIMIT]);



//Given a first and last name find all matching records
char* SearchByName(struct Struct_Employee_Info emp[], char Name[]){
   //function variables
   int count = 0;
   static char str[FILESIZE];
   static char* p;
   char salary[SALARYLIMIT];
   char firstLast[NAMELIMIT*2];

   strcpy(str, "");
   strcpy(firstLast, "");

   //loop to compare all names to provided name
   for(int i=0; i<MAXSTRUCT; i++){
      strncat(firstLast, emp[i].firstName,strlen(emp[i].firstName));
      strncat(firstLast, ",", 1);
      strncat(firstLast, emp[i].lastName, strlen(emp[i].lastName));
      //if names are equal then add to a string var
      //first,last,zip,department,salary
      if(!strcmp(Name, firstLast)){
         strncat(str, emp[i].firstName, strlen(emp[i].firstName));
         strncat(str, ",", 1);
         strncat(str, emp[i].lastName, strlen(emp[i].lastName));
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

   strcpy(strZip,"");

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
char* SearchBySalary(struct Struct_Employee_Info emp[], char input[SALARYLIMIT]){
   //function variables
   int count = 0;
   static char strSal[FILESIZE];
   static char* p3;
   char strSalary[SALARYLIMIT];
   int salary; 
   char comparisonOperator[2];

   sscanf(input, "%d,%[^,]", salary, comparisonOperator);

   strcpy(strSal, "");

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
