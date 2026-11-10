#include "pratica.h"
#include "pratica2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct time{
    Jogador **player;
    int nPlayers;
    char nomeTime[20];
    char conf;
};
struct aluno{
    char nome[20];
    float coe;
    int ano;
    int mat;
};
struct funcionario{
    char nome[50];
    int mat;
    float horas;
    float salario;
    int nDep;
};
struct carro{
    Rodas *rodas;
    char nome[20];
    int cor;
    int nRodas;
};

float maiorElemento(int i, float* v){
    if(i == 1)
        return v[0];
    float max = maiorElemento(i-1, &v[1]);
    if(v[0] > max){
        max = v[0];
    }
    return max;
}
int inverteInt(int n){
    int soma = 0;
    if(n < 1)
        return n;
    soma = (soma*10) + inverteInt(n%10);
    return soma;
}
int potenciaDeN(int k, int n){
    if(n == 0)
        return 1;
    return k* potenciaDeN(k, n-1);
}
void inverteVetor(float *v, int inicio, int fim){
    if(inicio >= fim)
        return;

    float temp = v[inicio];
    v[inicio] = v[fim];
    v[fim] = temp;
    inverteVetor(v, inicio+1, fim-1);
}
void inverteVetor2(float *v, int i, int tam){
    if(i >= tam/2)
        return;
        
    float temp = v[i];
    v[i] = v[tam-i-1];
    v[tam-i-1] = temp;
    inverteVetor2(v, i+1, tam);
}

Time* alocaTimes(int *v, int num_times){
    if(!v || num_times <= 0)
        return NULL;
    Time *p = (Time*)malloc(sizeof(Time) * num_times);
    if(!p)
        return NULL;
    for(int i = 0; i < num_times; i++){
        p[i].nPlayers = v[i];
        p[i].player = (Jogador**)malloc(sizeof(Jogador*)*v[i]);
        if(!p[i].player){
            for(int a = 0; a < i; a++){
                free(p[a].player);
            }
            free(p);
            return NULL;
        }
        for(int j = 0; j < p[i].nPlayers; j++){
            p[i].player[j] = alocaJogador();
        }
    }
    return p;
}
void desalocaTime(Time **p, int num_times){
    if(!p|| num_times <= 0)
        return;
    for(int i = 0; i < num_times; i++){
        for(int j = 0; j < (*p)[i].nPlayers; j++)
            desalocaJoogador((*p)[i].player[j]);
        free((*p)[i].player);
    }
    free(*p);
    *p = NULL;
}
void imprime(Time* p){
    if(!p)
        return;
    printf("\nNome do time: %s", p->nomeTime);
    print("\nNum de jogadores; %d", p->nPlayers);
    printf("\nJOGADORES TITULARES:\n");
    for(int i = 0; i < p->nPlayers; i++){
        imprimeTitular(p->player[i]);
    }
}
int quantidadeDeTimes(Time* times, char *conferencia, int n, int x, int tam){
    int cont = 0;
    if(!times || !conferencia || n <= 0 || x <= 0)
        return -1;
    for(int i = 0; i < tam; i++)
        if(times[i].conf == *conferencia)
            if(times[i].nPlayers > n)
                for(int j = 0; j < times[i].nPlayers; j++)
                    if(idadeJogador(times[i].player[j]) > x){
                        cont++;
                        break;
                    }
                
            
        
    return cont;
}
void imprimeVetor(int *v, int n){
    if(n == 0)
        return;
    printf("%d ", v[0]);
    imprimeVetor(v + 1, n -1);
}
void imprimeImpar(int *v, int n){
    if(n == 0)
        return;
    if((v[0] % 2))
        printf("%d ", v[0]);
    imprimeImpar(v +1, n -1);
}
void printTree(int n){
    if(n == 0)
        return;
    printTree(n -1);
    for(int i = 0; i < n; i++){
        printf("* ");
    }
    printf("\n");
}
Aluno* criaAlunos(char *nomes,int *matriculas, float *coeficientes,int *anos, int n){
    if(n <= 0)
        return NULL;
    Aluno* p = (Aluno*)malloc(sizeof(Aluno)*n);
    if(!p)
        return NULL;
    char *token = strtok(nomes, " ");
    for(int i = 0; i < n; i++){
        p[i].ano = anos[i];
        p[i].coe = coeficientes[i];
        p[i].mat = matriculas[i];
        strcpy(p[i].nome, token);
        token = strtok(NULL, " ");
    }
    return p;
}
Aluno* destroiAluno(Aluno* alunos, int n){
    if(alunos)
        free(alunos);
    return NULL;
}
float mediaCoeficientes(Aluno* alunos, int n, int ano){
    if(alunos && n && ano){
        int cont =0;
        float soma = 0;
        for(int i = 0; i < n; i++){
            if(alunos[i].ano <= ano){
                soma += alunos[i].coe;
                cont++;
            }
        }
        return soma / cont;
    }
    return -1;//código de erro
}
void imprimeAlunos(Aluno* alunos, int n){
    if(n == 0 || !alunos)
        return;
    if(!(alunos[0].mat % 2)){
        printf("\n%s", alunos[0].nome);
    }
    imprimeAlunos(alunos +1, n -1);
}
void imprimeMatriz(int **mat, int lin,int cols, int i){
    if(i >= lin)
        return;
    for(int j = 0; j < cols; j++){
        printf("%d ", mat[i][j]);
    }
    printf("\n");
    imprimeMatriz(mat, lin, cols, i+1);
}

