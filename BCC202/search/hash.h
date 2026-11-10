#ifndef HASH_H
#define HASH_H
#include "lista.h"
#include "item.h"

typedef struct hash Hash;


Hash *HashCria(int n);
Hash *HashDestroi(Hash *pHash);
bool HashInsere(Hash *pHash, Item x);
bool HashRemove(Hash *pHash, int chave, Item *pX);
bool HashPesquisa(Hash *pHash, int chave, Item *pX);
void HashImprime(Hash *pHash);



#endif