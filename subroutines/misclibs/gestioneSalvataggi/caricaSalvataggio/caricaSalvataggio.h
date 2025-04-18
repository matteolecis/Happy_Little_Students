#ifndef HAPPY_LITTLE_STUDENTS_V0_3_CARICASALVATAGGIO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_CARICASALVATAGGIO_H
#include <dirent.h>
#include <sys/types.h>
#include "../../../../subroutines/misclibs/misclibs.h"

/**
 * Carica i dati di un giocatore da un file binario.
 *
 * @param file Puntatore al file binario da cui leggere i dati del giocatore.
 * @param giocatore Puntatore al giocatore in cui memorizzare i dati letti.
 */
void caricaGiocatore(FILE *file, Giocatore *giocatore);


/***************************************************************************************************************************/


/**
 * Carica un mazzo di carte CFU da un file binario.
 *
 * @param file Puntatore al file binario da cui leggere il mazzo di carte CFU.
 * @param mazzo Puntatore al puntatore del mazzo di carte CFU da modificare con il mazzo letto.
 * @return Numero di carte CFU nel mazzo.
 */
int caricaMazzo(FILE *file, CartaCFU **mazzo);


/***************************************************************************************************************************/


/**
 * Carica un mazzo di carte Ostacolo da un file binario.
 *
 * @param file Puntatore al file binario da cui leggere il mazzo di carte Ostacolo.
 * @param mazzo Puntatore al puntatore del mazzo di carte Ostacolo da modificare con il mazzo letto.
 * @return Numero di carte Ostacolo nel mazzo.
 */
int caricaSaveMazzoOstacoli(FILE *file, CartaOstacolo **mazzo);


/***************************************************************************************************************************/


/**
 * @brief Mostra i file di salvataggio disponibili nella directory corrente con estensione .sav.
 */
void mostraSalvataggiDisponibili();


/***************************************************************************************************************************/


/**
 * Carica una partita salvata da file, includendo giocatori, mazzi di carte CFU e Ostacolo.
 *
 * @param nomeFile Nome del file di salvataggio (senza estensione) da cui caricare la partita.
 * @param listaGiocatori Puntatore al puntatore della lista dei giocatori da popolare con i dati caricati.
 * @param mazzoCFU Puntatore al puntatore del mazzo di carte CFU da popolare con i dati caricati.
 * @param scartiCFU Puntatore al puntatore del mazzo di carte CFU scartate da popolare con i dati caricati.
 * @param mazzoOstacoli Puntatore al puntatore del mazzo di carte Ostacolo da popolare con i dati caricati.
 */
void caricaPartita(char nomeFile[64],Giocatore **listaGiocatori, CartaCFU **mazzoCFU, CartaCFU **scartiCFU, CartaOstacolo **mazzoOstacoli);


#endif //HAPPY_LITTLE_STUDENTS_V0_3_CARICASALVATAGGIO_H
