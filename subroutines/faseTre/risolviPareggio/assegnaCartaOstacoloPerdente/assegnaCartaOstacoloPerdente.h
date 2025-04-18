#ifndef HAPPY_LITTLE_STUDENTS_V0_3_ASSEGNACARTAOSTACOLOPERDENTE_H
#define HAPPY_LITTLE_STUDENTS_V0_3_ASSEGNACARTAOSTACOLOPERDENTE_H
#include "../../../../subroutines/misclibs/misclibs.h"


/**
 * Assegna una nuova carta ostacolo a un giocatore perdente.
 *
 * Questa funzione assegna una copia della carta ostacolo appena estratta a un giocatore
 * che ha ottenuto il punteggio più basso in una giocata. La carta ostacolo viene duplicata
 * in modo che ogni giocatore possa avere la propria copia, mantenendo le informazioni
 * della carta originale.
 *
 * @param giocatorePerdente Puntatore al giocatore che riceve la carta ostacolo.
 * @param nuovaCartaOstacolo Puntatore alla carta ostacolo da assegnare.
 */
void assegnaCartaOstacoloPerdente(Giocatore *giocatore, CartaOstacolo *cartaOstacolo);


/*************************************************************************************************************************/


/**
 * Stampa a schermo le informazioni di una carta ostacolo assegnata a un giocatore perdente.
 *
 * Questa funzione stampa a schermo i dettagli di una carta ostacolo assegnata a un giocatore
 * che ha ottenuto il punteggio più basso in una giocata. La stampa include il nome della carta,
 * la sua descrizione divisa su più righe e un quadrato di delimitazione visuale.
 *
 * @param cartaOstacolo Puntatore alla struttura della carta ostacolo da stampare.
 */

void stampaCartaOstacoloAssegnataPerdente(CartaOstacolo *cartaOstacolo);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_ASSEGNACARTAOSTACOLOPERDENTE_H
