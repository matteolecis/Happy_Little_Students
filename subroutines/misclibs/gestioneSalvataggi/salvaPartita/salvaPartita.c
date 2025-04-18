#include "salvaPartita.h"
void salvaGiocatore(FILE *file, FILE*log, Giocatore *giocatore) {
    // Scrittura del nome utente
    fwrite(giocatore->nomeUtente, sizeof(char), MAX_CHAR, file);

    // Scrittura del personaggio
    fwrite(&giocatore->personaggio, sizeof(Personaggio), 1, file);

    // Scrittura dei CFU
    fwrite(&giocatore->cfu, sizeof(int), 1, file);

    fprintf(log, "Giocatore: %s\n", giocatore->nomeUtente);
    fprintf(log, "Personaggio: %s\n", giocatore->personaggio.nomePersonaggio);
    fprintf(log, "Abilità tipo ostacoli: ");
    for (int i = 0; i < TIPO_OSTACOLI; i++) {
        fprintf(log, "%d ", giocatore->personaggio.tipoOstacoli[i]);
    }
    fprintf(log, "\nCFU: %d\n", giocatore->cfu);

    // Scrittura delle carte CFU del giocatore
    CartaCFU *currentCfu = giocatore->carte_cfu;
    while (currentCfu != NULL) {
        fwrite(currentCfu, sizeof(CartaCFU), 1, file);
        fprintf(log, "Carta CFU: %s, Valore: %d, Effetto: %d\n", currentCfu->nomeCarta, currentCfu->valoreCarta, currentCfu->effetto);
        currentCfu = currentCfu->next;
    }

    // Scrittura del terminatore di fine lista per le carte CFU
    CartaCFU endCfu = { "END_OF_CFU", -1, NESSUNO, NULL };
    fwrite(&endCfu, sizeof(CartaCFU), 1, file);
    fprintf(log, "End of CFU Cards\n");

    // Scrittura delle carte Ostacolo del giocatore
    CartaOstacolo *currentOstacolo = giocatore->cartaOstacolo;
    while (currentOstacolo != NULL) {
        fwrite(currentOstacolo, sizeof(CartaOstacolo), 1, file);
        fprintf(log, "Carta Ostacolo: %s, Descrizione: %s, Tipo: %d\n", currentOstacolo->nomeCarta, currentOstacolo->descrizione, currentOstacolo->tipoOstacolo);
        currentOstacolo = currentOstacolo->next;
    }

    // Scrittura del terminatore di fine lista per le carte Ostacolo
    CartaOstacolo endOstacolo = { "END_OF_OSTACOLO", "", -1, NULL };
    fwrite(&endOstacolo, sizeof(CartaOstacolo), 1, file);
    fprintf(log, "End of Ostacolo Cards\n");
}

void salvaMazzo(FILE *file, FILE *log, CartaCFU *mazzo, int numCarte) {
    fwrite(&numCarte, sizeof(int), 1, file);
    fprintf(log, "Numero di Carte CFU nel Mazzo: %d\n", numCarte);
    while (mazzo) {
        fwrite(mazzo, sizeof(CartaCFU), 1, file);
        fprintf(log, "Carta CFU nel Mazzo: %s, Valore: %d, Effetto: %d\n", mazzo->nomeCarta, mazzo->valoreCarta, mazzo->effetto);
        mazzo = mazzo->next;
    }
}

void salvaMazzoOstacoli(FILE *file, FILE *log, CartaOstacolo *mazzo, int numCarte) {
    fwrite(&numCarte, sizeof(int), 1, file);
    fprintf(log, "Numero di Carte Ostacolo nel Mazzo: %d\n", numCarte);
    while (mazzo) {
        fwrite(mazzo, sizeof(CartaOstacolo), 1, file);
        fprintf(log, "Carta Ostacolo nel Mazzo: %s, Descrizione: %s, Tipo: %d\n", mazzo->nomeCarta, mazzo->descrizione, mazzo->tipoOstacolo);
        mazzo = mazzo->next;
    }
}

void salvaPartita(char nomeFile[MAX_NOME_SAVE], Giocatore *listaGiocatori, CartaCFU *mazzoCFU, int numCarteCFU, CartaCFU *scartiCFU, int numCarteScarti, CartaOstacolo *mazzoOstacoli, int numCarteOstacoli) {
    printf("Inserisci il nome del file di salvataggio: ");
    scanf("%s", nomeFile);

    char binFile[MAX_NOME_SAVE];
    strcpy(binFile, nomeFile);
    strcat(binFile, ".sav");
    char logFile[MAX_NOME_SAVE];
    strcpy(logFile, nomeFile);
    strcat(logFile, ".txt");

    FILE *file = fopen(binFile, "wb");
    if (!file) {
        perror("Errore nell'apertura del file");
    }

    FILE *log = fopen(logFile, "w");
    if (!log) {
        perror("Errore nell'apertura del file");
        fclose(file);
    }

    int numGiocatori = 0;
    Giocatore *temp = listaGiocatori;
    while (temp) {
        numGiocatori++;
        temp = temp->next;
    }

    fwrite(&numGiocatori, sizeof(int), 1, file);
    fprintf(log, "Numero di Giocatori: %d\n", numGiocatori);

    Giocatore *giocatore = listaGiocatori;
    while (giocatore) {
        salvaGiocatore(file,log, giocatore);
        giocatore = giocatore->next;
    }

    salvaMazzo(file, log, mazzoCFU, numCarteCFU);
    salvaMazzo(file, log, scartiCFU, numCarteScarti);
    salvaMazzoOstacoli(file, log, mazzoOstacoli, numCarteOstacoli);

    fclose(file);
    fclose(log);
    printf("Partita salvata con successo in %s e %s\n", binFile, logFile);
    premiUnoPerContinuare();
}

void salvaPartitaAutomatico(char nomeFile[MAX_NOME_SAVE], Giocatore *listaGiocatori, CartaCFU *mazzoCFU, int numCarteCFU, CartaCFU *scartiCFU, int numCarteScarti, CartaOstacolo *mazzoOstacoli, int numCarteOstacoli) {
    char binFile[MAX_NOME_SAVE];
    strcpy(binFile, nomeFile);
    strcat(binFile, ".sav");
    char logFile[MAX_NOME_SAVE];
    strcpy(logFile, nomeFile);
    strcat(logFile, ".txt");

    FILE *file = fopen(binFile, "wb");
    if (!file) {
        perror("Errore nell'apertura del file");
    }

    FILE *log = fopen(logFile, "w");
    if (!log) {
        perror("Errore nell'apertura del file");
        fclose(file);
    }

    int numGiocatori = 0;
    Giocatore *temp = listaGiocatori;
    while (temp) {
        numGiocatori++;
        temp = temp->next;
    }

    fwrite(&numGiocatori, sizeof(int), 1, file);
    fprintf(log, "Numero di Giocatori: %d\n", numGiocatori);

    Giocatore *giocatore = listaGiocatori;
    while (giocatore) {
        salvaGiocatore(file,log, giocatore);
        giocatore = giocatore->next;
    }

    salvaMazzo(file, log, mazzoCFU, numCarteCFU);
    salvaMazzo(file, log, scartiCFU, numCarteScarti);
    salvaMazzoOstacoli(file, log, mazzoOstacoli, numCarteOstacoli);

    fclose(file);
    fclose(log);
    printf("Partita salvata con successo in %s e %s\n", binFile, logFile);
    premiUnoPerContinuare();
}