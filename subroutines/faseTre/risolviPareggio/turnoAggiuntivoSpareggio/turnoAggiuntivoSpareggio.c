#include "turnoAggiuntivoSpareggio.h"
int turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti,
                             CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                             CartaOstacoloEstratta *cartaOstacoloEstratta) {

    // Controllo iniziale se nessun giocatore ha carte CFU punto
    Giocatore *listaGiocatoriPtr = *listaGiocatoriPerdenti;
    int nessunGiocatoreConCartePunto = 1; // Assume nessun giocatore ha carte CFU punto
    int giocatoreTrovato = 0;

    while (listaGiocatoriPtr != NULL && giocatoreTrovato == 0) {
        if (controllaCartePunto(listaGiocatoriPtr) != 0) {
            nessunGiocatoreConCartePunto = 0; // Almeno un giocatore ha carte CFU punto
            giocatoreTrovato = 1; // Imposta flag per uscire dal ciclo
        }
        listaGiocatoriPtr = listaGiocatoriPtr->next;
    }

    // Se nessun giocatore ha carte CFU punto, esce subito senza fare nient'altro
    if (nessunGiocatoreConCartePunto) {
        printf("\nNessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
        premiUnoPerContinuare();
        return 1; // Ritorna 1 per indicare la fine del turno
    }

    // Altrimenti, procede con il normale svolgimento del turno aggiuntivo di spareggio
    premiUnoPerContinuare();

    int flag = 0;
    while (flag == 0) {
        listaGiocatoriPtr = *listaGiocatoriPerdenti;

        // Reset per nuova lista di giocate
        Giocata *nuovaListaGiocate = NULL;
        Giocata *ultimoNuovaGiocata = NULL;
        Giocatore *nuovaListaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        int giocatoriSenzaCarte = 0;
        int giocatoriTotali = 0;
        int punteggioMassimo = 0;
        int punteggioMinimo = 0;
        int numPerdenti = 0;

        while (listaGiocatoriPtr != NULL) {
            giocatoriTotali++;
            // Controlla se il giocatore ha carte CFU punto
            if (controllaCartePunto(listaGiocatoriPtr) == 0) {
                printf("\n%s non ha carte CFU punto e perde il turno.\n", listaGiocatoriPtr->nomeUtente);
                assegnaCartaOstacoloPerdente(listaGiocatoriPtr, &cartaOstacoloEstratta->carta);
                premiUnoPerContinuare();
                return 1;
            } else {
                Giocata *nuovaGiocata = giocaCarta(listaGiocatoriPtr, mazzoCfu, mazzoCfuScarti);
                if (nuovaGiocata != NULL) {
                    // Ignora effetti e modificatori
                    nuovaGiocata->punteggioTemporaneo = nuovaGiocata->carta->valoreCarta;
                    int punteggioTemp = nuovaGiocata->punteggioTemporaneo;

                    // Aggiorna punteggi massimo e minimo
                    if (nuovaListaGiocate == NULL) {
                        punteggioMassimo = punteggioTemp;
                        punteggioMinimo = punteggioTemp;
                    } else {
                        if (punteggioTemp < punteggioMinimo) {
                            punteggioMinimo = punteggioTemp;
                        }
                        if (punteggioTemp > punteggioMassimo) {
                            punteggioMassimo = punteggioTemp;
                        }
                    }

                    // Aggiungi alla nuova lista di giocate
                    nuovaGiocata->next = NULL;
                    if (nuovaListaGiocate == NULL) {
                        nuovaListaGiocate = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    } else {
                        ultimoNuovaGiocata->next = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    }
                }
            }
            listaGiocatoriPtr = listaGiocatoriPtr->next;
        }

        // Se nessun giocatore ha carte CFU punto
        if (giocatoriSenzaCarte == giocatoriTotali) {
            printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
            flag = 1;
        } else {
            // Conta i giocatori con punteggio minimo e massimo
            int numVincitori = 0;
            Giocata *giocataPtr = nuovaListaGiocate;

            while (giocataPtr != NULL) {
                if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                    numPerdenti++;
                    // Aggiungi alla nuova lista di giocatori perdenti
                    Giocatore *giocatorePerdente = giocataPtr->giocatore;
                    if (!trovaGiocatore(nuovaListaGiocatoriPerdenti, giocatorePerdente)) { // Evita duplicati
                        if (nuovaListaGiocatoriPerdenti == NULL) {
                            nuovaListaGiocatoriPerdenti = giocatorePerdente;
                            ultimoGiocatorePerdente = giocatorePerdente;
                        } else {
                            ultimoGiocatorePerdente->next = giocatorePerdente;
                            ultimoGiocatorePerdente = giocatorePerdente;
                        }
                        giocatorePerdente->next = NULL; // Assicura che il puntatore next sia NULL
                    }
                }
                if (giocataPtr->punteggioTemporaneo == punteggioMassimo) {
                    numVincitori++;
                }
                giocataPtr = giocataPtr->next;
            }

            // Se c'è un unico perdente
            if (numPerdenti == 1) {
                giocataPtr = nuovaListaGiocate;
                while (giocataPtr != NULL) {
                    if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                        assegnaCartaOstacoloPerdente(giocataPtr->giocatore, &cartaOstacoloEstratta->carta);
                    }
                    giocataPtr = giocataPtr->next;
                }
                flag = 1;
            }

            // Libera la memoria delle nuove liste temporanee
            while (nuovaListaGiocate != NULL) {
                Giocata *temp = nuovaListaGiocate;
                nuovaListaGiocate = nuovaListaGiocate->next;
                free(temp);
            }

            *listaGiocatoriPerdenti = nuovaListaGiocatoriPerdenti;

            if (nuovaListaGiocatoriPerdenti == NULL) {
                printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
                flag = 1;
            }
        }
    }

    return flag; // Ritorna il valore di flag per indicare la fine del turno
}


