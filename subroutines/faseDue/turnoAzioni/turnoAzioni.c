#include "turnoAzioni.h"
Giocata* turnoAzioni(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                 CartaCFU **mazzoCfu,
                 CartaCFU **mazzoCfuScarti,
                 CartaOstacolo **mazzoOstacoli,
                 Giocatore **listaGiocatori,
                 CartaOstacoloEstratta *cartaEstratta) {

    Giocatore *giocatoreCorrente = *listaGiocatori;
    Giocata *listaGiocate = NULL; // Lista di giocate
    Giocata *ultimaGiocata = NULL;

    // Itera attraverso tutti i giocatori per scegliere le loro azioni
    while (giocatoreCorrente != NULL) {
        Giocata *giocataCorrente;
        giocataCorrente = sceltaAzione(giocatoreCorrente,listaGiocatori,mazzoOstacoli,mazzoCfu,mazzoCfuScarti,cartaEstratta);

        // Aggiungi la giocata corrente alla lista di giocate
        if (giocataCorrente != NULL) {
            if (listaGiocate == NULL) {
                listaGiocate = giocataCorrente;
            } else {
                ultimaGiocata->next = giocataCorrente;
            }
            ultimaGiocata = giocataCorrente;
        }

        giocatoreCorrente = giocatoreCorrente->next;
    }

    // Rivela le carte giocate da tutti i giocatori
    rivelazioneCarteTurno(listaGiocate);

    if (*mazzoCfu == NULL) {
        printf("Il mazzo delle carte CFU è vuoto! Verrà mescolato il mazzo delle carte CFU scartate e verrà usato quello");
        shuffleMazzoCfu(mazzoCfuScarti, LOOPS);
        *mazzoCfu = *mazzoCfuScarti;
    }
    return listaGiocate;
}