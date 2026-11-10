#include "circ.h"
#include <stdlib.h>

struct circulo {
    Ponto *centro;
    float raio;
};

Circulo* CirculoAloca(Ponto *pt, float raio) {
    if (!pt || raio <= 0) // pt == NULL
        return NULL;
    Circulo *c = (Circulo*) malloc(sizeof(Circulo));
    if (c) {
        c->raio = raio;
        float x, y;
        PontoGet(pt, &x, &y);
        c->centro = PontoAloca(x, y);
        if (!c->centro) { // c->centro == NULL
            free(c);
            c = NULL;
        }
    }
    return c;
}

Circulo* CirculoDesaloca(Circulo *c) {
    if (c) {
        c->centro = PontoDesaloca(c->centro);
        free(c);
    }
    return NULL;
}

float CirculoArea(Circulo *c) {
    if (c) 
        return 3.14 * c->raio * c->raio;
    return -1;
}

bool CirculoInterior(Circulo *c, Ponto *pt) {
    if (c || pt)
        return PontoDistacia(c->centro, pt) < c->raio;
    return false;
}