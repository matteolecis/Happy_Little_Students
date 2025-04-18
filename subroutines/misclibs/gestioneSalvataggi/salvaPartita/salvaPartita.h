#ifndef HAPPY_LITTLE_STUDENTS_V0_3_SALVAPARTITA_H
#define HAPPY_LITTLE_STUDENTS_V0_3_SALVAPARTITA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../../subroutines/misclibs/misclibs.h"

/**
 * Salva i dati di un giocatore in un file binario e un file di log txt.
 *
 * @param file Puntatore al file binario in cui salvare i dati.
 * @param log Puntatore al file di log txt in cui salvare i dati leggibili a occhi umani.
 * @param giocatore Puntatore al giocatore di cui salvare i dati.
 */
void salvaGiocatore(FILE *file, FILE *log, Giocatore *giocatore);


/***************************************************************************************************************************/

/**
 * Salva le carte CFU di un mazzo in un file binario e un file di log txt.
 *
 * @param file Puntatore al file binario in cui salvare i dati.
 * @param log Puntatore al file di log txt in cui salvare i dati leggibili a occhi umani.
 * @param mazzo Puntatore alla testa del mazzo di carte CFU da salvare.
 * @param numCarte Numero totale di carte CFU nel mazzo.
 */
void salvaMazzo(FILE *file, FILE *log, CartaCFU *mazzo, int numCarte);


/***************************************************************************************************************************/


/**
 * Salva le carte Ostacolo di un mazzo in un file binario e un file di log txt.
 *
 * @param file Puntatore al file binario in cui salvare i dati.
 * @param log Puntatore al file di log in cui salvare i dati leggibili a occhi umani.
 * @param mazzo Puntatore alla testa del mazzo di carte Ostacolo da salvare.
 * @param numCarte Numero totale di carte Ostacolo nel mazzo.
 */
void salvaMazzoOstacoli(FILE *file, FILE *log, CartaOstacolo *mazzo, int numCarte);


/***************************************************************************************************************************/


/**
 * Salva l'intera partita includendo informazioni su giocatori, mazzi di carte CFU e Ostacolo.
 *
 * @param nomeFile Nome del file di salvataggio (senza estensione).
 * @param listaGiocatori Puntatore alla lista dei giocatori da salvare.
 * @param mazzoCFU Puntatore alla testa del mazzo di carte CFU da salvare.
 * @param numCarteCFU Numero totale di carte CFU nel mazzo CFU.
 * @param scartiCFU Puntatore alla testa del mazzo di carte CFU scartate da salvare.
 * @param numCarteScarti Numero totale di carte CFU scartate.
 * @param mazzoOstacoli Puntatore alla testa del mazzo di carte Ostacolo da salvare.
 * @param numCarteOstacoli Numero totale di carte Ostacolo nel mazzo Ostacoli.
 */
void salvaPartita(char nomeFile[64],Giocatore *listaGiocatori, CartaCFU *mazzoCFU, int numCarteCFU, CartaCFU *scartiCFU, int numCarteScarti, CartaOstacolo *mazzoOstacoli, int numCarteOstacoli);


/***************************************************************************************************************************/


/**
 * Salva l'intera partita in modalità automatica usando un nome file predefinito, senza interazione utente.
 * Usato principalmente per salvare ad ogni turno sullo stesso file inserito a inizio partita
 *
 * @param nomeFile Nome del file di salvataggio (senza estensione).
 * @param listaGiocatori Puntatore alla lista dei giocatori da salvare.
 * @param mazzoCFU Puntatore alla testa del mazzo di carte CFU da salvare.
 * @param numCarteCFU Numero totale di carte CFU nel mazzo CFU.
 * @param scartiCFU Puntatore alla testa del mazzo di carte CFU scartate da salvare.
 * @param numCarteScarti Numero totale di carte CFU scartate.
 * @param mazzoOstacoli Puntatore alla testa del mazzo di carte Ostacolo da salvare.
 * @param numCarteOstacoli Numero totale di carte Ostacolo nel mazzo Ostacoli.
 */
void salvaPartitaAutomatico(char nomeFile[64], Giocatore *listaGiocatori, CartaCFU *mazzoCFU, int numCarteCFU, CartaCFU *scartiCFU, int numCarteScarti, CartaOstacolo *mazzoOstacoli, int numCarteOstacoli);

#endif //HAPPY_LITTLE_STUDENTS_V0_3_SALVAPARTITA_H
