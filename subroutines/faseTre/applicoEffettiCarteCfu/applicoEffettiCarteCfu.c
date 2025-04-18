#include "applicoEffettiCarteCfu.h"
void applicoEffettiCarteCfu(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                            CartaCFU **mazzoCfu,
                            CartaCFU **mazzoCfuScarti,
                            CartaOstacolo **mazzoOstacoli,
                            Giocatore **listaGiocatori,
                            Giocata **listaGiocate) {
    // Trova il valore massimo della carta nella lista delle giocate
    int valoreMax = 0;
    Giocata *current = *listaGiocate;
    while (current != NULL) {
        if (current->carta->effetto > valoreMax) {
            valoreMax = current->carta->effetto;
        }
        current = current->next;
    }

    // Variabile per tenere traccia se è stato attivato l'effetto ANNULLA
    int annullaAttivato = 0;

    // Applica gli effetti in ordine decrescente di valore della carta
    for (int valoreCorrente = valoreMax; valoreCorrente >= 0; valoreCorrente--) {
        current = *listaGiocate;
        while (current != NULL) {
            if (current->carta->effetto == valoreCorrente) {
                // Controlla se è stata giocata una carta ANNULLA
                if (current->carta->effetto == ANNULLA) {
                    // Attiva l'effetto ANNULLA
                    current->annullaEffetto = 1;
                    annullaAttivato = 1; // Imposta il flag di annullamento
                    // Applica l'effetto ANNULLA
                    effettoAnnulla(listaGiocate); // Chiama la funzione annulla
                } else {
                    // Verifica se l'effetto è stato annullato da ANNULLA
                    if (!annullaAttivato) {
                        // Applica l'effetto della carta solo se non è stato annullato
                        switch (current->carta->effetto) {
                            case SCARTAP:
                                effettoScartaP(current);
                                break;
                            case RUBA:
                                effettoRuba(current->giocatore, *listaGiocatori);
                                break;
                            case SCAMBIADS:
                                effettoScambiaDS(current->giocatore, *listaGiocatori);
                                break;
                            case SCARTAE:
                                effettoScartaE(current, mazzoCfu, mazzoCfuScarti);
                                break;
                            case SCARTAC:
                                effettoScartaC(current);
                                break;
                            case SCAMBIAP:
                                effettoScambiaP(current);
                                break;
                            case DOPPIOE:
                                effettoDoppioE(listaGiocate);
                                break;
                            case SBIRCIA:
                                effettoSbircia(current, mazzoCfu, mazzoCfuScarti);
                                break;
                            case SCAMBIAC:
                                effettoScambiaC(current, listaGiocatori);
                                break;
                            case ANNULLA:
                                effettoAnnulla(listaGiocate);
                                break;
                            case NESSUNO:
                            default:
                                break;
                        }
                    }
                }
            }
            current = current->next;
        }
    }
}

//****************************************************************************************************************************

void effettoScartaP(Giocata *giocata) {
    int indiceCarta;
    printf("\n%s Ha giocato una carta SCARTAP! \n\n", giocata->giocatore->nomeUtente);
    printf("\n%s, decidi quale carta scartare:\n", giocata->giocatore->nomeUtente);
    stampaCarteCFU(giocata->giocatore);

    int numeroCarte = contaCarteCFU(giocata->giocatore);
    do {
        if (numeroCarte == 0 && giocata->giocatore->carte_cfu->effetto>ULTIMA_CARTA_PUNTO) {
            printf("\nNon hai carte CFU da scartare.\n");
        }
        printf("\nScegli una carta CFU dalla tua mano (indice da 0 a %d): \n", numeroCarte-1);
        scanf("%d", &indiceCarta);
    } while (indiceCarta < 0 || indiceCarta >= numeroCarte);

    CartaCFU *cartaScelta = rimuoviCartaCFU(giocata->giocatore, indiceCarta);

    if (cartaScelta->valoreCarta > 0) {
        giocata->punteggioTemporaneo += cartaScelta->valoreCarta;
    }

    printf("\nHai scartato la carta %s con valore %d. Il tuo punteggio del turno è ora %d.\n",
           cartaScelta->nomeCarta, cartaScelta->valoreCarta, giocata->punteggioTemporaneo);

    free(cartaScelta); // Libera la memoria della carta scartata
}


