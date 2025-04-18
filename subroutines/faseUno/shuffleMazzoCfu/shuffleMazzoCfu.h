#ifndef HAPPY_LITTLE_STUDENTS_V0_2_SHUFFLEMAZZOCFU_H
#define HAPPY_LITTLE_STUDENTS_V0_2_SHUFFLEMAZZOCFU_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Divide un mazzo di carte CFU in due parti.
 *
 * La funzione divide un mazzo di carte CFU in due parti, separando le prime
 * numCartePrimoMazzoCfu carte dal mazzo originale.
 *
 * @param mazzoCfu Il mazzo di carte CFU da dividere.
 * @param numCartePrimoMazzoCfu Il numero di carte che devono rimanere nel primo mazzo.
 * @return Il puntatore al secondo mazzo di carte CFU.
 */
CartaCFU* smezzaCarteCFU(CartaCFU* mazzoCfu, int numCartePrimoMazzoCfu);


/***************************************************************************************************************************/


/**
 * Pesca una carta CFU dal mazzo.
 *
 * La funzione estrae la carta CFU superiore dal mazzo e aggiorna il mazzo.
 * Ovviamente la funzione è stata sfruttata non solo per mischiare il mazzo ma anche per altre funzioni
 *
 * @param mazzoCfu Il puntatore al mazzo di carte CFU.
 * @return La carta CFU pescata.
 */
CartaCFU pescaCartaCfu(CartaCFU** mazzo);


/***************************************************************************************************************************/


/**
 * Aggiunge una carta CFU in fondo al mazzo.
 *
 * La funzione aggiunge una carta CFU in fondo al mazzo di carte CFU.
 *
 * @param mazzoCfu Il puntatore al mazzo di carte CFU.
 * @param carta La carta CFU da aggiungere.
 */
void aggiungiCartaCfuInfondo(CartaCFU** mazzoCfu, CartaCFU carta);


/***************************************************************************************************************************/


/**
 * Esegue uno shuffle "riffle" del mazzo di carte CFU.
 *
 * La funzione divide il mazzo di carte CFU in due parti e le mescola insieme
 * utilizzando un algoritmo di shuffle "riffle".
 *
 * Un ringraziamento speciale a Scoc che ha reso possibile l'implementazione di questo algoritmo grazie al suo grande aiuto!
 *
 * @param mazzoCfu Il puntatore al mazzo di carte CFU.
 */
void riffleShuffleCfu(CartaCFU** mazzoCfu);


/***************************************************************************************************************************/


/**
 * Unisce due mazzi di carte CFU.
 *
 * La funzione unisce due mazzi di carte CFU, aggiungendo il secondo mazzo in fondo al primo.
 *
 * @param mazzo Il puntatore al primo mazzo di carte CFU.
 * @param mazzo_aggiunto Il puntatore al secondo mazzo di carte CFU da aggiungere.
 */
void unisciMazziCFU(CartaCFU * mazzo, CartaCFU * mazzo_aggiunto);


/***************************************************************************************************************************/


/**
 * Mescola il mazzo di carte CFU.
 *
 * La funzione esegue più iterazioni di shuffle del mazzo di carte CFU utilizzando
 * un algoritmo di shuffle "riffle" e unendo le due metà del mazzo.
 *
 * @param mazzo Il puntatore al mazzo di carte CFU.
 * @param loops Il numero di iterazioni di shuffle da eseguire.
 *
 * loops non è altro che una costante creata ad hoc e settata a 30
 */
void shuffleMazzoCfu(CartaCFU **head, int loops);

#endif //HAPPY_LITTLE_STUDENTS_V0_2_SHUFFLEMAZZOCFU_H
