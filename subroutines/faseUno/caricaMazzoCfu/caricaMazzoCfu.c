#include "caricaMazzoCfu.h"
int caricaMazzoCFU(CartaCFU **head) {
    CartaCFU *mazzopointer = *head; //Variabile che punta all'ultima carta del mazzo
    CartaCFU *node; //Il nuovo nodo
    FILE *fp; //Puntatore per lavorare con il file
    effettoCarta effetto; //var temp per salvare l'effetto con la fscanf
    int valoreCarta; //var temp per salvare il valore della carta con la fscanf
    char nome[MAX_CHAR]; //var temp per salvare il nome della carta con la fscanf
    int flag = -1; //variabile simil bool per indicare che la lista sia stata creata correttamente. se -1 no se !=-1 si
    int esci; //variabile simil bool per terminare il nostro ciclo do mentre creiamo la lista
    int occorrenza = 0; //variabile che ci indica quante carte ci sono di quel tipo usata nel primo for
    //Apriamo il file carte.txt in lettura
    fp = fopen("../carte_ostacoli_personaggi/carte.txt", "r");
    //controllo se il file esiste
    if (fp == NULL)
    {
        exit(-1);
    }
    //Utilizzo un do while per creare la nostra lista
    do {
        //assegno ad esci il risultato della fscanf. quando avrà letto tutto uscirà dal ciclo
        esci=fscanf(fp, "%d %d %d %[^\n]s", &occorrenza, &effetto, &valoreCarta, nome)==EOF;
        //ciclo for per creare i nodi delle carte in base a quante occorrenze ha quella carta
        for (int i = 0; i < occorrenza; i++) {
            node = (CartaCFU *) malloc(sizeof(CartaCFU)); //Alloco memoria per i nodi della lista
            //Copio i valori presi con la fscanf nel nuovo nodo allocato
            strcpy(node->nomeCarta, nome);
            node->effetto = effetto;
            node->valoreCarta = valoreCarta;
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
    }while(!esci);
    fclose(fp);
    return flag;
}