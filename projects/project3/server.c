

#include "csapp.h"


#define FILESIZE 1000
#define MAXSTRUCT 10
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
char* SearchBySalary(struct Struct_Employee_Info emp[], int salary, char comparisonOperator[2]);

//function the server will call while interacting with client
void serverFunction(int connfd){
    char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
    char successMessage[MAXLINE] = "Record added Sucessfully!!\n";
    char connectionClosed[MAXLINE] = "Connection Closed!!";
    int choice;
    size_t n;
    FILE *fp;
    char* filename = "records.csv";
    char buf[FILESIZE];
    int count = 0;
    char* searchName;
    char* searchZip;
    char* searchSalary;
    int salary;
    struct Struct_Employee_Info emp[MAXSTRUCT];
    
    //open file
   fp = fopen(filename, "a+");

   //read in the csv into the struct
   while(fgets(buf, FILESIZE, fp) != NULL){
      sscanf(buf, "%[^,],%[^,],%[^,],%[^,] ,%d ", emp[count].firstName, emp[count].lastName, emp[count].zipCode, emp[count].department, &emp[count].salary);
      count++;
   }
   for(int i=count; i<MAXSTRUCT; i++){
      strncpy(emp[i].firstName, "\0", 1);
   }
    

    //resetting the buffer
    bzero(buffer,MAXLINE);

    //n is the user input
    while((n= read(connfd, buffer, MAXLINE)) != 0){
        write(connfd,buffer,strlen(buffer));
        choice = atoi(buffer);
        switch(choice){
            case 1:
                bzero(buffer,MAXLINE);
                n= read(connfd, buffer, MAXLINE);

                sscanf(buffer, "%[^,],%[^,],%[^,],%[^,] ,%d ", emp[count].firstName, emp[count].lastName, emp[count].zipCode, emp[count].department, &emp[count].salary);
                count++;

                fprintf(fp, "%s","\n");
                fprintf(fp, "%s", buffer);

                write(connfd,successMessage,strlen(successMessage));
                bzero(buffer,MAXLINE);
                break;
            case 2:
                bzero(buffer,MAXLINE);
                //get input from client
                n= read(connfd, buffer, MAXLINE);
                 
                //search database(csv)
                searchName = SearchByName(emp, buffer);
                write(connfd,searchName,strlen(searchName));
                bzero(buffer,MAXLINE);
                break;
            case 3:
                bzero(buffer,MAXLINE);
                //get input from client
                n= read(connfd, buffer, MAXLINE);
                
                //search database(csv)
                searchZip = SearchByZipCode(emp, buffer);
                
                //return search to client
                write(connfd,searchZip,strlen(searchZip));
                bzero(buffer,MAXLINE);
                break;
            case 4:
                bzero(buffer,MAXLINE);
                //get salary from client
                n= read(connfd, buffer, MAXLINE);
                salary = atoi(buffer);
                write(connfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);

                //get comparison type
                n= read(connfd, buffer, MAXLINE);
                
                //search database(csv)
                searchSalary = SearchBySalary(emp, salary, buffer);
                
                //return search to client
                write(connfd,searchSalary,strlen(searchSalary));
                bzero(buffer,MAXLINE);
                break;
            case 5:
                bzero(buffer,MAXLINE);
                n= read(connfd, buffer, MAXLINE);
                printf("Message from Client: %s\n",buffer);
                write(connfd,connectionClosed,strlen(connectionClosed));
                bzero(buffer,MAXLINE);
                break;
            default:
                write(connfd,buffer,strlen(buffer));
                break;
        }
    }
    fclose(fp);
    return; 
}

int main(int argc, char *argv[])
{
    int listenfd;
    int connfd; //file descriptor to communicate with the client
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;  /* Enough space for any address */
    char client_hostname[MAXLINE], client_port[MAXLINE];
    

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    
    listenfd = Open_listenfd(argv[1]);
    //Server runs in the infinite loop.
    //To stop the server process, it needs to be killed using the Ctrl+C key.
    while (1) {
        clientlen = sizeof(struct sockaddr_storage);
        // wait for the connection from the client.
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname,
                                   MAXLINE,client_port, MAXLINE, 0);
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
        //function to interact with the client
        serverFunction(connfd);
        Close(connfd);
        printf("(%s, %s) disconnected\n", client_hostname, client_port);
    }

    exit(0); 
}


//Given a first and last name find all matching records
char* SearchByName(struct Struct_Employee_Info emp[], char Name[]){
   //function variables
   int count = 0;
   static char str[FILESIZE]="\0";
   static char* p;
   char salary[SALARYLIMIT];
   char firstLast[NAMELIMIT*2];
   char noRecord[MAXLINE] = "No record found!!\n";
    
   strncpy(str, "",FILESIZE);
   strcpy(firstLast, "");

   //loop to compare all names to provided name
   for(int i=0; i<MAXSTRUCT; i++){
      strcpy(firstLast, "");
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
   if(strlen(str)==0){
      strncpy(str,noRecord,strlen(noRecord));
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
   char noRecord[MAXLINE] = "No record found!!\n";
    
   strncpy(strZip,"",FILESIZE);

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
   if(strlen(strZip)==0){
      strncpy(strZip,noRecord,strlen(noRecord));
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
   char noRecord[MAXLINE] = "No record found!!\n";
    
   strncpy(strSal, "",FILESIZE);

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
   if(strlen(strSal)==0){
      strncpy(strSal,noRecord,strlen(noRecord));
   }


   p3 = strSal;
   return p3;
}
