#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char ** argv){

    int sockfd, n;
    struct sockaddr_in local_addr, remote_addr;
    char sendline[1000];
    char recvline[1000];

    if(argc < 3){
        printf("Errore, inserisci IP e porta");
        return -1;
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //differenza rispetto UDP in SOCK_STREAM
    if(sockfd == 0){
        printf("Errore nella apertura di socket");
        return -1;
    }

    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;

    //altro modo di settare indirizzo IP
    remote_addr.sin_addr.s_addr = inet_addr(argv[1]);
    remote_addr.sin_port = htons(atoi(argv[2]));

    //differenza con UDP
    connect(sockfd, (struct sockaddr * )&remote_addr, sizeof(remote_addr));

    while(fgets(sendline, 999, stdin)!= NULL){
        send(sockfd, sendline, strlen(sendline), 0);
        n = recv(sockfd, recvline, 999, 0); //restituisce numero di byte
        recvline[n]=0;
        printf("IP = %s, P %d, msg = %s\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), recvline);
        if(strcmp(recvline, "fine\n")== 0){
            printf("Fine\n");
            break;
        }
    }

    close(sockfd);

    return 0;
}