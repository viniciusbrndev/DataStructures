#include "poli.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    int coeficiente;
    int potencia;
} Termo;

struct polinomio{
    int tam;
    Termo* termos;

};


Polinomio* criaPolinomio(int tam){
    if(tam <= 0)
        return NULL;
    Polinomio* p = (Polinomio*)malloc(sizeof(Polinomio));
    if(!p)
        return NULL;
    p->tam = tam;
    //alocando vetor de termos *polinomio
    p->termos = (Termo*)malloc(sizeof(Termo)*tam);
    if(!p->termos){
        free(p);
        return NULL;
    }
    //inicializando os termos
    for(int i = 0; i < tam; i++){
        p->termos[i].coeficiente = 1;
        p->termos[i].potencia = 1;
    }
    return p;
}
bool destroiPolinomio(Polinomio* p){
    if(p){
        free(p->termos);
        free(p);
    }
    p = NULL;
    return true;
}
bool setPolinomio(Polinomio* p){
    if(!p)
        return false;
    int c, e;
    for(int i = 0; i < p->tam; i++){
        scanf("%d %d", &c, &e);
        p->termos[i].coeficiente = c;
        p->termos[i].potencia = e;
    }
    return true;
}
bool getTermo(Polinomio* p, int* c, int* e, int n){
    if(p && c && e && n < p->tam){
        *e = p->termos[n].potencia;
        *c = p->termos[n].coeficiente;
        return true;
    }
    return false;
}
bool derivaPolinomio(Polinomio* poli, Polinomio* derivada){
    if(poli && derivada){
        derivada->tam = poli->tam;
        for(int i = 0; i < poli->tam; i++){
            derivada->termos[i].coeficiente = (poli->termos[i].coeficiente) * (poli->termos[i].potencia);
            
            derivada->termos[i].potencia = (poli->termos[i].potencia) - 1;
        }
        return true;
    }
    return false;
}
double avaliarPolinomio(Polinomio* p, float ponto){
    double soma = 0;
    for(int i = 0; i < p->tam; i++){
        soma+= (double)p->termos[i].coeficiente * (pow(ponto, p->termos[i].potencia));
    }
    return soma;
}