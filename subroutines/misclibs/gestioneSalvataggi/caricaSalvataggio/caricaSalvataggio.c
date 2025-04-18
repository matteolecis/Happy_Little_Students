#include "caricaSalvataggio.h"
void caricaGiocatore(FILE *file, Giocatore *giocatore) {
    // Lettura del nome utente
    fread(giocatore->nomeUtente, sizeof(char), MAX_CHAR, file);

    // Lettura del personaggio
    fread(&giocatore->personaggio, sizeof(Personaggio), 1, file);

    // Lettura dei CFU
    fread(&giocatore->cfu, sizeof(int), 1, file);

    // Lettura delle carte CFU del giocatore
    CartaCFU *cartaCfuHead = NULL;
    CartaCFU *cartaCfuTail = NULL;
    while (1) {
        CartaCFU *cartaCfu = (CartaCFU *)malloc(sizeof(CartaCFU));
        fread(cartaCfu, sizeof(CartaCFU), 1, file);

        // Controllo del terminatore di fine lista per le carte CFU
        if (strcmp(cartaCfu->nomeCarta, "END_OF_CFU") == 0) {
            free(cartaCfu);
            break;
        }

        cartaCfu->next = NULL;
        if (cartaCfuHead == NULL) {
            cartaCfuHead = cartaCfuTail = cartaCfu;
        } else {
            cartaCfuTail->next = cartaCfu;
            cartaCfuTail = cartaCfu;
        }
    }
    giocatore->carte_cfu = cartaCfuHead;

    // Lettura delle carte Ostacolo del giocatore
    CartaOstacolo *cartaOstacoloHead = NULL;
    CartaOstacolo *cartaOstacoloTail = NULL;
    while (1) {
        CartaOstacolo *cartaOstacolo = (CartaOstacolo *)malloc(sizeof(CartaOstacolo));
        fread(cartaOstacolo, sizeof(CartaOstacolo), 1, file);

        // Controllo del terminatore di fine lista per le carte Ostacolo
        if (strcmp(cartaOstacolo->nomeCarta, "END_OF_OSTACOLO") == 0) {
            free(cartaOstacolo);
            break;
        }

        cartaOstacolo->next = NULL;
        if (cartaOstacoloHead == NULL) {
            cartaOstacoloHead = cartaOstacoloTail = cartaOstacolo;
        } else {
            cartaOstacoloTail->next = cartaOstacolo;
            cartaOstacoloTail = cartaOstacolo;
        }
    }
    giocatore->cartaOstacolo = cartaOstacoloHead;
}

int caricaMazzo(FILE *file, CartaCFU **mazzo) {
    int numCarte;
    fread(&numCarte, sizeof(int), 1, file);
    CartaCFU *head = NULL;
    CartaCFU *tail = NULL;
    for (int i = 0; i < numCarte; i++) {
        CartaCFU *carta = (CartaCFU *)malloc(sizeof(CartaCFU));
        fread(carta, sizeof(CartaCFU), 1, file);
        carta->next = NULL;
        if (head == NULL) {
            head = tail = carta;
        } else {
            tail->next = carta;
            tail = carta;
        }
    }
    *mazzo = head;
    return numCarte;
}

int caricaSaveMazzoOstacoli(FILE *file, CartaOstacolo **mazzo) {
    int numCarte;
    fread(&numCarte, sizeof(int), 1, file);
    CartaOstacolo *head = NULL;
    CartaOstacolo *tail = NULL;
    for (int i = 0; i < numCarte; i++) {
        CartaOstacolo *carta = (CartaOstacolo *)malloc(sizeof(CartaOstacolo));
        fread(carta, sizeof(CartaOstacolo), 1, file);
        carta->next = NULL;
        if (head == NULL) {
            head = tail = carta;
        } else {
            tail->next = carta;
            tail = carta;
        }
    }
    *mazzo = head;
    return numCarte;
}

void mostraSalvataggiDisponibili() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(".")) != NULL) {
        printf("Salvataggi disponibili:\n");
        int index = 1;
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".sav") != NULL) {
                printf("%d. %s\n", index, ent->d_name);
                index++;
            }
        }
        closedir(dir);
    } else {
        perror("");
        return;
    }
}
void caricaPartita(char nomeFile[MAX_NOME_SAVE], Giocatore **listaGiocatori, CartaCFU **mazzoCFU, CartaCFU **scartiCFU, CartaOstacolo **mazzoOstacoli) {
    mostraSalvataggiDisponibili();

    FILE *file;
    do {
        printf("Inserisci il nome del file di salvataggio (senza estensione): ");
        scanf("%s", nomeFile);

        char nomeCompleto[MAX_NOME_SAVE + 4]; // +4 per ".sav\0"
        sprintf(nomeCompleto, "%s.sav", nomeFile);

        file = fopen(nomeCompleto, "rb");
        if (!file) {
            printf("Il file %s non esiste. Riprova.\n", nomeCompleto);
        }
    } while (!file);

    int numGiocatori;
    fread(&numGiocatori, sizeof(int), 1, file);

    Giocatore *head = NULL;
    Giocatore *tail = NULL;
    for (int i = 0; i < numGiocatori; i++) {
        Giocatore *giocatore = (Giocatore *)malloc(sizeof(Giocatore));
        caricaGiocatore(file, giocatore);
        giocatore->next = NULL;
        if (head == NULL) {
            head = tail = giocatore;
        } else {
            tail->next = giocatore;
            tail = giocatore;
        }
    }
    *listaGiocatori = head;

    caricaMazzo(file, mazzoCFU);
    caricaMazzo(file, scartiCFU);
    caricaSaveMazzoOstacoli(file, mazzoOstacoli);

    // Rimuove l'estensione .sav
    char *dot = strrchr(nomeFile, '.');
    if (dot != NULL) {
        *dot = '\0';
    }

    fclose(file);

    printf("Partita caricata con successo da %s\n", nomeFile);
}
