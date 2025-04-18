#include "stampaCartaOstacolo.h"
#define MAX_WIDTH 68 // Massima larghezza per le righe nel rettangolo
void stampaCartaOstacolo(CartaOstacoloEstratta cartaOstacoloEstratta) {
    // Stampa la carta ostacolo estratta
    printf("                        +-------------------------+\n"
            "                        | Carta Ostacolo Estratta | \n"
            "                        +-------------------------+\n\n"  );
    // Calcola la lunghezza del nome della carta
    int lunghezzaNome = strlen(cartaOstacoloEstratta.carta.nomeCarta);
    // Calcola quanti spazi sono necessari per allineare il quadrato
    int spaziNecessari = MAX_WIDTH - lunghezzaNome;

    // Suddividi la descrizione in due parti
    char descPart1[MAX_WIDTH - 2] = "";
    char descPart2[MAX_WIDTH - 2] = "";
    divideString(cartaOstacoloEstratta.carta.descrizione, descPart1, descPart2, MAX_WIDTH);

    switch(cartaOstacoloEstratta.carta.tipoOstacolo) {
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
                   cartaOstacoloEstratta.carta.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
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
                   cartaOstacoloEstratta.carta.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
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
                   cartaOstacoloEstratta.carta.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
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
                   cartaOstacoloEstratta.carta.nomeCarta,spaziNecessari,"",MAX_WIDTH-2,descPart1,MAX_WIDTH-2,descPart2);
            break;
        default:
            printf("Tipo Ostacolo: SCONOSCIUTO\n");
            break;
    }
    printf("\n\n");
}