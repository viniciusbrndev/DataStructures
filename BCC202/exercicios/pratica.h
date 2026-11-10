#ifndef PRATICA_H
#define PRATICA_H
//TAD's
typedef struct time Time;
typedef struct aluno Aluno;
typedef struct funcionario Funcionario;
typedef struct carro Carro;

//Funções
float maiorElemento(int i, float* v);
int inverteInt(int n);
int potenciaDeN(int k, int n);
void imprime(Time* p);
int quantidadeDeTimes(Time* times, char *conferencia, int n, int x, int tam);
void imprimeVetor(int *v, int n);
void imprimeImpar(int *v, int n);
void printTree(int n);
Aluno* criaAlunos(char *nomes,int *matriculas, float *coeficientes,int *anos, int n);
Aluno* destroiAluno(Aluno* alunos, int n);
float mediaCoeficientes(Aluno* alunos, int n, int ano);
void imprimeAlunos(Aluno* alunos, int n);
void imprimeMatriz(int **mat, int lin,int cols, int i);
void cripCesar(char *c, int chave);
Funcionario* alocaFuncionarios(int n);
void calculaSalario(Funcionario* p, int n);
long int pot(int n, int a);
void removeLetra(char *c,char a, int str_len);
long int somaAbaixoDiagonal(int **mat, int n, int i, int j);
long int multDiagonal(int **mat,int n, int i);
void escadaInvertida(int n);
int somaVetor(int *v, int n);
void intercalaVetores(int *v1, int *v2, int *vRes, int n);

#endif