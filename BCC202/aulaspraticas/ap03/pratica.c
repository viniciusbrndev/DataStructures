#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>



int main(void){
    int nTestes,nItens, tamMochila;
    int* maiorLucro;
    int* totalCasos;
    
    scanf("%d", &nTestes);
    if(nTestes <= 0)
        return 0;
    maiorLucro = (int*)malloc(sizeof(int)*nTestes);
    totalCasos = (int*)malloc(sizeof(int)*nTestes);

    
    Mochila *bag;
    if(!maiorLucro || !totalCasos)
        return 0;
    for(int i = 0; i < nTestes; i++){
        scanf("%d %d", &nItens, &tamMochila);
        //monta a mochila a cada iteração
        bag = montaMochila(nItens, tamMochila);
        if(!bag)
            return 0;
        setItens(bag);//lê os pesos e valores dos itens
        analisaMochila(bag, 0, 0, 0);
        //salva os valores em vetores
        getLucro(bag, &maiorLucro[i]);
        getNcaso(bag, &totalCasos[i]);
        //libera a mochila a cada iteração
        destroiMochila(bag);
    }
    for(int i = 0; i < nTestes; i++){
        printf("Teste %d\n", i+1);
        printf("%d %d", maiorLucro[i], totalCasos[i]);
        printf("\n\n");
    }
    

    free(maiorLucro);
    free(totalCasos);

    return 0;
}