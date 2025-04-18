#ifndef HAPPY_LITTLE_STUDENTS_V0_2_SCELTAAZIONE_H
#define HAPPY_LITTLE_STUDENTS_V0_2_SCELTAAZIONE_H
#include "../../../../subroutines/misclibs/misclibs.h"

/**
 * Consente al giocatore corrente di scegliere un'azione da compiere nel proprio turno.
 *
 * Questa funzione gestisce l'interazione del giocatore con il gioco, permettendogli di giocare una carta CFU,
 * controllare lo stato degli altri giocatori, pulire lo schermo o uscire dalla partita.
 * Restituisce una giocata rappresentativa dell'azione effettuata dal giocatore nel turno corrente.
 *
 * @param giocatoreCorrente Il giocatore che sta effettuando un'azione nel turno.
 * @param listaGiocatori La lista di tutti i giocatori della partita.
 * @param mazzoOstacoli Un puntatore al mazzo delle carte ostacolo.
 * @param mazzoCfu Un puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Un puntatore al mazzo delle carte CFU scartate.
 * @param cartaEstratta Un puntatore alla carta ostacolo estratta per il turno corrente.
 * @return Un puntatore a una struttura Giocata che rappresenta l'azione effettuata dal giocatore.
 */
Giocata* sceltaAzione(Giocatore *giocatoreCorrente,
                      Giocatore **listaGiocatori,
                      CartaOstacolo **mazzoOstacoli,
                      CartaCFU **mazzoCfu,
                      CartaCFU **mazzoCfuScarti,
                      CartaOstacoloEstratta *cartaEstratta);


#endif //HAPPY_LITTLE_STUDENTS_V0_2_SCELTAAZIONE_H
