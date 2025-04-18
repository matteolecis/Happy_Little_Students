#ifndef HAPPY_LITTLE_STUDENTS_V0_2_TURNOAZIONI_H
#define HAPPY_LITTLE_STUDENTS_V0_2_TURNOAZIONI_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Gestisce il turno di azioni per tutti i giocatori nella partita corrente.
 *
 * Questa funzione gestisce il turno di azioni per tutti i giocatori presenti nella partita.
 * Ogni giocatore seleziona e compie una serie di azioni, inclusa la scelta di giocare una carta CFU,
 * fino a quando tutti i giocatori non hanno completato il loro turno.
 * Restituisce una lista di tutte le giocate effettuate dai giocatori durante il turno.
 *
 * @param listaPersonaggi Array contenente i personaggi di tutti i giocatori.
 * @param mazzoCfu Un puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Un puntatore al mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Un puntatore al mazzo delle carte ostacolo.
 * @param listaGiocatori Un puntatore alla lista di giocatori della partita.
 * @param cartaEstratta Un puntatore alla carta ostacolo estratta per il turno corrente.
 * @return Una lista di tutte le giocate effettuate dai giocatori durante il turno.
 */
Giocata* turnoAzioni(Personaggio listaPersonaggi[4],
                 CartaCFU **mazzoCfu,
                 CartaCFU **mazzoCfuScarti,
                 CartaOstacolo **mazzoOstacoli,
                 Giocatore **listaGiocatori,
                 CartaOstacoloEstratta *cartaEstratta);

#endif //HAPPY_LITTLE_STUDENTS_V0_2_TURNOAZIONI_H
