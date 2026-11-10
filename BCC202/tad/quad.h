#ifndef QUAD_H
#define QUAD_H
#include "ponto.h"
#include <stdlib.h>


typedef struct quadrado Quadrado;

Quadrado* alocaQuad(Ponto* pt1, Ponto* pt2);
Quadrado* desalocaQuad(Quadrado* q);
bool getQuad(Ponto* pt1, Ponto* pt2, Quadrado* q);
bool setQuad(Ponto* pt1, Ponto* pt2, Quadrado* q);

#endif