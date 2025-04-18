#include "stampaCarteCFU.h"
#define MAX_SPAZIO 35
void stampaCarteCFU(Giocatore *giocatore) {
    CartaCFU *carta = giocatore->carte_cfu;

    int indice = 0;
    while (carta != NULL) {
        // Calcola la lunghezza del nome della carta
        int lunghezzaNome = strlen(carta->nomeCarta);
        // Calcola quanti spazi sono necessari per allineare il quadrato
        int spaziNecessari = MAX_SPAZIO - lunghezzaNome;
        switch (carta->effetto) {
            case SCARTAP:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SCARTAP                            |\n"
                       " |                                    |\n"
                       " | Puo' scartare una carta CFU        |\n"
                       " | punto e aggiungere il suo          |\n"
                       " | valore al punteggio del turno.     |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                 \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case RUBA:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | RUBA                               |\n"
                       " |                                    |\n"
                       " | Puo' guardare le carte             |\n"
                       " | di un collega e rubarne            |\n"
                       " | una a sua scelta!                  |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                 \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SCAMBIADS:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SCAMBIADS                          |\n"
                       " |                                    |\n"
                       " | Puo' scambiare questa carta        |\n"
                       " | con quella di un altro giocatore   |\n"
                       " | purche' senza effetto.             |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]               \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SCARTAE:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SCARTAE                            |\n"
                       " |                                    |\n"
                       " | Puo' scartare una carta CFU punto  |\n"
                       " | con effetto e aggiungere il suo    |\n"
                       " | punteggio a quello del turno.      |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SCARTAC:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SCARTAC                            |\n"
                       " |                                    |\n"
                       " | Scarta da uno a tre carte          |\n"
                       " | della tua mano.                    |\n"
                       " |                                    |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SCAMBIAP:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SCAMBIAP                           |\n"
                       " |                                    |\n"
                       " | Scambia il punteggio del turno     |\n"
                       " | maggiore e minore dopo il calcolo  |\n"
                       " | del punteggio di base.             |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case DOPPIOE:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | DOPPIOE                            |\n"
                       " |                                    |\n"
                       " | Raddoppia gli effetti delle carte  |\n"
                       " | che aumentano o diminuiscono       |\n"
                       " | il punteggio (per tutti).          |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SBIRCIA:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SBIRCIA                            |\n"
                       " |                                    |\n"
                       " | Guarda due carte in cima al mazzo, |\n"
                       " | prendine una e scarta l’altra.     |\n"
                       " |                                    |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SCAMBIAC:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SCAMBIAC                           |\n"
                       " |                                    |\n"
                       " | Scambia la carta punto giocata     |\n"
                       " | nel turno da un giocatore G1 con   |\n"
                       " | quella di un giocatore G2,         |\n"
                       " | con G1 e G2 scelti da te!          |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case ANNULLA:
                printf(" +------------------------------------+ \n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | ANNULLA                            |\n"
                       " |                                    |\n"
                       " | Annulla gli effetti di tutte       |\n"
                       " | le carte punto durante il turno    |\n"
                       " |                                    |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case AUMENTA:
                printf(" +------------------------------------+ \n"
                       " |         [CARTA ISTANTANEA]         |\n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | AUMENTA                            |\n"
                       " |                                    |\n"
                       " | Aumenta di 2 CFU il punteggio del  |\n"
                       " | turno di un giocatore a scelta     |\n"
                       " |                                    |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case DIMINUISCI:
                printf(" +------------------------------------+ \n"
                       " |         [CARTA ISTANTANEA]         |\n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | DIMINUISCI                         |\n"
                       " |                                    |\n"
                       " | Diminuisci di 2 CFU il punteggio   |\n"
                       " | del turno di un giocatore a scelta |\n"
                       " |                                    |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case INVERTI:
                printf(" +------------------------------------+ \n"
                       " |         [CARTA ISTANTANEA]         |\n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | INVERTI                            |\n"
                       " |                                    |\n"
                       " | Inverti punteggio minimo e massimo |\n"
                       " | del turno.                         |\n"
                       " |                                    |\n"
                       " +------------------------------------+  \n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case SALVA:
                printf(" +------------------------------------+ \n"
                       " |         [CARTA ISTANTANEA]         |\n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | SALVA                              |\n"
                       " |                                    |\n"
                       " | Metti la carta Ostacolo che stai   |\n"
                       " | per prendere in fondo al mazzo.    |\n"
                       " |                                    |\n"
                       " +------------------------------------+\n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case DIROTTA:
                printf(" +------------------------------------+ \n"
                       " |         [CARTA ISTANTANEA]         |\n"
                       " | Valore: %d                          |\n"
                       " | %s%*s|\n"
                       " | DIROTTA                            |\n"
                       " |                                    |\n"
                       " | Dai la carta che stai per prendere |\n"
                       " | ad un altro giocatore a tua scelta.|\n"
                       " |                                    |\n"
                       " +------------------------------------+\n"
                       "                  [%d]                   \n\n\n", carta->valoreCarta, carta->nomeCarta,spaziNecessari,"", indice);
                break;
            case NESSUNO:
                printf(" +------------------------------------+ \n"
                             " | Valore: %d                          |\n"
                             " | %s%*s|\n"  // %*s aggiunge spazi in base a spaziNecessari\n"
                             " | NESSUNO                            |\n"
                             " |                                    |\n"
                             " +------------------------------------+  \n"
                             "                  [%d]                    \n\n\n",  carta->valoreCarta, carta->nomeCarta, spaziNecessari,"", indice);
                break;
        }
        carta = carta->next;
        indice++;
    }
}
