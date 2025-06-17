#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "structures.h"

#define MAX_SENSORS 10

typedef struct{
    int sockTCP;
    int sockUDP;
    struct sockaddr_in serv_address;
    bool alertStatus;
    sensorData localStatus;
    pthread_mutex_t statusMutex;
    pthread_mutex_t tcpMutex;
} clientData;

void sendAlert(clientData * c){ // TCP
    ALERT sendAl;
    memset(&sendAl, 0, sizeof(sendAl));
    sendAl.ID = c->localStatus.ID;
    sendAl.alertLevel = 10;
    sendAl.timestamp = time(NULL);
    strcpy(sendAl.alert, "BIGFIRE!");
    pthread_mutex_lock(&c->tcpMutex);
    send(c->sockTCP, &sendAl, sizeof(sendAl), 0);
    pthread_mutex_unlock(&c->tcpMutex);
    return;
}

void * generateSensorData(void * args){
    clientData * sensData = (clientData *)args;
    while(true){
        pthread_mutex_lock(&sensData->statusMutex);
        if(sensData->alertStatus == false){
            pthread_mutex_unlock(&sensData->statusMutex);
            sleep(3);
            continue;
        }
        pthread_mutex_unlock(&sensData->statusMutex);
        printf("[generateSensorData] Clear to generate!\n");
        pthread_mutex_lock(&sensData->statusMutex);
        sensData->localStatus.timestamp = time(NULL);
        sensData->localStatus.temperature = ((rand()%42)+15)*1.0;
        sensData->localStatus.humidity = rand()%255;
        int qual = (rand()%100)+1;
        if(qual>50){
            strcpy(sensData->localStatus.airQuality, "good");
        }else{
            strcpy(sensData->localStatus.airQuality, "bad!");
        }
        if((sensData->localStatus.temperature)>40){
            sendAlert(sensData);
        }
        pthread_mutex_unlock(&sensData->statusMutex);
        sleep(3);
    }
}

bool registerToServer(clientData * c, int sockfd, struct sockaddr_in sockaddrServ){ //TCP
    pthread_mutex_lock(&c->statusMutex);
    clientData data = *c;
    if(send(sockfd, &data.localStatus, sizeof(data.localStatus), 0)<0){
        perror("Send Init Error");
        close(sockfd);
        return false;
    }
    pthread_mutex_unlock(&c->statusMutex);
    return true;
}

void * sendingData(void * args){ //UDP
    clientData * c = (clientData *)args;
    while(true){
        pthread_mutex_lock(&c->statusMutex);
        if(c->alertStatus ==true){
            pthread_mutex_unlock(&c->statusMutex);
            sleep(3);
            continue;
        }
        pthread_mutex_unlock(&c->statusMutex);
        printf("[sendingData] Clear to send!\n");
        pthread_mutex_lock(&c->statusMutex);
        sensorData dataToSend = c->localStatus;
        sendto(c->sockUDP, &dataToSend, sizeof(dataToSend), 0, (struct sockaddr *)&c->serv_address, sizeof(c->serv_address));
        pthread_mutex_unlock(&c->statusMutex);
    }
}

void * receiveCommand(void * args){ //TCP
    clientData * c = (clientData * )args;
    ALERT al;
    memset(&al, 0, sizeof(al));
    while(true){
        pthread_mutex_lock(&c->tcpMutex);
        ssize_t bytesReceived = recv(c->sockTCP, &al, sizeof(al), 0);
        pthread_mutex_unlock(&c->tcpMutex);
        printf("[RECEIVE_COMMAND] COMMAND RECEIVED\n");
        if((strcmp(al.alert, "ClearToS"))==0){
            printf("[RECEIVE_COMMAND] CLEAR RECEIVED!\n");
            pthread_mutex_lock(&c->statusMutex);
            c->alertStatus=false;
            pthread_mutex_unlock(&c->statusMutex);
        }else if((strcmp(al.alert, "HaltSend"))==0){
            printf("[RECEIVE_COMMAND] HALT RECEIVED!\n");
            pthread_mutex_lock(&c->statusMutex);
            c->alertStatus=true;
            pthread_mutex_unlock(&c->statusMutex);
        }
    }
}

int main(int argc, char argv[]){
    if(argc!=3){
        printf("Usage: %s <IP> <PORT> \n",argv[0]);
        perror("wrong usage");
        exit(EXIT_FAILURE);
    }
    srand(time(0));
    int sockTCPfd, sockUDPfd;
    struct sockaddr_in servAddr;
    bool regist = false; 
    socklen_t socklen;
    uint16_t sensID = rand()%65535+1;

    if((sockTCPfd = socket(AF_INET, SOCK_STREAM,0))<0){
        perror("TCP socket opening");
        exit(EXIT_FAILURE);
    }
    if((sockUDPfd = socket(AF_INET, SOCK_DGRAM, 0))<0){
        perror("UDP socket opening");
        exit(EXIT_FAILURE);
    }
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(atoi(argv[2]));
    servAddr.sin_addr.s_addr = inet_addr(argv[1]);
    if(connect(sockTCPfd, (struct sockaddr*)&servAddr, sizeof(servAddr))<0){
        perror("connectError");
        exit(EXIT_FAILURE);
    }
    printf("[MAIN] connected!\n");

    
    sensorData sensStatus = {.ID = sensID, .timestamp = time(NULL)};
    clientData cData = {.localStatus=sensStatus, .alertStatus=false};
    pthread_t sensDataThread, sensorSend, sensorReceive;

    clientData * datapointer = &cData;
    pthread_mutex_init(&cData.statusMutex, NULL);
    pthread_mutex_init(&cData.tcpMutex, NULL);
    pthread_create(&sensDataThread, NULL, generateSensorData, datapointer);
    pthread_detach(sensDataThread);
    regist = registerToServer(datapointer, sockTCPfd, servAddr);
    if(regist==false){
        perror("REGISTRATON FAILED");
        close(sockTCPfd);
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&cData.statusMutex);
    cData.sockTCP = sockTCPfd;
    pthread_mutex_unlock(&cData.statusMutex);
    printf("Registered with the server!\n");
    
    if((sockUDPfd =socket(AF_INET, SOCK_DGRAM, 0))<0){
        perror("UDP socket creation failed");
        close(sockTCPfd);
        close(sockUDPfd);
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&cData.statusMutex);
    cData.sockUDP = sockUDPfd;
    cData.serv_address = servAddr;
    pthread_mutex_unlock(&cData.statusMutex);
    
    pthread_create(&sensorSend, NULL, sendingData, datapointer);
    pthread_create(&sensorReceive, NULL, receiveCommand, datapointer);

    pthread_join(sensorSend, NULL);
    pthread_join(sensorReceive, NULL);

}