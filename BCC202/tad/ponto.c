#include "ponto.h"

#include <stdlib.h>
#include <math.h>

struct ponto {
    float x;
    float y;
};

Ponto* PontoAloca(float x, float y) {
    Ponto* pt = (Ponto*) malloc(sizeof(Ponto));
    if (pt) { // pt != NULL
        pt->x = x;
        pt->y = y;
    }
    return pt;
}

bool PontoAlocaV2(Ponto **pt, float x, float y) {
    *pt = (Ponto*) malloc(sizeof(Ponto));
    if (pt) {
        (*pt)->x = x;
        (*pt)->y = y;
        return true;
    }
    return false;
}

Ponto* PontoDesaloca(Ponto* pt) {
    if (pt) {
        free(pt);
    }
    return NULL;
}

bool PontoDesalocaV2(Ponto** pt) {
    if (*pt) {
        free(*pt);
        *pt = NULL;
        return true;
    }
    return false;
}

bool PontoSet(Ponto* pt, float x, float y) {
    if (pt) { // pt != NULL
        pt->x = x;
        pt->y = y;
        return true;
    }
    return false;
}

bool PontoGet(Ponto* pt, float *x, float *y) {
    if (pt && x && y) { // pt != NULL && x != NULL && y != NULL
        *x = pt->x;
        *y = pt->y;
        return true;
    }
    return false;
}

float PontoDistacia(Ponto *p1, Ponto *p2) {
    if (p1 && p2) {
        return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
    }
    return -1;
}