//***********************************************************************************************************************



void effettoRuba(Giocatore *giocatoreCorrente, Giocatore *listaGiocatori) {
    char nomeGiocatore[MAX_CHAR];
    int indiceCarta;
    Giocatore *giocatoreScelto;
    printf("\n%s Ha giocato una carta RUBA! \n\n", giocatoreCorrente->nomeUtente);
    do {
        printf("\n\n%s, scegli un giocatore da cui rubare una carta: \n", giocatoreCorrente->nomeUtente);
        scanf("%s", nomeGiocatore);
        giocatoreScelto = scegliGiocatore(listaGiocatori, nomeGiocatore);
        if(giocatoreScelto==giocatoreCorrente)
        {
            printf("\nNon puoi scegliere te stesso! Scegli un altro giocatore!\n");
        }
        if (giocatoreScelto == NULL) {
            printf("Giocatore non trovato! Riprova.\n");
        }
    } while (giocatoreScelto == NULL||giocatoreScelto==giocatoreCorrente);



    printf("\nCarte CFU di %s:\n", giocatoreScelto->nomeUtente);
    stampaCarteCFU(giocatoreScelto);

    int numeroCarte = contaCarteCFU(giocatoreScelto);
    do {
        if (numeroCarte == 0) {
            printf("\n%s non ha carte che si possono rubare! Impossibile.\n", giocatoreScelto->nomeUtente);
        }
        printf("\nScegli una carta CFU da rubare (indice da 0 a %d): \n", numeroCarte-1);
        scanf("%d", &indiceCarta);
    } while (indiceCarta < 0 || indiceCarta >= numeroCarte);


    CartaCFU *cartaRubata = rimuoviCartaCFU(giocatoreScelto, indiceCarta);
    if (cartaRubata != NULL) {
        aggiungiCartaCFU(giocatoreCorrente, cartaRubata);
        printf("\n\nHai rubato la carta %s da %s!\n", cartaRubata->nomeCarta, giocatoreScelto->nomeUtente);
    } else {
        printf("Errore nel rubare la carta!\n");
    }
}

//*************************************************************************************************************************

