#ifndef HAPPY_LITTLE_STUDENTS_V0_3_GESTIONELOG_H
#define HAPPY_LITTLE_STUDENTS_V0_3_GESTIONELOG_H
#include "../../../subroutines/misclibs/misclibs.h"
#include "../../../subroutines/misclibs/gestioneLog/logOrario/logOrario.h"


/**
 * @brief Gestisce l'aggiornamento del log delle giocate di ogni turno.
 *
 * Scrive nel file di log "log.txt" le informazioni relative alle giocate effettuate durante il turno specificato.
 *
 * esempio:
 *  TURNO 1: Riccardo gioca un Clion
 *  TURNO 1: Andrea gioca Tastiera
 *  TURNO 1: Federico gioca Mouse
 *  TURNO 2: Luca gioca Lab T
 *
 * @param turno Numero del turno corrente della partita.
 * @param listaGiocate Puntatore alla lista delle giocate effettuate durante il turno.
 *                     Ogni elemento della lista contiene le informazioni su quale giocatore ha giocato quale carta.
 */
void gestioneLog(int turno, Giocata *listaGiocate);


#endif //HAPPY_LITTLE_STUDENTS_V0_3_GESTIONELOG_H
