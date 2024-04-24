#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char **argv){
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if (argc != 2){
        printf("Errore nell'apertura di socket");
        return -1;
    }
    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr * )&local_addr, len)<0){
        printf("Errore! Inserisci un numero diverso di porta");
        return -1;
    }

    for(;;){
        int n = recvfrom(sockfd, msg, 999, 0, (struct sockaddr *)&remote_addr, &len);
        msg[n] = 0;
        sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *) &remote_addr, len);
        printf("IP = %s, P = %d, msg = %s", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), recvline);

    }

    return 0;
}