void effettoScambiaDS(Giocatore *giocatoreCorrente, Giocatore *listaGiocatori) {
    char nomeGiocatore[MAX_CHAR];
    Giocatore *giocatoreScelto = NULL;
    Giocatore *listaGiocatoriPtr = listaGiocatori;
    int cartaSenzaEffettoTrovata = 0;
    int indiceCarta;
    CartaCFU *cartaScelta = NULL;
    CartaCFU *cartaRubata = NULL;

    printf("\n%s Ha giocato una carta SCAMBIADS! \n\n", giocatoreCorrente->nomeUtente);

    // Verifica se almeno un giocatore avversario ha una carta senza effetto
    while (listaGiocatoriPtr != NULL && !cartaSenzaEffettoTrovata) {
        if (listaGiocatoriPtr != giocatoreCorrente) {
            CartaCFU *carta = listaGiocatoriPtr->carte_cfu;
            while (carta != NULL && !cartaSenzaEffettoTrovata) {
                if (carta->effetto == NESSUNO) {
                    cartaSenzaEffettoTrovata = 1;
                }
                carta = carta->next;
            }
        }
        listaGiocatoriPtr = listaGiocatoriPtr->next;
    }

    if (!cartaSenzaEffettoTrovata) {
        printf("\nNon ci sono giocatori avversari con carte senza effetto. L'effetto della carta non viene esaurito.\n");
        return; // Esci dalla funzione se non ci sono carte senza effetto
    }

    // Scegliere un giocatore valido
    printf("\n\n%s, scegli un giocatore con cui scambiare la carta: \n", giocatoreCorrente->nomeUtente);
    scanf("%s", nomeGiocatore);
    giocatoreScelto = scegliGiocatore(listaGiocatori, nomeGiocatore);

    while (giocatoreScelto == NULL || giocatoreScelto == giocatoreCorrente) {
        if (giocatoreScelto == giocatoreCorrente) {
            printf("\nNon puoi scegliere te stesso! Scegli un altro giocatore!\n");
        } else {
            printf("\nGiocatore non trovato! Riprova.\n");
        }
        printf("\n%s, scegli un giocatore con cui scambiare la carta: \n", giocatoreCorrente->nomeUtente);
        scanf("%s", nomeGiocatore);
        giocatoreScelto = scegliGiocatore(listaGiocatori, nomeGiocatore);
    }

    // Mostrare le carte CFU del giocatore scelto
    printf("\nCarte CFU di %s:\n", giocatoreScelto->nomeUtente);
    stampaCarteCFU(giocatoreScelto);

    int numeroCarte = contaCarteCFU(giocatoreScelto);

    // Scegliere una carta senza effetto dal giocatore scelto
    printf("Scegli una carta CFU senza effetto da scambiare (indice da 0 a %d): \n", numeroCarte - 1);
    scanf("%d", &indiceCarta);

    while (indiceCarta < 0 || indiceCarta >= numeroCarte || cartaScelta == NULL || cartaScelta->effetto != NESSUNO) {
        if (indiceCarta < 0 || indiceCarta >= numeroCarte) {
            printf("Indice non valido!\n");
        } else {
            cartaScelta = getCartaCFU(giocatoreScelto, indiceCarta);
            if (cartaScelta->effetto != NESSUNO) {
                printf("La carta scelta ha un effetto! Devi scegliere una carta senza effetto.\n");
                printf("Scegli una carta CFU senza effetto da scambiare (indice da 0 a %d): \n", numeroCarte - 1);
                scanf("%d", &indiceCarta);
            }
        }
    }

    // Scambiare le carte
    printf("Hai scelto di scambiare la tua carta con la carta %s di %s!\n", cartaScelta->nomeCarta, giocatoreScelto->nomeUtente);

    // Rimuovere la carta scelta dalla mano del giocatore scelto
    cartaRubata = rimuoviCartaCFU(giocatoreScelto, indiceCarta);
    if (cartaRubata != NULL) {
        // Aggiungere la carta scelta alla mano del giocatore corrente
        aggiungiCartaCFU(giocatoreCorrente, cartaRubata);

        // Rimuovere la prima carta dalla mano del giocatore corrente
        if (giocatoreCorrente->carte_cfu != NULL) {
            CartaCFU *cartaCorrente = giocatoreCorrente->carte_cfu;
            giocatoreCorrente->carte_cfu = cartaCorrente->next;
            cartaCorrente->next = NULL;

            // Aggiungere la carta corrente alla mano del giocatore scelto
            aggiungiCartaCFU(giocatoreScelto, cartaCorrente);

            printf("Scambio completato con successo!\n");

            // Il giocatore corrente gioca immediatamente la carta rubata
            printf("%s, ora giochi la carta %s scambiata con %s.\n", giocatoreCorrente->nomeUtente, cartaRubata->nomeCarta, giocatoreScelto->nomeUtente);
            // Implementa la logica per giocare la carta rubata qui
        } else {
            printf("Errore: nessuna carta da scambiare nel mazzo del giocatore corrente.\n");
        }
    } else {
        printf("Errore nello scambiare la carta!\n");
    }
}

//****************************************************************************************************************************

