#include "risolviPareggio.h"
void risolviPareggio(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                     CartaCFU **mazzoCfu,
                     CartaCFU **mazzoCfuScarti,
                     CartaOstacolo **mazzoOstacoli,
                     Giocatore **listaGiocatori,
                     Giocata **listaGiocate,
                     CartaOstacoloEstratta *cartaOstacoloEstratta) {
    int flag = 0;

    while (flag == 0) {
        Giocata *giocataPtr = *listaGiocate;
        int punteggioMassimo = giocataPtr->punteggioTemporaneo;
        int punteggioMinimo = giocataPtr->punteggioTemporaneo;

        // Trova il punteggio massimo e minimo temporaneo dalla listaGiocate
        while (giocataPtr != NULL) {
            int punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp < punteggioMinimo) {
                punteggioMinimo = punteggioTemp;
            }
            if (punteggioTemp > punteggioMassimo) {
                punteggioMassimo = punteggioTemp;
            }
            giocataPtr = giocataPtr->next;
        }


        // Determina i vincitori e i perdenti dalla listaGiocate
        giocataPtr = *listaGiocate;
        int numVincitori = 0;
        int numPerdenti = 0;
        Giocatore *listaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        // Scansiona nuovamente per aggiungere solo i perdenti corretti
        while (giocataPtr != NULL) {
            int punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp == punteggioMassimo) {
                numVincitori++;
            }
            if (punteggioTemp == punteggioMinimo) {
                // Aggiungi alla lista solo se non è già presente
                Giocatore *giocatorePerdente = giocataPtr->giocatore;
                if (!trovaGiocatore(listaGiocatoriPerdenti, giocatorePerdente)) {
                    numPerdenti++;
                    Giocatore *nuovoPerdente = malloc(sizeof(Giocatore));
                    *nuovoPerdente = *giocatorePerdente;
                    nuovoPerdente->next = NULL;
                    if (listaGiocatoriPerdenti == NULL) {
                        listaGiocatoriPerdenti = nuovoPerdente;
                        ultimoGiocatorePerdente = nuovoPerdente;
                    } else {
                        ultimoGiocatorePerdente->next = nuovoPerdente;
                        ultimoGiocatorePerdente = nuovoPerdente;
                    }
                }
            }
            giocataPtr = giocataPtr->next;
        }

        int numGiocatori = contaGiocatori(*listaGiocatori);
        printf("\n NUM GIOCATORI %d", numGiocatori);
        printf("\nMAX %d, MIN %d\n", punteggioMassimo, punteggioMinimo);
        premiUnoPerContinuare();
        // Se tutti i giocatori hanno fatto lo stesso punteggio
        if (punteggioMassimo == punteggioMinimo && numGiocatori==2) {
            clearScreen();
            printf("\n\nTutti hanno fatto lo stesso punteggio!\n"
                   "Non ci sono ne' vinti ne' vincitori in questo turno!\n");
            flag = 1;
            numPerdenti = 0;
            numVincitori = 0;
        }

        // Assegna i CFU ai vincitori
        giocataPtr = *listaGiocate;
        while (giocataPtr != NULL) {
            int punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp == punteggioMassimo && numVincitori >= 1) {
                if(giocataPtr->punteggioTemporaneo == punteggioMassimo) {
                    giocataPtr->giocatore->cfu += punteggioMassimo;
                    clearScreen();
                    printf("\n\n%s vince il turno con %d punti e ora ha %d CFU.\n",
                           giocataPtr->giocatore->nomeUtente,
                           punteggioMassimo, giocataPtr->giocatore->cfu);
                }
            }
            giocataPtr = giocataPtr->next;
        }

        if (numPerdenti == 1) {
            giocataPtr = *listaGiocate;
            while (giocataPtr != NULL) {
                if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                    assegnaCartaOstacoloPerdente(giocataPtr->giocatore, &cartaOstacoloEstratta->carta);
                    premiUnoPerContinuare();
                }
                giocataPtr = giocataPtr->next;
            }
            flag = 1;
        } else if(numPerdenti>1) {
            printf("\nTurno aggiuntivo di spareggio tra i seguenti giocatori:\n");
            stampaDebugGiocatori(listaGiocatoriPerdenti);

            // Esegui un turno aggiuntivo di spareggio
            flag = turnoAggiuntivoSpareggio(&listaGiocatoriPerdenti, mazzoCfu, mazzoCfuScarti, cartaOstacoloEstratta);
        }
    }
}

