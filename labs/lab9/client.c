#include "csapp.h"

int main(int argc, char *argv[])
{
    int clientfd;  //file descriptor to communicate with the server
    char *host, *port;
    size_t n;
    char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];
    clientfd = Open_clientfd(host, port);
    
    rio_t rio;
    
    //getting a message from the user
    printf("Please enter the message: ");
    //resetting the buffer
    bzero(buffer,MAXLINE);
    //getting the message from the user
    Fgets(buffer,MAXLINE,stdin);
    //sending the message received from the user to the server
    write(clientfd,buffer,strlen(buffer));
    bzero(buffer,MAXLINE);
    //waiting for the message from the server.
    //the message will be stored in buffer variable.
    read(clientfd,buffer,MAXLINE);
    printf("Message from Server:");
    //displaying the message in buffer on the console
    Fputs(buffer,stdout);

    /*TODO
        1. Add a code to send new messages to the server
           (you can ask the user to provide a new message in the terminal)
        2. Wait for the confirmation message (using Rio_readlineb function)
             from the server and display it.
    */
    printf("Enter a 2nd message: ");
    //resetting the buffer
    bzero(buffer,MAXLINE);
    //getting the message from the user
    Fgets(buffer,MAXLINE,stdin);
    //sending the message received from the user to the server
    write(clientfd,buffer,strlen(buffer));
    bzero(buffer,MAXLINE);
    //waiting for the message from the server.
    //the message will be stored in buffer variable.
    Rio_readlineb(&rio,buffer,MAXLINE);
    printf("Message from Server:");
    //displaying the message in buffer on the console
    Fputs(buffer,stdout);
    //read(clientfd,buffer,MAXLINE);
    

    Close(clientfd);
    return 0;
}