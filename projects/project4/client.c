

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
        Fgets(buffer, MAXLINE, stdin);
        choice = atoi(buffer);

        //need to send choice to server so it knows what to do
        write(clientfd,buffer,strlen(buffer));
        read(clientfd,buffer,MAXLINE);

        //make a choice based on user input
        //until the user inputs 5
        switch(choice){
            //get record from user and sent to server as a string
            case 1:
                //get first name from user
                bzero(str,MAXLINE);
                bzero(buffer,MAXLINE);
                printf("Enter first name: ");   
                Fgets(str,MAXLINE,stdin);
                strncpy(buffer, str, strlen(str)-1);
                strncat(buffer, ",", 1);
                
                //get last name from user
                bzero(str,MAXLINE);
                printf("Enter last name: ");           
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);
                strncat(buffer, ",", 1);

                //get zip code from user
                printf("Enter Zip Code: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);
                strncat(buffer, ",", 1);
 
                //get department from user
                printf("Enter Department: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);
                strncat(buffer, ",", 1);

                //get salary from user
                printf("Enter Salary: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);

                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                printf("Message from Server:\n");
                //displaying the message in buffer on the console
                Fputs(buffer,stdout);
                break;
            //Search for records by name
            case 2:
                //get first name from user
                bzero(buffer,MAXLINE);
                printf("Enter first name: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncpy(buffer, str, strlen(str)-1);
                strncat(buffer, ",", 1);

                //get last name from user
                printf("Enter last name: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);

                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                printf("Message from Server:\n");
                //displaying the message in buffer on the console
                Fputs(buffer,stdout);
                break;
            //search for records by Zip Code
            case 3:
                //get zip code from user
                bzero(buffer,MAXLINE);
                printf("Enter Zip Code: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);
                
                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                printf("Message from Server:\n");
                //displaying the message in buffer on the console
                Fputs(buffer,stdout);
                break;
            //Search for records comparing salary
            case 4:
                //get salary from user
                bzero(buffer,MAXLINE);
                printf("Enter Salary: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);

                //send amount
                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                read(clientfd,buffer,MAXLINE);
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);   
                
                //get comparision type from user
                printf("Enter Comparision Type [’>’,’<’,’==’,’>=’,’<=’]: ");
                bzero(str,MAXLINE);
                Fgets(str,MAXLINE,stdin);
                strncat(buffer, str, strlen(str)-1);     

                //send comparision type
                //sending the message received from the user to the server
                write(clientfd,buffer,strlen(buffer));
                bzero(buffer,MAXLINE);
                bzero(str,MAXLINE);
                
                //get return message from server that new record was added
                read(clientfd,buffer,MAXLINE);
                printf("Message from Server:\n");
                //displaying the message in buffer on the console
                Fputs(buffer,stdout);
                break;
            //Terminate connection
            case 5:
                //close and exit the client program
                Close(clientfd);
                exit(0);
                break;
            //choice was not valid
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 5);
    
    Close(clientfd);
    return 0;
}