#include "misclibs.h"

int randNumInRange(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int contaGiocatori(Giocatore *listagiocatori) {
    Giocatore *giocatore = listagiocatori;
    int count = 0;
    while (giocatore != NULL) {
        count++;
        giocatore = giocatore->next;
    }
    return count;
}

int contaCarteCFU(Giocatore *giocatore) {
    CartaCFU *carta = giocatore->carte_cfu;
    int count = 0;
    while (carta != NULL) {
        count++;
        carta = carta->next;
    }
    return count;
}

int contaCarteCFUIstantanee(Giocatore *giocatore) {
    CartaCFU *carta = giocatore->carte_cfu;
    int count = 0;
    while (carta != NULL) {
        if (carta->effetto > ANNULLA && carta->effetto <= DIROTTA) {
            count++;
        }
        carta = carta->next;
    }
    return count;
}

int contaCarteMazzoCfu(CartaCFU *mazzoCfu){
    int count = 0;
    while (mazzoCfu != NULL) {
        count++;
        mazzoCfu = mazzoCfu->next;
    }
    return count;
}

int contaCarteOstacolo(CartaOstacolo *mazzoOstacoli){
    int count = 0;
    while (mazzoOstacoli != NULL) {
        count++;
        mazzoOstacoli = mazzoOstacoli->next;
    }
    return count;
}

void divideString(const char *input, char *part1, char *part2, int maxLength) {
    int length = strlen(input);
    if (length <= maxLength) {
        strncpy(part1, input, maxLength);
        part1[maxLength] = '\0';  // Ensure null-terminated string
        part2[0] = '\0';          // Empty second part
    } else {
        int breakPoint = maxLength;
        while (breakPoint > 0 && input[breakPoint] != ' ') {
            breakPoint--;
        }
        if (breakPoint == 0) breakPoint = maxLength;  // If no space found, just break at maxLength

        strncpy(part1, input, breakPoint);
        part1[breakPoint] = '\0';  // Ensure null-terminated string
        strncpy(part2, input + breakPoint + 1, maxLength);  // Skip the space for part2
        part2[maxLength] = '\0';  // Ensure null-terminated string
    }
}


void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(__unix__) || defined(__APPLE__) || defined(__linux__)
    system("clear");
#else
    printf("Funzione clearScreen non supportata su questo sistema operativo.\n");
#endif
}


void stampaDebugGiocate(Giocata *listaGiocate) {
    Giocata *giocataCorrente = listaGiocate;
    if(giocataCorrente==NULL){
        printf("NESSUNA GIOCATA TROVATA");
    }
    while (giocataCorrente != NULL) {
        printf("Giocatore: %s, Carta CFU: %s, Valore Carta: %d, Carta Ostacolo: %s, Tipo Ostacolo: %d, Punteggio del Turno: %d\n",
               giocataCorrente->giocatore->nomeUtente,
               giocataCorrente->carta->nomeCarta,
               giocataCorrente->carta->valoreCarta,
               giocataCorrente->cartaOstacoloEstratta->carta.nomeCarta,
               giocataCorrente->cartaOstacoloEstratta->carta.tipoOstacolo,
               giocataCorrente->punteggioTemporaneo);
        giocataCorrente = giocataCorrente->next;
    }
}

void stampaDebugGiocatori(Giocatore *listaGiocatori){
    Giocatore *giocatoreCorrente = listaGiocatori;
    if(giocatoreCorrente==NULL){
        printf("NESSUN GIOCATORE TROVATA");
    }
    while (giocatoreCorrente != NULL) {
        printf("Giocatore: %s, Personaggio %s, CFU %d\n",
               giocatoreCorrente->nomeUtente,
               giocatoreCorrente->personaggio.nomePersonaggio,
               giocatoreCorrente->cfu);
        giocatoreCorrente = giocatoreCorrente->next;
    }
}

void aggiungiCartaCFU(Giocatore *giocatore, CartaCFU *carta) {
    carta->next = giocatore->carte_cfu;
    giocatore->carte_cfu = carta;
}

Giocatore* scegliGiocatore(Giocatore *listaGiocatori, char *nomeGiocatore) {
    Giocatore *giocatoreCorrente = listaGiocatori;
    while (giocatoreCorrente != NULL) {
        if (strcmp(giocatoreCorrente->nomeUtente, nomeGiocatore) == 0) {
            return giocatoreCorrente;
        }
        giocatoreCorrente = giocatoreCorrente->next;
    }
}

