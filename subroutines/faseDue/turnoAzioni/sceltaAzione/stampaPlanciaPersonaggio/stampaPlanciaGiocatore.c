#include "stampaPlanciaGiocatore.h"
#define MAX_SPAZIO_PLANCIA 45
#define SPAZIO_PLANCIA_DI 11 //Numero di caratteri che prende la frase "PLANCIA DI " prima del nome del giocatore (fatto estetico)
void stampaPlanciaGiocatore(Giocatore *giocatoreCorrente) {
    // Calcola la lunghezza del nome del giocatore
    int lunghezzaNome = strlen(giocatoreCorrente->nomeUtente);
    // Calcola quanti spazi sono necessari per allineare il quadrato
    int spaziNecessariNome = MAX_SPAZIO_PLANCIA - lunghezzaNome - SPAZIO_PLANCIA_DI;
    //Calcola la lunghezza del nome del personaggio
    int lunghezzaPersonaggio = strlen(giocatoreCorrente->personaggio.nomePersonaggio);
    // Calcola quanti spazi sono necessari per allineare il quadrato
    int spaziNecessariPersonaggio = MAX_SPAZIO_PLANCIA - lunghezzaPersonaggio;
    // Calcola la lunghezza del numero dei punti CFU
    int lunghezzaCFU = calcolaLunghezzaNumero(giocatoreCorrente->cfu);
    // Calcola quanti spazi sono necessari per allineare il valore dei punti CFU
    int spaziNecessariCFU = MAX_SPAZIO_PLANCIA - lunghezzaCFU - 3; // "- 3" per " /60"

    // Calcola la lunghezza dei numeri per i punti dei vari tipi di ostacoli
    int lunghezzaStudio = calcolaLunghezzaNumero(giocatoreCorrente->personaggio.tipoOstacoli[STUDIO]);
    int spaziNecessariStudio = MAX_SPAZIO_PLANCIA - 23 - lunghezzaStudio; // "- 23" per "Ostacolo STUDIO: " e " PUNTI"

    int lunghezzaSopravvivenza = calcolaLunghezzaNumero(giocatoreCorrente->personaggio.tipoOstacoli[SOPRAVVIVENZA]);
    int spaziNecessariSopravvivenza = MAX_SPAZIO_PLANCIA - 30 - lunghezzaSopravvivenza; // "- 30" per "Ostacolo SOPRAVVIVENZA: " e " PUNTI"

    int lunghezzaSociale = calcolaLunghezzaNumero(giocatoreCorrente->personaggio.tipoOstacoli[SOCIALE]);
    int spaziNecessariSociale = MAX_SPAZIO_PLANCIA - 24 - lunghezzaSociale; // "- 24" per "Ostacolo SOCIALE: " e " PUNTI"

    int lunghezzaEsame = calcolaLunghezzaNumero(giocatoreCorrente->personaggio.tipoOstacoli[ESAME]);
    int spaziNecessariEsame = MAX_SPAZIO_PLANCIA - 22 - lunghezzaEsame; // "- 22" per "Ostacolo ESAME: " e " PUNTI"



    printf("+---------------------------------------------+\n"
           "|PLANCIA DI %s%*s|\n"
           "|                                             |\n"
           "|PUNTI CFU                                    |\n"
           "|%d/60%*s|\n"
           "|                                             |\n"
           "|PERSONAGGIO                                  |\n"
           "|%s%*s|\n"
           "|                                             |\n"
           "|Durante la partita, quando viene estratta    |\n"
           "|una carta ostacolo il tuo personaggio        |\n"
           "|ricevera' un bonus o un malus di punti       |\n"
           "|in base alla tipologia di ostacolo estratta  |\n"
           "|                                             |\n"
           "|Bonus e Malus del personaggio:               |\n"
           "|Ostacolo STUDIO: %d PUNTI%*s|\n"
           "|Ostacolo SOPRAVVIVENZA: %d PUNTI%*s|\n"
           "|Ostacolo SOCIALE: %d PUNTI%*s|\n"
           "|Ostacolo ESAME: %d PUNTI%*s|\n"
           "+---------------------------------------------+\n",
           giocatoreCorrente->nomeUtente,spaziNecessariNome, "",
           giocatoreCorrente->cfu, spaziNecessariCFU, "",
           giocatoreCorrente->personaggio.nomePersonaggio,spaziNecessariPersonaggio, "",
           giocatoreCorrente->personaggio.tipoOstacoli[STUDIO], spaziNecessariStudio, "",
           giocatoreCorrente->personaggio.tipoOstacoli[SOPRAVVIVENZA], spaziNecessariSopravvivenza, "",
           giocatoreCorrente->personaggio.tipoOstacoli[SOCIALE], spaziNecessariSociale, "",
           giocatoreCorrente->personaggio.tipoOstacoli[ESAME], spaziNecessariEsame, "");
}

int calcolaLunghezzaNumero(int numero) {
    int lunghezza = 0;
    if (numero == 0) {
        return 1;
    }
    if (numero < 0) {
        lunghezza++; // per il segno negativo
        numero = -numero;
    }
    while (numero != 0) {
        lunghezza++;
        numero /= 10;
    }
    return lunghezza;
}