#include "memorizzaCarteGiocateNelTurno.h"
// Funzione per aggiungere una giocata alla lista delle giocate
void memorizzaCarteGiocateNelTurno(Giocata **listaGiocate, Giocatore *giocatore, CartaCFU *carta) {
    Giocata *nuovaGiocata = (Giocata *)malloc(sizeof(Giocata));
    nuovaGiocata->giocatore = giocatore;
    nuovaGiocata->carta = carta;
    nuovaGiocata->next = *listaGiocate;
    *listaGiocate = nuovaGiocata;
}