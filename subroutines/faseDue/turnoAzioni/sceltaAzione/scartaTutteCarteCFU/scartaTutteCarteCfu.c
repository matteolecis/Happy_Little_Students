#include "scartaTutteCarteCfu.h"
void scartaTutteCarteCFU(Giocatore *giocatore, CartaCFU **mazzoCfuScarti) {
    CartaCFU *cartaCorrente = giocatore->carte_cfu;
    while (cartaCorrente != NULL) {
        CartaCFU *daScartare = cartaCorrente;
        cartaCorrente = cartaCorrente->next;
        daScartare->next = *mazzoCfuScarti;
        *mazzoCfuScarti = daScartare;
    }
    giocatore->carte_cfu = NULL; // La mano del giocatore è ora vuota
}