#ifndef HAPPY_LITTLE_STUDENTS_V0_3_MEMORIZZACARTEGIOCATENELTURNO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_MEMORIZZACARTEGIOCATENELTURNO_H
#include "../../../../../../subroutines/misclibs/misclibs.h"

/**
 * Aggiunge una giocata alla lista delle giocate nel turno corrente.
 *
 * Questa funzione crea una nuova struttura Giocata contenente un giocatore
 * e una carta CFU, quindi la aggiunge all'inizio della lista delle giocate
 * del turno corrente.
 *
 * @param listaGiocate Un puntatore alla lista delle giocate.
 * @param giocatore Un puntatore al giocatore che ha effettuato la giocata.
 * @param carta Un puntatore alla carta CFU giocata.
 */
void memorizzaCarteGiocateNelTurno(Giocata **listaGiocate, Giocatore *giocatore, CartaCFU *carta);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_MEMORIZZACARTEGIOCATENELTURNO_H
