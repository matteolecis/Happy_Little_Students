#include "assegnaCartaOstacoloPerdente.h"
#define MAX_WIDTH 68
void assegnaCartaOstacoloPerdente(Giocatore *giocatorePerdente, CartaOstacolo *nuovaCartaOstacolo) {
    printf("\nAssegnazione di una nuova carta ostacolo a %s\n\n", giocatorePerdente->nomeUtente);

    stampaCartaOstacoloAssegnataPerdente(nuovaCartaOstacolo);

    CartaOstacolo *copiaCarta = (CartaOstacolo *)malloc(sizeof(CartaOstacolo));
    if (copiaCarta == NULL) {
        perror("ERRORE DI ALLOCAZIONE DELLA MEMORIA");
    }
    strcpy(copiaCarta->nomeCarta, nuovaCartaOstacolo->nomeCarta);
    strcpy(copiaCarta->descrizione, nuovaCartaOstacolo->descrizione);
    copiaCarta->tipoOstacolo = nuovaCartaOstacolo->tipoOstacolo;
    copiaCarta->next = NULL;

    if (giocatorePerdente->cartaOstacolo == NULL) {
        giocatorePerdente->cartaOstacolo = copiaCarta;
    } else {
        CartaOstacolo *current = giocatorePerdente->cartaOstacolo;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = copiaCarta;
    }
    printf("\nCarta ostacolo assegnata con successo\n");
}


void stampaCartaOstacoloAssegnataPerdente(CartaOstacolo *cartaOstacolo){
    // Calcola la lunghezza del nome della carta
    int lunghezzaNome = strlen(cartaOstacolo->nomeCarta);
    // Calcola quanti spazi sono necessari per allineare il quadrato
    int spaziNecessari = MAX_WIDTH - lunghezzaNome;

    // Suddividi la descrizione in due parti
    char descPart1[MAX_WIDTH - 2] = "";
    char descPart2[MAX_WIDTH - 2] = "";
    divideString(cartaOstacolo->descrizione, descPart1, descPart2, MAX_WIDTH);

    switch(cartaOstacolo->tipoOstacolo) {
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
                   cartaOstacolo->nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
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
                   cartaOstacolo->nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
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
                   cartaOstacolo->nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
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
                   cartaOstacolo->nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
            break;
        default:
            printf("Tipo Ostacolo: SCONOSCIUTO\n");
            break;
    }
    printf("\n\n");
}