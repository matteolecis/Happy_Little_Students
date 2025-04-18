#ifndef HAPPY_LITTLE_STUDENTS_V0_3_AGGIORNAPUNTEGGIOTEMPORANEO_H
#define HAPPY_LITTLE_STUDENTS_V0_3_AGGIORNAPUNTEGGIOTEMPORANEO_H
#include "../../../../subroutines/misclibs/misclibs.h"

/**
 * Aggiorna il punteggio temporaneo di ogni giocata in base alla carta ostacolo estratta.
 *
 * La funzione calcola e aggiorna il punteggio temporaneo per ogni giocata nella lista delle giocate,
 * tenendo conto dei bonus o malus del personaggio del giocatore in base al tipo di ostacolo estratto.
 *
 * @param listaGiocate Puntatore alla lista delle giocate.
 * @param cartaOstacoloEstratta La carta ostacolo estratta che influisce sul punteggio.
 */
void aggiornaPunteggioTemporaneo(Giocata **listaGiocate, CartaOstacoloEstratta cartaOstacoloEstratta);
#endif //HAPPY_LITTLE_STUDENTS_V0_3_AGGIORNAPUNTEGGIOTEMPORANEO_H
