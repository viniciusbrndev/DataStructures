#include "lista.h"

typedef struct cel {
    Item info;
    struct cel* prox;
}Celula;

struct lista{
    int n;
    Celula *cab;
    Celula *fim;
};

Lista* criaLista(){
    Lista* pLista = malloc(sizeof(Lista));
    if(!pLista)
        return NULL;
    pLista->cab = malloc(sizeof(Celula));
    if(!pLista->cab){
        free(pLista);
        return NULL;
    }
    pLista->cab->prox = NULL;
    pLista->fim = pLista->cab;
    pLista->fim->prox = NULL;
    return pLista;
}
Lista* destroiLista(Lista *p){
    if(!p)
        return NULL;
    listaEsvazia(p);
    free(p->cab);
    free(p);
    return NULL;
}
bool listaInsereMeio(Lista *p, Item *x, int posLista){
    if(!p)
        return false;
    if(posLista > p->n || posLista < 0)
        return false;
    Celula *nova = malloc(sizeof(Celula));
    Celula *aux;
    if(!nova)
        return false;
    if(posLista == p->n)
        aux = p->fim;
    else{
        aux = p->cab;
        for(int i = 0; i < posLista; i++)
            aux = aux->prox;
    }
    
    nova->prox = aux->prox;
    nova->info = *x;
    aux->prox = nova;
    if(posLista == p->n)
        p->fim = nova;
    p->n++;

    return true;
}
bool listaInsereInicio(Lista *p, Item *x){
    return listaInsereMeio(p, x, 0);
}
bool listaInsereFim(Lista *p, Item *x){
    return listaInsereMeio(p, x, p->n);
}
bool listaRemoveMeio(Lista *p, Item *x, int posLista){
    if(!p)
        return false;
    if(posLista > p->n || posLista < 0)
        return false;
    Celula *ant;

    ant = p->cab;        
    for(int i = 0; i < posLista; i++)
        ant = ant->prox;
    Celula *aux = ant->prox;
    
    *x = aux->info;
    ant->prox = aux->prox;
    free(aux);
    p->n--;

    if(posLista == p->n)
        p->fim = ant;

    return true;
}
bool listaRemoveFim(Lista *p, Item *x){
    return listaRemoveMeio(p,x, p->n-1);
}
bool listaRemoveInicio(Lista *p, Item *x){
    return listaRemoveMeio(p, x, 0);
}
bool listaEsvazia(Lista *pLista){
    if(pLista){
        Item x;
        while(listaRemoveFim(pLista, &x));
        return true;
    }
    return false;
}