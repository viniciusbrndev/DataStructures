#include "arvore.h"
#include <stdlib.h>
#include "item.h"
#include <stdio.h>
#include <stdbool.h>


struct no{
    Item data;

    No* dir;
    No* esq;
};


No* criaNo(Item x){
    No* novo = malloc(sizeof(No));
    if(novo){
        novo->data = x;

        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

bool ArvorePesquisa(No *pRaiz, Item chave, Item *pX){
    if(!pRaiz)
        return false;
    else if(pRaiz->data.chave < chave.chave)
        return ArvorePesquisa(pRaiz->dir, chave, pX);
    else if(pRaiz->data.chave > chave.chave)
        return ArvorePesquisa(pRaiz->esq,chave, pX);
    *pX = pRaiz->data;
    return true;
}
bool ArvoreInsere(No **ppRaiz, Item x){
    if(!*ppRaiz){
        *ppRaiz = criaNo(x);
        if(*ppRaiz)
            return true;
        }
    if((*ppRaiz)->data.chave > x.chave)
        ArvoreInsere((*ppRaiz)->esq, x);
    if((*ppRaiz)->data.chave < x.chave)
        ArvoreInsere((*ppRaiz)->dir, x);
    return false;
}
bool noAntecessor(No *qSai,No **ppAnt){
    if((*ppAnt)->dir)
        return noAntecessor(qSai, (*ppAnt)->dir);
    qSai->data = (*ppAnt)->data;
    No* aux = *ppAnt;
    *ppAnt = aux->esq;
    free(aux);
}
bool ArvoreRemove(No **ppRaiz, Item chave, Item *pX){
    if(!(*ppRaiz))
        return false;
    if(chave.chave > (*ppRaiz)->data.chave)
        return ArvoreRemove((*ppRaiz)->dir, chave, pX);
    if(chave.chave < (*ppRaiz)->data.chave)
        return ArvoreRemove((*ppRaiz)->esq, chave, pX);
    *pX = (*ppRaiz)->data;
    //No folha
    if(!(*ppRaiz)->esq && !(*ppRaiz)->dir){
        free(*ppRaiz);
        *ppRaiz = NULL;
        return true;
    }
    //so tem filho na esquerda
    if((*ppRaiz)->esq && !(*ppRaiz)->dir){
        No* aux= *ppRaiz;
        *ppRaiz = (*ppRaiz)->esq;
        free(aux);
        return true;
    }
    //so tem filha na direita
    if(!(*ppRaiz)->esq && (*ppRaiz)->dir){
        No* aux = *ppRaiz;
        *ppRaiz = (*ppRaiz)->dir;
        free(aux);
        return true;
    }
    //TEM OS DOIS
    return noAntecessor(*ppRaiz, &(*ppRaiz)->esq);
}
int menorNivelfolha(No* pRaiz, int nivel){
    if(!pRaiz)
        return __INTMAX_MAX__;
    if(!pRaiz->dir && !pRaiz->esq)
        return nivel;
    int nEsq = menorNivelfolha(pRaiz->esq, nivel+1);
    int nDir = menorNivelfolha(pRaiz->dir, nivel+1);

    return (nEsq < nDir) ? nEsq : nDir;
}
void imprimeDoMenor(No* pRaiz){
    if(!pRaiz)
        return;
    
    imprimeDoMenor(pRaiz->esq);
    ItemImprime(pRaiz->data);
    imprimeDoMenor(pRaiz->dir);
    ItemImprime(pRaiz->data);
}
void decrescente(No* pNo){
    if(!pNo)
        return;
    
    decrescente(pNo->dir);
    ItemImprime(pNo->data);
    decrescente(pNo->esq);
    ItemImprime(pNo->data);
}
bool insereNaArvoreRec(No **ppRaiz, Item chave){
    if(!*ppRaiz){
        No* novo = malloc(sizeof(No));
        if(novo){
            novo->data = chave;
            novo->dir = NULL;
            novo->esq = NULL;
        }
        *ppRaiz = novo;
        return true;
    }
    if(chave.chave > (*ppRaiz)->data.chave)
        return insereNaArvoreRec((*ppRaiz)->dir, chave);
    if(chave.chave < (*ppRaiz)->data.chave)
        return insereNaArvoreRec((*ppRaiz)->esq, chave);
    return false;
}

void heapRefaz(int *v, int dir, int esq){
    int i, j;
    int aux = v[esq];
    i = esq;
    j = 2 * i +1;
    while(j <= dir){
        if(j < dir)
            if(v[j + 1] > v[j])
                j++;
        if(v[j] > v[i]){
            v[i] = v[j];
            i = j;
            j = 2 * i +1;
        }
    }
    v[i] = aux;
}
int qtdDeNosMaior(No* p, int v){
    if(!p)
        return 0;
    if(p->data.chave <= v)
        qtdDeNosMaior(p->dir, v);
    return 1 + qtdDeNosMaior(p->dir, v) + qtdDeNosMaior(p->esq, v);
}
void limpaNos(No** ppRaiz, int i, int j){
    if(!(*ppRaiz))
        return;
    limpaNos(&(*ppRaiz)->esq, i, j);
    limpaNos(&(*ppRaiz)->dir, i, j);    
    if((*ppRaiz)->data.chave >= i && (*ppRaiz)->data.chave <= j){
        if((*ppRaiz)->dir && !(*ppRaiz)->esq){
            No* aux = (*ppRaiz);
            (*ppRaiz) = aux->dir;
            free(aux);
        }
        if((*ppRaiz)->esq && !(*ppRaiz)->dir){
            No* aux = (*ppRaiz);
            (*ppRaiz) = aux->esq;
            free(aux);
        }
        if((*ppRaiz)->esq && (*ppRaiz)->dir)
            noAntecessor((*ppRaiz), &(*ppRaiz)->esq);
    }

}
long produtorio(No* p){
    if(!p || p->data.chave == 0)
        return 1;
    return produtorio(p->dir) * p->data.chave * produtorio(p->esq);
}
bool ehHeapValido(int *v,  int n){
    int i, j;
    i = n / 2 -1;

    while(i >= 0){
        j = 2*i + 1;
        if(v[i] > v[j] || v[i] > v[j+1])
            return false;
        i--;
    }
    return true;
}
float nosParesRec(No* pRaiz, int *qtdDeNosPares){
    if(!pRaiz)
        return 0;
    if(pRaiz->data.chave % 2 == 0)
        return pRaiz->data.chave + nosParesRec(pRaiz->dir, *qtdDeNosPares++) + nosParesRec(pRaiz->esq, *qtdDeNosPares++);
    
    return nosParesRec(pRaiz->dir, *qtdDeNosPares++) + nosParesRec(pRaiz->esq, *qtdDeNosPares++);
}
float mediaNosPares(No* pRaiz){
    int m = 0;
    if(!pRaiz)
        return 0;
    return nosParesRec(pRaiz, m) / m;
}

