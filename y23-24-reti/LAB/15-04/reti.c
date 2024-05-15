#include <stdio.h>
#include <stdlib.h>
#include "arpa/inet.h"
#include <string.h>

// Esame del 30 gennaio 2024 

//Step 1: Anche solo una macchina per ogni lan inizialmente
//Step 2: Progettare Caffe' DMI tramite Socket TCP.  

//Dividere il range IP --> Carta e penna  

//Gli indirizzi IP -v4 da utilizzare sono nel range 162.46.0.0/16  

/*

Calcolo suddivisione indirizzi IP (grazie ali.b.<3)

LAN 3 Server: chiede almeno 500 indirizzi, maschera /23, quindi 512
da 162.46.2.0 a 162.46.3.255
da 10100010.00101110.00000010.00000000 a 10100010.00101110.00000011.11111111

LAN 1 Client: chiede almeno 200 indirizzi, maschera /24 quindi 255
da 162.46.1.0 a 162.46.1.255
da 10100010.00101110.00000001.00000000 a 10100010.00101110.00000001.11111111

LAN 2 Client: chiede almeno 100 indirizzi, maschera /25 quindi 127
da 162.46.0.128 a 162.46.0.255
da 10100010.00101110.00000000.10000000 a 10100010.00101110.00000000.11111111

LAN 3 Client: chiede almeno 50 indirizzi, maschera /26 quindi 63
da 162.46.0.64. a 162.46.0.127
da 10100010.00101110.00000000.01000000 a 10100010.00101110.00000000.01111111

*/


int main(){

}