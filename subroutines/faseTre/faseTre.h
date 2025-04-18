#ifndef HAPPY_LITTLE_STUDENTS_V0_2_FASETRE_H
#define HAPPY_LITTLE_STUDENTS_V0_2_FASETRE_H
#include "../../subroutines/misclibs/misclibs.h"
#include "../../subroutines/faseTre/calcoloPunteggio/calcoloPunteggio.h"
#include "../../subroutines/faseTre/applicoEffettiCarteCfu/applicoEffettiCarteCfu.h"
#include "../../subroutines/faseTre/usaCarteCfuIstantanee/usaCarteCfuIstantanee.h"
#include "../../subroutines/faseTre/risolviPareggio/risolviPareggio.h"
#include "../../subroutines/faseTre/risolviPareggio/turnoAggiuntivoSpareggio/turnoAggiuntivoSpareggio.h"
#include "../../subroutines/faseTre/risolviPareggio/assegnaCartaOstacoloPerdente/assegnaCartaOstacoloPerdente.h"
#include "../../subroutines/faseTre/controlloGiocatoriPerdenti/controlloGiocatoriPerdenti.h"
#include "../../subroutines/faseTre/condizioniDiVittoria/condizioniDiVittoria.h"

/**
 *        Esegue la fase tre del gioco, aggiornando il punteggio temporaneo dei giocatori,
 *        calcolando il punteggio finale, risolvendo i pareggi, controllando i giocatori
 *        perdenti e verificando le condizioni di vittoria.
 *
 * Questa funzione esegue una serie di operazioni necessarie durante la fase tre del gioco:
 * - Aggiorna il punteggio temporaneo dei giocatori basato sulla carta ostacolo estratta.
 * - Calcola il punteggio finale per ciascun giocatore, considerando carte CFU e ostacoli.
 * - Risolve eventuali pareggi tra i giocatori.
 * - Controlla e rimuove i giocatori che hanno perso.
 * - Verifica le condizioni di vittoria per determinare il vincitore.
 *
 * @param listaPersonaggi Array dei personaggi dei giocatori.
 * @param mazzoCfu Puntatore al puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al puntatore al mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Puntatore al puntatore al mazzo delle carte ostacolo.
 * @param listaGiocatori Puntatore al puntatore alla lista dei giocatori.
 * @param listaGiocate Puntatore al puntatore alla lista delle giocate dei giocatori.
 * @param cartaOstacoloEstratta Carta ostacolo estratta per il turno.
 */
void faseTre(Personaggio listaPersonaggi[4],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori,
             Giocata **listaGiocate,
             CartaOstacoloEstratta *cartaOstacoloEstratta);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_FASETRE_H
