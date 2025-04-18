#ifndef HAPPY_LITTLE_STUDENTS_V0_3_CONDIZIONIDIVITTORIA_H
#define HAPPY_LITTLE_STUDENTS_V0_3_CONDIZIONIDIVITTORIA_H
#include "../../../subroutines/misclibs/misclibs.h"
/**
 * Verifica le condizioni di vittoria e termina la partita se sono soddisfatte.
 *
 * Questa funzione controlla se uno dei giocatori ha raggiunto i CFU necessari per vincere la partita,
 * oppure se è rimasto un solo giocatore. In tal caso, stampa un messaggio di vittoria e termina il gioco.
 *
 * @param listagiocatori Puntatore al puntatore della lista dei giocatori.
 */
void condizioniDiVittoria(Giocatore **listagiocatori);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_CONDIZIONIDIVITTORIA_H
