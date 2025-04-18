//
// Created by 66452 on 05/03/2024.
//

#ifndef HAPPY_LITTLE_STUDENTS_CARTACFU_H
#define HAPPY_LITTLE_STUDENTS_CARTACFU_H
#define MAX_CHAR 32

//ENUMERAZIONE PER GLI EFFETTI DELLE CARTE
typedef enum effettoCarta{NESSUNO,SCARTAP,RUBA,SCAMBIADS,SCARTAE,SCARTAC,SCAMBIAP,DOPPIOE,SBIRCIA,SCAMBIAC,
    ANNULLA,AUMENTA,DIMINUISCI,INVERTI,SALVA,DIROTTA} effettoCarta;

//Definizione struttura CarteCFU
typedef struct CartaCFU {
    char nomeCarta[MAX_CHAR];
    int valoreCarta;
    effettoCarta effetto;
    struct CartaCFU *next; // Puntatore alla prossima carta
} CartaCFU;

#endif //HAPPY_LITTLE_STUDENTS_CARTACFU_H