// Funzione ausiliaria per cercare un giocatore nella lista
int trovaGiocatore(Giocatore *lista, Giocatore *giocatore) {
    Giocatore *tmp = lista;
    while (tmp != NULL) {
        if (tmp == giocatore) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

/*
void risolviPareggio(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                     CartaCFU **mazzoCfu,
                     CartaCFU **mazzoCfuScarti,
                     CartaOstacolo **mazzoOstacoli,
                     Giocatore **listaGiocatori,
                     Giocata **listaGiocate,
                     CartaOstacoloEstratta *cartaOstacoloEstratta) {
    int flag = 0;

    while (flag == 0) {
        Giocata *giocataPtr = *listaGiocate;
        int punteggioMassimo = giocataPtr->punteggioTemporaneo;
        int punteggioMinimo = giocataPtr->punteggioTemporaneo;

        // Trova il punteggio massimo e minimo temporaneo dalla listaGiocate
        while (giocataPtr != NULL) {
            int punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp < punteggioMinimo) {
                punteggioMinimo = punteggioTemp;
            }
            if (punteggioTemp > punteggioMassimo) {
                punteggioMassimo = punteggioTemp;
            }
            giocataPtr = giocataPtr->next;
        }


        // Determina i vincitori e i perdenti dalla listaGiocate
        giocataPtr = *listaGiocate;
        int numVincitori = 0;
        int numPerdenti = 0;
        Giocatore *listaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        // Scansiona nuovamente per aggiungere solo i perdenti corretti
        while (giocataPtr != NULL) {
            int punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp == punteggioMassimo) {
                numVincitori++;
            }
            if (punteggioTemp == punteggioMinimo) {
                // Aggiungi alla lista solo se non è già presente
                Giocatore *giocatorePerdente = giocataPtr->giocatore;
                if (!trovaGiocatore(listaGiocatoriPerdenti, giocatorePerdente)) {
                    numPerdenti++;
                    Giocatore *nuovoPerdente = malloc(sizeof(Giocatore));
                    *nuovoPerdente = *giocatorePerdente;
                    nuovoPerdente->next = NULL;
                    if (listaGiocatoriPerdenti == NULL) {
                        listaGiocatoriPerdenti = nuovoPerdente;
                        ultimoGiocatorePerdente = nuovoPerdente;
                    } else {
                        ultimoGiocatorePerdente->next = nuovoPerdente;
                        ultimoGiocatorePerdente = nuovoPerdente;
                    }
                }
            }
            giocataPtr = giocataPtr->next;
        }


        // Se tutti i giocatori hanno fatto lo stesso punteggio
        if (punteggioMassimo == punteggioMinimo) {
            clearScreen();
            printf("\n\nTutti hanno fatto lo stesso punteggio!\n"
                   "Non ci sono ne' vinti ne' vincitori in questo turno!\n");
            numPerdenti = 0;
            numVincitori = 0;
            flag = 1;
        } else {
            // Gestisce i pareggi per il punteggio più basso
            if (numPerdenti > 1) {
                printf("\n\nPareggio per il punteggio più basso. Turno aggiuntivo tra i giocatori che pareggiano.\n");
                flag = turnoAggiuntivoSpareggio(&listaGiocatoriPerdenti, mazzoCfu, mazzoCfuScarti, cartaOstacoloEstratta);
            } else {
                // Assegna i CFU ai vincitori
                giocataPtr = *listaGiocate;
                while (giocataPtr != NULL) {
                    int punteggioTemp = giocataPtr->punteggioTemporaneo;
                    if (punteggioTemp == punteggioMassimo) {
                        giocataPtr->giocatore->cfu += punteggioMassimo;
                        clearScreen();
                        printf("\n\n%s vince il turno con %d punti e ora ha %d CFU.\n",
                               giocataPtr->giocatore->nomeUtente,
                               punteggioMassimo, giocataPtr->giocatore->cfu);
                    }
                    giocataPtr = giocataPtr->next;
                }

                // Assegna la carta ostacolo al perdente
                giocataPtr = *listaGiocate;
                while (giocataPtr != NULL) {
                    if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                        assegnaCartaOstacoloPerdente(giocataPtr->giocatore, &cartaOstacoloEstratta->carta);
                        flag = 1;
                    }
                    giocataPtr = giocataPtr->next;
                }
                flag = 1;
            }
        }

        if (flag == 1) {
            premiUnoPerContinuare();
        }
    }
}


*/
/*
void risolviPareggio(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
                     CartaCFU **mazzoCfu,
                     CartaCFU **mazzoCfuScarti,
                     CartaOstacolo **mazzoOstacoli,
                     Giocatore **listaGiocatori,
                     Giocata **listaGiocate,
                     CartaOstacoloEstratta *cartaOstacoloEstratta) {
    int flag = 0;

    while(flag == 0) {
        Giocata *giocataPtr = *listaGiocate;
        int punteggioMassimo = giocataPtr->punteggioTemporaneo;
        int punteggioMinimo = giocataPtr->punteggioTemporaneo;
        int punteggioTemp = 0;

        // Trova il punteggio massimo e minimo temporaneo dalla listaGiocate
        while (giocataPtr != NULL) {
            punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp < punteggioMinimo) {
                punteggioMinimo = punteggioTemp;
            }
            if (punteggioTemp > punteggioMassimo) {
                punteggioMassimo = punteggioTemp;
            }
            giocataPtr = giocataPtr->next;
        }

        // Determina i vincitori e i perdenti dalla listaGiocate
        giocataPtr = *listaGiocate;
        int numVincitori = 0;
        int numPerdenti = 0;

        while (giocataPtr != NULL) {
            punteggioTemp = giocataPtr->punteggioTemporaneo;
            if (punteggioTemp == punteggioMassimo) {
                numVincitori++;
            }
            if (punteggioTemp == punteggioMinimo) {
                numPerdenti++;
            }
            giocataPtr = giocataPtr->next;
        }

        // Se tutti i giocatori hanno fatto lo stesso punteggio
        if (punteggioMassimo == punteggioMinimo) {
            clearScreen();
            printf("\n\nTutti hanno fatto lo stesso punteggio!\n"
                   "Non ci sono ne' vinti ne' vincitori in questo turno!\n");
            numPerdenti = 0;
            numVincitori = 0;
            flag = 1;
        } else {
            // Gestisce i pareggi per il punteggio più basso
            if (numPerdenti > 1) {
                Giocata *listaGiocatePerdenti = NULL;
                Giocata *ultimoGiocata = NULL;
                Giocatore *listaGiocatoriPerdenti = NULL;
                Giocatore *ultimoGiocatore = NULL;
                giocataPtr = *listaGiocate;

                while (giocataPtr != NULL) {
                    if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                        // Aggiungi alla lista delle giocate perdenti
                        Giocata *nuovaGiocata = (Giocata *) malloc(sizeof(Giocata));
                        *nuovaGiocata = *giocataPtr;
                        nuovaGiocata->next = NULL;
                        if (listaGiocatePerdenti == NULL) {
                            listaGiocatePerdenti = nuovaGiocata;
                            ultimoGiocata = nuovaGiocata;
                        } else {
                            ultimoGiocata->next = nuovaGiocata;
                            ultimoGiocata = nuovaGiocata;
                        }

                        // Aggiungi alla lista dei giocatori perdenti
                        Giocatore *nuovoGiocatorePerdente;
                        nuovoGiocatorePerdente = giocataPtr->giocatore;
                        nuovoGiocatorePerdente->next = NULL;
                        if (listaGiocatoriPerdenti == NULL) {
                            listaGiocatoriPerdenti = nuovoGiocatorePerdente;
                            ultimoGiocatore = nuovoGiocatorePerdente;
                        } else {
                            ultimoGiocatore->next = nuovoGiocatorePerdente;
                            ultimoGiocatore = nuovoGiocatorePerdente;
                        }
                    }
                    giocataPtr = giocataPtr->next;
                }

                printf("\n\nPareggio per il punteggio più basso. Turno aggiuntivo tra i giocatori che pareggiano.\n");
                while(listaGiocatoriPerdenti!=NULL) {
                    if (controllaCartePunto(listaGiocatoriPerdenti) == 0){
                        printf("%s non ha carte CFU punto per lo spareggio! Perde automaticamente il turno", listaGiocatoriPerdenti->nomeUtente);
                        flag=1;
                    }
                        turnoAggiuntivoSpareggio(&listaGiocatoriPerdenti, listaGiocatePerdenti, mazzoCfu,
                                                 mazzoCfuScarti, cartaOstacoloEstratta);
                }

                // Libera la memoria allocata per le giocate dei perdenti
                while (listaGiocatePerdenti != NULL) {
                    Giocata *temp = listaGiocatePerdenti;
                    listaGiocatePerdenti = listaGiocatePerdenti->next;
                    free(temp);
                }

                flag = 0;
            } else {
                // Assegna i CFU ai vincitori
                giocataPtr = *listaGiocate;
                if(numVincitori >= 1){
                    while (giocataPtr != NULL) {
                        punteggioTemp = giocataPtr->punteggioTemporaneo;
                        if (punteggioTemp == punteggioMassimo) {
                            giocataPtr->giocatore->cfu += punteggioMassimo;
                            clearScreen();
                            printf("\n\n%s vince il turno con %d punti e ora ha %d CFU.\n",
                                   giocataPtr->giocatore->nomeUtente,
                                   punteggioMassimo, giocataPtr->giocatore->cfu);
                        }
                        giocataPtr = giocataPtr->next;
                    }
                }

                // Assegna la carta ostacolo al perdente
                if (numPerdenti == 1) {
                    giocataPtr = *listaGiocate;
                    while (giocataPtr != NULL) {
                        if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                            assegnaCartaOstacoloPerdente(giocataPtr->giocatore, &cartaOstacoloEstratta->carta);
                        }
                        giocataPtr = giocataPtr->next;
                    }
                }

                flag = 1;
            }
        }

        if (flag == 1) {
            premiUnoPerContinuare();
        }
    }
}
 */