void effettoScartaE(Giocata *giocata, CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti) {
    int indiceCarta;
    CartaCFU *cartaScelta = NULL;

    printf("\n%s Ha giocato una carta SCARTAE! \n\n", giocata->giocatore->nomeUtente);
    // Controlla se il giocatore ha carte con effetto
    if (!haCarteConEffetto(giocata->giocatore)) {
        printf("\nNon hai carte con effetto da scartare. Scegli un'altra carta.\n");
        premiUnoPerContinuare();
        CartaCFU *cartaGiocata = giocata->carta;
        aggiungiCartaCFU(giocata->giocatore, cartaGiocata);  // Rimette la carta SCARTAE nella mano del giocatore
        giocata = giocaCarta(giocata->giocatore, mazzoCfu, mazzoCfuScarti);  // Fa scegliere un'altra carta da giocare
        return;
    }

    printf("\n%s, decidi quale carta scartare. La carta scelta deve avere un effetto!\n", giocata->giocatore->nomeUtente);
    stampaCarteCFU(giocata->giocatore);

    int numeroCarte = contaCarteCFU(giocata->giocatore);

    if (numeroCarte == 0) {
        printf("\nNon hai carte CFU da scartare.\n");
        return;
    }

    do {
        printf("\nScegli una carta CFU dalla tua mano (indice da 0 a %d): \n", numeroCarte - 1);
        scanf("%d", &indiceCarta);

        if (indiceCarta < 0 || indiceCarta >= numeroCarte) {
            printf("\nIndice non valido! Riprova.\n");
            continue;
        }

        cartaScelta = getCartaCFU(giocata->giocatore, indiceCarta); // Ottieni la carta senza rimuoverla

        if (cartaScelta->effetto == NESSUNO) {
            printf("\nLa carta scelta deve avere un effetto!\n");
        } else {
            cartaScelta = rimuoviCartaCFU(giocata->giocatore, indiceCarta); // Rimuovi la carta solo se ha l'effetto desiderato
            giocata->punteggioTemporaneo += cartaScelta->valoreCarta;
        }

    } while (cartaScelta == NULL || cartaScelta->effetto == NESSUNO);

    printf("\nHai scartato la carta %s con valore %d e effetto %d. Il tuo punteggio del turno è ora %d.\n",
           cartaScelta->nomeCarta, cartaScelta->valoreCarta, cartaScelta->effetto, giocata->punteggioTemporaneo);

    free(cartaScelta); // Libera la memoria della carta scartata
}

//**************************************************************************************************************************
void effettoScartaC(Giocata *giocata){
    int indiceCarta;
    int carteDaScartare;
    int numeroCarte = contaCarteCFU(giocata->giocatore);
    printf("\n%s Ha giocato una carta SCARTAC! \n\n", giocata->giocatore->nomeUtente);
    if (numeroCarte == 0) {
        printf("\nNon hai carte CFU in mano da scartare.\n");
        return;
    }else{
        do {
            printf("\nQuante carte vuoi scartare? Puoi scartare da 1 a %d carte!\n", numeroCarte-1);
            scanf("%d", &carteDaScartare);
            if((carteDaScartare<=0 || carteDaScartare > MAX_CARTE_SCARTAC)||carteDaScartare>numeroCarte){
                printf("\n Numero di carte non valido!\n");
            }
        }while((carteDaScartare<=0 || carteDaScartare > MAX_CARTE_SCARTAC)||carteDaScartare>numeroCarte);
    }

    int carteScartate=0;
    do {
        printf("\nCarta n. %d\n", carteScartate+1);
        stampaCarteCFU(giocata->giocatore);
        do {
            numeroCarte = contaCarteCFU(giocata->giocatore);
            printf("\nScegli una carta CFU dalla tua mano (indice da 0 a %d): \n", numeroCarte-1);
            scanf("%d", &indiceCarta);
        } while (indiceCarta < 0 || indiceCarta >= numeroCarte);
        CartaCFU *cartaScelta = rimuoviCartaCFU(giocata->giocatore, indiceCarta);
        printf("\nHai scartato la carta %s con valore %d.\n",
               cartaScelta->nomeCarta, cartaScelta->valoreCarta);

        carteScartate++;
    }while(carteScartate<carteDaScartare);
}

