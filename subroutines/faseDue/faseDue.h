#ifndef HAPPY_LITTLE_STUDENTS_V0_2_FASEDUE_H
#define HAPPY_LITTLE_STUDENTS_V0_2_FASEDUE_H
#include "../../subroutines/misclibs/misclibs.h"
#include "../../subroutines/faseDue/inizioTurno/inizioTurno.h"
#include "../../subroutines/faseDue/turnoAzioni/turnoAzioni.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/sceltaAzione.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/giocaCarta/giocaCarta.h"
#include "../../subroutines/faseDue/inizioTurno/printNumeroTurno/printNumeroTurno.h"
#include "../../subroutines/faseDue/inizioTurno/stampaCartaOstacolo/stampaCartaOstacolo.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/giocaCarta/stampaCarteCFU/stampaCarteCFU.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/giocaCarta/rimuoviCartaCFU/rimuoviCartaCFU.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/giocaCarta/memorizzaCarteGiocateNelTurno/memorizzaCarteGiocateNelTurno.h"
#include "../../subroutines/faseDue/turnoAzioni/rivelazioneCarteTurno/rivelazioneCarteTurno.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/controlloStatoTurno/controlloStatoTurno.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/controllaCartePunto/controllaCartePunto.h"
#include "../../subroutines/faseDue/turnoAzioni/sceltaAzione/scartaTutteCarteCFU/scartaTutteCarteCfu.h"
#include "../../subroutines/faseDue/turnoAzioni/aggiornaPunteggioTemporaneo/aggiornaPunteggioTemporaneo.h"

/**
 * Gestisce la fase due del gioco, che comprende il ciclo principale di turni di gioco.
 *
 * Questa funzione gestisce la fase due del gioco, durante la quale i giocatori eseguono i loro turni fino
 * al raggiungimento del numero massimo di turni consentiti. Ad ogni turno, vengono eseguite diverse operazioni
 * tra cui salvataggio automatico della partita, gestione dei log, inizio e esecuzione del turno di ogni giocatore.
 * Alla fine di ogni turno, viene chiamata la funzione per gestire la fase tre del gioco.
 *
 * @param listaPersonaggi Array contenente i personaggi di tutti i giocatori.
 * @param mazzoCfu Un puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Un puntatore al mazzo delle carte CFU scartate.
 * @param mazzoOstacoli Un puntatore al mazzo delle carte ostacolo.
 * @param listaGiocatori Un puntatore alla lista di giocatori della partita.
 * @param nomeSave Nome del file in cui salvare lo stato della partita.
 */
void faseDue(Personaggio listaPersonaggi[4],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori,
             char nomeSave[64]);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_FASEDUE_H
