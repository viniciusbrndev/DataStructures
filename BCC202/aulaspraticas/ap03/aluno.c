#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int peso;
    int valor;
}Item;
struct mochila{
    int pesoMax;
    int casosV;
    int n;
    int lucroMax;
    Item* itens;
};


Mochila* montaMochila(int tam, int k){
    if(tam == 0 || k == 0)
        return NULL;
    Mochila* p = (Mochila*)malloc(sizeof(Mochila));
    if(!p)
        return NULL;
    p->itens = malloc(sizeof(Item)*tam);
    if(p->itens == NULL){
        free(p);
        return NULL;
    }
    
    p->pesoMax = k;
    p->n = tam;
    p->casosV = 0;
    p->lucroMax = 0;
    return p;
}
void destroiMochila(Mochila* p){
    free(p->itens);
    free(p);
    p =  NULL;
}
int setItens(Mochila* p){
    int peso, valor;
    for(int i = 0; i < p->n; i++){
        scanf("%d %d", &peso, &valor);
        if(peso >= 0 && valor >= 0){
            p->itens[i].peso = peso;
            p->itens[i].valor = valor;
        }
        else
            return 0;
    }
    return 1;
}
void analisaMochila(Mochila *m, int indice, int pesoAtual, int lucroAtual){
    if(pesoAtual > m->pesoMax)
        return;
    if(indice == m->n){
        m->casosV++;
        if(lucroAtual > m->lucroMax)
            m->lucroMax = lucroAtual;
        return;
    }
    //recursão n pegou o item
    analisaMochila(m, indice +1, pesoAtual, lucroAtual);
    //recursão pegou o item
    analisaMochila(m, indice +1, pesoAtual + m->itens[indice].peso, lucroAtual + m->itens[indice].valor);

}
void getLucro(Mochila* m, int *lucroMax){
    *lucroMax = m->lucroMax;
}
void getNcaso(Mochila* m, int *casosPossiveis){
    *casosPossiveis = m->casosV;
}