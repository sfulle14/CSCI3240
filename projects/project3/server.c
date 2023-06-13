

#include "csapp.h"


void serverFunction(int connfd){
    char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
    char successMessage[MAXLINE] = "Record added Sucessfully!!\n";
    char firstName[MAXLINE] = "Enter First Name: ";
    char lastName[MAXLINE] = "Enter Last Name: ";
    char zipCode[MAXLINE] = "Enter Zip Code: ";
    char department[MAXLINE] = "Enter Department: ";
    char salary[MAXLINE] = "Enter Salary: ";
    char department[MAXLINE] = "Enter Department: ";
    
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

            write(connfd,lastName,strlen(lastName));
            bzero(buffer,MAXLINE);
            n = read(connfd, buffer, MAXLINE);

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
    //printf("server received %ld bytes message\n", n);
    //printf("Message from Client: %s\n",buffer);
    write(connfd,successMessage,strlen(successMessage));
    /*TODO:
       1. Add a code to receive new messages from the client
       2. Send the message "I have received your second message" to the client
    */

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
