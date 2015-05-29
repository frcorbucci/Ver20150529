#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 25

struct s_caratteristiche {
    char nome[MAX_STRLEN + 1];
    char cognome[MAX_STRLEN + 1];
    char cellulare;
    unsigned int eta;
    int gradimento;
};

typedef struct s_caratteristiche caratteristiche;

//funzione per inserire le ragazze

void inserimentoRagzze(caratteristiche ragazze[], int dimensione) {
    //dichiarazione delle variabili   
    int contatore;

    //ciclo inserimento ragazze;
    for (contatore = 0; contatore < dimensione; contatore++) {
        printf("Inserisci il nome della %d ragazza: ", contatore + 1);
        scanf("\n%[^\n]", (ragazze[contatore].nome));
        printf("Inserisci il cognome della %d ragazza: ", contatore + 1);
        scanf("\n%[^\n]", (ragazze[contatore].cognome));
        printf("Inserisci il numero di cellulare della %d ragazza: ", contatore + 1);
        scanf("%s.", (ragazze[contatore].cellulare));
        printf("Inserisci l'eta della %d ragazza: ", contatore + 1);
        scanf("%d.", &(ragazze[contatore].eta));
        printf("Inserisci l'indice di gradimento della %d ragazza (inserisci '0' pessimo gradimento fino a '4' ottimo gradimento) : ", contatore + 1);
        scanf("%d.", &(ragazze[contatore].gradimento));
    }
}

//funzine per l'oridnamento

void ordinamento(int dimensione, caratteristiche ragazze[], caratteristiche temp) {
    //dichiariziano delle variabili        
    int contatore, contatorea;
    //ciclo
    for (contatore = 0; contatore < dimensione - 1; contatore++) {
        for (contatorea = 0; contatorea < dimensione - contatore; contatorea++) {
            if (strcmp(ragazze[contatorea].cognome, ragazze[contatorea + 1].cognome) > 0) {
                temp = ragazze[contatorea];
                ragazze[contatorea] = ragazze[contatorea + 1];
                ragazze[contatorea] = temp;
            }
        }
    }
}

//funzine per inserimento sul FILE

void inserimentoFile(caratteristiche ragazze[], int dimensione, FILE *evitare, FILE *ripetere) {

    //dichiariazione delle variabili
    int Contatore;

    fprintf(evitare, "Nome, Cognome, cellulare, Eta, Gradimento;\n");
    fprintf(ripetere, "Nome, Cognome, cellulare, Eta, Gradimento;\n");

    for (Contatore = 0; Contatore < dimensione; Contatore++) {
        if (ragazze[Contatore].gradimento < 2) {
            fprintf(evitare, "%s, %s, %s, %d, %d;\n", (ragazze[Contatore].nome), (ragazze[Contatore].cognome), (ragazze[Contatore].cellulare), (ragazze[Contatore].eta), (ragazze[Contatore].gradimento));
        } else {
            fprintf(ripetere, "%s, %s, %s, %d, %d;\n", (ragazze[Contatore].nome), (ragazze[Contatore].cognome), (ragazze[Contatore].cellulare), (ragazze[Contatore].eta), (ragazze[Contatore].gradimento));
        }
    }
}

int main(int argc, char** argv) {

    //dichiarazione delle variabili
    FILE *evitare, *ripetere;
    int contatore, contatorea;
    int numRagazze = 0;
    caratteristiche ragazze[numRagazze], temp;

    //inserimento numero femmine da inserire
    printf("Quante ragazze vuoi inserire?");
    scanf("%d", &(numRagazze));

    //allocazione dinamica della meoria
    //ragazze=(caratteristiche*)malloc(sizeof(caratteristiche));

    //chaiamata della funzione 
    inserimentoRagzze(ragazze, numRagazze);

    //chiamata della funzione
    ordinamento(numRagazze, ragazze, temp);

    //apertura dei FILE
    evitare = fopen("daevitare.csv", "w");
    ripetere = fopen("daripetere.csv", "w");

    //chiamato della funzione
    inserimentoFile(ragazze, numRagazze, evitare, ripetere);

    //chiusura dei FILE
    fclose(evitare);
    fclose(ripetere);

    //deallocazione della memoria
    //free(ragazze);
    return (EXIT_SUCCESS);
}

