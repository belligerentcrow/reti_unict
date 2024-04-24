#include <netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char ** argv){
    int sockfd, n;
    struct sockaddr_in6 remote_addr;
    socklen_t len = sizeof(struct sockaddr_in6);
    char sendline[1000];
    char recvline[1000];
    char ipv6_addr[INET6_ADDRSTRLEN];

    if(argc != 3){
        printf("Errore inserisci ip e porta");
        return -1;
    }

    sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
    if (sockfd<0){
        printf("Errore nell'apertura di socket");
        return -1; 
    }
    
    memset(&remote_addr, 0, len);
    remote_addr.sin6_family = AF_INET6;
    inet_pton(AF_INET6, argv[1], &(remote_addr.sin6_addr));
    remote_addr.sin6_port = htons(atoi(argv[2]));

    while(fgets(sendline, 1000, stdin), != NULL){
        sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&remote_addr, len);
        n = recvfrom(sockfd, recvline, 999, 0, (struct sockaddr *) &remote_addr, &len);
        recvline[n] = 0;
        inet_ntop(AF_INET6, &(remote_adr.sin6_addr), ipv6_addr, INET6_ADDRSTRLEN);

        printf("IP = %s, P = %d, msg = %s", ipv6_addr, ntohs(remote_addr.sin6_port), recvline);

        if (strcmp(recvline, "fine\n")==0){
            break;
        }
    }

    return 0;
}