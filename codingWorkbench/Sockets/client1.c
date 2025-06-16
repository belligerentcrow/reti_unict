#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){
    int s, numBytes;
    struct sockaddr_in sa;
    char buffer [BUFSIZ+1];
    if((s=socket(PF_INET,SOCK_STREAM,0))<0){
        perror("socket");
        return 1;
    }
    memset(&sa, '\0', sizeof(sa));

    sa.sin_family = AF_INET;
    sa.sin_port = htons(13);
    sa.sin_addr.s_saddr = inet_addr("10.0.0.2");
    if(connect(s, (struct sockaddr *)&sa, sizeof sa)<0){
        perror("connect");
        close(s);
        return 2;
    }
    while((numBytes = read(s,buffer,BUFSIZ))>0){
        write(1, buffer, numBytes);
    }
    close(s);
    return 0;
}
