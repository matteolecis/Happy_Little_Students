#ifndef HAPPY_LITTLE_STUDENTS_V0_2_GIOCACARTA_H
#define HAPPY_LITTLE_STUDENTS_V0_2_GIOCACARTA_H
#include "../../../../../subroutines/misclibs/misclibs.h"

/**
 * Gioca una carta CFU per il giocatore corrente.
 *
 * Questa funzione consente al giocatore corrente di selezionare e giocare una carta CFU dalla propria mano.
 * La carta selezionata viene rimossa dalla mano del giocatore, inserita nel mazzo delle carte CFU scartate
 * e memorizzata come una giocata nel turno corrente.
 *
 * @param giocatoreCorrente Il giocatore che sta giocando la carta CFU.
 * @param mazzoCFU Un puntatore al mazzo delle carte CFU.
 * @param mazzoCFUScarti Un puntatore al mazzo delle carte CFU scartate.
 * @return Un puntatore a una struttura Giocata che rappresenta la giocata effettuata.
 */
Giocata* giocaCarta(Giocatore *giocatoreCorrente, CartaCFU **mazzoCFU, CartaCFU **mazzoCFUScarti);


#endif //HAPPY_LITTLE_STUDENTS_V0_2_GIOCACARTA_H
