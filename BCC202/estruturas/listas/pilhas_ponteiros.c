#include "lista.h"


typedef struct cel {
    Item item;
    struct cel *prox;
} Celula;


struct pilha {
    Celula *topo;
};


Pilha* pilhaCria(){
    Pilha *pPilha = malloc(sizeof(Pilha));
    if(pPilha){
        pPilha->topo = malloc(sizeof(Celula));
        if(!pPilha->topo){
            free(pPilha);
            pPilha = NULL;
        }
        pPilha->topo->prox = NULL;
    }
    return pPilha;
}
Pilha* pilhaDestroi(Pilha *pPilha){
    if(!pPilha)
        return NULL;
    EsvaziaPilha(pPilha);
    free(pPilha->topo);
    free(pPilha);
}
bool pilhaPush(Pilha *pPilha, Item n){
    if(!pPilha)
        return false;
    Celula *nova = malloc(sizeof(Celula));
    if(nova){
        nova->item = n;
        nova->prox = pPilha->topo->prox;
        pPilha->topo->prox = nova;
        return true;
    }
    return false;
}
bool pilhaPop(Pilha *pPilha, Item *p){
    if(!pPilha || !p)
        return false;
    Celula *aux = pPilha->topo->prox;
    *p = aux->item;
    pPilha->topo->prox = aux->prox;
    free(aux);
    return true;
}
bool EsvaziaPilha(Pilha *pPilha){
    if(!pPilha)
        return false;
    if(!pPilha->topo->prox)
        return true;
    Item temp;
    while(pilhaPop(pPilha,&temp));
    return true;
}

/*
Pilha* pilhaCria(){
    Pilha *pPilha = malloc(sizeof(Pilha));
    if(pPilha){
        pPilha->lista = criaLista();
        if(!pPilha->lista){
            free(pPilha);
            pPilha = NULL;
        }
    }
    return pPilha;
}
bool pilhaPush(Pilha *pPilha, Item n){
    if(!pPilha)
        return false;
    listaInsereMeio(pPilha->lista, &n, 0);
    return true;
}
bool pilhaPop(Pilha *pPilha, Item *n){
    if(!pPilha || !n)
        return false;
}

*/
