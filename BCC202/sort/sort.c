#include "sort.h"
#include <stdbool.h>

void troca(Item* p1, Item *p2) {
    Item aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void BubbleSort(Item *v, int n, Analise *a) {
    if (!v || !a) return;
    *a = (Analise) {0, 0};
    int i, j;
    for (i=0;i<n-1;i++) {
        for (j=1;j<n-i;j++) {
            a->comp++;
            if (ItemCompara(v[j-1], v[j]) == MAIOR) {
                troca(&v[j-1], &v[j]);
                a->mov++;
            }
        }
    }
}

void BubbleSortMod(Item *v, int n, Analise *a) {
    if (!v || !a) return;
    *a = (Analise) {0, 0};
    int i, j;
    bool trocou;
    for (i=0;i<n-1;i++) {
        trocou = false;
        for (j=1;j<n-i;j++) {
            a->comp++;
            if (ItemCompara(v[j-1], v[j]) == MAIOR) {
                troca(&v[j-1], &v[j]);
                trocou = true;
                a->mov++;
            }
        }
        if (!trocou)
            break;
    }
}

void SelectionSort(Item *v, int n, Analise *a) {
    if (!v || !a) return;
    *a = (Analise) {0, 0};
    int i, j;
    int menor;
    for (i=0;i<n-1;i++) {
        menor = i;
        for (j=i+1;j<n;j++) {
            a->comp++;
            if (ItemCompara(v[menor], v[j]) == MAIOR)
                menor = j;
        }
        troca(&v[i], &v[menor]);
        a->mov++;
    }
}

void SelectionSortMod(Item *v, int n, Analise *a) {
    if (!v || !a) return;
    *a = (Analise) {0, 0};
    int i, j;
    int menor;
    for (i=0;i<n-1;i++) {
        menor = i;
        for (j=i+1;j<n;j++) {
            a->comp++;
            if (ItemCompara(v[menor], v[j]) == MAIOR)
                menor = j;
        }
        if (menor != i) {
            troca(&v[i], &v[menor]);
            a->mov++;
        }
    }
}

void InsertionSort(Item *v, int n, Analise *a) {
    if (!v || !a) return;
    *a = (Analise) {0, 0};
    int i, j;
    Item aux;
    for (i=1;i<n;i++) {
        aux = v[i];
        j = i - 1;
        a->comp++;
        while (j >= 0 && ItemCompara(v[j], aux) == MAIOR) {
            a->comp++;
            v[j+1] = v[j]; 
            j--;
            a->mov++;
        }
        a->mov++;
        v[j+1] = aux; 
    }
}

//HEAP
void HeapRefaz(Item *v, int dir, int esq){
    Item aux = v[esq];
    int i = esq; // pai
    int j = 2 * i +1; // filho da esquerda

    while(j <= dir){ //tem filho na esquerda
        if(j < dir) // tem filhos na direita
            if(ItemCompara(v[j +1], v[j]) == MAIOR)
                j++;
        //se o pai tem mais prioridade para
        if(ItemCompara(v[j], aux) == MENOR)
            break;

        v[i] = v[j];
        i = j;
        j = 2 * i +1;
    }
    v[i] = aux;
}
void HeapConstroi(Item *v, int n){
    int esq = (n / 2) -1;
    while(esq >= 0){
        HeapRefaz(v, n-1, esq);
        esq--;
    }
}
void HeapSort(){}
