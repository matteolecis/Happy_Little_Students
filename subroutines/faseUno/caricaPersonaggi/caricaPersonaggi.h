#ifndef HAPPY_LITTLE_STUDENTS_V0_2_CARICAPERSONAGGI_H
#define HAPPY_LITTLE_STUDENTS_V0_2_CARICAPERSONAGGI_H
#include "../../../subroutines/misclibs/misclibs.h"

/**
 * Carica l'elenco dei personaggi da un file.
 *
 * Questa funzione legge il file "personaggi.txt" per caricare i personaggi disponibili in un array.
 * Ogni elemento dell'array contiene le informazioni di un personaggio.
 *
 * @param listaPersonaggi Array di personaggi da riempire con i dati letti dal file.
 */
void caricaPersonaggi(Personaggio listaPersonaggi[4]);
#endif //HAPPY_LITTLE_STUDENTS_V0_2_CARICAPERSONAGGI_H