/*
int turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti,
                             CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                             CartaOstacoloEstratta *cartaOstacoloEstratta) {

    // Controllo iniziale se nessun giocatore ha carte CFU punto
    Giocatore *listaGiocatoriPtr = *listaGiocatoriPerdenti;
    int nessunGiocatoreConCartePunto = 1; // Assume nessun giocatore ha carte CFU punto

    while (listaGiocatoriPtr != NULL) {
        if (controllaCartePunto(listaGiocatoriPtr) != 0) {
            nessunGiocatoreConCartePunto = 0; // Almeno un giocatore ha carte CFU punto
            break;
        }
        listaGiocatoriPtr = listaGiocatoriPtr->next;
    }

    // Se nessun giocatore ha carte CFU punto, esce subito senza fare nient'altro
    if (nessunGiocatoreConCartePunto) {
        printf("\nNessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
        premiUnoPerContinuare();
        return 1; // Ritorna 1 per indicare la fine del turno
    }

    // Altrimenti, procede con il normale svolgimento del turno aggiuntivo di spareggio
    premiUnoPerContinuare();

    int flag = 0;
    while (flag == 0) {
        listaGiocatoriPtr = *listaGiocatoriPerdenti;

        // Reset per nuova lista di giocate
        Giocata *nuovaListaGiocate = NULL;
        Giocata *ultimoNuovaGiocata = NULL;
        Giocatore *nuovaListaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        int giocatoriSenzaCarte = 0;
        int giocatoriTotali = 0;
        int punteggioMassimo = 0;
        int punteggioMinimo = 0;
        int numPerdenti = 0;

        while (listaGiocatoriPtr != NULL) {
            giocatoriTotali++;
            // Controlla se il giocatore ha carte CFU punto
            if (controllaCartePunto(listaGiocatoriPtr) == 0) {
                printf("\n%s non ha carte CFU punto e perde il turno.\n", listaGiocatoriPtr->nomeUtente);
                premiUnoPerContinuare();
                return 1;
                giocatoriSenzaCarte++;
            } else {
                Giocata *nuovaGiocata = giocaCarta(listaGiocatoriPtr, mazzoCfu, mazzoCfuScarti);
                if (nuovaGiocata != NULL) {
                    // Ignora effetti e modificatori
                    nuovaGiocata->punteggioTemporaneo = nuovaGiocata->carta->valoreCarta;
                    int punteggioTemp = nuovaGiocata->punteggioTemporaneo;

                    // Aggiorna punteggi massimo e minimo
                    if (nuovaListaGiocate == NULL) {
                        punteggioMassimo = punteggioTemp;
                        punteggioMinimo = punteggioTemp;
                    } else {
                        if (punteggioTemp < punteggioMinimo) {
                            punteggioMinimo = punteggioTemp;
                        }
                        if (punteggioTemp > punteggioMassimo) {
                            punteggioMassimo = punteggioTemp;
                        }
                    }

                    // Aggiungi alla nuova lista di giocate
                    nuovaGiocata->next = NULL;
                    if (nuovaListaGiocate == NULL) {
                        nuovaListaGiocate = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    } else {
                        ultimoNuovaGiocata->next = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    }
                }
            }
            listaGiocatoriPtr = listaGiocatoriPtr->next;
        }

        // Se nessun giocatore ha carte CFU punto
        if (giocatoriSenzaCarte == giocatoriTotali) {
            printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
            flag = 1;
        } else {
            // Conta i giocatori con punteggio minimo e massimo
            int numVincitori = 0;
            Giocata *giocataPtr = nuovaListaGiocate;

            while (giocataPtr != NULL) {
                if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                    numPerdenti++;
                    // Aggiungi alla nuova lista di giocatori perdenti
                    Giocatore *giocatorePerdente = giocataPtr->giocatore;
                    if (nuovaListaGiocatoriPerdenti == NULL) {
                        nuovaListaGiocatoriPerdenti = giocatorePerdente;
                        ultimoGiocatorePerdente = giocatorePerdente;
                    } else {
                        ultimoGiocatorePerdente->next = giocatorePerdente;
                        ultimoGiocatorePerdente = giocatorePerdente;
                    }
                }
                if (giocataPtr->punteggioTemporaneo == punteggioMassimo) {
                    numVincitori++;
                }
                giocataPtr = giocataPtr->next;
            }

            // Se c'è un unico perdente
            if (numPerdenti == 1) {
                giocataPtr = nuovaListaGiocate;
                while (giocataPtr != NULL) {
                    if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                        assegnaCartaOstacoloPerdente(giocataPtr->giocatore, &cartaOstacoloEstratta->carta);
                    }
                    giocataPtr = giocataPtr->next;
                }
                flag = 1;
            }

            // Libera la memoria delle nuove liste temporanee
            while (nuovaListaGiocate != NULL) {
                Giocata *temp = nuovaListaGiocate;
                nuovaListaGiocate = nuovaListaGiocate->next;
                free(temp);
            }

            *listaGiocatoriPerdenti = nuovaListaGiocatoriPerdenti;

            if (nuovaListaGiocatoriPerdenti == NULL) {
                printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
                flag = 1;
            }
        }
    }

    return flag; // Ritorna il valore di flag per indicare la fine del turno
}

*/
/*
void turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti,
                              CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                              CartaOstacoloEstratta *cartaOstacoloEstratta) {

    // Controllo iniziale se nessun giocatore ha carte CFU punto
    Giocatore *listaGiocatoriPtr = *listaGiocatoriPerdenti;
    int nessunGiocatoreConCartePunto = 1; // Assume nessun giocatore ha carte CFU punto

    while (listaGiocatoriPtr != NULL) {
        if (controllaCartePunto(listaGiocatoriPtr) != 0) {
            nessunGiocatoreConCartePunto = 0; // Almeno un giocatore ha carte CFU punto
            break;
        }
        listaGiocatoriPtr = listaGiocatoriPtr->next;
    }

    // Se nessun giocatore ha carte CFU punto, esce subito senza fare nient'altro
    if (nessunGiocatoreConCartePunto) {
        printf("\nNessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
        premiUnoPerContinuare();
        return;
    }

    // Altrimenti, procede con il normale svolgimento del turno aggiuntivo di spareggio
    premiUnoPerContinuare();

    int flag = 0;
    while (flag == 0) {
        listaGiocatoriPtr = *listaGiocatoriPerdenti;

        // Reset per nuova lista di giocate
        Giocata *nuovaListaGiocate = NULL;
        Giocata *ultimoNuovaGiocata = NULL;
        Giocatore *nuovaListaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        int giocatoriSenzaCarte = 0;
        int giocatoriTotali = 0;
        int punteggioMassimo = 0;
        int punteggioMinimo = 0;
        int numPerdenti = 0;

        while (listaGiocatoriPtr != NULL) {
            giocatoriTotali++;
            // Controlla se il giocatore ha carte CFU punto
            if (controllaCartePunto(listaGiocatoriPtr) == 0) {
                printf("\n%s non ha carte CFU punto e perde il turno.\n", listaGiocatoriPtr->nomeUtente);
                premiUnoPerContinuare();
                giocatoriSenzaCarte++;
            } else {
                Giocata *nuovaGiocata = giocaCarta(listaGiocatoriPtr, mazzoCfu, mazzoCfuScarti);
                if (nuovaGiocata != NULL) {
                    // Ignora effetti e modificatori
                    nuovaGiocata->punteggioTemporaneo = nuovaGiocata->carta->valoreCarta;
                    int punteggioTemp = nuovaGiocata->punteggioTemporaneo;

                    // Aggiorna punteggi massimo e minimo
                    if (nuovaListaGiocate == NULL) {
                        punteggioMassimo = punteggioTemp;
                        punteggioMinimo = punteggioTemp;
                    } else {
                        if (punteggioTemp < punteggioMinimo) {
                            punteggioMinimo = punteggioTemp;
                        }
                        if (punteggioTemp > punteggioMassimo) {
                            punteggioMassimo = punteggioTemp;
                        }
                    }

                    // Aggiungi alla nuova lista di giocate
                    nuovaGiocata->next = NULL;
                    if (nuovaListaGiocate == NULL) {
                        nuovaListaGiocate = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    } else {
                        ultimoNuovaGiocata->next = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    }
                }
            }
            listaGiocatoriPtr = listaGiocatoriPtr->next;
        }

        // Se nessun giocatore ha carte CFU punto
        if (giocatoriSenzaCarte == giocatoriTotali) {
            printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
            flag = 1;
        } else {
            // Conta i giocatori con punteggio minimo e massimo
            int numVincitori = 0;
            Giocata *giocataPtr = nuovaListaGiocate;

            while (giocataPtr != NULL) {
                if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                    numPerdenti++;
                    // Aggiungi alla nuova lista di giocatori perdenti
                    Giocatore *giocatorePerdente = giocataPtr->giocatore;
                    if (nuovaListaGiocatoriPerdenti == NULL) {
                        nuovaListaGiocatoriPerdenti = giocatorePerdente;
                        ultimoGiocatorePerdente = giocatorePerdente;
                    } else {
                        ultimoGiocatorePerdente->next = giocatorePerdente;
                        ultimoGiocatorePerdente = giocatorePerdente;
                    }
                }
                if (giocataPtr->punteggioTemporaneo == punteggioMassimo) {
                    numVincitori++;
                }
                giocataPtr = giocataPtr->next;
            }

            // Se c'è un unico perdente
            if (numPerdenti == 1) {
                giocataPtr = nuovaListaGiocate;
                while (giocataPtr != NULL) {
                    if (giocataPtr->punteggioTemporaneo == punteggioMinimo) {
                        assegnaCartaOstacoloPerdente(giocataPtr->giocatore, &cartaOstacoloEstratta->carta);
                    }
                    giocataPtr = giocataPtr->next;
                }
                flag = 1;
            }

            // Libera la memoria delle nuove liste temporanee
            while (nuovaListaGiocate != NULL) {
                Giocata *temp = nuovaListaGiocate;
                nuovaListaGiocate = nuovaListaGiocate->next;
                free(temp);
            }

            *listaGiocatoriPerdenti = nuovaListaGiocatoriPerdenti;

            if (nuovaListaGiocatoriPerdenti == NULL) {
                printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
                flag = 1;
            }
        }
    }
}
*/
/*
void turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti,
                              CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                              CartaOstacoloEstratta *cartaOstacoloEstratta) {

    premiUnoPerContinuare();

    int flag = 0;
    while (flag == 0) {
        Giocatore *listaGiocatoriPtr = *listaGiocatoriPerdenti;
        Giocata *listaGiocatePerdentiPtr = NULL;

        // Reset per nuova lista di giocate
        Giocata *nuovaListaGiocate = NULL;
        Giocata *ultimoNuovaGiocata = NULL;
        Giocatore *nuovaListaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        int giocatoriSenzaCarte = 0;
        int giocatoriTotali = 0;
        int punteggioMassimo=0;
        int punteggioMinimo=0;

        while (listaGiocatoriPtr != NULL) {
            giocatoriTotali++;
            // Controlla se il giocatore ha carte CFU punto
            if (controllaCartePunto(listaGiocatoriPtr) == 0) {
                printf("\n%s non ha carte CFU punto e perde il turno.\n", listaGiocatoriPtr->nomeUtente);
                premiUnoPerContinuare();
                giocatoriSenzaCarte++;
            } else {
                Giocata *nuovaGiocata = giocaCarta(listaGiocatoriPtr, mazzoCfu, mazzoCfuScarti);
                if (nuovaGiocata != NULL) {
                    // Ignora effetti e modificatori
                    nuovaGiocata->punteggioTemporaneo = nuovaGiocata->carta->valoreCarta;
                    punteggioMassimo = nuovaGiocata->punteggioTemporaneo;
                    punteggioMinimo = nuovaGiocata->punteggioTemporaneo;
                    int punteggioTemp = 0;


                    // Aggiorna punteggi massimo e minimo
                    punteggioTemp = nuovaGiocata->punteggioTemporaneo;
                    if (punteggioTemp < punteggioMinimo) {
                        punteggioMinimo = punteggioTemp;
                    }
                    if (punteggioTemp > punteggioMassimo) {
                        punteggioMassimo = punteggioTemp;
                    }

                    // Aggiungi alla nuova lista di giocate
                    nuovaGiocata->next = NULL;
                    if (nuovaListaGiocate == NULL) {
                        nuovaListaGiocate = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    } else {
                        ultimoNuovaGiocata->next = nuovaGiocata;
                        ultimoNuovaGiocata = nuovaGiocata;
                    }
                }
            }
            listaGiocatoriPtr = listaGiocatoriPtr->next;
        }

        // Se nessun giocatore ha carte CFU punto
        if (giocatoriSenzaCarte == giocatoriTotali) {
            printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
            flag = 1;
        } else {
            // Conta i giocatori con punteggio minimo e massimo
            int numPerdenti = 0;
            int numVincitori = 0;

            listaGiocatePerdentiPtr = nuovaListaGiocate;
            while (listaGiocatePerdentiPtr != NULL) {
                if (listaGiocatePerdentiPtr->punteggioTemporaneo == punteggioMinimo) {
                    numPerdenti++;
                    // Aggiungi alla nuova lista di giocatori perdenti
                    Giocatore *giocatorePerdente = listaGiocatePerdentiPtr->giocatore;
                    if (nuovaListaGiocatoriPerdenti == NULL) {
                        nuovaListaGiocatoriPerdenti = giocatorePerdente;
                        ultimoGiocatorePerdente = giocatorePerdente;
                    } else {
                        ultimoGiocatorePerdente->next = giocatorePerdente;
                        ultimoGiocatorePerdente = giocatorePerdente;
                    }
                }
                if (listaGiocatePerdentiPtr->punteggioTemporaneo == punteggioMassimo) {
                    numVincitori++;
                }
                listaGiocatePerdentiPtr = listaGiocatePerdentiPtr->next;
            }

            // Se c'è un unico perdente
            if (numPerdenti == 1) {
                listaGiocatePerdentiPtr = nuovaListaGiocate;
                while (listaGiocatePerdentiPtr != NULL) {
                    if (listaGiocatePerdentiPtr->punteggioTemporaneo == punteggioMinimo) {
                        assegnaCartaOstacoloPerdente(listaGiocatePerdentiPtr->giocatore, &cartaOstacoloEstratta->carta);
                    }
                    listaGiocatePerdentiPtr = listaGiocatePerdentiPtr->next;
                }
                flag = 1;
            }

            // Libera la memoria delle nuove liste temporanee
            while (nuovaListaGiocate != NULL) {
                Giocata *temp = nuovaListaGiocate;
                nuovaListaGiocate = nuovaListaGiocate->next;
                free(temp);
            }

            *listaGiocatoriPerdenti = nuovaListaGiocatoriPerdenti;

            if (nuovaListaGiocatoriPerdenti == NULL) {
                printf("Nessun giocatore ha carte CFU punto. Nessun perdente in questo turno.\n");
                flag = 1;
            }
        }
    }
}
 */
