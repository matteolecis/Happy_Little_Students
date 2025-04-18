#include "getMazzoOstacoli.h"
// Definizione della funzione per ottenere il mazzo di ostacoli
CartaOstacolo* getMazzoOstacoli() {
    CartaOstacolo* mazzoOstacoli = NULL;
    // Se il mazzo non è stato ancora caricato, caricalo
    if (mazzoOstacoli == NULL) {
        mazzoOstacoli = (CartaOstacolo *) malloc(sizeof(CartaOstacolo));
        // Carica il mazzo di ostacoli tramite la funzione caricaMazzoOstacoli
        int flag = caricaMazzoOstacoli(&mazzoOstacoli); // Assumi che ci sia una funzione caricaMazzoOstacoli per caricare il mazzo di ostacoli
        if (flag == -1) {
            // Errore nel caricamento del mazzo di ostacoli
            // Deallocazione della memoria allocata per il mazzo
            free(mazzoOstacoli);
            mazzoOstacoli = NULL;
        }
    }
    return mazzoOstacoli;
}