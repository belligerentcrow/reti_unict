#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main(int argc, char ** argv){
    int sockfd;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[100];

    if(argc <2){
        printf("Errore! Inserisci il numero di port\n");
        return -1;
    }

    //famiglia, tipo, 0
    sockfd = socket(AF_INET,SOCK_DGRAM, 0);

    if (sockfd < 0){
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    //settare a 0 solo localaddr perche' remote addr verranno sovrascritti quando riceveremo informazioni quindi non serve resettare
    memset(&local_addr, 0, len);

    local_addr.sin_family = AF_INET;

    //local_addr.sin_addr = htonl(INADDR_ANY); <<--  non lo usiamo perche' potrebbe creare conflitti

    local_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &local_addr, len)<0){
        printf("Errore: Inserisci un numero di porta differente");
        return -1;
    }

    for(;;){

        //BLOCCANTE!
        recvfrom(sockfd, buffer, 99, 0, (struct sockaddr *) &remote_addr, &len );

        //mandiamo informazione
        printf("IP= %s, port=%d, MSG=%s\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port), buffer);
    }

    close(sockfd);

    return 0; 
}