//****************************************************************************************************************************

void effettoScambiaP(Giocata *giocata) {
    if (giocata == NULL) {
        printf("Non ci sono giocate da valutare.\n");
        return;
    }

    printf("\n%s Ha giocato una carta SCAMBIAP! \n\n", giocata->giocatore->nomeUtente);
    Giocata *giocataCorrente = giocata;
    Giocata *giocataMin = giocata;
    Giocata *giocataMax = giocata;

    // Trova le giocate con il punteggio del turno minore e maggiore
    while (giocataCorrente != NULL) {
        if (giocataCorrente->punteggioTemporaneo < giocataMin->punteggioTemporaneo) {
            giocataMin = giocataCorrente;
        }
        if (giocataCorrente->punteggioTemporaneo > giocataMax->punteggioTemporaneo) {
            giocataMax = giocataCorrente;
        }
        giocataCorrente = giocataCorrente->next;
    }

    // Scambia i punteggi temporanei solo se giocataMin e giocataMax sono diverse
    if (giocataMin != giocataMax) {
        int temp = giocataMin->punteggioTemporaneo;
        giocataMin->punteggioTemporaneo = giocataMax->punteggioTemporaneo;
        giocataMax->punteggioTemporaneo = temp;

        printf("\nIl punteggio del turno di %s (%d) è stato scambiato con quello di %s (%d).\n",
               giocataMin->giocatore->nomeUtente, giocataMin->punteggioTemporaneo,
               giocataMax->giocatore->nomeUtente, giocataMax->punteggioTemporaneo);
    } else {
        printf("\nNon ci sono abbastanza giocate per effettuare lo scambio dei punteggi.\n");
    }
}
//****************************************************************************************************************************

void effettoDoppioE(Giocata **listaGiocate) {
    Giocata *current = *listaGiocate;
    printf("\n%s Ha giocato una carta DOPPIOE! Le carte Istantanee AUMENTA e DIMINUISCI hanno effetto DOPPIO! \n\n", current->giocatore->nomeUtente);
    while (current != NULL) {
        if (current->carta->effetto == AUMENTA || current->carta->effetto == DIMINUISCI) {
            current->doppioEffettoAttivo = 1; // Attiva il flag per l'effetto DOPPIOE
        }
        current = current->next;
    }
}
//****************************************************************************************************************************

void effettoSbircia(Giocata *giocata, CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti) {
    if (giocata == NULL || giocata->giocatore == NULL) {
        printf("Giocata o giocatore non validi.\n");
        return;
    }

    if (*mazzoCfu == NULL || (*mazzoCfu)->next == NULL) {
        printf("Non ci sono abbastanza carte nel mazzo per l'effetto SBIRCIA.\n");
        return;
    }

    // Prendi le prime due carte dal mazzo
    CartaCFU *primaCarta = *mazzoCfu;
    CartaCFU *secondaCarta = primaCarta->next;

    // Mostra le carte al giocatore
    printf("\n%s Ha giocato una carta SBIRCIA! \n\n", giocata->giocatore->nomeUtente);
    printf("Carte trovate:\n1. %s (Valore: %d)\n2. %s (Valore: %d)\n",
           primaCarta->nomeCarta, primaCarta->valoreCarta,
           secondaCarta->nomeCarta, secondaCarta->valoreCarta);

    // Fai scegliere al giocatore quale carta prendere
    int scelta;
    do {
        printf("\nOtterrai in mano la carta che scegli, mentre l'altra andra' scartata!\n");
        printf("\n%s scegli una carta (1 o 2): \n", giocata->giocatore->nomeUtente);
        scanf("%d", &scelta);
        if(scelta != 1 && scelta != 2){
            printf("\nScelta non valida!\n");
        }
    } while (scelta != 1 && scelta != 2);

    // Aggiungi la carta scelta alla mano del giocatore
    CartaCFU *cartaScelta;
    CartaCFU *cartaScartata;
    if (scelta == 1) {
        cartaScelta = primaCarta;
        cartaScartata = secondaCarta;
        *mazzoCfu = secondaCarta->next;  // Aggiorna il mazzo per saltare entrambe le carte
    } else {
        cartaScelta = secondaCarta;
        cartaScartata = primaCarta;
        *mazzoCfu = secondaCarta->next;  // Aggiorna il mazzo per saltare entrambe le carte
    }

    // Aggiungi la carta scelta alla mano del giocatore
    cartaScelta->next = giocata->giocatore->carte_cfu;
    giocata->giocatore->carte_cfu = cartaScelta;

    // Aggiungi la carta scartata al mazzo degli scarti
    cartaScartata->next = *mazzoCfuScarti;
    *mazzoCfuScarti = cartaScartata;


    printf("Hai scelto di prendere la carta %s e di scartare la carta %s.\n",
           cartaScelta->nomeCarta, cartaScartata->nomeCarta);
}

