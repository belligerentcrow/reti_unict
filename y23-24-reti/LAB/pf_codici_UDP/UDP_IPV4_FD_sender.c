#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc, char **argv){

    int sockfd, n;
    struct sockaddr_in remote_addr;
    char sendline[1000];
    char recline[1000];
    socklen_t len = sizeof(struct sockaddr_in);

    if(argc != 3){
        printf("Errore! Inserisci IP e port\n");
        return -1;
    }

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    memset(&remote_addr, 0, len);
    remote_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(remote_addr.sin_addr));
    remote_addr.sin_port = htons(atoi(argv[2]));

    while(fgets(sendline, 1000, stdin) != NULL){
        sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&remote_addr, len);
        n = recvfrom(sockfd, recline, 999, 0, (struct sockaddr *)&remote_addr, &len);
        recline[n] = 0;
        printf("IP = %s, Port = %d, MSG = %s\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), recline);

        if(strcmp(recline, "fine\n") == 0){
            printf("FINE\n");
            break;
        }

    }

    close(sockfd);

    return 0;
}