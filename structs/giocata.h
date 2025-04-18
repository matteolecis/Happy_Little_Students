#ifndef HAPPY_LITTLE_STUDENTS_V0_3_GIOCATA_H
#define HAPPY_LITTLE_STUDENTS_V0_3_GIOCATA_H
#include "giocatore.h"
#include "cartaCFU.h"
#include "cartaOstacoloEstratta.h"

// Struttura per associare giocatore e carta giocata
struct Giocata {
    Giocatore *giocatore;
    CartaCFU *carta;
    CartaOstacoloEstratta *cartaOstacoloEstratta;
    int punteggioTemporaneo;
    int doppioEffettoAttivo;
    int annullaEffetto;      // Flag per indicare se l'effetto è stato annullato dall'ANNULLA
    struct Giocata *next;
};
typedef struct Giocata Giocata;

#endif //HAPPY_LITTLE_STUDENTS_V0_3_GIOCATA_H
