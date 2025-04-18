#ifndef HAPPY_LITTLE_STUDENTS_V0_2_SHUFFLEMAZZOOSTACOLI_H
#define HAPPY_LITTLE_STUDENTS_V0_2_SHUFFLEMAZZOOSTACOLI_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Divide un mazzo di carte ostacolo in due parti.
 *
 * La funzione divide un mazzo di carte ostacolo in due parti, separando le prime
 * numCartePrimoMazzoOstacoli carte dal mazzo originale.
 *
 * @param mazzoOstacoli Il mazzo di carte ostacolo da dividere.
 * @param numCartePrimoMazzoOstacoli Il numero di carte che devono rimanere nel primo mazzo.
 * @return Il puntatore al secondo mazzo di carte ostacolo.
 */
CartaOstacolo* smezzaCarteOstacolo(CartaOstacolo * mazzoOstacoli, int numCartePrimoMazzoOstacoli);


/***************************************************************************************************************************/

/**
 * Pesca una carta ostacolo dal mazzo.
 *
 * La funzione estrae la carta ostacolo superiore dal mazzo e aggiorna il mazzo.
 *
 * @param mazzoOstacolo Il puntatore al mazzo di carte ostacolo.
 * @return La carta ostacolo pescata.
 */
CartaOstacolo pescaCartaOstacolo(CartaOstacolo ** mazzoOstacolo);


/***************************************************************************************************************************/


/**
 * Aggiunge una carta ostacolo in fondo al mazzo.
 *
 * La funzione aggiunge una carta ostacolo in fondo al mazzo di carte ostacolo.
 *
 * @param mazzoOstacolo Il puntatore al mazzo di carte ostacolo.
 * @param carta La carta ostacolo da aggiungere.
 */
void aggiungiCartaOstacoloInfondo(CartaOstacolo** mazzoOstacolo, CartaOstacolo carta);


/***************************************************************************************************************************/


/**
 * Esegue uno shuffle "riffle" del mazzo di carte ostacolo.
 *
 * La funzione divide il mazzo di carte ostacolo in due parti e le mescola insieme
 * utilizzando un algoritmo di shuffle "riffle".
 *
 * Un ringraziamento speciale a Scoc che ha reso possibile l'implementazione di questo algoritmo grazie al suo grande aiuto!
 *
 *
 * @param mazzoOstacolo Il puntatore al mazzo di carte ostacolo.
 */
void riffleShuffleOstacolo(CartaOstacolo** mazzoOstacolo);


/***************************************************************************************************************************/


/**
 * Unisce due mazzi di carte ostacolo.
 *
 * La funzione unisce due mazzi di carte ostacolo, aggiungendo il secondo mazzo in fondo al primo.
 *
 * @param mazzoOstacolo Il puntatore al primo mazzo di carte ostacolo.
 * @param mazzo_aggiunto Il puntatore al secondo mazzo di carte ostacolo da aggiungere.
 */
void unisciMazziOstacolo(CartaOstacolo * mazzo, CartaOstacolo * mazzo_aggiunto);


/***************************************************************************************************************************/


/**
 * @brief Mescola il mazzo di carte ostacolo.
 *
 * La funzione esegue più iterazioni di shuffle del mazzo di carte ostacolo utilizzando
 * un algoritmo di shuffle "riffle" e unendo le due metà del mazzo.
 *
 * @param mazzoOstacolo Il puntatore al mazzo di carte ostacolo.
 * @param loops Il numero di iterazioni di shuffle da eseguire.
 *
 * loops non è altro che una costante creata ad hoc e settata a 30
 */
void shuffleMazzoOstacoli(CartaOstacolo ** mazzo, int loops);

#endif //HAPPY_LITTLE_STUDENTS_V0_2_SHUFFLEMAZZOOSTACOLI_H
