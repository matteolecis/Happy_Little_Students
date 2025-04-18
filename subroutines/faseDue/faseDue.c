
#include "faseDue.h"

void faseDue(Personaggio listaPersonaggi[MAX_NUM_GIOCATORI],
             CartaCFU **mazzoCfu,
             CartaCFU **mazzoCfuScarti,
             CartaOstacolo **mazzoOstacoli,
             Giocatore **listaGiocatori,
             char nomeSave[MAX_NOME_SAVE]) {
    int counterTurno=1;
    CartaOstacoloEstratta cartaOstacoloEstratta;
    Giocata *listaGiocate = NULL;
    logOrario();
    do{
        int numCarteMazzoCFU = contaCarteMazzoCfu(*mazzoCfu);
        int numCarteMazzoCfuScarti = contaCarteMazzoCfu(*mazzoCfuScarti);
        int numCarteOstacolo = contaCarteOstacolo(*mazzoOstacoli);
        salvaPartitaAutomatico(nomeSave, *listaGiocatori, *mazzoCfu, numCarteMazzoCFU, *mazzoCfuScarti,
                               numCarteMazzoCfuScarti,*mazzoOstacoli, numCarteOstacolo);
        gestioneLog(counterTurno, listaGiocate);
        //salvare ad ogni turno la partita
        inizioTurno(listaPersonaggi, mazzoCfu, mazzoCfuScarti, mazzoOstacoli, listaGiocatori, &cartaOstacoloEstratta);
        printf("================================================== GIOCATORI - Num: %d ================================================\n",
               contaGiocatori(*listaGiocatori));
        printNumeroTurno(counterTurno);
        listaGiocate = turnoAzioni(listaPersonaggi, mazzoCfu, mazzoCfuScarti, mazzoOstacoli, listaGiocatori,
                                   &cartaOstacoloEstratta);
        faseTre(listaPersonaggi, mazzoCfu, mazzoCfuScarti, mazzoOstacoli, listaGiocatori, &listaGiocate, &cartaOstacoloEstratta);
        counterTurno++;
    }while(counterTurno<MAX_NUM_TURNI);
}