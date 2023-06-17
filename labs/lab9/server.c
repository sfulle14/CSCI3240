#include "csapp.h"
void serverFunction(int connfd){
   char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
   char successMessage[MAXLINE] = "I got your message\n";
   char secoundMessage[MAXLINE] = "I have received your second message";
   //TODO:
   //Add second message here
   //TODO End
   size_t n;
   //resetting the buffer
   bzero(buffer,MAXLINE);
   n = read(connfd, buffer, MAXLINE);
   printf("server received %ld bytes message\n", n);
   printf("Message from Client: %s\n",buffer);
   write(connfd,successMessage,strlen(successMessage));
   /*TODO:
       1. Add a code to receive new messages from the client
       2. Send the message "I have received your second message" to the client
   */
   bzero(buffer,MAXLINE);
   n = read(connfd, buffer, MAXLINE);
   write(connfd,secoundMessage,strlen(secoundMessage));

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