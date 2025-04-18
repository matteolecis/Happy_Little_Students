#include "inizializzaGiocatori.h"
Giocatore inizializzaGiocatori(Giocatore **head, CartaCFU **mazzoCfu) {
    // Dichiarazione Variabili
    Giocatore *listaGiocatoriPointer = *head; // Variabile che punta all'ultima carta del mazzo
    Giocatore *node; // Il nuovo nodo
    Personaggio arrayPersonaggi[MAX_NUM_GIOCATORI]; // Array utilizzato per caricare i personaggi dalla subroutine dedicata
    int is_generated[MAX_NUM_GIOCATORI] = {}; // Array di simil bool per controllare se il personaggio è già stato generato
    int nGiocatori; // Numero di giocatori inserito dall'utente
    int personaggioCasuale = 0; // Variabile che avrà il personaggio numero del personaggio casuale assegnato
    int cheGiocatore = 1;

    caricaPersonaggi(arrayPersonaggi);
    nGiocatori = prendiNumeroGiocatori();
    for (int i = 0; i < nGiocatori; i++) {
        // I giocatori inseriscono i loro nomi
        int nomeValido;
        char nomeUtenteTemp[MAX_CHAR];
        do {
            nomeValido = 1; // Assumiamo che il nome sia valido
            printf("\nInserisci il nome del giocatore numero %d\n", cheGiocatore);
            scanf(" %[^\n]s", nomeUtenteTemp);

            if (strlen(nomeUtenteTemp) > MAX_CHAR) {
                printf("NOME TROPPO LUNGO!\n");
                nomeValido = 0; // Il nome non è valido
            }

            // Controllo se il nome è già stato utilizzato
            Giocatore *temp = *head;
            while (temp != NULL) {
                if (strcmp(temp->nomeUtente, nomeUtenteTemp) == 0) {
                    printf("Nome già utilizzato! Inserisci un altro nome.\n");
                    nomeValido = 0; // Il nome non è valido
                }
                temp = temp->next;
            }

        } while (!nomeValido);

        // Alloco memoria per il nuovo nodo solo dopo aver trovato un nome valido
        node = (Giocatore *)malloc(sizeof(Giocatore)); // Alloco memoria per i nodi della lista
        if (node == NULL) {
            printf("Errore di allocazione memoria per il giocatore.\n");
            exit(EXIT_FAILURE);
        }

        // Copia il nome valido nel nodo del giocatore
        strcpy(node->nomeUtente, nomeUtenteTemp);
        cheGiocatore++;

        /*
         * GENERAZIONE NUMERO CASUALE PER ASSEGNARE PERSONAGGIO CASUALE
         * SALVO IL NUMERO CASUALE GENERATO IN UN ARRAY SIMIL BOOL PER
         * EVITARE DI ASSEGNARE LO STESSO PERSONAGGIO A PIù DI UN GIOCATORE
         */
        do {
            personaggioCasuale = rand() % MAX_NUM_GIOCATORI;
        } while (is_generated[personaggioCasuale]);
        is_generated[personaggioCasuale] = 1;

        // Assegno personaggio casuale
        node->personaggio = arrayPersonaggi[personaggioCasuale];

        // Azzero i punti cfu
        node->cfu = 0;

        // Distribuisco 5 carte CFU
        node->carte_cfu = NULL; // Inizializzo la lista delle carte CFU
        for (int j = 0; j < 5; j++) {
            if (*mazzoCfu == NULL) {
                printf("Il mazzo di carte CFU è vuoto.\n");
                exit(-1);
            }

            // Prendo la carta CFU superiore dal mazzo
            CartaCFU *cartaCFU = malloc(sizeof(CartaCFU));
            if (cartaCFU == NULL) {
                printf("Errore di allocazione memoria per la carta CFU.\n");
                exit(EXIT_FAILURE);
            }
            *cartaCFU = pescaCartaCfu(mazzoCfu);

            // Aggiungo la carta CFU al giocatore corrente
            cartaCFU->next = node->carte_cfu;
            node->carte_cfu = cartaCFU;
        }

        // Il nodo punta a NULL perchè è l'ultimo giocatore della lista
        node->next = NULL;

        // Se la nostra lista di giocatori è vuota punto al primo elemento
        if (listaGiocatoriPointer == NULL) {
            *head = node;
            listaGiocatoriPointer = node;
        } else {
            // Altrimenti la nostra lista punterà al nuovo nodo
            listaGiocatoriPointer->next = node;
            listaGiocatoriPointer = node;
        }
    }

    return *listaGiocatoriPointer;
}
