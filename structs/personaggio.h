#ifndef HAPPY_LITTLE_STUDENTS_PERSONAGGIO_H
#define HAPPY_LITTLE_STUDENTS_PERSONAGGIO_H
#define TIPO_OSTACOLI 4 //PARI AL NUMERO DI OSTACOLI NELL'ENUMERAZIONE PRESENTE IN cartaOstacolo.h
#define MAXCHAR 32
//Definizione struttura per il personaggio
struct personaggio{
    char nomePersonaggio[MAXCHAR];
    int tipoOstacoli[TIPO_OSTACOLI];
};
typedef struct personaggio Personaggio;
#endif //HAPPY_LITTLE_STUDENTS_PERSONAGGIO_H
