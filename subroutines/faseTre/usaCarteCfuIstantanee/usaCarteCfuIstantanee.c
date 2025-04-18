#include "usaCarteCfuIstantanee.h"

void usaCarteCfuIstantanee(Personaggio listaPersonaggi[4],
                           CartaCFU **mazzoCfu,
                           CartaCFU **mazzoCfuScarti,
                           CartaOstacolo **mazzoOstacoli,
                           Giocatore **listaGiocatori,
                           Giocata **listaGiocate,
                           CartaOstacoloEstratta **cartaOstacoloEstratta) {
    Giocatore *giocatoreCorrente = *listaGiocatori;
    char scelta;
    char sceltaInst; //Var usata per gestire il caso in cui non ci fossero carte istantanee. Il giocatore deve premere n per andare avanti

    while (giocatoreCorrente != NULL) {
        do {
            int countCarteCfuIstantanee = contaCarteCFUIstantanee(giocatoreCorrente);
            if (countCarteCfuIstantanee == 0) {
                do {
                    printf("\n%s Non possiedi carte istantanee! Premi [n] per andare avanti!\n", giocatoreCorrente->nomeUtente);
                    scanf(" %c", &sceltaInst);
                    // Pulisce il buffer dallo '\n'
                    while (getchar() != '\n');
                } while (sceltaInst != 'n');
                break; // Esce dal ciclo se non ci sono carte istantanee
            } else {
                printf("\n%s, vuoi giocare una carta istantanea? Hai %d carte istantanee (y/n): \n", giocatoreCorrente->nomeUtente, countCarteCfuIstantanee);
                scanf(" %c", &scelta);
                // Pulisce il buffer dallo '\n'
                while (getchar() != '\n');
                if ((scelta != 'y' && scelta != 'Y') && (scelta != 'n' && scelta != 'N'))
                    printf("\nSCELTA NON VALIDA\n");
            }
        } while ((scelta != 'y' && scelta != 'Y') && (scelta != 'n' && scelta != 'N'));


        if ((scelta == 'y' || scelta == 'Y') && contaCarteIstantanee(giocatoreCorrente) > 0) {
            printf("\nEcco le tue carte CFU:\n");
            stampaCarteCFU(giocatoreCorrente);

            char sceltaGiocatore;
            printf("\nVuoi giocare una carta istantanea o passare al prossimo giocatore? (g/p): ");
            scanf(" %c", &sceltaGiocatore);
            // Pulisce il buffer dallo '\n'
            while (getchar() != '\n');

            if (sceltaGiocatore == 'p' || sceltaGiocatore == 'P') {
                printf("\n%s ha deciso di passare al prossimo giocatore.\n", giocatoreCorrente->nomeUtente);
                giocatoreCorrente = giocatoreCorrente->next;
                continue;
            }

            int indiceCarta;
            int cartePossedute = contaCarteCFU(giocatoreCorrente);
            CartaCFU *cartaScelta = NULL;

            do {
                printf("\nScegli una carta CFU istantanea dalla tua mano (indice da 0 a %d): ", cartePossedute - 1);
                scanf("%d", &indiceCarta);

                if (indiceCarta < 0 || indiceCarta >= cartePossedute) {
                    printf("SCELTA NON VALIDA\n");
                    continue;
                }

                cartaScelta = getCartaCFU(giocatoreCorrente, indiceCarta);

                if (cartaScelta->effetto < AUMENTA || cartaScelta->effetto > DIROTTA) {
                    printf("SCELTA NON VALIDA: Puoi giocare solo carte istantanee.\n");
                    cartaScelta = NULL; // Resetta la carta scelta
                }
            } while (cartaScelta == NULL);

            cartaScelta = rimuoviCartaCFU(giocatoreCorrente, indiceCarta);
            // Inserisce la carta nel mazzo degli scarti
            cartaScelta->next = *mazzoCfuScarti;
            *mazzoCfuScarti = cartaScelta;

            Giocata *giocata = (Giocata *)malloc(sizeof(Giocata));
            giocata->giocatore = giocatoreCorrente;
            giocata->carta = cartaScelta;
            giocata->next = NULL;
            giocata->doppioEffettoAttivo = 0; // Inizialmente non attivo
            memorizzaCarteGiocateNelTurno(&giocata, giocata->giocatore, giocata->carta);

            // Applicare l'effetto della carta istantanea qui
            if (giocata->doppioEffettoAttivo) {
                switch (cartaScelta->effetto) {
                    case AUMENTA:
                        effettoAumenta(giocata, listaGiocatori, listaGiocate);
                        // Applicare l'effetto AUMENTA due volte
                        effettoAumenta(giocata, listaGiocatori, listaGiocate);
                        break;
                    case DIMINUISCI:
                        effettoDiminuisci(giocata, listaGiocatori, listaGiocate);
                        // Applicare l'effetto DIMINUISCI due volte
                        effettoDiminuisci(giocata, listaGiocatori, listaGiocate);
                        break;
                    case INVERTI:
                        effettoInverti(*listaGiocate);
                        break;
                    case SALVA:
                        effettoSalva(giocata->giocatore, mazzoOstacoli, cartaOstacoloEstratta);
                        return; // Conclude il turno dopo aver giocato SALVA
                    case DIROTTA:
                        effettoDirotta(giocata->giocatore, listaGiocatori, cartaOstacoloEstratta);
                        return; // Conclude il turno dopo aver giocato DIROTTA
                }
            } else {
                switch (cartaScelta->effetto) {
                    case AUMENTA:
                        effettoAumenta(giocata, listaGiocatori, listaGiocate);
                        break;
                    case DIMINUISCI:
                        effettoDiminuisci(giocata, listaGiocatori, listaGiocate);
                        break;
                    case INVERTI:
                        effettoInverti(*listaGiocate);
                        break;
                    case SALVA:
                        effettoSalva(giocata->giocatore, mazzoOstacoli, cartaOstacoloEstratta);
                        return; // Conclude il turno dopo aver giocato SALVA
                    case DIROTTA:
                        effettoDirotta(giocata->giocatore, listaGiocatori, cartaOstacoloEstratta);
                        return; // Conclude il turno dopo aver giocato DIROTTA
                }
            }
        } else if (scelta == 'y' || scelta == 'Y') {
            printf("\nNon hai carte istantanee da giocare.\n");
        }

        giocatoreCorrente = giocatoreCorrente->next;
    }
}
//************************************************************************************************************************

