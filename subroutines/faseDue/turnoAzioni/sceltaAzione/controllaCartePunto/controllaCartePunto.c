#include "controllaCartePunto.h"
int controllaCartePunto(Giocatore *giocatore) {
    CartaCFU *cartaCorrente = giocatore->carte_cfu;
    while (cartaCorrente != NULL) {
        if (cartaCorrente->effetto >= 0 && cartaCorrente->effetto <= 10) {
            return 1; // Il giocatore ha almeno una carta CFU punto
        }
        cartaCorrente = cartaCorrente->next;
    }
    return 0; // Il giocatore non ha carte CFU punto
}