#include "controlloStatoTurno.h"
#define MAX_WIDTH 68 // Massima larghezza per le righe nel rettangolo SERVE PER LA FUNZIONE stampaCartaOStacolo

void controlloStatoTurno(Giocatore *listaGiocatori, CartaOstacoloEstratta *cartaOstacoloCorrente) {
    //TODO CLEARSCREEN QUI
    clearScreen();
    // Stampa la carta ostacolo corrente
    stampaCartaOstacolo(*cartaOstacoloCorrente);

    // Stampa lo stato degli altri giocatori
    printf("\n+---------------------+\n"
           "| Stato dei giocatori |\n"
           "+---------------------+\n");
    Giocatore *listaGiocatoriPtr = listaGiocatori;
    while (listaGiocatoriPtr != NULL) {
        stampaPlanciaGiocatore(listaGiocatoriPtr);
        if(listaGiocatoriPtr->cartaOstacolo == NULL){
            printf("\n\n           [Non possiede Carte Ostacolo al momento!]\n\n");
        } else {
            printf("\n\n           [Possiede le seguenti carte ostacolo]\n\n");
            CartaOstacolo *cartaOstacoloPtr = listaGiocatoriPtr->cartaOstacolo;
            while (cartaOstacoloPtr != NULL) {
                stampaCarteOstacoloControlloTurno(*cartaOstacoloPtr);
                cartaOstacoloPtr = cartaOstacoloPtr->next; // Avanza alla carta ostacolo successiva
            }
        }
        // Passa al giocatore successivo
        listaGiocatoriPtr = listaGiocatoriPtr->next;
        printf("\n\n\n\n=============================================================================================\n\n\n\n");
    }
    // Messaggio di debug per verificare la fine del controllo
    printf("\nControllo dello stato turno completato.\n\n");
    int scelta=0;
    do{
        printf("\nPremi [1] per continuare: \n");
        scanf("%d", &scelta);
    }while(scelta != 1);
    //TODO CLEARSCREEN QUI
    clearScreen();
}

void stampaCarteOstacoloControlloTurno(CartaOstacolo cartaOstacolo){
    // Calcola la lunghezza del nome della carta
    int lunghezzaNome = strlen(cartaOstacolo.nomeCarta);
    // Calcola quanti spazi sono necessari per allineare il quadrato
    int spaziNecessari = MAX_WIDTH - lunghezzaNome;

    // Suddividi la descrizione in due parti
    char descPart1[MAX_WIDTH - 2] = "";
    char descPart2[MAX_WIDTH - 2] = "";
    divideString(cartaOstacolo.descrizione, descPart1, descPart2, MAX_WIDTH);

    switch(cartaOstacolo.tipoOstacolo) {
        case STUDIO:
            printf(" +*********************************************************************+ \n"
                   " *                        [OSTACOLO: STUDIO]                           *\n"
                   " *                                                                     *\n"
                   " * NOME                                                                *\n"
                   " * %s%*s*\n"
                   " *                                                                     *\n"
                   " * DESCRIZIONE                                                         *\n"
                   " *  %-*s *\n"
                   " *  %-*s *\n"
                   " *                                                                     *\n"
                   " +*********************************************************************+  \n",
                   cartaOstacolo.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
            break;
        case SOPRAVVIVENZA:
            printf(" +*********************************************************************+ \n"
                   " *                      [OSTACOLO: SOPRAVVIVENZA]                      *\n"
                   " *                                                                     *\n"
                   " * NOME                                                                *\n"
                   " * %s%*s*\n"
                   " *                                                                     *\n"
                   " * DESCRIZIONE                                                         *\n"
                   " *  %-*s *\n"
                   " *  %-*s *\n"
                   " *                                                                     *\n"
                   " +*********************************************************************+  \n",
                   cartaOstacolo.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
            break;
        case SOCIALE:
            printf(" +*********************************************************************+ \n"
                   " *                         [OSTACOLO: SOCIALE]                         *\n"
                   " *                                                                     *\n"
                   " * NOME                                                                *\n"
                   " * %s%*s*\n"
                   " *                                                                     *\n"
                   " * DESCRIZIONE                                                         *\n"
                   " *  %-*s *\n"
                   " *  %-*s *\n"
                   " *                                                                     *\n"
                   " +*********************************************************************+  \n",
                   cartaOstacolo.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
            break;
        case ESAME:
            printf(" +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+ \n"
                   " x                       ++++[OSTACOLO: ESAME]++++                     x\n"
                   " x                                                                     x\n"
                   " x NOME                                                                x\n"
                   " x %s%*sx\n"
                   " x                                                                     x\n"
                   " x DESCRIZIONE                                                         x\n"
                   " x  %-*s x\n"
                   " x  %-*s x\n"
                   " x                                                                     x\n"
                   " +xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx+  \n",
                   cartaOstacolo.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
            break;
        default:
            printf("Tipo Ostacolo: SCONOSCIUTO\n");
            break;
    }
    printf("\n\n");
}