#include "matriz.h"
#include <stdlib.h>

struct matriz {
    int lin;
    int col;
    float** v;
};

Matriz* mat_cria (int m, int n){
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    if(mat){
        mat->lin = m;
        mat->col = n;
        mat->v = (float*)malloc(sizeof(float*)*m);
        for(int i = 0; i < m; i++){
            mat->v[i] = malloc(sizeof(float)*n);
            if(mat->v[i] == NULL){
                for(int j = 0; j < i; j++)
                    free(mat->v[j]);
                free(mat->v);
                free(mat);
                return NULL;
            }
        }
    }
    return mat;
}
void mat_libera ( Matriz* mat){
    if(!mat)
        return NULL;
    for(int i = 0; i < mat->lin; i++){
        free(mat->v[i]);
    
    free(mat->v);
    free(mat);
    return NULL;
    }
}
float mat_acessa ( Matriz* mat, int i, int j){
    if(mat && i <=  mat->lin && j <= mat->col && i > 0 && j > 0){
        return mat->v[i][j];
    }
}