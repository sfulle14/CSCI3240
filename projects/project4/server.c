

#include "csapp.h"

//define constants
#define FILESIZE 1000
#define MAXSTRUCT 10
#define NAMELIMIT 100
#define ZIPLIMIT 6
#define DEPTLIMIT 100
#define SALARYLIMIT 10

//Define struct globally
struct Struct_Employee_Info{
   char firstName[NAMELIMIT];
   char lastName[NAMELIMIT];
   char zipCode[ZIPLIMIT];
   char department[DEPTLIMIT];
   int salary;
};

//define global variables
struct Struct_Employee_Info emp[MAXSTRUCT];
int readcnt=0;
sem_t mutex, w;


//function declaration
char* SearchByName(struct Struct_Employee_Info emp[], char Name[NAMELIMIT]);
char* SearchByZipCode(struct Struct_Employee_Info emp[], char zipCode[ZIPLIMIT]);
char* SearchBySalary(struct Struct_Employee_Info emp[], int salary, char comparisonOperator[2]);
void serverFunction(int connfd);
void *thread(void *vargp);


int main(int argc, char *argv[]){
    int listenfd;
    int *connfdp; //file descriptor to communicate with the client
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;  /* Enough space for any address */
    char client_hostname[MAXLINE], client_port[MAXLINE];
    pthread_t tid;
    
    sem_init(&mutex,0,1);
    sem_init(&w, 0, 1);
    
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
        connfdp = Malloc(sizeof(int));
        *connfdp = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname,
                                   MAXLINE,client_port, MAXLINE, 0);
        Pthread_create(&tid, NULL, thread, connfdp);
        printf("Connected to (%s, %s)\n", client_hostname, client_port);
    }

    exit(0); 
}

//function the server will call while interacting with client
void serverFunction(int connfd){
   //define local variables
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
    
    
   //open file
   fp = fopen(filename, "a+");

   //read in the csv into the struct
   while(fgets(buf, FILESIZE, fp) != NULL){
      sscanf(buf, "%[^,],%[^,],%[^,],%[^,] ,%d ", emp[count].firstName, emp[count].lastName, emp[count].zipCode, emp[count].department, &emp[count].salary);
      count++;
   }
   //fill out the rest of the struct as NULL
   for(int i=count; i<MAXSTRUCT; i++){
      strncpy(emp[i].firstName, "\0", 1);
   }
    

    //resetting the buffer
    bzero(buffer,MAXLINE);

    //n is the user input
    while((n= read(connfd, buffer, MAXLINE)) != 0){
        //get user choice
        write(connfd,buffer,strlen(buffer));
        //convert user choice to an integer from char
        choice = atoi(buffer);

        //pick an action based on the users choice
        switch(choice){
            case 1:
                P(&w);
                //reset buffer
                bzero(buffer,MAXLINE);
                //read in data from client
                n= read(connfd, buffer, MAXLINE);
                
                //add record to emp struct
                sscanf(buffer, "%[^,],%[^,],%[^,],%[^,] ,%d ", emp[count].firstName, emp[count].lastName, emp[count].zipCode, emp[count].department, &emp[count].salary);
                //increase the count of records
                count++;

                //add the record to the csv file
                fprintf(fp, "%s","\n");
                fprintf(fp, "%s", buffer);
                //close file pointer so data is written
                fclose(fp);
                //reopen file pointer
                fp = fopen(filename, "a+");
                
                //write back to client
                write(connfd,successMessage,strlen(successMessage));
                //reset buffer
                bzero(buffer,MAXLINE);
                V(&w);
                break;
            case 2:
                P(&mutex);
                readcnt++;
                if(readcnt==1){
                    P(&w);
                }
                V(&mutex);
                
                //reset buffer
                bzero(buffer,MAXLINE);
                //read in data from client
                n= read(connfd, buffer, MAXLINE);
                
                //search database(csv)
                searchName = SearchByName(emp, buffer);
                
                //write back to client
                write(connfd,searchName,strlen(searchName));
                //reset buffer
                bzero(buffer,MAXLINE);
                
                P(&mutex);
                readcnt--;
                if(readcnt==0){
                    V(&w);
                }
                V(&mutex);
                break;
            case 3:
                P(&mutex);
                readcnt++;
                if(readcnt==1){
                    P(&w);
                }
                V(&mutex);
                
                //reset buffer
                bzero(buffer,MAXLINE);
                //read in data from client
                n= read(connfd, buffer, MAXLINE);
                     
                //search database(csv)
                searchZip = SearchByZipCode(emp, buffer);
                
                //return search to client
                write(connfd,searchZip,strlen(searchZip));
                //reset buffer
                bzero(buffer,MAXLINE);
                
                P(&mutex);
                readcnt--;
                if(readcnt==0){
                    V(&w);
                }
                V(&mutex);
                break;
            case 4:
                P(&mutex);
                readcnt++;
                if(readcnt==1){
                    P(&w);
                }
                V(&mutex);
                
                //reset buffer
                bzero(buffer,MAXLINE);
                //read in data from client
                n= read(connfd, buffer, MAXLINE);
                //convert input from char to int
                salary = atoi(buffer);
                //write back to client
                write(connfd,buffer,strlen(buffer));
                //reset buffer
                bzero(buffer,MAXLINE);
                //read in data from client
                n= read(connfd, buffer, MAXLINE);
                
                
                //search database(csv)
                searchSalary = SearchBySalary(emp, salary, buffer);
                
                //return search to client
                write(connfd,searchSalary,strlen(searchSalary));
                //reset buffer
                bzero(buffer,MAXLINE);
                
                P(&mutex);
                readcnt--;
                if(readcnt==0){
                    V(&w);
                }
                V(&mutex);
                break;
            case 5:
                //reset buffer
                bzero(buffer,MAXLINE);
                //read in data from client
                n= read(connfd, buffer, MAXLINE);
                //write back to client
                write(connfd,connectionClosed,strlen(connectionClosed));
                //reset buffer
                bzero(buffer,MAXLINE);
                break;
            default:
                write(connfd,buffer,strlen(buffer));
                break;
        }
    }
    //close the file pointer
    fclose(fp);
    return; 
}


