#include "lista.h"




struct lista{
    Item *itens;
    int tamMax;
    int n; //número de itens 
};

Lista* criaLista(){
    Lista *p = malloc(sizeof(Lista));
    if(p){
        p->itens = malloc(sizeof(Item));
        if(!p->itens){
            free(p);
            return NULL;
        }
        p->n = 0;
        p->tamMax = 1;
        return p;
    }
    
    return NULL;

}
Lista* destroiLista(Lista *p){
    if(p){
        free(p->itens);
        free(p);
    }
    return NULL;
}
bool listaInsereMeio(Lista *p, Item *x, int posLista){
    if(p && posLista >= 0){
        if(p->n == 0){
            p->itens[0] = *x;
        }
        else{
            if(posLista > p->tamMax)
                return false;
            if(p->n == p->tamMax)
                p->itens = realloc(p->itens,p->tamMax*2);
            for(int i = p->n; i > posLista; i--)
                p->itens[i] = p->itens[i-1];
            
            p->itens[posLista] = *x;
        }
        p->n++;
        return true;
    }
    return false;
}

bool listaRemoveMeio(Lista *p, Item *x, int posLista){
    if(!p || !x || posLista > p->tamMax)
        return false;
    *x = p->itens[posLista];
    for(int i = posLista; i < p->n; i++)
        p->itens[i] = p->itens[i+1];
    p->n--;
    return true;
}

