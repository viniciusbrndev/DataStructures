#include "aluno.h"




int main(){
    Lista *pLista = criaLista();
    if(!pLista)
        return 0;
    preencheAmigos(pLista);
    for(int i = 0; i < listaTamanho(pLista); i++)
        preencheSubAmigos(pLista);
    

}
