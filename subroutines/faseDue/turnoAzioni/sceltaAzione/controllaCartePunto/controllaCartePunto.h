#ifndef HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLACARTEPUNTO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLACARTEPUNTO_H
#include "../../../../../subroutines/misclibs/misclibs.h"

/**
 * Controlla se un giocatore possiede almeno una carta CFU punto.
 *
 * La funzione verifica se il giocatore possiede almeno una carta CFU punto tra le carte nella sua mano.
 *
 * @param giocatore Puntatore al giocatore da controllare.
 * @return 1 se il giocatore ha almeno una carta CFU punto, 0 altrimenti.
 */
int controllaCartePunto(Giocatore *giocatore);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLACARTEPUNTO_H
