#ifndef ITEM_H
#define ITEM_H

typedef struct {
    int chave;
    char nome[21];
} Item;

typedef enum {
    MENOR=0,
    IGUAL,
    MAIOR
} RES; // RES = RESULTADO

void ItemImprime(Item item);

RES ItemCompara(Item i1, Item i2);

#endif // ITEM_H