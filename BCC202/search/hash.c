#include "hash.h"
#include <stdbool.h>
#include <stdio.h>
#include "lista.h"

struct hash
{
    Lista **listas;
    int n;
};

Hash *HashCria(int n){
    Hash* haxixi = (Hash*)malloc(sizeof(Hash));
    if(haxixi){
        haxixi->n = n;
        for(int i = 0; i < n; i++){
            haxixi->listas[i] = criaLista();
            if(!haxixi->listas[i]){
                for(int j = 0; j < i; j++){
                    haxixi->listas[i] = destroiLista(haxixi->listas[j]);
                }
                free(haxixi);
            return NULL;
            }
            
        }
    }
    return haxixi;
}
Hash *HashDestroi(Hash *pHash){
    if(!pHash)
        return NULL;
    for(int i = 0; i < pHash->n; i++){
        pHash->listas[i] = destroiLista(pHash->listas[i]);
    }
    free(pHash);
    return NULL;
}
bool HashInsere(Hash *pHash, Item x){
    if(!pHash)
        return false;
    int pos = x.chave % pHash->n;
    if(listaPesquisa(pHash->listas[pos], x))
        return false;
    return listaInsereMeio(pHash->listas[pos], &x,0);
}
bool HashPesquisa(Hash *pHash, Item chave, Item *pX){
    if(!pHash)
        return false;
    int pos = chave.chave % pHash->n;
    return listaPesquisa(pHash->listas[pos], chave);
}
void HashImprime(Hash *pHash){
    if(!pHash)
        return;
    for(int i = 0; i < pHash->n; i++){
        im
    }
}

