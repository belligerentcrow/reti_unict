#include <netinet/in.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char ** argv){
    int sockfd, newsockfd, n;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if(argc !=2){
        printf("Errore, inserisci numero di porta");
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
        printf("Errore nella apertura della socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = ntohl(INADDR_ANY); //metti come indirizzo IP quello locale della macchina
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr *)&local_addr, len)<0){
        printf("Errore nella bind");
        return -1;
    }

    listen(sockfd, 5);

    for(;;){
        newsockfd = accept(sockfd, (struct sockaddr *)&remote_addr, &len);

        //sockfd newsockfd
        if(fork()==0){
            close(sockfd);

            for(;;){
                n = recv(newsockfd, msg, 999, 0);
                msg[n] = 0;

                printf("IP = %s, P %d, msg = %s\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), msg);

                send(newsockfd, msg, n, 0);
                if(strcmp(msg, "fine\n") ==0){
                    printf("fine della connessione\n");
                    break;
                }
            }
            //si chiude solo il figlio 
            close(newsockfd);
            return 0;

        }else{
            close(newsockfd);



        }


    }

    
    
    return 0;
}