/*
void turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti, Giocata *listaGiocatePerdenti,
                              CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                              CartaOstacoloEstratta *cartaOstacoloEstratta) {

    premiUnoPerContinuare();

    int flag = 0;
    while (flag == 0) {
        Giocatore *listaGiocatoriPtr = *listaGiocatoriPerdenti;
        Giocata *listaGiocatePerdentiPtr = NULL;
        int punteggioMassimo = -1;
        int punteggioMinimo = INT_MAX;
        int punteggioTemp = 0;

        // Reset per nuova lista di giocate
        Giocata *nuovaListaGiocate = NULL;
        Giocata *ultimoNuovaGiocata = NULL;
        Giocatore *nuovaListaGiocatoriPerdenti = NULL;
        Giocatore *ultimoGiocatorePerdente = NULL;

        while (listaGiocatoriPtr != NULL) {
            Giocata *nuovaGiocata = giocaCarta(listaGiocatoriPtr, mazzoCfu, mazzoCfuScarti);
            if (nuovaGiocata == NULL) {
                listaGiocatoriPtr = listaGiocatoriPtr->next;
                continue;
            }

            // Ignora effetti e modificatori
            nuovaGiocata->punteggioTemporaneo = nuovaGiocata->carta->valoreCarta;

            // Aggiorna punteggi massimo e minimo
            punteggioTemp = nuovaGiocata->punteggioTemporaneo;
            if (punteggioTemp < punteggioMinimo) {
                punteggioMinimo = punteggioTemp;
            }
            if (punteggioTemp > punteggioMassimo) {
                punteggioMassimo = punteggioTemp;
            }

            // Aggiungi alla nuova lista di giocate
            nuovaGiocata->next = NULL;
            if (nuovaListaGiocate == NULL) {
                nuovaListaGiocate = nuovaGiocata;
                ultimoNuovaGiocata = nuovaGiocata;
            } else {
                ultimoNuovaGiocata->next = nuovaGiocata;
                ultimoNuovaGiocata = nuovaGiocata;
            }

            listaGiocatoriPtr = listaGiocatoriPtr->next;
        }

        // Conta i giocatori con punteggio minimo e massimo
        int numPerdenti = 0;
        int numVincitori = 0;

        listaGiocatePerdentiPtr = nuovaListaGiocate;
        while (listaGiocatePerdentiPtr != NULL) {
            if (listaGiocatePerdentiPtr->punteggioTemporaneo == punteggioMinimo) {
                numPerdenti++;
                // Aggiungi alla nuova lista di giocatori perdenti
                Giocatore *giocatorePerdente = listaGiocatePerdentiPtr->giocatore;
                if (nuovaListaGiocatoriPerdenti == NULL) {
                    nuovaListaGiocatoriPerdenti = giocatorePerdente;
                    ultimoGiocatorePerdente = giocatorePerdente;
                } else {
                    ultimoGiocatorePerdente->next = giocatorePerdente;
                    ultimoGiocatorePerdente = giocatorePerdente;
                }
            }
            if (listaGiocatePerdentiPtr->punteggioTemporaneo == punteggioMassimo) {
                numVincitori++;
            }
            listaGiocatePerdentiPtr = listaGiocatePerdentiPtr->next;
        }

        // Se c'è un unico perdente
        if (numPerdenti == 1) {
            listaGiocatePerdentiPtr = nuovaListaGiocate;
            while (listaGiocatePerdentiPtr != NULL) {
                if (listaGiocatePerdentiPtr->punteggioTemporaneo == punteggioMinimo) {
                    assegnaCartaOstacoloPerdente(listaGiocatePerdentiPtr->giocatore, &cartaOstacoloEstratta->carta);
                }
                listaGiocatePerdentiPtr = listaGiocatePerdentiPtr->next;
            }
            flag = 1;
        }

        // Libera la memoria delle nuove liste temporanee
        while (nuovaListaGiocate != NULL) {
            Giocata *temp = nuovaListaGiocate;
            nuovaListaGiocate = nuovaListaGiocate->next;
            free(temp);
        }

        *listaGiocatoriPerdenti = nuovaListaGiocatoriPerdenti;
    }
}
*/

