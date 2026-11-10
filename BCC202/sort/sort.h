#ifndef SORT_H
#define SORT_H

#include "item.h"

typedef struct {
    int comp, mov;
} Analise;

void BubbleSort(Item *v, int n, Analise *a);
void BubbleSortMod(Item *v, int n, Analise *a);
void SelectionSort(Item *v, int n, Analise *a);
void SelectionSortMod(Item *v, int n, Analise *a);
void InsertionSort(Item *v, int n, Analise *a);

#endif // SORT_H