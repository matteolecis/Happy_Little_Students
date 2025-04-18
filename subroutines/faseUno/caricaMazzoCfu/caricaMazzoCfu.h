#ifndef HAPPY_LITTLE_STUDENTS_V0_2_CARICAMAZZOCFU_H
#define HAPPY_LITTLE_STUDENTS_V0_2_CARICAMAZZOCFU_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Carica il mazzo di carte CFU da un file.
 *
 * Questa funzione legge il file "carte.txt" per caricare il mazzo di carte CFU.
 * Crea una lista collegata di carte CFU e la collega alla variabile head.
 *
 * @param head Puntatore al puntatore alla testa della lista delle carte CFU.
 * @return int Restituisce -1 se il file non è stato caricato correttamente, altrimenti restituisce 0.
 */
int caricaMazzoCFU(CartaCFU **head);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_CARICAMAZZOCFU_H
