#include "item.h"

#include <stdio.h>
#include <string.h>

void ItemImprime(Item item) {
    printf("[%2d|%10s]", item.chave, item.nome);
}

RES comparaNome(Item i1, Item i2);
RES comparaChave(Item i1, Item i2);
RES comparaNomeChave(Item i1, Item i2);

RES ItemCompara(Item i1, Item i2) {
    return comparaNome(i1, i2);
    // return comparaChave(i1, i2);
    // return comparaNomeChave(i1, i2);
}

RES comparaNome(Item i1, Item i2) {
    int resultado = strcmp(i1.nome, i2.nome);
    if (resultado == 0)
        return IGUAL;
    else if (resultado < 0)
        return MENOR;
    return MAIOR;
}

RES comparaChave(Item i1, Item i2) {
    if (i1.chave == i2.chave)
        return IGUAL;
    else if (i1.chave < i2.chave)
        return MENOR;
    return MAIOR;
}

RES comparaNomeChave(Item i1, Item i2) {
    RES result = comparaNome(i1, i2);
    if (result == IGUAL)
        return comparaChave(i1, i2);
    return result;
    // int resultado = strcmp(i1.nome, i2.nome);
    // if (resultado == 0) {
    //     if (i1.chave == i2.chave)
    //         return IGUAL;
    //     else if (i1.chave < i2.chave)
    //         return MENOR;
    //     return MAIOR;
    // }
    // else if (resultado < 0)
    //     return MENOR;
    // return MAIOR;
}