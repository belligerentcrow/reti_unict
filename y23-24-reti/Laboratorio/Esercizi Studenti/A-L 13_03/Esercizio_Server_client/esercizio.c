#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct scheda{

    char nome[50];
    char cognome[50];
    int età;


}scheda;

char* concatena(scheda* A){

    int c=0;
    for(int i=0; i<3; i++){
        c+=4;
        c+=strlen(A[i].nome);
        c+=strlen(A[i].nome);
        c+=3;
    }

    char *finale=malloc(c+1);
    char* app=malloc(4);

    for(int i=0; i<3; i++){
        strcat(finale, A[i].nome);
        strcat(finale,",");
        strcat(finale, A[i].cognome);
        strcat(finale, ",");
        sprintf(app, "%d", A[i].età);
        strcat(finale, app);
        strcat(finale, "_");
    }
    return finale;
}

int main(){
/*
    scheda S;
    scanf("%s", S.nome);
    scanf("%s", S.cognome);
    scanf("%d", &S.età);
    printf("%s", S.nome);
    printf("%s", S.cognome);
    printf("%d\n", S.età);*/

    scheda Array[3];
    for(int i=0; i<3; i++){
        printf("inserisci nome: ");
        scanf("%s", Array[i].nome);
        printf("inserisci nome: ");
        scanf("%s", Array[i].cognome);
        printf("inserisci nome: ");
        scanf("%d", &Array[i].età);
    }

    char* tipo=concatena(Array);
    printf("%s", tipo);


}