#include "calcoloPunteggio.h"
void calcoloPunteggio(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                      CartaCFU **mazzoCfu,
                      CartaCFU **mazzoCfuScarti,
                      CartaOstacolo **mazzoOstacoli,
                      Giocatore **listaGiocatori,
                      Giocata **listaGiocate,
                      CartaOstacoloEstratta **cartaOstacoloEstratta) {
    applicaBonusMalus(*listaGiocate);
    applicoEffettiCarteCfu(listaPersonaggi,mazzoCfu,mazzoCfuScarti,mazzoOstacoli,listaGiocatori,listaGiocate);
    usaCarteCfuIstantanee(listaPersonaggi,mazzoCfu,mazzoCfuScarti,mazzoOstacoli,listaGiocatori,listaGiocate, cartaOstacoloEstratta);
    resetDoppioEffetto(listaGiocate); // Resetta l'effetto DOPPIOE alla fine del turno
    resetAnnullaEffetto(listaGiocate);
}

void applicaBonusMalus(Giocata *giocataCorrente) {
    if (giocataCorrente == NULL || giocataCorrente->cartaOstacoloEstratta == NULL) {
        perror("NESSUNA GIOCATA TROVATA! COME E' POSSIBILE? RIAVVIA IL GIOCO.");
    }
    int tipo = giocataCorrente->cartaOstacoloEstratta->carta.tipoOstacolo;
    int bonusMalus = giocataCorrente->giocatore->personaggio.tipoOstacoli[tipo];
    giocataCorrente->carta->valoreCarta += bonusMalus;
}

void resetDoppioEffetto(Giocata **listaGiocate) {
    Giocata *current = *listaGiocate;
    while (current != NULL) {
        current->doppioEffettoAttivo = 0;
        current = current->next;
    }
}

void resetAnnullaEffetto(Giocata **listaGiocate) {
    Giocata *current = *listaGiocate;
    while (current != NULL) {
        current->annullaEffetto = 0; // Resetta l'effetto ANNULLA
        current = current->next;
    }
}