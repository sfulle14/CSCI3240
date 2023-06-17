

#include "csapp.h"


int main(int argc, char *argv[])
{
    int clientfd;  //file descriptor to communicate with the server
    char *host, *port;
    size_t n;
    char buffer[MAXLINE]; //MAXLINE = 8192 defined in csapp.h
    char str[MAXLINE];
    int choice;
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
       exit(0);
    }

    host = argv[1];
    port = argv[2];
    clientfd = Open_clientfd(host, port);

    

    //resetting the buffer
    bzero(buffer,MAXLINE);
    //entering loop until disconnect
    do{
        //print out user options
        printf("(1) Add record\n");
        printf("(2) Search by Name\n");
        printf("(3) Search by Zip Code\n");
        printf("(4) Search by Salary\n");
        printf("(5) Terminate\n");
        printf("Select an option [1,2,3,4, or 5]: ");

        //get choice from user
        Fgets(str, MAXLINE, stdin);
        choice = atoi(str);

        //make a choice based on user input
        switch(choice){
            //get record from user and sent to server as a string
            case 1:
                bzero(str,MAXLINE);
                bzero(buffer,MAXLINE);
                printf("Enter first name: ");   
                Fgets(str,MAXLINE,stdin);
                strncpy(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                bzero(str,MAXLINE);
                printf("Enter last name: ");           
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                printf("Enter Zip Code: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                printf("Enter Department: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                printf("Enter Salary: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));

                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                break;
            case 2:
                printf("Enter first name: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncpy(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                printf("Enter last name: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                break;
            case 3:
                printf("Enter Zip Code: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));
                strncat(buffer, ",", 1);

                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                break;
            case 4:
                printf("Enter Salary: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str));

                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                break;
            case 5:
                Close(clientfd);
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 5);
    


    Close(clientfd);
    return 0;
}