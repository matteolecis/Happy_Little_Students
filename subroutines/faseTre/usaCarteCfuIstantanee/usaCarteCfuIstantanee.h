#ifndef HAPPY_LITTLE_STUDENTS_V0_3_USACARTECFUISTANTANEE_H
#define HAPPY_LITTLE_STUDENTS_V0_3_USACARTECFUISTANTANEE_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Gestisce l'uso delle carte CFU istantanee da parte dei giocatori.
 *
 * Questa funzione permette ai giocatori di giocare una carta CFU istantanea, applicandone
 * l'effetto al gioco. Se un giocatore non ha carte istantanee, viene richiesto di procedere
 * senza giocare alcuna carta. L'effetto della carta selezionata viene applicato al turno corrente.
 *
 * @param listaPersonaggi Array dei personaggi dei giocatori.
 * @param mazzoCfu Puntatore al puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al puntatore al mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Puntatore al puntatore al mazzo delle carte ostacolo.
 * @param listaGiocatori Puntatore al puntatore alla lista dei giocatori.
 * @param listaGiocate Puntatore al puntatore alla lista delle giocate dei giocatori.
 */
void usaCarteCfuIstantanee(Personaggio listaPersonaggi[4],
                           CartaCFU **mazzoCfu,
                           CartaCFU **mazzoCfuScarti,
                           CartaOstacolo **mazzoOstacoli,
                           Giocatore **listaGiocatori,
                           Giocata **listaGiocate,
                           CartaOstacoloEstratta **cartaOstacoloEstratta);


/****************************************************************************************************************************/


/**
 * Applica l'effetto di aumentare il punteggio di un giocatore scelto.
 *
 * 11 [AUMENTA] Aumenta di 2 CFU il punteggio del turno di un giocatore a scelta
 *
 * Questa funzione permette al giocatore che ha giocato una carta CFU istantanea
 * di scegliere un altro giocatore e aumentare il suo punteggio temporaneo di 2 punti.
 *
 * @param giocata Puntatore alla giocata corrente contenente la carta CFU istantanea giocata.
 * @param listaGiocatori Puntatore al puntatore alla lista dei giocatori.
 * @param listaGiocate Puntatore al puntatore alla lista delle giocate dei giocatori.
 */
void effettoAumenta(Giocata *giocata, Giocatore **listaGiocatori, Giocata **listaGiocate);


/****************************************************************************************************************************/


/**
 * Applica l'effetto di diminuire il punteggio di un giocatore scelto.
 *
 * 12 [DIMINUISCI] Diminuisci di 2 CFU il punteggio del turno di un giocatore a scelta
 *
 * Questa funzione permette al giocatore che ha giocato una carta CFU istantanea
 * di scegliere un altro giocatore e diminuire il suo punteggio temporaneo di 2 punti.
 *
 * @param giocata Puntatore alla giocata corrente contenente la carta CFU istantanea giocata.
 * @param listaGiocatori Puntatore al puntatore alla lista dei giocatori.
 * @param listaGiocate Puntatore al puntatore alla lista delle giocate dei giocatori.
 */
void effettoDiminuisci(Giocata *giocata, Giocatore **listaGiocatori, Giocata **listaGiocate);


/****************************************************************************************************************************/


/**
 * Applica l'effetto di scambio dei punteggi temporanei tra il giocatore con il punteggio minore e quello con il punteggio maggiore.
 *
 * 13 [INVERTI] Inverti punteggio minimo e massimo del turno
 *
 * Questa funzione scambia i punteggi temporanei tra il giocatore con il punteggio più basso e quello con il punteggio più alto
 * all'interno della lista delle giocate, se ci sono più di una giocata. In caso contrario, stampa un messaggio di avviso.
 *
 * @param giocata Puntatore alla giocata corrente contenente le informazioni sul turno.
 */
void effettoInverti(Giocata *giocata);


/****************************************************************************************************************************/


void effettoSalva(Giocatore *giocatore, CartaOstacolo **mazzoOstacoli, CartaOstacoloEstratta **cartaOstacoloEstratta);


/****************************************************************************************************************************/


void effettoDirotta(Giocatore *giocatore, Giocatore **listaGiocatori, CartaOstacoloEstratta **cartaOstacoloEstratta);

#endif //HAPPY_LITTLE_STUDENTS_V0_3_USACARTECFUISTANTANEE_H
