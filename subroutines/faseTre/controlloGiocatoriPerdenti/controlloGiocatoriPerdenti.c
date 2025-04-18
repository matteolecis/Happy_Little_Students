#include "controlloGiocatoriPerdenti.h"
void rimettiCarteOstacoloInFondo(CartaOstacolo **mazzoOstacoli, CartaOstacolo *carteDaRimettere) {
    while (carteDaRimettere != NULL) {
        CartaOstacolo *carta = carteDaRimettere;
        carteDaRimettere = carteDaRimettere->next;
        carta->next = NULL;
        if (*mazzoOstacoli == NULL) {
            *mazzoOstacoli = carta;
        } else {
            CartaOstacolo *temp = *mazzoOstacoli;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = carta;
        }
    }
}

void deallocaGiocatore(Giocatore **listaGiocatori, Giocatore *giocatoreDaDeallocare, CartaCFU **mazzoCfuScarti, CartaOstacolo **mazzoOstacoli) {
    if (giocatoreDaDeallocare == NULL) {
        perror("ERRORE Giocatore non trovato");
        return;
    }
    // Rimuove il giocatore dalla lista
    Giocatore *temp = *listaGiocatori;
    Giocatore *prev = NULL;
    while (temp != NULL && temp != giocatoreDaDeallocare) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        perror("ERRORE Giocatore non trovato");
        return;
    }
    if (prev == NULL) {
        *listaGiocatori = temp->next;
    } else {
        prev->next = temp->next;
    }

    // Scarta le carte CFU del giocatore
    scartaCarte(mazzoCfuScarti, giocatoreDaDeallocare->carte_cfu);

    // Rimette le carte ostacolo in fondo al mazzo
    rimettiCarteOstacoloInFondo(mazzoOstacoli, giocatoreDaDeallocare->cartaOstacolo);

    // Dealloca il giocatore
    free(giocatoreDaDeallocare);
}


void controlloGiocatoriPerdenti(Giocatore **listaGiocatori, CartaCFU **mazzoCfuScarti, CartaOstacolo **mazzoOstacoli) {
    Giocatore *giocatore = *listaGiocatori;
    while (giocatore != NULL) {
        int contoStudio = 0;
        int contoSopravvivenza = 0;
        int contoSociale = 0;
        int contoEsami = 0;
        CartaOstacolo *carta = giocatore->cartaOstacolo;

        // Conta il numero di ostacoli di ogni tipo e i jolly (esami)
        while (carta != NULL) {
            if (carta->tipoOstacolo == ESAME) {
                contoEsami++;
            } else if (carta->tipoOstacolo == STUDIO) {
                contoStudio++;
            } else if (carta->tipoOstacolo == SOPRAVVIVENZA) {
                contoSopravvivenza++;
            } else if (carta->tipoOstacolo == SOCIALE) {
                contoSociale++;
            }
            carta = carta->next;
        }

        Giocatore *nextGiocatore = giocatore->next;
        int eliminato = 0;

        // Controlla la condizione di morte: 1 carta di ogni tipo
        if ((contoStudio == 1 && contoSopravvivenza == 1 && contoSociale == 1) ||
            (contoStudio == 1 && contoSopravvivenza == 1 && contoEsami == 1) ||
            (contoSopravvivenza == 1 && contoSociale == 1 && contoEsami == 1) ||
            (contoStudio == 1 && contoSociale == 1 && contoEsami == 1)) {
            printf("Il giocatore %s è eliminato dato che ha una carta ostacolo di ogni tipo.\n", giocatore->nomeUtente);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        // Controlla la condizione di morte: 3 carte dello stesso tipo
        if (!eliminato && contoStudio == MAX_CARTE_OSTACOLO_PRENDIBILI) {
            printf("Il giocatore %s è eliminato dato che ha 3 carte ostacolo STUDIO!.\n", giocatore->nomeUtente);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        if (!eliminato && contoSopravvivenza == MAX_CARTE_OSTACOLO_PRENDIBILI) {
            printf("Il giocatore %s è eliminato dato che ha 3 carte ostacolo SOPRAVVIVENZA!.\n", giocatore->nomeUtente);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        if (!eliminato && contoSociale == MAX_CARTE_OSTACOLO_PRENDIBILI) {
            printf("Il giocatore %s è eliminato dato che ha 3 carte ostacolo SOCIALE!.\n", giocatore->nomeUtente);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        // Controlla la condizione di morte: 3 carte dello stesso tipo + eventuali jolly
        if (!eliminato && contoStudio + contoEsami == MAX_CARTE_OSTACOLO_PRENDIBILI) {
            printf("Il giocatore %s è eliminato dato che ha %d carte ostacolo STUDIO e %d carte ostacolo ESAME!.\n",
                   giocatore->nomeUtente, contoStudio, contoEsami);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        if (!eliminato && contoSopravvivenza + contoEsami == MAX_CARTE_OSTACOLO_PRENDIBILI) {
            printf("Il giocatore %s è eliminato dato che ha %d carte ostacolo SOPRAVVIVENZA e %d carte ostacolo ESAME!.\n",
                   giocatore->nomeUtente, contoSopravvivenza, contoEsami);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        if (!eliminato && contoSociale + contoEsami == MAX_CARTE_OSTACOLO_PRENDIBILI) {
            printf("Il giocatore %s è eliminato dato che ha %d carte ostacolo SOCIALE e %d carte ostacolo ESAME!.\n",
                   giocatore->nomeUtente, contoSociale, contoEsami);
            deallocaGiocatore(listaGiocatori, giocatore, mazzoCfuScarti, mazzoOstacoli);
            eliminato = 1;
            giocatore = nextGiocatore;
        }

        // Passa al prossimo giocatore se non è stato eliminato, altrimenti il puntatore è già aggiornato
        if (!eliminato) {
            giocatore = nextGiocatore;
        }
    }
}