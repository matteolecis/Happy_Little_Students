#ifndef HAPPY_LITTLE_STUDENTS_V0_3_RIMUOVICARTACFU_H
#define HAPPY_LITTLE_STUDENTS_V0_3_RIMUOVICARTACFU_H
#include "../../../../../../subroutines/misclibs/misclibs.h"

/**
 * Rimuove una carta CFU dalla mano di un giocatore.
 *
 * Questa funzione rimuove una carta CFU dalla mano di un giocatore, basandosi
 * sull'indice specificato, e restituisce un puntatore alla carta rimossa.
 *
 * @param giocatore Un puntatore al giocatore dal quale rimuovere la carta.
 * @param indiceCarta L'indice della carta da rimuovere.
 * @return Un puntatore alla carta CFU rimossa.
 */
CartaCFU* rimuoviCartaCFU(Giocatore *giocatore, int indiceCarta);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_RIMUOVICARTACFU_H
