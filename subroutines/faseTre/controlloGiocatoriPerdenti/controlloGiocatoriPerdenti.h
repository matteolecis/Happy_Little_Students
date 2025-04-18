#ifndef HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLOGIOCATORIPERDENTI_H
#define HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLOGIOCATORIPERDENTI_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Rimette le carte ostacolo in fondo al mazzo delle carte ostacolo.
 *
 * Questa funzione riceve una lista di carte ostacolo da rimettere in fondo al mazzo.
 * Le carte vengono inserite alla fine del mazzo delle carte ostacolo.
 *
 * @param mazzoOstacoli Puntatore al puntatore del mazzo delle carte ostacolo.
 * @param carteDaRimettere Puntatore alla testa della lista delle carte ostacolo da rimettere.
 */
void rimettiCarteOstacoloInFondo(CartaOstacolo **mazzoOstacoli, CartaOstacolo *carteDaRimettere);


/************************************************************************************************************************/


/**
 * Dealloca un giocatore dalla lista dei giocatori attivi.
 *
 * Questa funzione rimuove un giocatore dalla lista dei giocatori attivi, scarta le sue carte CFU,
 * rimette le sue carte ostacolo in fondo al mazzo delle carte ostacolo e dealloca la memoria
 * associata al giocatore.
 *
 * @param listaGiocatori Puntatore al puntatore della lista dei giocatori.
 * @param giocatoreDaDeallocare Puntatore al giocatore da deallocare.
 * @param mazzoCfuScarti Puntatore al puntatore del mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Puntatore al puntatore del mazzo delle carte ostacolo.
 */
void deallocaGiocatore(Giocatore **listaGiocatori, Giocatore *giocatoreDaDeallocare, CartaCFU **mazzoCfuScarti, CartaOstacolo **mazzoOstacoli);


/*************************************************************************************************************************/


/**
 * @brief Controlla se ci sono giocatori da eliminare e li elimina se necessario.
 *
 * Questa funzione verifica se ci sono giocatori eliminati secondo le condizioni del gioco
 * (avere una carta ostacolo di ogni tipo oppure tre carte dello stesso tipo). Se un giocatore è
 * eliminato, lo rimuove dalla lista dei giocatori attivi, scarta le sue carte CFU e rimette
 * le sue carte ostacolo in fondo al mazzo delle carte ostacolo.
 *
 * @param listaGiocatori Puntatore al puntatore della lista dei giocatori.
 * @param mazzoCfuScarti Puntatore al puntatore del mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Puntatore al puntatore del mazzo delle carte ostacolo.
 */
void controlloGiocatoriPerdenti(Giocatore **listaGiocatori, CartaCFU **mazzoCfuScarti, CartaOstacolo **mazzoOstacoli);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_CONTROLLOGIOCATORIPERDENTI_H
