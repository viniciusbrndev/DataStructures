#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz(int tam){
    float **matriz = malloc(sizeof(float*) * tam);
    if(matriz == NULL)
        return NULL;

    for(int i = 0; i < tam; i++){
        matriz[i] = malloc(sizeof(float) * tam);
        if(matriz[i] == NULL){
            for(int j = 0; j < i; j++)
                free(matriz[j]);
            return NULL;
            }
    }
    return matriz;
}
void liberaMatriz(float** mat, int tam){
    for(int i = 0; i < tam; i++)
        free(mat[i]);
    free(mat);
}
void preencheMatriz(float** mat, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            scanf("%f", &mat[i][j]);
        }
    }
}
float sUpper(float** mat, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j > i && i+j < tam-1)
                soma += mat[i][j];
        }
    }
    return soma;
}
float sDown(float** mat, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j < i && i+j > tam-1)
                soma += mat[i][j];
        }
    }
    return soma;
}
float sLeft(float** mat, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j < i && i+j < tam-1)
                soma += mat[i][j];
        }
    }
    return soma;
}
float sRight(float** mat, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j > i && i+j > tam-1)
                soma += mat[i][j];
        }
    }
    return soma;
}

//medias
float mUpper(float** mat, int tam){
    int cont = 0;
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j > i && i+j < tam-1){
                soma += mat[i][j];
                cont++;
            }
        }
    }
    soma = (soma / cont);
    return soma;
}
float mDown(float** mat, int tam){
    int cont = 0;
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j < i && i+j > tam-1){
                soma += mat[i][j];
                cont++;
            }
        }
    }
    soma = (soma / cont);
    return soma;
}
float mLeft(float** mat, int tam){
    int cont = 0;
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j < i && i+j < tam-1){
                soma += mat[i][j];
                cont++;
            }
        }
    }
    soma = (soma / cont);
    return soma;
}
float mRight(float** mat, int tam){
    int cont = 0;
    float soma = 0;
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(j > i && i+j > tam-1)
                soma += mat[i][j];
        }
    }
    soma = (soma / cont);
    return soma;
}