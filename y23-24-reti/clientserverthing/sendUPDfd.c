#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char ** argv){
    int sockfd, n;
    struct sockaddr_in remote_addr;
    char sendline[1000];
    char recvline[1000];
    socklen_t len = sizeof(struct sockaddr_in);

    if(argc != 3){
        printf("Errore! Inserisci IP e port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd<0){
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&remote_addr, 0, len);
    remote_addr.sin_family = AF_INET; //consideriamo ipv4
    inet_pton(AF_INET, argv[1],&(remote_addr.sin_addr)); //convertire in formato rete
    remote_addr.sin_port = htons(aoti(argv[2]));

    while(fgets(sendline, 1000, stdin)!=NULL){ //per scrivere il messaggio e metterlo in sendline
        //per inviare il messaggio
        sendto(sockfd, sendline, strlen(sendline), 0, 
        (struct sockaddr *)&remote_addr, len);
        
        //n restituisce un numero
        n = recvfrom(sockfd, recvline, 999, 0, (struct sockaddr *)&remote_addr, &len);

        // inserire il terminatore di stringa
        recvline[n] = 0;

        printf("IP = %s, P = %d, msg = %s", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), recvline);

        if(strcmp(recvline, "fine\n")){
            break; 
        }
        printf("Fine comunicazione\n");
        close(sockfd);
    }

    return 0;
}