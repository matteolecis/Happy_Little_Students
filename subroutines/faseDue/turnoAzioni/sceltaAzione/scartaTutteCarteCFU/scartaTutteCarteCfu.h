#ifndef HAPPY_LITTLE_STUDENTS_V0_3_SCARTATUTTECARTECFU_H
#define HAPPY_LITTLE_STUDENTS_V0_3_SCARTATUTTECARTECFU_H
#include "../../../../../subroutines/misclibs/misclibs.h"

/**
 * Sposta tutte le carte CFU di un giocatore nel mazzo delle carte CFU scartate.
 *
 * Questa funzione prende tutte le carte CFU possedute da un giocatore e le sposta nel mazzo delle carte CFU scartate.
 * Alla fine dell'operazione, la mano del giocatore sarà vuota.
 *
 * @param giocatore Il giocatore il cui le carte CFU devono essere scartate.
 * @param mazzoCfuScarti Un puntatore al mazzo delle carte CFU scartate.
 */
void scartaTutteCarteCFU(Giocatore *giocatore, CartaCFU **mazzoCfuScarti);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_SCARTATUTTECARTECFU_H
