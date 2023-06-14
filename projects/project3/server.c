

#include "csapp.h"


void serverFunction(int connfd){
    char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
    char successMessage[MAXLINE] = "Record added Sucessfully!!\n";
    char firstName[MAXLINE] = "Enter First Name: ";
    char lastName[MAXLINE] = "Enter Last Name: ";
    char zipCode[MAXLINE] = "Enter Zip Code: ";
    char department[MAXLINE] = "Enter Department: ";
    char salary[MAXLINE] = "Enter Salary: ";
    char comparisionType[MAXLINE] = "Enter Comparision Type ['>', '<', '==', '>=', '<=']: ";
    char connectionClosed[MAXLINE] = "Connection Closed!!";
    
    size_t n;
    //resetting the buffer
    bzero(buffer,MAXLINE);
    //n is the user input
    n = read(connfd, buffer, MAXLINE);
    //make a choice based on user input
    switch(n){
        case 1:
            //get first name
            write(connfd,firstName,strlen(firstName));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            /*Still need to add to csv file*/

            //get last name
            write(connfd,lastName,strlen(lastName));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            /*Still need to add to csv file*/

            //get zip code
            write(connfd,zipCode,strlen(zipCode));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            /*Still need to add to csv file*/

            //get department
            write(connfd,department,strlen(department));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            /*Still need to add to csv file*/

            //get salary
            write(connfd,salary,strlen(salary));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            /*Still need to add to csv file*/

            //report success
            write(connfd,successMessage,strlen(successMessage));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);

            break;
        case 2:
            //get first name
            write(connfd,firstName,strlen(firstName));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            
            //get last name
            write(connfd,lastName,strlen(lastName));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);

            /*Still need to search csv file*/
            break;
        case 3:
            //get zip code
            write(connfd,zipCode,strlen(zipCode));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);

            /*Still need to search csv file*/
            break;
        case 4:
            //get salary
            write(connfd,salary,strlen(salary));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            //get comparision type
            write(connfd,comparisionType,strlen(comparisionType));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);

            /*Still need to search csv file*/
            break;
        case 5:
            //send message
            write(connfd,connectionClosed,strlen(connectionClosed));
            bzero(buffer,MAXLINE);
            /*Still need to terminate server*/
            break;
        default:
            break;
    }
    //printf("server received %ld bytes message\n", n);
    //printf("Message from Client: %s\n",buffer);
    //write(connfd,successMessage,strlen(successMessage));

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
