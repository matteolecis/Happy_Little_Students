#include "gestioneLog.h"
// Funzione per scrivere il log
void gestioneLog(int turno, Giocata *listaGiocate) {
    FILE *logFile;
    Giocata *giocata = listaGiocate;


    logFile = fopen("log.txt", "a"); // Apri il file in modalità append per aggiungere nuovi log
    if (logFile == NULL) {
        printf("Errore nell'apertura del file log.txt\n");
        exit(1);
    }

    while (giocata != NULL) {
        fprintf(logFile, "TURNO %d: %s gioca %s\n", turno-1, giocata->giocatore->nomeUtente, giocata->carta->nomeCarta);
        giocata = giocata->next;
    }

    fclose(logFile); // Chiudi il file
}