#include "shuffleMazzoOstacoli.h"
CartaOstacolo* smezzaCarteOstacolo(CartaOstacolo * mazzoOstacoli, int numCartePrimoMazzoOstacoli)
{
    if(numCartePrimoMazzoOstacoli<1)
    {
        perror("Fornire un numero maggiore di 1\n");
        return NULL;
    }
    if(numCartePrimoMazzoOstacoli==1)
    {
        CartaOstacolo* mazzoOstacoliRes = (CartaOstacolo * )malloc(sizeof(CartaOstacolo));
        mazzoOstacoliRes = mazzoOstacoli->next;
        mazzoOstacoli->next = NULL;
        return mazzoOstacoliRes;
    }
    else
        smezzaCarteOstacolo(mazzoOstacoli->next, numCartePrimoMazzoOstacoli-1);
}

CartaOstacolo pescaCartaOstacolo(CartaOstacolo ** mazzoOstacolo)
{
    CartaOstacolo cartaOstacolo;
    if(mazzoOstacolo == NULL)
    {
        cartaOstacolo.tipoOstacolo-1;
        printf("MAZZO VUOTO\n");
        return cartaOstacolo;
    }
    cartaOstacolo = **mazzoOstacolo;
    (*mazzoOstacolo) = (*mazzoOstacolo)->next;
    return cartaOstacolo;
}

void aggiungiCartaOstacoloInfondo(CartaOstacolo** mazzoOstacolo, CartaOstacolo carta)
{
    if(*mazzoOstacolo == NULL)
    {
        *mazzoOstacolo = (CartaOstacolo * )malloc(sizeof(CartaOstacolo));
        strcpy((char *) (*mazzoOstacolo)->nomeCarta, carta.nomeCarta);
        strcpy((char *) (*mazzoOstacolo)->descrizione, carta.descrizione);
        (*mazzoOstacolo)->tipoOstacolo = carta.tipoOstacolo;
        (*mazzoOstacolo)->next = NULL;
    }
    else if((*mazzoOstacolo)->next == NULL)
    {
        CartaOstacolo* mazzoNew = (CartaOstacolo * )malloc(sizeof(CartaOstacolo));
        strcpy(mazzoNew->nomeCarta, carta.nomeCarta);
        strcpy(mazzoNew->descrizione, carta.descrizione);
        mazzoNew->tipoOstacolo = carta.tipoOstacolo;
        mazzoNew->next = NULL;
        (*mazzoOstacolo)->next = mazzoNew;
    }
    else
        aggiungiCartaOstacoloInfondo(&(*mazzoOstacolo)->next, carta);
}

void riffleShuffleOstacolo(CartaOstacolo** mazzoOstacolo)
{
    CartaOstacolo* mazzo2 = (CartaOstacolo *) malloc(sizeof(CartaOstacolo));
    CartaOstacolo* mazzoOstacoloRes = (CartaOstacolo *) malloc(sizeof(CartaOstacolo));
    mazzoOstacoloRes = NULL;
    CartaOstacolo carta;
    mazzo2 = smezzaCarteOstacolo(*mazzoOstacolo, NUM_CARTE_OSTACOLO/2);
    while (*mazzoOstacolo != NULL)
    {
        carta=pescaCartaOstacolo(mazzoOstacolo);
        aggiungiCartaOstacoloInfondo(&mazzoOstacoloRes, carta);
        carta=pescaCartaOstacolo(&mazzo2);
        aggiungiCartaOstacoloInfondo(&mazzoOstacoloRes, carta);
    }
    *mazzoOstacolo=mazzoOstacoloRes;
}

void unisciMazziOstacolo(CartaOstacolo * mazzoOstacolo, CartaOstacolo * mazzo_aggiunto)
{
    if(mazzoOstacolo->next == NULL)
        mazzoOstacolo->next = mazzo_aggiunto;
    else
        unisciMazziOstacolo(mazzoOstacolo->next,mazzo_aggiunto);
}

void shuffleMazzoOstacoli(CartaOstacolo ** mazzoOstacolo, int loops)
{
    int i;
    CartaOstacolo * mazzo_tmp = (CartaOstacolo * )malloc(sizeof(CartaOstacolo));
    mazzo_tmp = NULL;
    for (i = 0; i < loops; ++i)
    {
        riffleShuffleOstacolo(mazzoOstacolo);
        mazzo_tmp = smezzaCarteOstacolo(*mazzoOstacolo, randNumInRange(1,NUM_CARTE_OSTACOLO-1));
        unisciMazziOstacolo(mazzo_tmp,*mazzoOstacolo);
        riffleShuffleOstacolo(&mazzo_tmp);
        *mazzoOstacolo = smezzaCarteOstacolo(mazzo_tmp, randNumInRange(1,NUM_CARTE_OSTACOLO-1));
        unisciMazziOstacolo(*mazzoOstacolo,mazzo_tmp);
    }
}
