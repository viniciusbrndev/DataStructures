#include "busca.h"
#include "item.h"




int PesquisaBinariaRec(Item *itens, int esq, int dir, Item chave){
    if(esq < dir){
        int meio = esq + dir / 2;
        if(ItemCompara(itens[meio], chave) == MAIOR)
            PesquisaBinariaRec(itens, meio+1,dir, chave);
        else if(ItemCompara(itens[meio], chave) == MENOR)
            pesquisaBinaria(itens, esq, meio-1, chave);
        
        return meio;
    }
    return -1;
}