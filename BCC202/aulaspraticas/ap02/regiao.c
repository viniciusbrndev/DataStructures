#include "regiao.h"
#include <stdio.h>
#include <stdlib.h>
struct ponto
{
    int x;
    int y;
};
struct regiao
{
    Ponto left;
    Ponto right;
};


Regiao alocaRetangulo(){
    Regiao r = malloc(sizeof(struct regiao));

    if(!r) 
        return NULL;

    /* Inicialização neutra */
    r->left.x = 0;
    r->left.y = 0;
    r->right.x = 0;
    r->right.y = 0;

    return r;
}
void destroiRegiao(Regiao r){
    free(r);
}
int setRetangulo(Regiao p, int x1, int y1, int x2, int y2){
    if(p && x1 < x2 && y1 > y2){    
        p->left.x = x1;
        p->left.y = y1;

        p->right.x = x2;
        p->right.y = y2;
        return  1;
    }
    return 0;
}

int getRetangulo(Regiao r, int *x1, int *y1, int *x2, int *y2){
    if (!r || !x1 || !y1 || !x2 || !y2) 
        return 0;

    *x1 = r->left.x;
    *y1 = r->left.y;
    *x2 = r->right.x;
    *y2 = r->right.y;
    return 1;
}
int verificaInter(Regiao r,int *x1, int *y1, int *x2, int *y2){
    if (!r || !x1 || !y1 || !x2 || !y2) 
        return 0;
    
    if(*x1 < r->left.x )
        *x1 = r->left.x;
    if(*y1 > r->left.y)
        *y1 = r->left.y;
    
    if(*x2 > r->right.x )
        *x2 = r->right.x;
    
    if(*y2 < r->right.y)
        *y2 = r->right.y;
    return 1;

    if(*x1 >= *x2 || *y1 <= *y2)
        return 0;//intersecção vazia
    
}