#ifndef PONTO_H
#define PONTO_H

#include <stdbool.h>

typedef struct ponto Ponto;

Ponto* PontoAloca(float x, float y);
Ponto* PontoDesaloca(Ponto *pt);

bool PontoSet(Ponto *pt, float x, float y);
bool PontoGet(Ponto *pt, float *x, float *y);

float PontoDistacia(Ponto *p1, Ponto *p2);

#endif