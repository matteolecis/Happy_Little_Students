#ifndef HAPPY_LITTLE_STUDENTS_V0_2_MISCLIBS_H
#define HAPPY_LITTLE_STUDENTS_V0_2_MISCLIBS_H

#include "../../structs/cartaCFU.h"
#include "../../structs/cartaOstacolo.h"
#include "../../structs/giocata.h"
#include "../../structs/giocatore.h"
#include "../../structs/personaggio.h"
#include "../../structs/cartaOstacoloEstratta.h"
#include "../../subroutines/faseUno/faseUno.h"
#include "../../subroutines/faseDue/faseDue.h"
#include "../../subroutines/faseTre/faseTre.h"
#include "../../subroutines/misclibs/gestioneLog/gestioneLog.h"
#include "../../subroutines/misclibs/gestioneSalvataggi/salvaPartita/salvaPartita.h"
#include "../../subroutines/misclibs/gestioneSalvataggi/caricaSalvataggio/caricaSalvataggio.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/stampaPlanciaPersonaggio/stampaPlanciaGiocatore.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <ctype.h>

#define AUMENTA_DIMINUISCI 2 //Usata per gestire gli effetti AUMENTA e DIMINUISCI delle carte CFU
#define MIN_NUM_GIOCATORI 2
#define MAX_NUM_GIOCATORI 4
#define MAX_NUM_OSTACOLI 4
#define MAX_CHAR 32
#define MAX_DESC_OSTACOLI 128
#define NUM_CARTE_CFU 58
#define NUM_CARTE_OSTACOLO 28
#define LOOPS 30
#define MAX_NUM_TURNI 9999 //Usata per far ciclare i turni ad un numero talmente elevato che ci sarà per forza un vincitore
#define CFU_VITTORIA 60 //CFU necessari per vincere
#define MAX_NOME_SAVE 64 //Lunghezza massima nome salvataggio
#define MAX_CARTE_MANO 5 //Usata per far pescare fino a cinque carte ad ogni giocatore ogni turno
#define ULTIMA_CARTA_PUNTO 10 //Usata per funzioni dove è necessario capire e separare le carte cfu punto da quelle istantanee
#define MAX_CARTE_SCARTAC 3 //Usato per gestire l'effetto SCARTAC dove il massimo numero che puoi scartare di carte è 3
#define MAX_CARTE_OSTACOLO_PRENDIBILI 3 //usato per controllare se il giocatore ha preso 3 carte ostacolo ed è morto

/***************************************************************************************************************************


/**
 * Una funzione che ricevuti due estremi di un range, restituisce
 * un numero randomico compreso nel range[min, max].
 **/
int randNumInRange(int min, int max);


/***************************************************************************************************************************/


/**
 * Conta il numero di giocatori in una lista collegata di giocatori.
 *
 * @param *listagiocatori Puntatore alla testa della lista di giocatori.
 * @return Il numero di giocatori nella lista.
 */
int contaGiocatori(Giocatore *listagiocatori);


/***************************************************************************************************************************/


/**
 * Conta il numero di carte CFU di un giocatore.
 *
 * @param giocatore Puntatore alla struttura del giocatore.
 * @return Il numero di carte CFU del giocatore.
 */
int contaCarteCFU(Giocatore *giocatore);


/***************************************************************************************************************************/


/**
 * Conta il numero di carte CFU istantanee (con effetto da AUMENTA a DIROTTA) di un giocatore.
 *
 * @param giocatore Puntatore alla struttura del giocatore.
 * @return Il numero di carte CFU istantanee del giocatore.
 */
int contaCarteCFUIstantanee(Giocatore *giocatore);


/***************************************************************************************************************************/


/**
 * Conta il numero di carte CFU in un mazzo di carte CFU.
 *
 * @param mazzoCfu Puntatore alla testa del mazzo di carte CFU.
 * @return Il numero di carte CFU nel mazzo.
 */
int contaCarteMazzoCfu(CartaCFU *mazzoCfu);


/***************************************************************************************************************************/


/**
 * Conta il numero di carte ostacolo in un mazzo di carte ostacolo.
 *
 * @param mazzoOstacoli Puntatore alla testa del mazzo di carte ostacolo.
 * @return Il numero di carte ostacolo nel mazzo.
 */
int contaCarteOstacolo(CartaOstacolo *mazzoOstacoli);


/***************************************************************************************************************************/


/**
 * Aggiunge una carta CFU alla mano di un giocatore.
 *
 * @param giocatore Puntatore alla struttura del giocatore.
 * @param carta Puntatore alla carta CFU da aggiungere.
 */
void aggiungiCartaCFU(Giocatore *giocatore, CartaCFU *carta);


/***************************************************************************************************************************/


