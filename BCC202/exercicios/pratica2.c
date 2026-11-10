#include "pratica2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct jogador{
    char nome[30];
    int idade;
    int ehTitular;
};

struct rodas{
    char nome[30];
    int raio;
    int psi;
};

Jogador* alocaJogador(){
    Jogador* p = (Jogador*)malloc(sizeof(Jogador));
    if(!p)
        return NULL;
    return p;
}
void desalocaJoogador(Jogador **p){
    if(!p)
        return;
    free(*p);
    *p = NULL;
}
void imprimeTitular(Jogador *jogador){
    if(!jogador)
        return;
    if(jogador->ehTitular == 1)
        printf("\nNome do jogador: %s Idade: %d", jogador->nome, jogador->idade);
}
int idadeJogador(Jogador* p){
    if(p)
        return p->idade;
}
Rodas* alocaRodas(int n){
    Rodas *p = (Rodas*)malloc(sizeof(Rodas)*n);
    if(p)
        return p;
    return NULL;
}
void desalocaRodas(Rodas **p){
    if(p)
        free(*p);
    *p = NULL;
    return;
}
void getRoda(Rodas *v,char *nome, int *psi){
    if(v && nome && psi){
        strcpy(nome, v->nome);
        *psi = v->psi;
    }
    return;
}