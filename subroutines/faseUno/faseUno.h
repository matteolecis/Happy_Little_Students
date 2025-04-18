#ifndef HAPPY_LITTLE_STUDENTS_V0_2_FASEUNO_H
#define HAPPY_LITTLE_STUDENTS_V0_2_FASEUNO_H
#include "../../subroutines/faseUno/caricaPersonaggi/caricaPersonaggi.h"
#include "../../subroutines/faseUno/caricaMazzoCfu/caricaMazzoCfu.h"
#include "../../subroutines/faseUno/caricaMazzoOstacoli/caricaMazzoOstacoli.h"
#include "../../subroutines/faseUno/inizializzaGiocatori/inizializzaGiocatori.h"
#include "../../subroutines/faseUno/visualizzaPresentazione/visualizzaPresentazione.h"
#include "../../subroutines/faseUno/shuffleMazzoCfu/shuffleMazzoCfu.h"
#include "../../subroutines/faseUno/shuffleMazzoOstacoli/shuffleMazzoOstacoli.h"
#include "../../subroutines/faseUno/getMazzoOstacoli/getMazzoOstacoli.h"
#include "../../subroutines/misclibs/misclibs.h"

/**
 * @brief Esegue la fase uno del gioco.
 *
 * La funzione esegue la fase uno del gioco, che include il caricamento dei mazzi di carte,
 * la mischiatura dei mazzi, l'inizializzazione dei giocatori e il salvataggio della partita.
 *
 * @param listaPersonaggi La lista dei personaggi disponibili.
 * @param mazzoCfu Il puntatore al mazzo di carte CFU.
 * @param mazzoCfuScarti Il puntatore al mazzo di carte CFU scartate.
 * @param mazzoOstacoli Il puntatore al mazzo di carte ostacolo.
 * @param listaGiocatori Il puntatore alla lista dei giocatori.
 * @param nomeSave Il nome del file di salvataggio.
 */
void faseUno(Personaggio listaPersonaggi[4],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori,
             char nomeSave[64]);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_FASEUNO_H
