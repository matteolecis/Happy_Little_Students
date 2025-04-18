#ifndef HAPPY_LITTLE_STUDENTS_V0_2_CARICAMAZZOOSTACOLI_H
#define HAPPY_LITTLE_STUDENTS_V0_2_CARICAMAZZOOSTACOLI_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Carica il mazzo di carte Ostacolo da un file.
 *
 * Questa funzione legge il file "ostacoli.txt" per caricare il mazzo di carte Ostacolo.
 * Crea una lista collegata di carte Ostacolo e la collega alla variabile head.
 *
 * @param head Puntatore al puntatore alla testa della lista delle carte Ostacolo.
 * @return int Restituisce -1 se il file non è stato caricato correttamente, altrimenti restituisce 0.
 */
int caricaMazzoOstacoli(CartaOstacolo **head);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_CARICAMAZZOOSTACOLI_H