void effettoAumenta(Giocata *giocata, Giocatore **listaGiocatori, Giocata **listaGiocate) {
    char nomeGiocatore[MAX_CHAR];
    Giocatore *giocatoreScelto = NULL;
    Giocata *giocataScelta = NULL;

    // Scegliere un giocatore valido
    do {
        printf("\n\nGiocatore %s, scegli un giocatore per aumentare il punteggio: \n", giocata->giocatore->nomeUtente);
        scanf("%s", nomeGiocatore);
        giocatoreScelto = scegliGiocatore(*listaGiocatori, nomeGiocatore);
        if (giocatoreScelto == NULL) {
            printf("\nGiocatore non trovato! Riprova.\n");
        }
    } while (giocatoreScelto == NULL);

    // Trova la giocata del giocatore scelto
    giocataScelta = trovaGiocata(*listaGiocate, giocatoreScelto);
    if (giocataScelta != NULL) {
        giocataScelta->punteggioTemporaneo += AUMENTA_DIMINUISCI;
        printf("Il punteggio temporaneo di %s è stato aumentato di 2 punti.\n", giocatoreScelto->nomeUtente);
    } else {
        printf("Giocata non trovata per il giocatore scelto.\n");
    }
}

//************************************************************************************************************************

void effettoDiminuisci(Giocata *giocata, Giocatore **listaGiocatori, Giocata **listaGiocate) {
    char nomeGiocatore[MAX_CHAR];
    Giocatore *giocatoreScelto = NULL;
    Giocata *giocataScelta = NULL;

    // Scegliere un giocatore valido
    do {
        printf("\n\nGiocatore %s, scegli un giocatore per diminuirne il punteggio: \n", giocata->giocatore->nomeUtente);
        scanf("%s", nomeGiocatore);
        giocatoreScelto = scegliGiocatore(*listaGiocatori, nomeGiocatore);
        if (giocatoreScelto == NULL) {
            printf("\nGiocatore non trovato! Riprova.\n");
        }
    } while (giocatoreScelto == NULL);

    // Trova la giocata del giocatore scelto
    giocataScelta = trovaGiocata(*listaGiocate, giocatoreScelto);
    if (giocataScelta != NULL) {
        giocataScelta->punteggioTemporaneo -= AUMENTA_DIMINUISCI;
        printf("Il punteggio temporaneo di %s è stato diminuito di 2 punti.\n", giocatoreScelto->nomeUtente);
    } else {
        printf("Giocata non trovata per il giocatore scelto.\n");
    }
}

