#include "rivelazioneCarteTurno.h"
void rivelazioneCarteTurno(Giocata *listaGiocate) {
    Giocata *giocataCorrente = listaGiocate;

    while (giocataCorrente != NULL) {
        Giocatore *giocatore = giocataCorrente->giocatore;
        CartaCFU *carta = giocataCorrente->carta;
        switch (carta->effetto) {
            case SCARTAP:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SCARTAP.\n"
                       "Può scartare una carta CFU punto e aggiungere il suo valore al punteggio del turno\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case RUBA:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto RUBA.\n"
                       "Può guardare le carte di un collega e rubarne una a sua scelta!\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SCAMBIADS:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SCAMBIADS.\n"
                       "Può scambiare questa carta con quella di un altro giocatore, purché senza effetto\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SCARTAE:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SCARTAE.\n"
                       "Può scartare una carta CFU punto con effetto e aggiungere il suo punteggio a quello del turno\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SCARTAC:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SCARTAC.\n"
                       "Scarta da uno a tre carte dalla tua mano.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SCAMBIAP:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SCAMBIAP.\n"
                       "Scambia il punteggio del turno maggiore e minore dopo il calcolo del punteggio di base.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case DOPPIOE:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto DOPPIOE.\n"
                       "Raddoppia gli effetti delle carte che aumentano o diminuiscono il punteggio (per tutti).\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SBIRCIA:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SBIRCIA.\n"
                       "Guarda due carte in cima al mazzo, prendine una e scarta l’altra.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SCAMBIAC:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SCAMBIAC.\n"
                       "Scambia la carta punto giocata nel turno da un giocatore G1 con quella di un giocatore G2, con G1 e G2 \n"
                       "scelti dal giocatore che ha giocato la carta SCAMBIAC.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case ANNULLA:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto ANNULLA.\n"
                       "Annulla gli effetti di tutte le carte punto durante il turno.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case AUMENTA:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto AUMENTA.\n"
                       "Aumenta di 2 CFU il punteggio del turno di un giocatore a scelta.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case DIMINUISCI:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto DIMINUISCI.\n"
                       "Diminuisci di 2 CFU il punteggio del turno di un giocatore a scelta.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case INVERTI:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto INVERTI.\n"
                       "Inverti punteggio minimo e massimo del turno.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case SALVA:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto SALVA.\n"
                       "Metti la carta Ostacolo che stai per prendere in fondo al mazzo.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case DIROTTA:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d ed effetto DIROTTA.\n"
                       "Dai la carta che stai per prendere ad un altro giocatore a tua scelta.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
            case NESSUNO:
                printf("\n\nGiocatore %s ha giocato la carta CFU %s con valore %d e NESSUN effetto.\n\n",
                       giocatore->nomeUtente, carta->nomeCarta, carta->valoreCarta);
                break;
        }
        giocataCorrente = giocataCorrente->next;
    }
}