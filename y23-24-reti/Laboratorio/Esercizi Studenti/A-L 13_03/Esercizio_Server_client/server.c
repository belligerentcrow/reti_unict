#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void esecuzione(){

    //visuallizzazione e salvatagio operazione nel log
    FILE* fc=fopen("operazioni.txt", "r");
    FILE* fl=fopen("log.txt", "a");
    char s[1000];
    fgets(s,1000,fc);
    fprintf(fl,"%s",s);
    fclose(fl);

    //verifica accesso al server
    if(s[0]=='1'){
        FILE* fs=fopen("Server.txt", "r");
        char d[1000];
        char* nome=malloc(sizeof(char));
        char* pass=malloc(sizeof(char));
        strcpy(nome, fgets(s,1000,fc));
        strcpy(pass,fgets(s,1000,fc));
        char* riga=malloc(sizeof(char));
        strcpy(riga,fgets(d,1000,fs));

        do{

            if(strcmp(nome,riga)==0){
                riga=fgets(d,1000,fs);
                if(strcmp(pass,riga)==0){
                    printf("accesso eseguito\n");
                    return;
                }


            }
            riga=fgets(d,1000,fs);
        }while(riga!=NULL);
        fclose(fs);
        printf("Accesso negato, password o nomeutente errati");
        exit(-1);
    }
    
    //registrazione al server
    if(s[0]=='2'){

        FILE* fs=fopen("Server.txt", "r");
        char d[1000];
        char* nome=malloc(sizeof(char));
        char* pass=malloc(sizeof(char));
        strcpy(nome, fgets(s,1000,fc));
        strcpy(pass,fgets(s,1000,fc));
        char* riga=malloc(sizeof(char));
        strcpy(riga,fgets(d,1000,fs));
        //controllo doppioni
        do{
            if(strcmp(nome,riga)==0){
                printf("nomeUtente gia esistente");
                return;
            }
            riga=fgets(d,1000,fs);
        }while(riga!=NULL);
        fclose(fs);
        
        
        FILE* fs2=fopen("Server.txt", "a");
        fprintf(fs2,"%s", nome);
        fprintf(fs2,"%s", pass);
        fprintf(fs2,"%s", "//\n");
        fclose(fs2);
        fclose(fc);
        return;
    }

    //modifica password
    if(s[0]=='3'){

        FILE* fs=fopen("Server.txt", "r");
        FILE* ft=fopen("Temporaneo.txt", "w");
        char d[1000];
        char* Vpass=malloc(sizeof(char));
        strcpy(Vpass,fgets(s,1000,fc));
        char* Npass=malloc(sizeof(char));
        strcpy(Npass,fgets(s,1000,fc));

        char* riga=malloc(sizeof(char));
        strcpy(riga,fgets(d,1000,fs));
        do{
            if(strcmp(Vpass,riga)==0){
                fprintf(ft, "%s", Npass);
                fgets(d,1000,fs);
            }
            fprintf(ft,"%s",riga);
            riga=fgets(d,1000,fs);
        }while(riga!=NULL);
        fclose(fs);
        fclose(ft);
        FILE* ft2=fopen("Temporaneo.txt", "r");
        FILE* fs2=fopen("Server.txt", "w");
        char f[1000];
        char* riga3=malloc(sizeof(char));
        strcpy(riga3, fgets(f,1000,ft2));

        do{
            fprintf(fs2, "%s", riga3);
            riga3=fgets(f,1000,ft2);
        }while(riga3!=NULL);

        fclose(ft2);
        fclose(fs2); 
       
    }

    //modifica nomeutente
    if(s[0]=='4'){

        FILE* fs=fopen("Server.txt", "r");
        FILE* ft=fopen("Temporaneo.txt", "w");
        char d[1000];
        char* Vnome=malloc(sizeof(char));
        strcpy(Vnome,fgets(s,1000,fc));
        char* Nnome=malloc(sizeof(char));
        strcpy(Nnome,fgets(s,1000,fc));

        char* riga=malloc(sizeof(char));
        strcpy(riga,fgets(d,1000,fs));
        do{

            if(strcmp(Vnome,riga)==0){
                fprintf(ft, "%s", Nnome);
                fgets(d,1000,fs);
            }
            fprintf(ft,"%s",riga);
            riga=fgets(d,1000,fs);
        }while(riga!=NULL);
        fclose(fs);
        fclose(ft);
        FILE* ft2=fopen("Temporaneo.txt", "r");
        FILE* fs2=fopen("Server.txt", "w");
        char f[1000];
        char* riga3=malloc(sizeof(char));
        strcpy(riga3, fgets(f,1000,ft2));

        do{
            fprintf(fs2, "%s", riga3);
            riga3=fgets(f,1000,ft2);
        }while(riga3!=NULL);

        fclose(ft2);
        fclose(fs2); 
       
    }
    fclose(fc);
    return;
}

