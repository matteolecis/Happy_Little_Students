#include "faseTre.h"
void faseTre(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori,
             Giocata **listaGiocate,
             CartaOstacoloEstratta *cartaOstacoloEstratta) {
    aggiornaPunteggioTemporaneo(listaGiocate, *cartaOstacoloEstratta);
    calcoloPunteggio(listaPersonaggi, mazzoCfu, mazzoCfuScarti, mazzoOstacoli, listaGiocatori, listaGiocate,
                     &cartaOstacoloEstratta);
    if(cartaOstacoloEstratta != NULL) {
        risolviPareggio(listaPersonaggi, mazzoCfu, mazzoCfuScarti, mazzoOstacoli, listaGiocatori, listaGiocate,
                        cartaOstacoloEstratta);
    }

    controlloGiocatoriPerdenti(listaGiocatori, mazzoCfuScarti, mazzoOstacoli);
    condizioniDiVittoria(listaGiocatori);

}