#include <netinet/in.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <arpa/inet.h> //libreria per le socket e tutto 
#include <sys/socket.h>


int main (int argc, char **argv){

    int sockfd;
    struct sockaddr_in dest_addr; //prendera' in input porta
    char buffer[100]; //buffer di memoria

    //informazione a linea di comando. Gestione errori con semplice if per ora.  
    if(argc < 3){
        printf("Errore! Inserisci IP e port\n");
        return -1;
    }


    //sinonimo di quello di giu':
    // if((sockfd = socket(PF_INET, SOCK_DGRAM, 0))<0);  //parentesi necessarie
    //PF INET e' una macro di Socket -- SOCKDGRAM e' UDP -- protocol 0 perche' lo capisce da solo
    sockfd = socket(PF_INET,SOCK_DGRAM,0);
    if(sockfd <0){
        printf("Errore nell'apertura di socket\n");
        return -1;
    }

    //dobbiamo settare tutto questo ?? a zero perche' non sappiamo se in quella area di memoria ci sia 0
    //se punta in aree di memoria piene potrebbero esserci problemi. Prende in input la variabile da azzerare,
    // il valore da azzerare, e la dimensione (quanto) azzerare. Per evitare problemi  
    memset(&dest_addr, 0, sizeof(dest_addr));

    //settare 4 parametri. 
    dest_addr.sin_family = AF_INET;

    //prendiamo l'indirizzo IP e lo trasformiamo in ?? leggibile per la macchina. per questo usiamo la funzione inet_pton
    //dal formato stringa lo trasforma al formato network e lo memorizza ?? 
    inet_pton(AF_INET, argv[1],&(dest_addr.sin_addr));

    //indirizzo di destinazione -->
    //convertire da string ad intero la stringa che abbiamo messo in input
    dest_addr.sin_port = htons(atoi(argv[2]));


    //dobbiamo fare questa parte al lab --v  e non quella sopra!!! Ci sara' gia' al lab esame
    //stiamo mandando al server un buffer con dei numeri da 0 a 10

    for(int i = 0; i<10;i++){
        //mettiamo i numeri nel buffer
        sprintf(buffer, "%d",i);
        // vuole gli argomenti ... dest_addr dobbiamo castarlo !! 
        // il cast va da sockaddr_in a sockaddr. 
        sendto(sockfd, buffer, sizeof(buffer)+1, 0, (struct sockaddr *) & dest_addr, sizeof(dest_addr)); 
    }

    close(sockfd);

    return 0; 
}