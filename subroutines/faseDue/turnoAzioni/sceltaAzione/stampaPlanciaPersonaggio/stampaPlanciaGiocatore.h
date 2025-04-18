#ifndef HAPPY_LITTLE_STUDENTS_V0_3_STAMPAPLANCIAGIOCATORE_H
#define HAPPY_LITTLE_STUDENTS_V0_3_STAMPAPLANCIAGIOCATORE_H
#include "../../../../../subroutines/misclibs/misclibs.h"
/**
 * Stampa la plancia del giocatore corrente con le informazioni relative al personaggio e ai CFU.
 *
 * Questa funzione stampa graficamente la plancia del giocatore corrente, includendo il nome del giocatore,
 * il punteggio CFU attuale, il nome del personaggio, e i punti relativi ai vari tipi di ostacoli.
 *
 * @param giocatoreCorrente Il giocatore di cui stampare la plancia.
 */
void stampaPlanciaGiocatore(Giocatore *giocatoreCorrente);

/**
 * @brief Calcola la lunghezza del numero dato in input.
 *
 * Questa funzione calcola la lunghezza del numero intero dato in input.
 * Viene restituita la lunghezza del numero, considerando anche il segno nel caso di numeri negativi.
 *
 * @param numero Il numero intero di cui calcolare la lunghezza.
 * @return La lunghezza del numero.
 */
int calcolaLunghezzaNumero(int numero);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_STAMPAPLANCIAGIOCATORE_H
