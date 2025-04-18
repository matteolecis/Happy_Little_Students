#include "caricaPersonaggi.h"
void caricaPersonaggi(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI]){
    FILE *fp; //Puntatore per lavorare con il file
    int numPersonaggi=0; //contatore utilizzato per contare quanti personaggi ci sono
    //Apriamo il file personaggi.txt in lettura
    fp = fopen("../carte_ostacoli_personaggi/personaggi.txt", "r");
    //controllo se il file esiste
    if (fp == NULL) {
        exit(-1);
    }
    while(fscanf(fp, "%d %d %d %d %[^\n]s",
                 &listaPersonaggi[numPersonaggi].tipoOstacoli[0],&listaPersonaggi[numPersonaggi].tipoOstacoli[1],
                 &listaPersonaggi[numPersonaggi].tipoOstacoli[2], &listaPersonaggi[numPersonaggi].tipoOstacoli[3],
                 listaPersonaggi[numPersonaggi].nomePersonaggio) != EOF && numPersonaggi<MAX_NUM_GIOCATORI){
        numPersonaggi++;
    }
    //Chiusura del file
    fclose(fp);
}
