#include "condizioniDiVittoria.h"
void condizioniDiVittoria(Giocatore **listagiocatori){
    Giocatore *giocatore = *listagiocatori;
    int giocatoriRimasti = contaGiocatori(giocatore);
    while(giocatore != NULL){
        if(giocatore->cfu == CFU_VITTORIA){
            int scelta=1;
            printf("\n\n\n\nGiocatore %s, COMPLIMENTI HAI RAGGIUNTO I 60 CFU! HAI VINTO LA PARTITA!\n\n\n",
                   giocatore->nomeUtente);
            do{
                printf("\nPremi il tasto [0] per uscire dalla partita!\n");
                scanf("%d", &scelta);
            } while(scelta != 0);
            exit(0);
        }
        if(giocatoriRimasti == 1){
            int scelta=1;
            printf("\n\n\n\nGiocatore %s, COMPLIMENTI SEI L'ULTIMO DEI TUOI COLLEGHI RIMASTO, HAI VINTO LA PARTITA!\n\n\n",
                   giocatore->nomeUtente);
            do{
                printf("\nPremi il tasto [0] per uscire dalla partita!\n");
                scanf("%d", &scelta);
            } while(scelta != 0);
            exit(0);
        }
        giocatore = giocatore->next;
    }
}
