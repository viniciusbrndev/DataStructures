#include <stdio.h>
#include "regiao.h"
#include <stdlib.h>



int main(){
    int tam = 0;
    int x1, y1, x2, y2;
    Regiao *vetor;

    scanf("%d", &tam);
    vetor = malloc(sizeof(Regiao)*tam);
    //ler os valores das posições
    int test;
    for(int i = 0; i < tam; i++){
        //alocando as posições
        vetor[i] = alocaRetangulo();

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 >= x2 || y1 <= y2){
            printf("\nnenhum\n");
            return 0;
        }
        test = setRetangulo(vetor[i],x1, y1, x2, y2 );
        if(!test){
            printf("\nnenhum\n");
            return 0; 
        }
    
    }
    getRetangulo(vetor[0], &x1,&y1,&x2,&y2);
    int flag = 1;
    for(int i = 1; i < tam; i++){
        flag = verificaInter(vetor[i],&x1, &y1, &x2, &y2);
        if(!flag){
            printf("\nnenhum\n");
            break;
        }
    }
    if(flag)
        printf("\n%d %d %d %d\n", x1, y1, x2, y2);
    printf("\n");
    
    //libera a memória usada
    for(int i = 0; i < tam; i++){
        destroiRegiao(vetor[i]);
    }
    free(vetor);

    return 0;
}