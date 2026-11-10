
#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct lista Lista;
typedef struct pilha Pilha;

typedef struct item{
    int chave;
    char nome[10];
}Item;

Lista* criaLista();
Lista* destroiLista(Lista *p);
bool listaInsereMeio(Lista *p, Item *x, int posLista);
bool listaRemoveMeio(Lista *p, Item *x, int posLista);
bool listaPesquisa(Lista* pLista, Item x);

#endif