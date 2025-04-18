#ifndef HAPPY_LITTLE_STUDENTS_V0_2_INIZIOTURNO_H
#define HAPPY_LITTLE_STUDENTS_V0_2_INIZIOTURNO_H
#include "../../../subroutines/misclibs/misclibs.h"
#include "../../../subroutines/faseDue/inizioTurno/printNumeroTurno/printNumeroTurno.h"
#include "../../../subroutines/faseDue/inizioTurno/stampaCartaOstacolo/stampaCartaOstacolo.h"
#include "../../../subroutines/faseUno/faseUno.h"
#include "../../../subroutines/faseDue/faseDue.h"


/**
 * Inizia il turno di gioco.
 *
 * La funzione esegue le operazioni necessarie per iniziare un turno di gioco. Include
 * la gestione delle carte CFU dei giocatori e l'estrazione di una carta ostacolo.
 *
 * @param listaPersonaggi La lista dei personaggi disponibili.
 * @param mazzoCfu Il puntatore al mazzo di carte CFU.
 * @param mazzoCfuScarti Il puntatore al mazzo di carte CFU scartate.
 * @param mazzoOstacoli Il puntatore al mazzo di carte ostacolo.
 * @param listaGiocatori Il puntatore alla lista dei giocatori.
 * @param cartaEstratta Il puntatore alla carta ostacolo estratta.
 */
void inizioTurno(Personaggio listaPersonaggi[4],
                          CartaCFU **mazzoCfu,
                          CartaCFU **mazzoCfuScarti,
                          CartaOstacolo **mazzoOstacoli,
                          Giocatore **listaGiocatori,
                          CartaOstacoloEstratta *cartaEstratta);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_INIZIOTURNO_H
