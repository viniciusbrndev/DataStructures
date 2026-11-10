#ifndef POLI_H
#define POLI_H
#include <stdbool.h>

typedef struct polinomio Polinomio;

Polinomio* criaPolinomio(int tam);
bool destroiPolinomio(Polinomio* p);
bool setPolinomio(Polinomio* p);
bool getTermo(Polinomio* p, int* c, int* e, int n);
bool derivaPolinomio(Polinomio* poli, Polinomio* derivada);
double avaliarPolinomio(Polinomio* p, float ponto);
#endif 