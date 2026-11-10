#include "quad.h"
//#include "ponto.h"

struct quadrado {
    Ponto* ptMin;
    Ponto* ptMax;
};
Quadrado* alocaQuad(Ponto* pt1, Ponto* pt2){
    if(!pt1 || !pt2)
        return NULL;
    Quadrado* q = (Quadrado*)malloc(sizeof(Quadrado));
    if(q){
        float x1, y1, x2, y2;

        PontoGet(pt1, &x1, &y1);
        q->ptMin = PontoAloca(x1, y1);
        
        PontoGet(pt2, &x2, &y2);
        q->ptMax = PontoAloca(x2, y2);
    }
    return q;
}
Quadrado* desalocaQuad(Quadrado* q){
    if(q){
        q->ptMax = PontoDesaloca(q->ptMax);
        q->ptMin = PontoDesaloca(q->ptMin);
        free(q);
    }
    return NULL;
}
bool getQuad(Ponto* pt1, Ponto* pt2, Quadrado* q){
    if(pt1 && pt2 && q){
        float x,y;
        PontoGet(q->ptMin, &x, &y);
        PontoSet(pt1, x, y);
        //Ponto 2
        PontoGet(q->ptMax, &x, &y);
        PontoSet(pt2, x, y);
        
        return true;
    }
    return false; 
}
bool setQuad(Ponto* pt1, Ponto* pt2, Quadrado* q){
    if(pt1 && pt2 && q){
        float x,y;
        PontoGet(pt1, &x, &y);
        PontoSet(q->ptMin, x, y);
        //Ponto 2
        PontoGet(pt2, &x, &y);
        PontoSet(q->ptMax, x, y);
        
        return true;
    }
    return false;
}