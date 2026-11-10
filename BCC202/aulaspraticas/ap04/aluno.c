#include "aluno.h"




typedef struct no{
    char nome[50];
    struct no *prox;
};

typedef struct amigo{
    char nome[50];
    No* listaDeAmigos;
    No* ultimo;
    struct amigo *prox;

};

struct lista{
    char usuario[50];
    int nAmigos;

    Amigo *cab;
    Amigo *fim;
};

Lista* criaLista(){
    Lista *pLista = malloc(sizeof(Lista));
    if(pLista){
        pLista->cab = malloc(sizeof(Amigo));
        if(!pLista->cab){
            free(pLista);
            pLista = NULL;
        }
        pLista->nAmigos = 0;
        pLista->cab->listaDeAmigos = NULL;
        pLista->cab->ultimo = NULL;
        pLista->cab->prox = NULL;

        pLista->fim = pLista->cab;
    }
    else
        pLista = NULL;
    
    return pLista;
}
bool insereAmigo(Lista *pLista, char *nome){
    if(!pLista || !nome)
        return false;
    Amigo *novo = malloc(sizeof(Amigo));
    if(novo){
        strcpy(novo->nome, nome);

        novo->listaDeAmigos = NULL;
        novo->ultimo;
        pLista->fim->prox = novo;
        pLista->fim = novo;
        pLista->nAmigos++;
        return true;
    }
    return false;
}
bool insereAmigoDoAmigo(Amigo *pAmigo, char *nome){
    if(!pAmigo || !nome)
        return false;
    No* novo = (No*)malloc(sizeof(No));
    if(novo){
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        if(!pAmigo->listaDeAmigos)
            pAmigo->listaDeAmigos = novo;
        else
            pAmigo->ultimo->prox = novo;
        pAmigo->ultimo = novo;
        pAmigo->ultimo->prox = NULL;
        return true;
    }
    return false;
}
Amigo* buscaAmigoLista(Lista* pLista, char *nome){
    if(!pLista || !nome)
        return NULL;
    Amigo *aux = pLista->cab->prox;
    while(aux){
        if(strcmp(aux->nome, nome) == 0)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}
bool preencheAmigos(Lista* pLista){
    if(!pLista)
        return false;
    
    char linha[300];
    fgets(linha, sizeof(linha), stdin);
    char *token = (char*)strtok(linha," ");
    strcpy(pLista->usuario, token);
    while(token){
        token = (char*)strtok(NULL, " ");
        insereAmigo(pLista, token);
    }
    return true;
}
bool preencheSubAmigos(Lista* pLista){
    if(!pLista)
        return false;
    char linha[300];
    fgets(linha, sizeof(linha), stdin);
    char *token = strtok(linha, " ");
    Amigo *a = buscaAmigoLista(pLista, token);
    if(a){
        while(token){
            token = strtok(NULL, " ");
            insereAmigoDoAmigo(a, token);
        }
        return true;
    }
    return false;
}
int listaTamanho(Lista *pLista){
    return pLista->nAmigos;
}
void procuraRecorrencia(Lista *plista, Sugestao* rec){
    Amigo* aux = plista->cab->prox;
    No* subAmigo = aux->listaDeAmigos;
    int cont = 0;
    for(int i = 0; i < listaTamanho(plista); i++){
        if(!strcmp(plista->usuario, aux->nome))
            continue;
        while(subAmigo){
            if(!strcmp(plista->usuario, subAmigo->nome))
                continue;
            for(int j = 0; j <= cont; j++){
                if(!strcmp(subAmigo->nome, rec[j].nome))
                    rec[j].qtRec++;
                // else{
                //     rec = realloc(rec,sizeof(Sugestao)+cont);
                //     strcpy(rec[cont].nome, subAmigo->nome);
                //     rec[cont].qtRec++;
                //     cont++;
                }
            }
            subAmigo = subAmigo->prox;
        }
        aux = aux->prox;
    }
}