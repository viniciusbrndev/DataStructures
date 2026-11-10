#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
    float** mat;
    float resultado;
    int tam;
    char res, area;
    
    scanf("%c %c %d", &res, &area, &tam);
    //erro
    if(tam < 3){
        printf("Erro!Ordem minima:3");
        return 0;
    }
    mat = alocaMatriz(tam);//aloquei a matriz
    preencheMatriz(mat, tam);// preenchi

    if(res == 'S'){
        if(area == 'U'){
            resultado = sUpper(mat, tam);
        }
        else if(area == 'B'){
            resultado = sDown(mat, tam);
        }
        else if(area == 'L'){
            resultado = sLeft(mat, tam);
        }
        else if(area == 'R'){
            resultado = sRight(mat, tam);
        }
    }
    else if(res == 'M'){
        if(area == 'U'){
            resultado = mUpper(mat, tam);
        }
        else if(area == 'B'){
            resultado = mDown(mat, tam);
        }
        else if(area == 'L'){
            resultado = mLeft(mat, tam);
        }
        else if(area == 'R'){
            resultado = mRight(mat, tam);
        }
    }

    printf("%.1f ", resultado);
    liberaMatriz(mat, tam);
}