#include "circ.h"
#include <stdlib.h>
#include <math.h>

// EVITAR ESTA IMPLEMENTAÇÃO

struct circulo {
    float x;
    float y;
    float raio;
};

Circulo* CirculoAloca(Ponto *pt, float raio) {
    if (!pt || raio <= 0) // pt == NULL
        return NULL;
    Circulo *c = (Circulo*) malloc(sizeof(Circulo));
    if (c) {
        c->raio = raio;
        PontoGet(pt, &c->x, &c->y);
    }
    return c;
}

Circulo* CirculoDesaloca(Circulo *c) {
    if (c)
        free(c);
    return NULL;
}

float CirculoArea(Circulo *c) {
    if (c) 
        return 3.14 * c->raio * c->raio;
    return -1;
}

float distanciaPontoAPonto(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool CirculoInterior(Circulo *c, Ponto *pt) {
    if (c || pt) {
        float x, y;
        PontoGet(pt, &x, &y);
        return distanciaPontoAPonto(c->x, c->y, x, y);
    }
    return false;
}