#include <stdio.h>

#include "sort.h"

int main() {
    Analise a;
    int n = 10;
    Item itens[] = {
        (Item){10, "ze"},
        (Item){3, "jose"},
        (Item){4, "daiane"},
        (Item){5, "joao"},
        (Item){8, "link"},
        (Item){1, "pedro"},
        (Item){9, "park"},
        (Item){7, "ze"},
        (Item){2, "maria"},
        (Item){6, "karla"}
    };

    // BubbleSort(itens, n, &a);
    // BubbleSortMod(itens, n, &a);
    // SelectionSort(itens, n, &a);
    // SelectionSortMod(itens, n, &a);
    InsertionSort(itens, n, &a);

    for (int i=0;i<n;i++) {
        ItemImprime(itens[i]);
        printf("\n");
    }

    printf("\nAnalise (comp = %d|mov = %d)\n", a.comp, a.mov);
    return 0;
}
