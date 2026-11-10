#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

typedef struct circulo Circulo;

Circulo* CirculoAloca(Ponto *pt, float raio);
Circulo* CirculoDesaloca(Circulo *c);

float CirculoArea(Circulo *c);
bool CirculoInterior(Circulo *c, Ponto *pt);

#endif // CIRCULO_H