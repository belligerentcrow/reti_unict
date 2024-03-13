#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona
{
    char nome[50];
    char cognome[50];
    int eta;
} Persona;

char *concatena(Persona *p, int size)
{
    int c = 0;
    for (size_t i = 0; i < size; i++)
    {
        c += 4;
        c += strlen(p[i].nome);
        c += strlen(p[i].cognome);
        c += 3;
    }

    char *finale = malloc(c + 1);
    char *app = malloc(4);

    for (size_t i = 0; i < size; i++)
    {
        strcat(finale, p[i].nome);
        strcat(finale, ",");
        strcat(finale, p[i].cognome);
        strcat(finale, ",");
        sprintf(app, "%d", p[i].eta);
        strcat(finale, app);
        strcat(finale, "_");
    }
    return finale;
}

void print_struct(Persona *p, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Nome %s:\n", (p + i)->nome);
        printf("Cognome %s:\n", (p + i)->cognome);
        printf("Eta' %d:\n", (p + i)->eta);
    }
}

void set_struct(Persona *p, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("inserisci il nome\n");
        scanf("%s", p[i].nome);
        printf("inserisci il cognome\n");
        scanf("%s", p[i].cognome);
        printf("\ninserisci il eta\n");
        scanf("%d", &p[i].eta);
    }
}

int main(int argc, char *argv[])
{
    int n = 0;
    printf("Inserisci la grandezza array\n");
    scanf("%d", &n);

    Persona persona2[n];
    set_struct(persona2, n);
    print_struct(persona2, n);

    char *result_concat = concatena(persona2, n);
    printf("Risultato concatenato %s:", result_concat);

    /* Singola
     pers person;
     scanf("%s", person.nome);
     scanf("%s", person.cognome);
     scanf("%d", &person.eta);
     printf("%s", person.nome);
     printf("%s", person.cognome);
     printf("%d", person.eta);
     */
}
