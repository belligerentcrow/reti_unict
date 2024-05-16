#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main(int argc, char **argv){

    int sockfd, n;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if(argc < 2){
        printf("Errore! Inserisci numero Port\n");
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Errore nell'apertura di socket!\n");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr *)&local_addr, len) < 0){
        printf("Errore nell'apertura di bind\n");
        return -1;
    }

    for(;;){
        n = recvfrom(sockfd, msg, 999, 0, (struct sockaddr *)&remote_addr, &len);
        msg[n] = 0;
        printf("IP = %s, Port = %d, MSG = %s\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), msg);
        sendto(sockfd, msg, n, 0, (struct sockaddr *)&remote_addr, len);
        if(strcmp(msg, "fine\n") == 0){
            printf("FINE\n");
            break;
        }
    }
    
    close(sockfd);

    return 0;
}