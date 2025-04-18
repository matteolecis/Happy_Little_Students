#ifndef HAPPY_LITTLE_STUDENTS_CARTAOSTACOLO_H
#define HAPPY_LITTLE_STUDENTS_CARTAOSTACOLO_H
#define MAXCHAR 32
#define MAXDESC 128
//ENUMERAZIONE PER IL TIPO DI OSTACOLO
typedef enum tipoOstacolo{STUDIO, SOPRAVVIVENZA, SOCIALE, ESAME} tipoOstacolo;

//Definizione struttura carta ostacolo
typedef struct CartaOstacolo {
    char nomeCarta[MAXCHAR]; //nome della carta MAX 32 CARATTERI
    char descrizione[MAXDESC]; //descrizione della carta MAX 128 CARATTERI
    tipoOstacolo tipoOstacolo; //enumerazione al tipo di ostacolo
    struct CartaOstacolo *next; // Puntatore alla prossima carta
} CartaOstacolo;

#endif //HAPPY_LITTLE_STUDENTS_CARTAOSTACOLO_H
