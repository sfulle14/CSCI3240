

#include "csapp.h"


void serverFunction(int connfd){
    char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
    char successMessage[MAXLINE] = "Record added Sucessfully!!\n";
    char connectionClosed[MAXLINE] = "Connection Closed!!";
    
    size_t n;
    //resetting the buffer
    bzero(buffer,MAXLINE);
    //n is the user input
    while((n= read(connfd, buffer, MAXLINE)) != 0){
        printf("server received %ld bytes message\n", n);
        printf("Message from Client: %s\n",buffer);
        write(connfd,successMessage,strlen(successMessage));
        bzero(buffer,MAXLINE);
    }
    
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
