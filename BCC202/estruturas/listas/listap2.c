#include "listap2.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct celula{
    int chave;
    Celula *prox;
};
struct lista{
    Celula *cabeca;
};

struct pilha{
    Celula* topo;
};
typedef struct fila{
    int tam;
    int *itens;
    
    int n;
    int fim;
    int ini;
}Fila;

Lista* criaLista(){
    Lista* p = (Lista*)malloc(sizeof(Lista));
    if(p){
        p->cabeca = (Celula*)malloc(sizeof(Celula));
        if(!p->cabeca){
            free(p);
            p = NULL;
        }
        p->cabeca->prox = NULL;
    }
    return p;
}
bool insereFim(Lista* p, int item){
    if(!p)
        return false;
    Celula *aux = p->cabeca->prox;
    while(aux->prox)
        aux = aux->prox;
    Celula* novo = (Celula*)malloc(sizeof(Celula));
    novo->chave = item;
    novo->prox = NULL;
    aux->prox = novo;
    return true;
}
void moveElemento(Lista *p, int chave){
    if(!p)
        return;
    Celula *ant, *aux;
    ant = p->cabeca;
    aux = p->cabeca->prox;
    while(aux->chave != chave){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    aux->prox = p->cabeca->prox;
    p->cabeca->prox = aux;
}
int listaTamanho(Lista *p){
    if(!p)
        return -1;
    int tam = 0;
    Celula *aux = p->cabeca->prox;
    while(aux){
        tam++;
        aux = aux->prox;
    }
    return tam;
}
//O(n²)
Lista* ListaIntercala(Lista* p1, Lista*p2){
    if(!p1 || !p2)
        return NULL;
    Lista* p3 = criaLista();
    if(!p3)
        return NULL;
    Celula *aux1, *aux2;
    aux1 = p1->cabeca->prox;
    aux2 = p2->cabeca->prox;
    while(aux1 || aux2){
        if(aux1){
            insereFim(p3, aux1->chave);
            aux1 = aux1->prox;
        }
        if(aux2){
            insereFim(p3, aux2->chave);
            aux2 = aux2->prox;
        }
    }
    return p3;
}
//O(n)
Lista* ListaIntercalamod(Lista* p1, Lista* p2){
    if(!p1 || !p2)
        return NULL;
    Lista* p3 = criaLista();
    if(!p3)
        return NULL;
    Celula *aux1, *aux2, *ult, *novo;
    aux1 = p1->cabeca->prox;
    aux2 = p2->cabeca->prox;
    ult = p3->cabeca;
    while(aux1 || aux2){
        if(aux1){
            novo = malloc(sizeof(Celula));
            novo->chave = aux1->chave;
            novo->prox = NULL;
            ult->prox = novo;

            ult = novo;
            aux1 = aux1->prox;
        }
        if(aux2){
            novo = malloc(sizeof(Celula));
            novo->chave = aux2->chave;
            novo->prox = NULL;
            ult->prox = novo;

            ult = novo;
            aux1 = aux2->prox;
        }
    }
    return p3;
}
Fila* FilaInicia(int tam){
    Fila *p = malloc(sizeof(Fila));
    if(p){
        p->itens = malloc(sizeof(int) * tam);
        if(!p->itens){
            free(p);
            p = NULL;
        }
        p->n = 0;
        p->tam = tam;
        p->fim = 0;
        p->ini = 0;
    }
}
bool FilaEnfileira(Fila* p, int item){
    if(!p || p->n == p->tam)
        return false;
    p->itens[p->fim] = item;
    p->fim = (p->fim +1) % p->tam;
    p->n++;
    return true;
}
bool FilaDesenfileira(Fila* p, int *pItem){
    if(!p || !p->n)
        return false;
    *pItem = p->itens[p->ini];
    p->ini = (p->ini +1) % p->tam;
    p->n--;
    return true;
}
void imprimeCel(Celula *p){
    if(!p)
        return;
    printf("%d ", p->chave);
    imprimeCel(p->prox);
}
void imprimeLista(Lista *pLista){
    if(!pLista)
        return;
    imprimeCel(pLista->cabeca->prox);
}
void dumbSort(Lista* pLista){
    if(!pLista)
        return;
    Celula* aux = pLista->cabeca->prox;
    Celula *ant = pLista->cabeca;
    while(aux && aux->prox){
        if(aux->chave < aux->prox->chave && aux->chave < ant->chave){
            ant->prox = aux->prox;
            free(aux);
            aux = ant->prox;
            continue;
        }
        ant = aux;
        aux = aux->prox;
    }
    /*
        MÉTODO INVÁLIDO POIS NÃO ORDENA DE VERDADE SÓ REMOVE VALES
        SE ant > aux < aux->prox
            REMOVE
    */
}

Pilha* PilhaALoca(){
    Pilha* ptemp = malloc(sizeof(Pilha));
    if(ptemp){
        ptemp->topo = malloc(sizeof(Celula));
        if(!ptemp->topo){
            free(ptemp);
            return NULL;
        }
        ptemp->topo->chave = 0;
        ptemp->topo->prox = NULL;
    }
    return ptemp;
}
bool PilhaEhVazia(Pilha *pPilha){
    if(!pPilha || !pPilha->topo->prox)
        return true;
    else
        return false;
}
bool pilhaPop(Pilha* pPilha, int *item){
    if(!pPilha || !pPilha->topo->prox)
        return false;
    Celula *aux = pPilha->topo->prox;
    if(!aux->prox){
        *item = aux->chave;
        free(aux);
        return true;
    }
    *item = aux->chave;
    pPilha->topo->prox = aux->prox;
    free(aux);
    return true;
}
bool PilhaPush(Pilha *pPilha, int n){
    if(!pPilha)
        return false;
    Celula * novo = malloc(sizeof(Celula));
    if(!novo)
        return false;

    novo->chave = n;
    novo->prox = pPilha->topo->prox;
    pPilha->topo->prox = novo;

    return true;
}
int PilhaTamnho(Pilha* p){
    if(!p)
        return 0;
    int cont = 0;
    Celula *aux = p->topo->prox;
    while(aux){
        cont++;
        aux = aux->prox;
    }
    return cont;
}
//O(n)
Pilha* PilhaFree(Pilha *p){
    if(!p)
        return NULL;
    int temp;
    while(!PilhaEhVazia(p))
        pilhaPop(p, &temp);
    free(p->topo);
    free(p);
    return NULL;
}
int filaInicia(Fila** fila, int tam){
    if(tam <= 0)
        return 0;
    *fila = malloc(sizeof(Fila));
    if(*fila){
        (*fila)->itens = malloc(sizeof(int)*tam);
        if(!(*fila)->itens){
            free(*fila);
            return 0;
        }
        (*fila)->tam = tam;
        (*fila)->fim = 0;
        (*fila)->ini = 0;
        (*fila)->n = 0;
        return 1;
    }
    return 0;
}
int filaEnfileira(Fila *fila, int item){
    if(!fila || fila->tam == fila->n)
        return 0;
    fila->itens[fila->fim] = item;
    fila->fim = (fila->fim +1) % fila->tam;
    fila->n++;
    return 1;
}
int filaDesenfileira(Fila *fila, int *item){
    if(!fila || !item)
        return 0;
    *item = fila->itens[fila->ini];
    fila->ini = (fila->ini +1) % fila->tam;
    fila->n--;
    return 1;
}
bool listaTemNumRepetidos(Lista* plista){
    if(!plista)
        return false;
    
    Celula* aux, *frente;
    aux = plista->cabeca->prox;
    frente = aux->prox;
    if(!aux)
        return false;
    int i = 1, j = 1;
    while(aux){
        while(frente){
            if(aux->chave == frente->chave)
                printf("%d - %d, %d\n",i, aux->chave, j);
            j++;
            frente = frente->prox;
        }
        i++;
        aux = aux->prox;
        j = 0;
        frente = aux->prox;
    }
    return true;
}
bool filaEhVazia(Fila *p){
    if(!p || p->n == 0)
        return true;
    return false;
}
int filaTamanho(Fila* fila){
    if(!fila)
        return 0;
    return fila->tam;
}
bool listaTrocaParte(Lista *p, int pos){
    if(!p || pos <= 0)
        return false;
    Celula *aux, *ant;
    
    aux = p->cabeca->prox;
    ant = aux->prox; 
    for(int i = 0; i < pos; i++){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    aux->prox = p->cabeca->prox;
    p->cabeca->prox = aux;
    
    return true;
}
bool filaIntercala(Fila *fila1, Fila *fila2, Fila* resultado){
    if(!fila1 || !fila2 || !resultado)
        return false;
    
    int item;
    while(!filaEhVazia(fila2) && !filaEhVazia(fila2)){
        filaDesenfileira(fila1, &item);
        filaEnfileira(resultado, item);

        filaDesenfileira(fila2, &item);
        FilaEnfileira(resultado, item);
    }
    while(!filaEhVazia(fila1)){
        filaDesenfileira(fila1, &item);
        filaEnfileira(resultado, item);
    }
    while(!filaEhVazia(fila2)){
        filaDesenfileira(fila2, &item);
        FilaEnfileira(resultado, item);
    }
    return true;
}
Fila* filaInverte(Fila *p){
    if(!p)
        return NULL;
    Fila* filaAux;
    int item;
    filaInicia(&filaAux, filaTamanho(p));
    if(!filaAux)
        return NULL;
    for(int i = filaTamanho(p); i > 0; i--){
        for(int j = 0; j < i-1; j++){
            filaDesenfileira(p, &item);
            filaEnfileira(filaAux, item);
        }
        filaDesenfileira(p, item);
        filaEnfileira(filaAux,  item);
    }
    while(!filaEhVazia(filaAux)){
        filaDesenfileira(filaAux, &item);
        filaEnfileira(p, item);
    }
    
}
void filaImprime(Fila *p){
    if(!p || p->n == 0){
        printf("Fila vazia!");
        return;
    }
    printf("Fila: ");
    int atual = p->ini;
    for(int i = 0; i < p->n; i++){
        printf("%d ", p->itens[atual]);
        atual = (atual + 1) % p->tam;
    }

}
void filaRec(Fila *p, int atual, int n){
    if(!n)
        return;
    printf("%d ", p->itens[atual]);
    int prox = (atual +1) % p->tam;
    filaRec(p, prox, n--);
}
void filaImprimeRec(Fila *p){
    if(!p || p->n == 0){
        printf("Fila vazia!");
        return;
    }
    printf("Fila: ");
    filaRec(p, p->ini, p->n);
    printf("\n");
}
void filaEspelho(Fila *fila){
    if(!fila)
        return;
    filaImprime(fila);
    filaInverte(fila);
    filaImprime(fila);
}