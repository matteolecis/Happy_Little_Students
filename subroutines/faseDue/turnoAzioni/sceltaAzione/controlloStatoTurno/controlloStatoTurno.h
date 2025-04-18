#ifndef HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLOSTATOTURNO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLOSTATOTURNO_H
#include "../../../../../subroutines/misclibs/misclibs.h"

/**
 * Controlla e stampa lo stato del turno corrente.
 *
 * La funzione stampa lo stato del turno corrente, inclusa la carta ostacolo estratta e lo stato degli altri giocatori,
 * comprese le loro carte ostacolo.
 *
 * @param listaGiocatori Puntatore alla lista dei giocatori.
 * @param cartaOstacoloCorrente Puntatore alla carta ostacolo corrente estratta.
 */
void controlloStatoTurno(Giocatore *listaGiocatori, CartaOstacoloEstratta *cartaOstacoloCorrente);


/**************************************************************************************************************************/

/**
 * Stampa la carta ostacolo estratta nel turno.
 *
 * Questa funzione stampa una rappresentazione grafica della carta ostacolo.
 * La stampa varia in base al tipo di ostacolo specificato nella carta.
 *
 * @param cartaOstacolo La carta ostacolo da stampare.
 */
void stampaCarteOstacoloControlloTurno(CartaOstacolo cartaOstacolo);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLOSTATOTURNO_H
