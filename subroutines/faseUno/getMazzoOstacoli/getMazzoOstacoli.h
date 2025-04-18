#ifndef HAPPY_LITTLE_STUDENTS_V0_2_GETMAZZOOSTACOLI_H
#define HAPPY_LITTLE_STUDENTS_V0_2_GETMAZZOOSTACOLI_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Ottiene il mazzo di ostacoli caricandolo da un file se non è già stato caricato.
 *
 * Questa funzione verifica se il mazzo di ostacoli è già stato caricato. Se non lo è, lo carica
 * utilizzando la funzione caricaMazzoOstacoli. Restituisce il puntatore alla testa della lista delle carte Ostacolo.
 *
 * @return CartaOstacolo* Puntatore alla testa della lista delle carte Ostacolo.
 */
CartaOstacolo* getMazzoOstacoli();

#endif //HAPPY_LITTLE_STUDENTS_V0_2_GETMAZZOOSTACOLI_H
