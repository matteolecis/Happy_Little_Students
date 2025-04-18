#ifndef HAPPY_LITTLE_STUDENTS_V0_2_INIZIALIZZAGIOCATORI_H
#define HAPPY_LITTLE_STUDENTS_V0_2_INIZIALIZZAGIOCATORI_H
#include "../../../subroutines/misclibs/misclibs.h"
#include "../../../subroutines/faseUno/inizializzaGiocatori/prendiNumeroGiocatori/prendiNumeroGiocatori.h"

/**
 * Inizializza i giocatori della partita.
 *
 * Questa funzione richiede all'utente di inserire il numero di giocatori (tra 2 e 4).
 * Per ogni giocatore, richiede un nome utente e assegna casualmente un personaggio.
 * Ogni giocatore riceve 5 carte CFU dal mazzo. I giocatori sono collegati in una lista.
 *
 * @param head Puntatore al puntatore alla testa della lista dei giocatori.
 * @param mazzoCfu Puntatore al puntatore al mazzo di carte CFU da cui distribuire le carte.
 * @return Giocatore Puntatore all'ultimo giocatore della lista.
 */
Giocatore inizializzaGiocatori(Giocatore **head, CartaCFU **mazzoCfu);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_INIZIALIZZAGIOCATORI_H