void cripCesar(char *c, int chave){
    if(c[0] == '\0')
        return;
    if(c[0] +chave >= 'z')
        c[0] = 'a'+chave;
    else
        c[0] = c[0] +chave;
    cripCesar(c+1, chave);
}

Funcionario* alocaFuncionarios(int n){
    if(n){
        Funcionario* p = (Funcionario*)malloc(sizeof(Funcionario)*n);
        if(p)
            return p;
    }
    return NULL;
}
void calculaSalario(Funcionario* p, int n){
    if(p && n){
        for(int i = 0; i < n; i++){
            p[i].salario = ((p[i].horas *12) +(40 * p[i].nDep)) *0,865;
            printf("\nNome: %s, Salário: %f", p[i].nome,p[i].salario);
        }
    }
}
long int pot(int n, int a){
    if(n == 1)
        return 1;
    return a * pot(n -1, a);
}
void removeLetra(char *c,char a, int str_len){
    if(str_len < 0)
        return;
    if(c[str_len-1] == 'a')
        c[str_len-1] = ' ';
    removeLetra(c, a, str_len-1);
}
long int somaAbaixoDiagonal(int **mat, int n, int i, int j){
    if(i == n)
        return 0;
    if(j == i)
        return somaAbaixoDiagonal(mat, n, i+1, 0);
    return mat[i][j] + somaAbaixoDiagonal(mat, n, i,j+1);
}
long int multDiagonal(int **mat,int n, int i){
    if(i == n)
        return 1;
    if(mat[i][i] == 0)
        return multDiagonal(mat, n, i+1);
    return mat[i][i] * multDiagonal(mat, n, i+1);
    }
void escadaInvertida(int n){
    if(n == 0)
        return;
    for(int j = n; j > 0; j--){
        printf("%d ", j);
    }
    printf("\n");
    escadaInvertida(n-1);
}
int somaVetor(int *v, int n){
    if(n == 0)
        return 0;
    return v[0] + somaVetor(v+1, n-1);
}
void intercalaVetores(int *v1, int *v2, int *vRes, int n){
    if(n == 0)
        return;
    vRes[0] = v1[0];
    vRes[1] = v2[0];
    intercalaVetores(v1+1, v2+1, vRes+2, n-1);

}
Carro* alocaCarro(int qtdRodas){
    Carro *p = (Carro*)malloc(sizeof(Carro));
    if(p){
        p->nRodas = qtdRodas;
        p->rodas = alocaRodas(qtdRodas);
        if(!p->rodas){
            free(p);
            return NULL;
        }
        return p;
    }
    return NULL;
}
void desalocaCarro(Carro **carro){
    if(!carro)
        return;
    desalocaRodas(&(*carro)->rodas);
    free(*carro);
    *carro = NULL;
}
void imprimeRodas(Carro* c){
    char nome[30];
    int psi;
    for(int i = 0; i < c->nRodas; i++){
        getRoda(&c->rodas[i], nome, &psi);
        printf("Marca roda %d: %s Pressão: %d\n",i+1, nome, psi);
    }   
}
int quantidadeRodas(Carro* car, char c){
    int cont = 0;
    int temp;
    char nome[30];
    for(int i =0; i < car->nRodas; i++){
        getRoda(&car->rodas[i],nome, &temp);
        if(nome[0] == c)
            cont++;
    }

}
void triangulo(int n){
    if(n == 0)
        return;
    triangulo(n-1);
    for(int i = 0; i < n; i++){
        printf("* ");
    }
    printf("\n");
}
void trianguloInverso(int n){
    if(n == 0)
        return;
    for(int i = 0; i < n; i++){
        printf("* ");
    }
    printf("\n");
    trianguloInverso(n-1);
}