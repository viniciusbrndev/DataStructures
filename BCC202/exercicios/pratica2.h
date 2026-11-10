#ifndef PRATICA2_H
#define PRATICA2_H

typedef struct jogador Jogador;
typedef struct rodas Rodas;

Jogador* alocaJogador();
void desalocaJoogador(Jogador **p);
void imprimeTitular(Jogador *jogador);
int idadeJogador(Jogador* p);
Rodas* alocaRodas(int n);
void desalocaRodas(Rodas **p);
void getRoda(Rodas *v,char *nome, int *psi);
#endif