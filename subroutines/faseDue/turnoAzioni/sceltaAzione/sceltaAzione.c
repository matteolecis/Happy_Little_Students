#include "sceltaAzione.h"
Giocata* sceltaAzione(Giocatore *giocatoreCorrente,
                      Giocatore **listaGiocatori,
                      CartaOstacolo **mazzoOstacoli,
                      CartaCFU **mazzoCfu,
                      CartaCFU **mazzoCfuScarti,
                      CartaOstacoloEstratta *cartaEstratta) {
    Giocata *giocataCorrente = NULL;
    Giocata *listaGiocate = NULL;
    int scelta;
    do {
        stampaCartaOstacolo(*cartaEstratta);
        stampaPlanciaGiocatore(giocatoreCorrente);
        printf("\n\n\nGiocatore %s, che cosa vuoi fare?\n"
               "[TASTO 1] Gioca una carta CFU\n"
               "[TASTO 2] Controlla come son messi gli giocatori\n"
               "[TASTO 3] Pulisci schermo\n"
               "[TASTO 0] Esci dalla partita\n", giocatoreCorrente->nomeUtente);
        scanf("%d", &scelta);
        switch(scelta) {
            case 1:
                // Controlla se il giocatore ha almeno una carta CFU punto
                if (controllaCartePunto(giocatoreCorrente)) {
                    // Il giocatore decide di giocare una carta CFU
                    giocataCorrente = giocaCarta(giocatoreCorrente, mazzoCfu, mazzoCfuScarti);
                    //TODO CLEARSCREEN QUI
                    clearScreen();
                    giocataCorrente->cartaOstacoloEstratta = malloc(sizeof(CartaOstacoloEstratta));
                    *(giocataCorrente->cartaOstacoloEstratta) = *cartaEstratta;

                    // Aggiungi la giocataCorrente alla listaGiocate
                    giocataCorrente->next = listaGiocate;
                    listaGiocate = giocataCorrente;

                } else {
                    // Se il giocatore non ha carte CFU punto, scarta tutte le carte e pesca fino a quando non ha una carta CFU punto.
                    printf("Giocatore %s non ha carte CFU punto, deve scartare e pescare fino a quando non avrà una carta CFU punto.\n", giocatoreCorrente->nomeUtente);
                    premiUnoPerContinuare();
                    // Il ciclo continua fino a quando il giocatore non ha una carta punto
                    do {
                        // Scarta tutte le carte CFU del giocatore
                        scartaTutteCarteCFU(giocatoreCorrente, mazzoCfuScarti);
                        // Il giocatore pesca una nuova carta e gli viene assegnata
                        CartaCFU nuovaCarta = pescaCartaCfu(mazzoCfu);
                        nuovaCarta.next = giocatoreCorrente->carte_cfu;
                        giocatoreCorrente->carte_cfu = &nuovaCarta;
                    } while (!controllaCartePunto(giocatoreCorrente));
                    if (controllaCartePunto(giocatoreCorrente)) {
                        // Il giocatore decide di giocare una carta CFU
                        giocataCorrente = giocaCarta(giocatoreCorrente, mazzoCfu, mazzoCfuScarti);
                        //TODO CLEARSCREEN QUI
                        clearScreen();
                        giocataCorrente->cartaOstacoloEstratta = malloc(sizeof(CartaOstacoloEstratta));
                        *(giocataCorrente->cartaOstacoloEstratta) = *cartaEstratta;

                        // Aggiungi la giocataCorrente alla listaGiocate
                        giocataCorrente->next = listaGiocate;
                        listaGiocate = giocataCorrente;
                    }
                }
                break;
            case 2:
                // Controlla le carte degli altri giocatori
                printf("Giocatore %s sta controllando le carte degli altri giocatori.\n", giocatoreCorrente->nomeUtente);
                controlloStatoTurno(*listaGiocatori,  cartaEstratta);
                break;
            case 3:
                //TODO CLEARSCREEN QUI
                clearScreen();
                break;
            case 0:
                // Esci dalla partita
                printf("Giocatore %s ha scelto di uscire dalla partita.\n", giocatoreCorrente->nomeUtente);
                exit(0);
                break;
            default:
                printf("Scelta non valida!");
                break;
        }
    } while(scelta < 0 || scelta > 1);
    return listaGiocate;
}