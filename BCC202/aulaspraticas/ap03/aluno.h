#ifndef ALUNO_H
#define ALUNO_H

typedef struct mochila Mochila;
Mochila* montaMochila(int tam, int k);
void destroiMochila(Mochila* p);
int setItens(Mochila* p);
void analisaMochila(Mochila *m, int indice, int pesoAtual, int lucroAtual);
void getLucro(Mochila* m, int *lucroMax);
void getNcaso(Mochila* m, int *casosPossiveis);
#endif