#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "server.h"

int main(){

    FILE* fp=fopen("operazioni.txt", "w");
    int x;
    char* nome=malloc(sizeof(char));
    char* pass=malloc(sizeof(char));
    //Interfacccia Client
    do{
        //registrazione al server
        printf("scegliere un operazione:\n -1 (Accesso)\n -2 (Registrazione)\n");
        scanf("%d", &x);
        if(x<0 || x>2){
            printf("scegliere un nuemro tra 1 e 2");
        }
        if(x==1){
            //accesso al server
            fprintf(fp, "%d\n", x);
            printf("Inserire nomeUtente: ");
            scanf("%s", nome);
            printf("inserire password: ");
            scanf("%s", pass);
            fprintf(fp, "%s\n", nome);
            fprintf(fp, "%s\n", pass);
            fclose(fp);
            esecuzione();
            printf("Scegliere un operazione: -3 (modifica Password) -4 (modifica nomeUtente)\n");
            scanf("%d", &x);
            
        }
    }while(x==0 || x>4);


    //variabili per la registrazione
    if(x==2){
        fprintf(fp,"%d\n",x);
        char* nome=malloc(sizeof(char));
        char* pass=malloc(sizeof(char));
        printf("inserire nome: ");
        scanf("%s", nome);
        printf("inserire Password: ");
        scanf("%s", pass);

        fopen("operazioni.txt", "w");
        fprintf(fp, "%s\n", nome);
        fprintf(fp, "%s\n", pass);

        fclose(fp);
        esecuzione();

    }

    //variabili modifica Nome
    if(x==4){
        FILE* fp2=fopen("operazioni.txt", "w");
        fprintf(fp2,"%d\n",x);
        char* Vnome=malloc(sizeof(char));
        char* Nnome=malloc(sizeof(char));

        printf("inserire Vecchio nomeUtente: ");
        scanf("%s", Vnome);
        printf("inserire Nuovo nomeUtente: ");
        scanf("%s", Nnome);

        fopen("operazioni.txt", "w");
        fprintf(fp2, "%s\n", Vnome);
        fprintf(fp2, "%s\n", Nnome);

        fclose(fp2);
        esecuzione();

    }

    //variabili modifica password
    if(x==3){
        FILE* fp2=fopen("operazioni.txt", "w");
        fprintf(fp2,"%d\n",x);

        char* pass=malloc(sizeof(char));
        char* Npass=malloc(sizeof(char));

        printf("inserire Vecchia password: ");
        scanf("%s", pass);
        printf("inserire Nuova password: ");
        scanf("%s", Npass);

        fopen("operazioni.txt", "w");
        fprintf(fp2, "%s\n", pass);
        fprintf(fp2, "%s\n", Npass);

        fclose(fp2);
        esecuzione();

    }

    return 0;
}

