#include "caricaMazzoOstacoli.h"
int caricaMazzoOstacoli(CartaOstacolo **head) {
    CartaOstacolo *mazzopointer = *head; //Variabile che punta all'ultima carta del mazzo
    CartaOstacolo *node; //Il nuovo nodo
    FILE *fp; //Puntatore per lavorare con il file
    char nome[MAX_CHAR]; //var temp per salvare il nome della carta con la fscanf
    char descrizione[MAX_DESC_OSTACOLI];
    tipoOstacolo tipo=0;
    int flag = -1; //variabile simil bool per indicare che la lista sia stata creata correttamente. se -1 no se !=-1 si
    int occorrenza = 0; //variabile che ci indica quante carte ci sono di quel tipo usata nel primo for
    //Apriamo il file carte.txt in lettura
    fp = fopen("../carte_ostacoli_personaggi/ostacoli.txt", "r");
    //controllo se il file esiste
    if (fp == NULL)
    {
        exit(-1);
    }
    //Utilizzo un do while per creare la nostra lista
    do {
        //assegno ad esci il risultato della fscanf. quando avrà letto tutto uscirà dal ciclo
        fscanf(fp, "%d", &occorrenza)==EOF;
        //ciclo for per creare i nodi delle carte in base a quante occorrenze ha quella carta
        for (int i = 0; i < occorrenza; i++) {
            //Leggo i dati con due fscanf
            fscanf(fp, " %[^\n]s", nome);
            fscanf(fp, " %[^\n]s", descrizione);
            node = (CartaOstacolo *) malloc(sizeof(CartaOstacolo)); //Alloco memoria per i nodi della lista
            //Copio i valori presi con la fscanf nel nuovo nodo allocato

            strcpy(node->nomeCarta, nome);
            strcpy(node->descrizione, descrizione);
            node->tipoOstacolo = tipo;

            //Il nodo punta a NULL perchè è l'ultima carta della lista
            node->next = NULL;
            //Se il nostro mazzo è vuoto punto alla prima carta
            if (mazzopointer == NULL) {
                *head = node;
                mazzopointer = node;
                //Altrimenti il nostro mazzo punterà al nuovo nodo
            } else {
                mazzopointer->next = node;
                mazzopointer = node;
            }
        }
        tipo++;
    }while(tipo<ESAME+1);

    /*TODO: IL CICLO NON LEGGE L'ULTIMA CARTA. COME SOLUZIONE HO COPIATO IL CONTENUTO DEL FOR FUORI DAL CICLO
     * PER UN'ALTRA ITERAZIONE BALORDA*/
    //Leggo i dati con due fscanf
    fscanf(fp, " %[^\n]s", nome);
    fscanf(fp, " %[^\n]s", descrizione);
    node = (CartaOstacolo *) malloc(sizeof(CartaOstacolo)); //Alloco memoria per i nodi della lista
    //Copio i valori presi con la fscanf nel nuovo nodo allocato

    strcpy(node->nomeCarta, nome);
    strcpy(node->descrizione, descrizione);
    node->tipoOstacolo = tipo;

    //Il nodo punta a NULL perchè è l'ultima carta della lista
    node->next = NULL;
    //Se il nostro mazzo è vuoto punto alla prima carta
    if (mazzopointer == NULL) {
        *head = node;
        mazzopointer = node;
        //Altrimenti il nostro mazzo punterà al nuovo nodo
    } else {
        mazzopointer->next = node;
        mazzopointer = node;
    }
    fclose(fp);
    return flag;
}