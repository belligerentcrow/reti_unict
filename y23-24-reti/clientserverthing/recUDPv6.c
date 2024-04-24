#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char ** argv){

    int sockfd, n;
    struct sockaddr_in6 local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in6);
    char ipv6_addr[INET6_ADDRSTRLEN];
    char msg[1000];

    if(argc != 2){
        printf("Errore inserisci porta");
        return -1;
    }

    sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
    if (sockfd<0){
        printf("errore nell'apertura di socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin6_family = AF_INET6;
    local_addr.sin6_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&local_addr, len) <0){
        printf("errore nella bind");
        return -1;
    }

    return 0;
}