CartaCFU* getCartaCFU(Giocatore *giocatore, int indiceCarta) {
    CartaCFU *corrente = giocatore->carte_cfu;
    for (int i = 0; i < indiceCarta; i++) {
        corrente = corrente->next;
    }
    return corrente;
}

int haCarteConEffetto(Giocatore *giocatore) {
    CartaCFU *corrente = giocatore->carte_cfu;
    while (corrente != NULL) {
        if (corrente->effetto != NESSUNO) {
            return 1; // Il giocatore ha almeno una carta con effetto
        }
        corrente = corrente->next;
    }
    return 0; // Il giocatore non ha carte con effetto
}

Giocata* trovaGiocata(Giocata *listaGiocate, Giocatore *giocatore) {
    Giocata *giocata = listaGiocate;
    while (giocata != NULL) {
        if (giocata->giocatore == giocatore) {
            return giocata;
        }
        giocata = giocata->next;
    }
}

// Funzione di utilità per contare le carte istantanee (effetti da 11 a 15) di un giocatore
int contaCarteIstantanee(Giocatore *giocatore) {
    int conteggio = 0;
    CartaCFU *current = giocatore->carte_cfu;

    while (current != NULL) {
        if (current->effetto >= AUMENTA && current->effetto <= DIROTTA) {
            conteggio++;
        }
        current = current->next;
    }

    return conteggio;
}

void stampaDebugCarteOstacolo(Giocatore *listaGiocatori){
    Giocatore *listaGiocatoriPtr = listaGiocatori;
    while (listaGiocatoriPtr != NULL) {
        printf("\n\nGiocatore: %s, ha i seguenti CFU: %d\n",
               listaGiocatoriPtr->nomeUtente,
               listaGiocatoriPtr->cfu);
        if(listaGiocatoriPtr->cartaOstacolo == NULL){
            printf("Non possiede Carte Ostacolo al momento!\n");
        } else {
            printf("Possiede le seguenti carte ostacolo:\n\n");
            CartaOstacolo *cartaOstacoloPtr = listaGiocatoriPtr->cartaOstacolo;
            while (cartaOstacoloPtr != NULL) {
                printf("Nome: %s\n"
                       "Descrizione: %s\n",
                       cartaOstacoloPtr->nomeCarta,
                       cartaOstacoloPtr->descrizione);
                switch(cartaOstacoloPtr->tipoOstacolo) {
                    case 0:
                        printf("Tipo Ostacolo: STUDIO\n");
                        break;
                    case 1:
                        printf("Tipo Ostacolo: SOPRAVVIVENZA\n");
                        break;
                    case 2:
                        printf("Tipo Ostacolo: SOCIALE\n");
                        break;
                    case 3:
                        printf("Tipo Ostacolo: ESAME\n");
                        break;
                    default:
                        printf("Tipo Ostacolo: SCONOSCIUTO\n");
                        break;
                }
                cartaOstacoloPtr = cartaOstacoloPtr->next; // Avanza alla carta ostacolo successiva
            }
        }
        // Passa al giocatore successivo
        listaGiocatoriPtr = listaGiocatoriPtr->next;
    }
}

void scartaCarte(CartaCFU **mazzoCfuScarti, CartaCFU *carteDaScartare) {
    while (carteDaScartare != NULL) {
        CartaCFU *carta = carteDaScartare;
        carteDaScartare = carteDaScartare->next;
        carta->next = *mazzoCfuScarti;
        *mazzoCfuScarti = carta;
    }
}

void mettiCartaOstacoloInFondo(CartaOstacolo **mazzoOstacoli, CartaOstacolo *cartaOstacolo) {
    // Trova la fine del mazzo
    CartaOstacolo *current = *mazzoOstacoli;
    while (current->next != NULL) {
        current = current->next;
    }
    // Metti la carta in fondo
    current->next = cartaOstacolo;
    cartaOstacolo->next = NULL;
}


void premiUnoPerContinuare(){
    int scelta=0;
    do{
        printf("\nPremi [1] per continuare: \n");
        scanf("%d", &scelta);
    }while(scelta != 1);
    //TODO CLEARSCREEN QUI
    clearScreen();
}

void freeall(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori){
    free(listaPersonaggi);
    free(mazzoCfu);
    free(mazzoCfuScarti);
    free(mazzoOstacoli);
    free(listaGiocatori);
}