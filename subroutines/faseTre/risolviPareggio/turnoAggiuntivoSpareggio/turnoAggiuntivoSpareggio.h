#ifndef HAPPY_LITTLE_STUDENTS_V0_3_TURNOAGGIUNTIVOSPAREGGIO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_TURNOAGGIUNTIVOSPAREGGIO_H
#include "../../../../subroutines/misclibs/misclibs.h"

/**
 * Gestisce un turno aggiuntivo di spareggio tra giocatori perdenti.
 *
 * Questa funzione gestisce un turno aggiuntivo nel caso in cui più giocatori abbiano
 * ottenuto lo stesso punteggio più basso in una giocata. Ogni giocatore rimasto in gioco
 * con carte CFU punto partecipa a questo turno aggiuntivo, dove il punteggio più
 * basso determina il perdente finale. A questo giocatore viene assegnata una nuova
 * carta ostacolo estratta casualmente dal mazzo.
 *
 * @param listaGiocatoriPerdenti Puntatore al puntatore alla lista dei giocatori perdenti.
 * @param mazzoCfu Puntatore al puntatore al mazzo delle carte CFU.
 * @param mazzoCfuScarti Puntatore al puntatore al mazzo delle carte CFU scartate.
 * @param cartaOstacoloEstratta Puntatore alla struttura contenente la carta ostacolo estratta.
 */
//void turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti,
                              //CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                              //CartaOstacoloEstratta *cartaOstacoloEstratta);


int turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti,
                             CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                             CartaOstacoloEstratta *cartaOstacoloEstratta);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_TURNOAGGIUNTIVOSPAREGGIO_H