//*************************************************************************************************************************

//UGUALE A SCAMBIA P MA VERRA' USATA COME CARTA ISTANTANEA
void effettoInverti(Giocata *giocata) {
    if (giocata == NULL) {
        printf("Non ci sono giocate da valutare.\n");
        return;
    }
    Giocata *giocataCorrente = giocata;
    Giocata *giocataMin = giocata;
    Giocata *giocataMax = giocata;

    // Trova le giocate con il punteggio del turno minore e maggiore
    while (giocata != NULL) {
        if (giocata->punteggioTemporaneo < giocataMin->punteggioTemporaneo) {
            giocataMin = giocata;
        }
        if (giocata->punteggioTemporaneo > giocataMax->punteggioTemporaneo) {
            giocataMax = giocata;
        }
        giocata = giocata->next;
    }
// Scambia i punteggi temporanei
    if (giocataMin != giocataMax) {
        int temp = giocataMin->punteggioTemporaneo;
        giocataMin->punteggioTemporaneo = giocataMax->punteggioTemporaneo;
        giocataMax->punteggioTemporaneo = temp;

        printf("\nIl punteggio del turno del giocatore %s (%d) è stato scambiato con quello del giocatore %s (%d).\n",
               giocataMin->giocatore->nomeUtente, giocataMin->punteggioTemporaneo,
               giocataMax->giocatore->nomeUtente, giocataMax->punteggioTemporaneo);
    } else {
        printf("\nNon ci sono abbastanza giocate per effettuare lo scambio dei punteggi.\n");
    }
}

//***************************************************************************************************************************

void effettoSalva(Giocatore *giocatore, CartaOstacolo **mazzoOstacoli, CartaOstacoloEstratta **cartaOstacoloEstratta) {
    printf("\n%s gioca la carta istantanea 'SALVA'!\n", giocatore->nomeUtente);
    if (*cartaOstacoloEstratta != NULL) {
        mettiCartaOstacoloInFondo(mazzoOstacoli, &(*cartaOstacoloEstratta)->carta);
        *cartaOstacoloEstratta = NULL;
        printf("La carta Ostacolo è stata messa in fondo al mazzo. Il turno si conclude qui.\n");
        premiUnoPerContinuare();
    } else {
        printf("Errore: Nessuna carta ostacolo estratta.\n");
    }
}

//*************************************************************************************************************************

void effettoDirotta(Giocatore *giocatore, Giocatore **listaGiocatori, CartaOstacoloEstratta **cartaOstacoloEstratta) {
    if (*cartaOstacoloEstratta != NULL) {
        // Stampa la lista dei giocatori
        printf("\nLista dei giocatori:\n");
        int i = 0;
        Giocatore *current = *listaGiocatori;
        while (current != NULL) {
            printf("[%d] %s\n", i, current->nomeUtente);
            current = current->next;
            i++;
        }

        // Chiedi al giocatore di scegliere a chi assegnare la carta
        int scelta;
        do {
            printf("\n%s, scegli un giocatore a cui assegnare la carta ostacolo (indice da 0 a %d): ", giocatore->nomeUtente, i - 1);
            scanf("%d", &scelta);
            // Pulisce il buffer dallo '\n'
            while (getchar() != '\n');
        } while (scelta < 0 || scelta >= i);

        // Trova il giocatore scelto
        current = *listaGiocatori;
        for (int j = 0; j < scelta; j++) {
            current = current->next;
        }

        // Assegna la carta ostacolo al giocatore scelto
        printf("%s assegna la carta ostacolo a %s!\n", giocatore->nomeUtente, current->nomeUtente);
        assegnaCartaOstacoloPerdente(current, &(*cartaOstacoloEstratta)->carta);
        *cartaOstacoloEstratta = NULL; // Imposta a NULL la carta estratta
        premiUnoPerContinuare();
    } else {
        printf("Errore: Nessuna carta ostacolo estratta.\n");
    }
}