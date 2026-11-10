#ifndef ARVORE_H
#define ARVORE_H
#include "item.h"
#include <stdbool.h>

typedef struct no No;

void ArvoreInicia(No **ppRaiz);
void ArvoreDestroi(No **ppRaiz);
bool ArvoreInsere(No **ppRaiz, Item x);
bool ArvoreRemove(No **ppRaiz, Item chave, Item *pX);
bool ArvorePesquisa(No *pRaiz, Item chave, Item *pX);
void ArvoreImprime(No *pRaiz, char forma[]);


#endif