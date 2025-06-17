#include <unistd.h>
#include <stdlib.h>
#define MAX_SENSORS 10
#pragma pack(push, 1)

typedef struct{
    uint16_t ID; // 2 bytes
    uint32_t timestamp; // 4 bytes
    float temperature; // 4 bytes
    uint8_t humidity; // 1 byte
    char airQuality[5]; //5 bytes
} sensorData; // 16 bytes

typedef struct{
    uint16_t ID; // 2 bytes
    uint8_t alertLevel; //1 bytes
    uint32_t timestamp; // 4 bytes
    char alert[9]; //9 bytes
}ALERT; //16 bytes

typedef struct{
    int sockSensorfd;
    struct sockaddr_in address;
    sensorData sensData;
} sensorRegInfo;

#pragma pack(pop)

typedef struct{
    sensorRegInfo * sensors[MAX_SENSORS];
    int count;
    pthread_mutex_t mutex;
} sensorList;