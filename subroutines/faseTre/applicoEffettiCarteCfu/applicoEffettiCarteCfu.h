#ifndef HAPPY_LITTLE_STUDENTS_V0_3_APPLICOEFFETTICARTECFU_H
#define HAPPY_LITTLE_STUDENTS_V0_3_APPLICOEFFETTICARTECFU_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Applica gli effetti delle carte CFU giocati durante il turno corrente.
 *
 * Questa funzione esamina le giocate effettuate dai giocatori durante il turno corrente,
 * determina il valore massimo degli effetti delle carte giocati e applica gli effetti in ordine
 * decrescente di valore. Gli effetti sono descritti uno per uno qui sotto
 *
 * @param listaPersonaggi Array contenente i personaggi di tutti i giocatori.
 * @param mazzoCfu Un puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Un puntatore al mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Un puntatore al mazzo delle carte ostacolo.
 * @param listaGiocatori Un puntatore alla lista di giocatori della partita.
 * @param listaGiocate Un puntatore al puntatore della lista delle giocate effettuate nel turno.
 */
void applicoEffettiCarteCfu(Personaggio listaPersonaggi[4],
                            CartaCFU **mazzoCfu,
                            CartaCFU **mazzoCfuScarti,
                            CartaOstacolo **mazzoOstacoli,
                            Giocatore **listaGiocatori,
                            Giocata **listaGiocate);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Scarta P" per il giocatore corrente durante il turno.
 *
 * 1 [SCARTAP] Scarta una carta CFU punto e aggiungi il suo punteggio a quello del turno
 *
 * Questa funzione consente al giocatore corrente di scegliere una carta CFU dalla propria mano
 * da scartare, aggiornando il punteggio temporaneo del turno in base al valore della carta scartata.
 *
 * @param giocata Puntatore alla struttura Giocata contenente le informazioni sul turno corrente.
 */
void effettoScartaP(Giocata *giocata);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Ruba" per il giocatore corrente durante il turno.
 *
 * 2 [RUBA] Guarda la mano di un collega e ruba una carta a scelta.
 *
 * Questa funzione permette al giocatore corrente di scegliere un giocatore avversario da cui rubare
 * una carta CFU, aggiungendola alla propria mano se disponibile nel giocatore scelto.
 *
 * @param giocatoreCorrente Puntatore al giocatore che sta eseguendo l'effetto "Ruba".
 * @param listaGiocatori Puntatore alla lista dei giocatori della partita.
 */
void effettoRuba(Giocatore *giocatoreCorrente, Giocatore *listaGiocatori);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Scambia DS" per il giocatore corrente durante il turno.
 *
 * 3 [SCAMBIADS] Scambia questa carta con quella di un altro giocatore, purché senza effetto
 *
 * Questa funzione consente al giocatore corrente di scegliere un giocatore avversario con cui
 * scambiare una carta CFU senza effetto. Se il giocatore avversario ha almeno una carta senza effetto,
 * viene eseguito lo scambio tra le carte selezionate altrimento l'effetto non viene esaurito.
 *
 * @param giocatoreCorrente Puntatore al giocatore che sta eseguendo l'effetto "Scambia DS".
 * @param listaGiocatori Puntatore alla lista dei giocatori della partita.
 */
//TODO MANCA CONTROLLO SE IL GIOCATORE SCELTO NON HA CARTE SENZA EFFETTO
//TODO MAGARI INSERIRE UN WHILE SU LISTAGIOCATORI E CREARE UNA LISTA DI GIOCATORI CHE HANNO SOLO CARTE SENZA EFFETTO E
//TODO POTER SCEGLIERE SOLO TRA QUEI GIOCATORI? SE NON CI SONO GIOCATORI CON CARTE S/EFFETTO ALLORA LA CARTA SI GIOCA SENZA EFFETTO
void effettoScambiaDS(Giocatore *giocatoreCorrente, Giocatore *listaGiocatori);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Scarta E" per il giocatore corrente durante il turno.
 *
 * 4 [SCARTAE] Scarta una carta CFU punto con effetto e aggiungi il suo punteggio a quello del turno
 *
 * Questa funzione consente al giocatore corrente di scegliere una carta CFU con effetto dalla propria
 * mano da scartare, aggiornando il punteggio temporaneo del turno in base al valore della carta scartata.
 * Se il giocatore non ha carte con effetto, la funzione restituisce la carta SCARTAE alla mano del giocatore
 * e consente di scegliere un'altra carta da giocare.
 *
 * @param giocata Puntatore alla struttura Giocata contenente le informazioni sul turno corrente.
 * @param mazzoCfu Puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al mazzo delle carte CFU scartate.
 */
