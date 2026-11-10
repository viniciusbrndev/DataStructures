#include "poli.h"
#include <stdio.h>
#include <math.h>




int main(){
    int tam;
    scanf("%d", &tam);
    //alocando os polinomios
    Polinomio *poli = criaPolinomio(tam);
    Polinomio *derivada = criaPolinomio(tam);
    //preenchendo com valores inseridos pelo usuário
    setPolinomio(poli);
    //função percorre n termos do polinomio e deriva sem perder os valores orginais^ 
    derivaPolinomio(poli, derivada);
    
    printf("Polinomio: ");
    int coe, exp; 
    for(int i = 0; i < tam; i++){
        getTermo(poli, &coe, &exp, i);
        printf("%.2fx^%.2f ", (float)coe, (float)exp);
    }
    printf("\nDerivada: ");
    for(int i = 0; i < tam; i++){
        getTermo(derivada, &coe, &exp, i);
        printf("%.2fx^%.2f ", (float)coe, (float)exp);
    }

    //liberando memória
    destroiPolinomio(derivada);
    destroiPolinomio(poli);

}