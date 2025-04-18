#include "aggiornaPunteggioTemporaneo.h"
void aggiornaPunteggioTemporaneo(Giocata **listaGiocate, CartaOstacoloEstratta cartaOstacoloEstratta) {
    Giocata *giocataCorrente = *listaGiocate;
    while (giocataCorrente != NULL) {
        giocataCorrente->punteggioTemporaneo = 0; // Azzeramento
        if (giocataCorrente->carta != NULL) {
            giocataCorrente->punteggioTemporaneo += giocataCorrente->carta->valoreCarta; // Aggiornamento

            if (cartaOstacoloEstratta.carta.tipoOstacolo == STUDIO) {
                if (giocataCorrente->giocatore->personaggio.tipoOstacoli[STUDIO] < 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[STUDIO];
                    printf("\n%s, Il tuo punteggio è stato modificato di %d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[STUDIO]);
                }
                else if(giocataCorrente->giocatore->personaggio.tipoOstacoli[STUDIO] > 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[STUDIO];
                    printf("\n%s, Il tuo punteggio è stato modificato di +%d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[STUDIO]);
                }
            }

//===============================================================================================================================

            if (cartaOstacoloEstratta.carta.tipoOstacolo == SOPRAVVIVENZA) {
                if (giocataCorrente->giocatore->personaggio.tipoOstacoli[SOPRAVVIVENZA] < 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[SOPRAVVIVENZA];
                    printf("\n%s, Il tuo punteggio è stato modificato di %d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[SOPRAVVIVENZA]);
                }
                else if(giocataCorrente->giocatore->personaggio.tipoOstacoli[SOPRAVVIVENZA] > 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[SOPRAVVIVENZA];
                    printf("\n%s, Il tuo punteggio è stato modificato di +%d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[SOPRAVVIVENZA]);
                }
            }

//===============================================================================================================================


            if (cartaOstacoloEstratta.carta.tipoOstacolo == SOCIALE) {
                if (giocataCorrente->giocatore->personaggio.tipoOstacoli[SOCIALE] < 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[SOCIALE];
                    printf("\n%s, Il tuo punteggio è stato modificato di %d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[SOCIALE]);
                }
                else if(giocataCorrente->giocatore->personaggio.tipoOstacoli[SOCIALE] > 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[SOCIALE];
                    printf("\n%s, Il tuo punteggio è stato modificato di +%d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[SOCIALE]);
                }
            }

//===============================================================================================================================

            if (cartaOstacoloEstratta.carta.tipoOstacolo == ESAME) {
                if (giocataCorrente->giocatore->personaggio.tipoOstacoli[ESAME] < 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[ESAME];
                    printf("\n%s, Il tuo punteggio è stato modificato di %d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[ESAME]);
                }
                else if(giocataCorrente->giocatore->personaggio.tipoOstacoli[ESAME] > 0) {
                    giocataCorrente->punteggioTemporaneo += giocataCorrente->giocatore->personaggio.tipoOstacoli[ESAME];
                    printf("\n%s, Il tuo punteggio è stato modificato di +%d PUNTI (BONUS/MALUS Personaggio.)\n",
                           giocataCorrente->giocatore->nomeUtente,
                           giocataCorrente->giocatore->personaggio.tipoOstacoli[ESAME]);
                }
            }
            // Controlla se il punteggio temporaneo è inferiore a zero e lo imposta a zero se necessario
            if (giocataCorrente->punteggioTemporaneo < 0) {
                giocataCorrente->punteggioTemporaneo = 0;
            }
        }

        printf("\n%s al momento ha fatto %d punti!\n", giocataCorrente->giocatore->nomeUtente,
               giocataCorrente->punteggioTemporaneo);
        giocataCorrente = giocataCorrente->next;
    }
    printf("\nPuoi giocare una carta istantanea per cambiare la situazione! (Se ne possiedi almeno una)\n");
}