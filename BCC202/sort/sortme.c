#include "sort.h"
#include "item.h"

void trocaItem(Item *I1, Item *I2){
    Item aux = *I1;
    *I1 = *I2;
    *I2 = aux;
}
void SelectionSort(Item *v, int n, Analise *a){
    if(!v|| n < 0 || !a )
        return;
    *a = (Analise){0, 0};
    int i, j , menor;
        for(i = 0; i < n; i++){
            menor = i;
            for(j = i+1; j < n; j++){
                a->comp++;
                if(ItemCompara(v[menor],v[j]) == MAIOR)
                    menor = j;
            }
            trocaItem(&v[menor], &v[i]);
            a->mov++;
        }
}
void InsertionSort(Item *v, int n, Analise *a){
    if(!v || !a || n <= 0)
        return;
    
    Item chave;
    int i, j;
    for(i = 1; i < n; i++){
        chave = v[i];
        j= i-1;
        while(j >= 0 && ItemCompara(chave, v[j]) == MAIOR){
            a->comp++;
            v[j+1] = v[j];
            a->mov++;
            j--;
        }
        v[j+1] = chave;
        a->mov++;
    }
}
