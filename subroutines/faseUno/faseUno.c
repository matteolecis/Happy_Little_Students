#include "faseUno.h"
void faseUno(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori,
             char nomeSave[MAX_NOME_SAVE]) {

    // Caricamento dai file txt dei dati e popolo le liste con i mazzi
    caricaMazzoCFU(mazzoCfu);
    caricaMazzoOstacoli(mazzoOstacoli);


    // Mischio i due mazzi
    shuffleMazzoCfu(mazzoCfu, LOOPS);
    shuffleMazzoOstacoli(mazzoOstacoli, LOOPS);

    // Chiedo quanti giocatori devono giocare e i loro nomi. Assegno un personaggio casuale a ogni giocatore
    inizializzaGiocatori(listaGiocatori, mazzoCfu);

    int numCarteMazzoCFU = contaCarteMazzoCfu(*mazzoCfu);
    int numCarteMazzoCfuScarti = contaCarteMazzoCfu(*mazzoCfuScarti);
    int numCarteOstacolo = contaCarteOstacolo(*mazzoOstacoli);
    //Creo un nuovo salvataggio
    salvaPartita(nomeSave, *listaGiocatori, *mazzoCfu, numCarteMazzoCFU, *mazzoCfuScarti,
                 numCarteMazzoCfuScarti,*mazzoOstacoli, numCarteOstacolo);
}