/**
 * Cerca un giocatore in una lista di giocatori per nome.
 *
 * @param listaGiocatori Puntatore alla testa della lista di giocatori.
 * @param nomeGiocatore Nome del giocatore da cercare.
 * @return Puntatore al giocatore trovato, o NULL se non trovato.
 */
Giocatore* scegliGiocatore(Giocatore *listaGiocatori, char *nomeGiocatore);


/***************************************************************************************************************************/


/**
 * Ottiene una carta CFU di un giocatore dato un indice.
 *
 * @param giocatore Puntatore alla struttura del giocatore.
 * @param indiceCarta Indice della carta CFU da ottenere.
 * @return Puntatore alla carta CFU.
 */
CartaCFU* getCartaCFU(Giocatore *giocatore, int indiceCarta);


/***************************************************************************************************************************/


/**
 * Verifica se un giocatore possiede carte CFU con effetti speciali.
 *
 * @param giocatore Puntatore alla struttura del giocatore.
 * @return 1 se il giocatore ha almeno una carta con effetto, 0 altrimenti.
 */
int haCarteConEffetto(Giocatore *giocatore);


/***************************************************************************************************************************/


/**
 * Trova una giocata di un giocatore specifico in una lista di giocate.
 *
 * @param listaGiocate Puntatore alla testa della lista di giocate.
 * @param giocatore Puntatore alla struttura del giocatore.
 * @return Puntatore alla giocata trovata, o NULL se non trovata.
 */
Giocata* trovaGiocata(Giocata *listaGiocate, Giocatore *giocatore);


/***************************************************************************************************************************/


/**
 * Conta il numero di carte istantanee (effetti da AUMENTA a DIROTTA) di un giocatore.
 *
 * @param giocatore Puntatore alla struttura del giocatore.
 * @return Il numero di carte istantanee del giocatore.
 */
int contaCarteIstantanee(Giocatore *giocatore);


/***************************************************************************************************************************/


/**
 * Scarta una lista di carte CFU aggiungendole al mazzo degli scarti.
 *
 * @param mazzoCfuScarti Puntatore alla testa del mazzo degli scarti.
 * @param carteDaScartare Puntatore alla testa della lista di carte da scartare.
 */
void scartaCarte(CartaCFU **mazzoCfuScarti, CartaCFU *carteDaScartare);


/***************************************************************************************************************************/

//TODO DOCUMENTAZIONE MANCANTE
// Funzione per mettere una carta Ostacolo in fondo al mazzo
void mettiCartaOstacoloInFondo(CartaOstacolo **mazzoOstacoli, CartaOstacolo *cartaOstacolo);


/***************************************************************************************************************************/


/**
 * Libera la memoria allocata per diverse strutture di gioco.
 *
 * @param listaPersonaggi Array dei personaggi.
 * @param mazzoCfu Puntatore al mazzo di carte CFU.
 * @param mazzoCfuScarti Puntatore al mazzo di carte CFU scartate.
 * @param mazzoOstacoli Puntatore al mazzo di carte ostacolo.
 * @param listaGiocatori Puntatore alla testa della lista di giocatori.
 */
void freeall(Personaggio listaPersonaggi[4],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori);


/***************************************************************************************************************************/


/**
 * Mostra un messaggio che richiede di premere [1] per continuare.
 */
void premiUnoPerContinuare();


/***************************************************************************************************************************/


/**
 * Cancella lo schermo della console.
 *
 * Utilizza il comando appropriato in base al sistema operativo.
 */
void clearScreen();


/***************************************************************************************************************************/


/**
 * Divide una stringa in due parti, cercando di mantenere parole intere in ogni parte.
 *
 * @param input La stringa di input da dividere.
 * @param part1 Buffer per la prima parte della stringa.
 * @param part2 Buffer per la seconda parte della stringa.
 * @param maxLength La lunghezza massima per ogni parte.
 */
void divideString(const char *input, char *part1, char *part2, int maxLength);


/***************************************************************************************************************************/


/**
 * Stampa informazioni di debug per una lista di giocate.
 *
 * @param listaGiocate Puntatore alla testa della lista di giocate.
 */
void stampaDebugGiocate(Giocata *listaGiocate);


/***************************************************************************************************************************/


/**
 * Stampa informazioni di debug per una lista di giocatori.
 *
 * @param listaGiocatori Puntatore alla testa della lista di giocatori.
 */
void stampaDebugGiocatori(Giocatore *listaGiocatori);


/***************************************************************************************************************************/


/**
 * Stampa informazioni di debug sulle carte ostacolo possedute dai giocatori.
 *
 * @param listaGiocatori Puntatore alla testa della lista di giocatori.
 */
void stampaDebugCarteOstacolo(Giocatore *listaGiocatori);


#endif //HAPPY_LITTLE_STUDENTS_V0_2_MISCLIBS_H
