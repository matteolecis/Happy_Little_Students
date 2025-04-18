#include "rimuoviCartaCFU.h"
// Funzione ausiliaria per rimuovere una carta CFU dalla mano del giocatore
CartaCFU* rimuoviCartaCFU(Giocatore *giocatore, int indiceCarta) {
    CartaCFU *cartaPrecedente = NULL;  // Puntatore alla carta precedente nella lista
    CartaCFU *cartaCorrente = giocatore->carte_cfu; // Puntatore alla carta corrente nella lista

    // Ciclo per trovare la carta da rimuovere in base all'indice
    for (int i = 0; i < indiceCarta; i++) {
        cartaPrecedente = cartaCorrente; // Aggiorna il puntatore alla carta precedente
        cartaCorrente = cartaCorrente->next; // Passa alla carta successiva
    }

    // Se la carta da rimuovere è la prima nella lista
    if (cartaPrecedente == NULL) {
        giocatore->carte_cfu = cartaCorrente->next; // La testa della lista punta alla seconda carta
    } else {
        cartaPrecedente->next = cartaCorrente->next; // La carta precedente salta la carta corrente
    }

    cartaCorrente->next = NULL; // Disconnette la carta rimossa dalla lista
    return cartaCorrente; // Ritorna il puntatore alla carta rimossa
}