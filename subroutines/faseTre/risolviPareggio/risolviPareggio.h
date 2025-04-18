#ifndef HAPPY_LITTLE_STUDENTS_V0_3_RISOLVIPAREGGIO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_RISOLVIPAREGGIO_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Risolve un pareggio tra giocatori sulla base delle loro giocate.
 *
 * Questa funzione determina il vincitore e il perdente di un turno in cui i giocatori
 * hanno ottenuto punteggi identici. Gestisce anche i casi in cui tutti i giocatori
 * hanno lo stesso punteggio, evitando di dichiarare vincitori o perdenti in tale caso.
 * In caso di pareggio per il punteggio più basso, viene eseguito un turno aggiuntivo
 * tra i giocatori coinvolti per determinare un unico perdente.
 *
 * @param listaPersonaggi Array di strutture dei personaggi dei giocatori.
 * @param mazzoCfu Puntatore al puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al puntatore al mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Puntatore al puntatore al mazzo delle carte ostacolo.
 * @param listaGiocatori Puntatore al puntatore alla lista dei giocatori.
 * @param listaGiocate Puntatore al puntatore alla lista delle giocate dei giocatori.
 * @param cartaOstacoloEstratta Puntatore alla struttura contenente la carta ostacolo estratta.
 */

void risolviPareggio(Personaggio listaPersonaggi[4],
                     CartaCFU **mazzoCfu,
                     CartaCFU **mazzoCfuScarti,
                     CartaOstacolo **mazzoOstacoli,
                     Giocatore **listaGiocatori,
                     Giocata **listaGiocate,
                     CartaOstacoloEstratta *cartaOstacoloEstratta);

int trovaGiocatore(Giocatore *lista, Giocatore *giocatore);

#endif //HAPPY_LITTLE_STUDENTS_V0_3_RISOLVIPAREGGIO_H