void effettoScartaE(Giocata *giocata, CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Scarta C" per il giocatore corrente durante il turno.
 *
 * 5 [SCARTAC] Scarta da uno a tre carte dalla tua mano
 *
 * Questa funzione consente al giocatore corrente di scegliere un numero specifico di carte CFU dalla propria
 * mano da scartare. Il giocatore può scartare da 1 a un massimo di (numero di carte in mano - 1) carte CFU.
 *
 * @param giocata Puntatore alla struttura Giocata contenente le informazioni sul turno corrente.
 */

void effettoScartaC(Giocata *giocataCorrente);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Scambia P" tra le giocate presenti nella lista delle giocate.
 *
 * 6 [SCAMBIAP] Scambia il punteggio del turno maggiore e minore dopo il calcolo del punteggio di base
 *
 * Questa funzione trova le giocate con il punteggio temporaneo minimo e massimo tra quelle presenti nella lista
 * e scambia i punteggi temporanei delle due giocate. Se non ci sono abbastanza giocate per effettuare lo scambio,
 * stampa un messaggio di avviso.
 *
 * @param listaGiocate Puntatore alla testa della lista delle giocate.
 */

void effettoScambiaP(Giocata *listaGiocate);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Doppio E" per il giocatore corrente durante il turno.
 *
 * 7 [DOPPIOE] Raddoppia gli effetti delle carte che aumentano o diminuiscono il punteggio (per tutti)
 *
 * Questa funzione implementa l'effetto "Doppio E", il quale deve essere definito ulteriormente nella logica di gioco.
 *
 * @param giocata Puntatore alla struttura Giocata contenente le informazioni sul turno corrente.
 */
void effettoDoppioE(Giocata **listaGiocate);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Sbircia" per il giocatore corrente durante il turno.
 *
 * 8 [SBIRCIA] Guarda due carte in cima al mazzo, prendine una e scarta l’altra
 *
 * Questa funzione consente al giocatore corrente di sbirciare le prime due carte dal mazzo delle carte CFU.
 * Il giocatore può scegliere una delle due carte visualizzate e aggiungerla alla propria mano, mentre l'altra
 * viene scartata nel mazzo degli scarti.
 *
 * @param giocata Puntatore alla struttura Giocata contenente le informazioni sul turno corrente.
 * @param mazzoCfu Puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al mazzo delle carte CFU scartate.
 */
void effettoSbircia(Giocata *giocata, CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti);


/****************************************************************************************************************************/


/**
 * Applica l'effetto "Scambia C" tra giocatori nella lista dei giocatori.
 *
 * 9 [SCAMBIAC] Scambia la carta punto giocata nel turno da un giocatore G1 con quella di un giocatore G2, con G1 e G2
 * scelti dal giocatore che ha giocato la carta SCAMBIAC
 *
 * Questa funzione consente al giocatore di selezionare due giocatori dalla lista dei giocatori e scambiare
 * la carta CFU giocata da ciascuno dei due giocatori.
 *
 * @param listaGiocate Puntatore alla testa della lista delle giocate.
 * @param listaGiocatori Puntatore al puntatore della testa della lista dei giocatori.
 */
void effettoScambiaC(Giocata *giocataCorrente, Giocatore **listaGiocatori);


/****************************************************************************************************************************/


void effettoAnnulla(Giocata **listaGiocate);

#endif //HAPPY_LITTLE_STUDENTS_V0_3_APPLICOEFFETTICARTECFU_H