//Given a first and last name find all matching records
char* SearchByName(struct Struct_Employee_Info emp[], char Name[NAMELIMIT]){
   //function variables
   static char str[FILESIZE]="\0";
   static char* p;
   char salary[SALARYLIMIT];
   char firstLast[NAMELIMIT*2];
   char noRecord[MAXLINE] = "No record found!!\n";
    
   //clearing the strings 
   strncpy(str, "",FILESIZE);
   strcpy(firstLast, "");

   //loop to compare all names to provided name
   for(int i=0; i<MAXSTRUCT; i++){
      //combining the name to compare in the loop
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
   //if string is empty return noRecord message
   if(strlen(str)==0){
      strncpy(str,noRecord,strlen(noRecord));
   }
   //setting the string to a char* so it can be returned
   p = str;
   return p;
}


//Given a zipCode find all records with that zipCode
char* SearchByZipCode(struct Struct_Employee_Info emp[], char zipCode[ZIPLIMIT]){
   //function variables
   static char strZip[FILESIZE];
   static char* p2;
   char salary[SALARYLIMIT];
   char noRecord[MAXLINE] = "No record found!!\n";
    
   //clearing the string of all values 
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
   //if string is empty return noRecord message
   if(strlen(strZip)==0){
      strncpy(strZip,noRecord,strlen(noRecord));
   }

   //setting the string to a char* so it can be returned
   p2 = strZip;
   return p2;
}


//given a salary and comparison operator return all records corresponding with those values
char* SearchBySalary(struct Struct_Employee_Info emp[], int salary, char comparisonOperator[2]){
   //function variables
   static char strSal[FILESIZE];
   static char* p3;
   char strSalary[SALARYLIMIT];
   char noRecord[MAXLINE] = "No record found!!\n";
    
   //clearing the string of all data 
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
   //if string is empty return noRecord message
   if(strlen(strSal)==0){
      strncpy(strSal,noRecord,strlen(noRecord));
   }

   //setting the string to a char* so it can be returned
   p3 = strSal;
   return p3;
}

/*Thread routine*/
void *thread(void *vargp){
    int connfd = *((int *)vargp);
    Pthread_detach(pthread_self());
    Free(vargp);
    
    //function to interact with the client
    serverFunction(connfd);
    Close(connfd);    
    return NULL;
}