/*
void turnoAggiuntivoSpareggio(Giocatore **listaGiocatoriPerdenti, Giocata *listaGiocatePerdenti,
                              CartaCFU **mazzoCfu, CartaCFU **mazzoCfuScarti,
                              CartaOstacoloEstratta *cartaOstacoloEstratta) {

    Giocata *listaGiocatePerdentiPtr = NULL;
    Giocatore *listaGiocatoriPtr = *listaGiocatoriPerdenti;

    while(listaGiocatoriPtr){
        listaGiocatePerdentiPtr = giocaCarta(listaGiocatoriPtr, mazzoCfu, mazzoCfuScarti);
        int punteggioMassimo = listaGiocatePerdentiPtr->punteggioTemporaneo;
        int punteggioMinimo = listaGiocatePerdentiPtr->punteggioTemporaneo;
        int punteggioTemp = 0;

        // Trova il punteggio massimo e minimo temporaneo dalla listaGiocate
        while (listaGiocatePerdentiPtr != NULL)
        {
            punteggioTemp = listaGiocatePerdentiPtr->punteggioTemporaneo;
            if (punteggioTemp < punteggioMinimo) {
                punteggioMinimo = punteggioTemp;
            }
            if (punteggioTemp > punteggioMassimo) {
                punteggioMassimo = punteggioTemp;
            }
            listaGiocatePerdentiPtr = listaGiocatePerdentiPtr->next;
        }

        listaGiocatoriPtr = listaGiocatoriPtr->next;
    }
}*/