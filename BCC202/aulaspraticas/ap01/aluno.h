#ifndef ALUNO_H
#define ALUNO_H

float **alocaMatriz(int tam);
void liberaMatriz(float** mat, int tam);
void preencheMatriz(float** mat, int tam);
float sUpper(float** mat, int tam);
float sDown(float** mat, int tam);
float sLeft(float** mat, int tam);
float sRight(float** mat, int tam);
float mUpper(float** mat, int tam);
float mDown(float** mat, int tam);
float mLeft(float** mat, int tam);
float mRight(float** mat, int tam);
#endif