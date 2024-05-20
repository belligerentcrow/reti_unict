#include <netinet/in.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
//#include <Winsock2.h>
#include <arpa/inet.h>

int main(int argc, char ** argv){

    int sockfd, newsockfd, n;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t lenghtt = sizeof(struct sockaddr_in);
    char message[1000];

    if(argc != 2){
        printf("Error! Insert port number.\n");
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Errore nell'apertura della socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = ntohl(INADDR_ANY);
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr *)&local_addr, lenghtt)<0){
        printf("Errore nella Bind");
        return -1;
    }

    listen(sockfd, 5);

    for(;;){
        newsockfd = accept(sockfd, (struct sockaddr *)&remote_addr, &lenghtt);

        //sockfd newsockfd
        if(fork()==0){
            close(sockfd);

            for(;;){
                n = recv(newsockfd,message,999,0);
                message[n]=0;
                


            }

        }else{
            close(newsockfd);
        }


    }

}