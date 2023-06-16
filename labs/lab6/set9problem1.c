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
   char* ch;

   struct Struct_Employee_Info emp[MAXSTRUCT];

   //open file
   fp = fopen(filename, "r+");

   //read in the csv into the struct
   while(fgets(buf, FILESIZE, fp) != NULL){
      sscanf(buf, "%[^,],%[^,],%[^,],%[^,] ,%d ", emp[count].firstName, emp[count].lastName, emp[count].zipCode, emp[count].department, &emp[count].salary);
      count++;
   }

   printf("%s %s %s %s %d\n", emp[0].firstName, emp[0].lastName, emp[0].zipCode, emp[0].department, emp[0].salary);

   ch = SearchByName(emp, "Pablo", "Picasso");
   printf("%s\n", ch);
   
   fclose(fp);
   return 0;
}

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

   printf("%s\n", str);

   p = str;
   return p;
}

/*
int SearchByZipCode(struct Struct_Employee_Info employeeStructure, char zipCode[ZIPLIMIT]){

   return 0;
}

int SearchBySalary(struct Struct_Employee_Info employeeStructure, int salary, char comparisonOperator[2]){


   return 0;
}
*/