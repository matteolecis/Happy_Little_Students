#ifndef HAPPY_LITTLE_STUDENTS_GIOCATORE_H
#define HAPPY_LITTLE_STUDENTS_GIOCATORE_H
#include "../structs/personaggio.h"
#include "../structs/cartaOstacolo.h"
#include "../structs/cartaCFU.h"
//Definizione struttura per il giocatore
struct giocatore{
    char nomeUtente[MAX_CHAR];
    Personaggio personaggio;
    int cfu;
    CartaCFU * carte_cfu;
    CartaOstacolo *cartaOstacolo;
    struct giocatore *next;
};
typedef struct giocatore Giocatore;
#endif //HAPPY_LITTLE_STUDENTS_GIOCATORE_H
