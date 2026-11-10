#ifndef REGIAO_H
#define REGIAO_H
typedef struct ponto Ponto;
typedef struct regiao *Regiao;

Regiao alocaRetangulo();
void destroiRegiao(Regiao r);
int setRetangulo(Regiao p, int x1, int y1, int x2, int y2);
int getRetangulo(Regiao r, int *x1, int *y1, int *x2, int *y2);
int verificaInter(Regiao r,int *x1, int *y1, int *x2, int *y2);
#endif