//****************************************************************************************************************************


void effettoScambiaC(Giocata *listaGiocate, Giocatore **listaGiocatori) {
    if (listaGiocate == NULL) {
        printf("\nNon ci sono giocate da valutare.\n");
        return;
    }

    Giocatore *giocatore1 = NULL;
    Giocatore *giocatore2 = NULL;

    // Mostra i giocatori disponibili
    printf("\nGiocatori disponibili:\n");
    int index = 0;
    Giocatore *currentGiocatore = *listaGiocatori;
    while (currentGiocatore != NULL) {
        printf("%d. %s\n", index, currentGiocatore->nomeUtente);
        currentGiocatore = currentGiocatore->next;
        index++;
    }

    // Seleziona il primo giocatore
    int scelta1, scelta2;
    do {
        printf("Seleziona il primo giocatore (indice): \n");
        scanf("%d", &scelta1);
        currentGiocatore = *listaGiocatori;
        for (int i = 0; i < scelta1 && currentGiocatore != NULL; i++) {
            currentGiocatore = currentGiocatore->next;
        }
        giocatore1 = currentGiocatore;
    } while (giocatore1 == NULL);

    // Seleziona il secondo giocatore
    do {
        printf("Seleziona il secondo giocatore (indice): \n");
        scanf("%d", &scelta2);
        currentGiocatore = *listaGiocatori;
        for (int i = 0; i < scelta2 && currentGiocatore != NULL; i++) {
            currentGiocatore = currentGiocatore->next;
        }
        giocatore2 = currentGiocatore;
    } while (giocatore2 == NULL || giocatore2 == giocatore1);

    // Trova le giocate dei giocatori selezionati
    Giocata *giocata1 = NULL;
    Giocata *giocata2 = NULL;
    Giocata *temp = listaGiocate;  // Inizia dall'inizio della lista delle giocate
    while (temp != NULL) {
        if (temp->giocatore == giocatore1) {
            giocata1 = temp;
        }
        if (temp->giocatore == giocatore2) {
            giocata2 = temp;
        }
        temp = temp->next;
    }

    if (giocata1 == NULL || giocata2 == NULL) {
        printf("Una o entrambe le giocate non sono valide.\n");
        return;
    }

    // Scambia le carte giocate
    CartaCFU *cartaTemp = giocata1->carta;
    giocata1->carta = giocata2->carta;
    giocata2->carta = cartaTemp;

    printf("La carta giocata da %s è stata scambiata con quella giocata da %s.\n",
           giocatore1->nomeUtente, giocatore2->nomeUtente);
}

//*************************************************************************************************************************

void effettoAnnulla(Giocata **listaGiocate){
    Giocata *current = *listaGiocate;
    while (current != NULL) {
        if (current->carta->effetto != ANNULLA) {
            current->annullaEffetto = 1; // Imposta il flag di annullamento
        }
        current = current->next;
    }
}

