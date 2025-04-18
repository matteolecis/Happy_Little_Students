#ifndef HAPPY_LITTLE_STUDENTS_V0_2_CALCOLOPUNTEGGIO_H
#define HAPPY_LITTLE_STUDENTS_V0_2_CALCOLOPUNTEGGIO_H
#include "../../../subroutines/misclibs/misclibs.h"
#include "../../../subroutines/faseTre/usaCarteCfuIstantanee/usaCarteCfuIstantanee.h"


/**
 * Calcola il punteggio temporaneo per ogni giocata e applica gli effetti delle carte CFU.
 *
 * Questa funzione calcola il punteggio temporaneo di ogni giocata, applicando gli eventuali bonus o malus
 * dovuti alle carte ostacolo estratte. Successivamente, chiama le funzioni per applicare gli effetti delle
 * carte CFU istantanee e permanenti.
 *
 * @param listaPersonaggi Array di strutture Personaggio che contiene i personaggi dei giocatori.
 * @param mazzoCfu Puntatore al puntatore del mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al puntatore del mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Puntatore al puntatore del mazzo delle carte ostacolo.
 * @param listaGiocatori Puntatore al puntatore della lista dei giocatori.
 * @param listaGiocate Puntatore al puntatore della lista delle giocate.
 */
void calcoloPunteggio(Personaggio listaPersonaggi[4],
                      CartaCFU **mazzoCfu,
                      CartaCFU **mazzoCfuScarti,
                      CartaOstacolo **mazzoOstacoli,
                      Giocatore **listaGiocatori,
                      Giocata **listaGiocate,
                      CartaOstacoloEstratta **cartaOstacoloEstratta);


/****************************************************************************************************************************/


/**
 * Applica il bonus o malus relativo alla carta ostacolo estratta nella giocata corrente.
 *
 * Questa funzione prende in input la giocata corrente e, se questa esiste e ha una carta ostacolo estratta,
 * applica il bonus o malus alla carta CFU giocata in base al tipo di ostacolo della carta estratta.
 * Il bonus o malus dipende dal valore associato al tipo di ostacolo nel personaggio del giocatore.
 * Il bonus o malus dipendono principalmente dal personaggio che un giocatore possiede.
 *
 * @param giocataCorrente Puntatore alla giocata corrente a cui applicare il bonus/malus.
 */
void applicaBonusMalus(Giocata *giocataCorrente);


/****************************************************************************************************************************/


void resetDoppioEffetto(Giocata **listaGiocate);


/****************************************************************************************************************************/


void resetAnnullaEffetto(Giocata **listaGiocate);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_CALCOLOPUNTEGGIO_H
