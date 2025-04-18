#include "shuffleMazzoCfu.h"

CartaCFU* smezzaCarteCFU(CartaCFU* mazzoCfu, int numCartePrimoMazzoCfu) {
    if (numCartePrimoMazzoCfu < 1) {
        perror("Fornire un numero maggiore di 1\n");
        return NULL;
    }

    if (numCartePrimoMazzoCfu == 1) {
        CartaCFU* mazzoCfuRes = mazzoCfu->next;
        mazzoCfu->next = NULL;
        return mazzoCfuRes;
    } else {
        return smezzaCarteCFU(mazzoCfu->next, numCartePrimoMazzoCfu - 1);
    }
}

CartaCFU pescaCartaCfu(CartaCFU** mazzoCfu)
{
    CartaCFU cartaCfu;
    if(mazzoCfu == NULL)
    {
        cartaCfu.effetto=-1;
        cartaCfu.valoreCarta=-1;
        printf("MAZZO VUOTO\n");
        return cartaCfu;
    }
    cartaCfu = **mazzoCfu;
    (*mazzoCfu) = (*mazzoCfu)->next;
    return cartaCfu;
}

void aggiungiCartaCfuInfondo(CartaCFU** mazzoCfu, CartaCFU carta)
{
    if(*mazzoCfu == NULL)
    {
        *mazzoCfu = (CartaCFU * )malloc(sizeof(CartaCFU));
        strcpy((char *) *mazzoCfu, carta.nomeCarta);
        (*mazzoCfu)->effetto = carta.effetto;
        (*mazzoCfu)->valoreCarta = carta.valoreCarta;
        (*mazzoCfu)->next = NULL;
    }
    else if((*mazzoCfu)->next == NULL)
    {
        CartaCFU* mazzoNew = (CartaCFU * )malloc(sizeof(CartaCFU));
        strcpy(mazzoNew->nomeCarta, carta.nomeCarta);
        mazzoNew->effetto = carta.effetto;
        mazzoNew->valoreCarta = carta.valoreCarta;
        mazzoNew->next = NULL;
        (*mazzoCfu)->next = mazzoNew;
    }
    else
        aggiungiCartaCfuInfondo(&(*mazzoCfu)->next, carta);
}
void riffleShuffleCfu(CartaCFU** mazzoCfu) {
    CartaCFU* mazzo2 = smezzaCarteCFU(*mazzoCfu, NUM_CARTE_CFU / 2);
    CartaCFU* mazzoCfuRes = NULL;
    CartaCFU carta;

    while (*mazzoCfu != NULL || mazzo2 != NULL) {
        if (*mazzoCfu != NULL) {
            carta = pescaCartaCfu(mazzoCfu);
            if (carta.effetto != -1) {
                aggiungiCartaCfuInfondo(&mazzoCfuRes, carta);
            }
        }
        if (mazzo2 != NULL) {
            carta = pescaCartaCfu(&mazzo2);
            if (carta.effetto != -1) {
                aggiungiCartaCfuInfondo(&mazzoCfuRes, carta);
            }
        }
    }
    *mazzoCfu = mazzoCfuRes;
}

void unisciMazziCFU(CartaCFU * mazzo, CartaCFU * mazzo_aggiunto)
{
    if(mazzo->next == NULL)
        mazzo->next = mazzo_aggiunto;
    else
        unisciMazziCFU(mazzo->next,mazzo_aggiunto);
}

void shuffleMazzoCfu(CartaCFU ** mazzo, int loops)
{
    int i;
    CartaCFU* mazzo_tmp = (CartaCFU * )malloc(sizeof(CartaCFU));
    mazzo_tmp = NULL;
    for (i = 0; i < loops; ++i)
    {
        riffleShuffleCfu(mazzo);
        mazzo_tmp = smezzaCarteCFU(*mazzo, randNumInRange(1,NUM_CARTE_CFU-1));
        unisciMazziCFU(mazzo_tmp,*mazzo);
        riffleShuffleCfu(&mazzo_tmp);
        *mazzo = smezzaCarteCFU(mazzo_tmp, randNumInRange(1,NUM_CARTE_CFU-1));
        unisciMazziCFU(*mazzo,mazzo_tmp);
    }
}
