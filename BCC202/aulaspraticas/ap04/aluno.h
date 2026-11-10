#ifndef ALUNO_H
#define ALUNO_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct no No;
typedef struct amigo Amigo;
typedef struct lista Lista;

typedef struct sugestao{
    char nome[50];
    int qtRec;
}Sugestao;
Lista* criaLista();
bool insereAmigo(Lista *pLista, char *nome);
bool insereAmigoDoAmigo(Amigo *pAmigo, char *nome);
Amigo* buscaAmigoLista(Lista* pLista, char *nome);
bool preencheAmigos(Lista* pLista);
bool preencheSubAmigos(Lista* pLista);
int listaTamanho(Lista *pLista);
#endif