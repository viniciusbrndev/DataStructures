#include <ostream>
#define MM 4   // Exemplo de constante para páginas internas
#define MM2 4  // Exemplo de constante para páginas folhas

TipoChave Pesquisa(TipoRegistro* x, TipoApontador* Ap);
TipoChave PesquisaSucessor();


typedef long TipoChave;

typedef struct TipoRegistro {
    TipoChave Chave;
    /* outros componentes */

} TipoRegistro;

typedef enum {Interna, Externa} TipoIntExt;

typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina {
    TipoIntExt Pt;
    union {
        struct {
            int ni;
            TipoChave ri[MM];
            TipoApontador pi[MM + 1];
        } U0;
        struct {
            int ne;
            TipoRegistro re[MM2];
        } U1;
    } UU;
} TipoPagina;
//ARVORE B
typedef struct Node* tipoApontador;

typedef struct Node{
    int n;
    TipoRegistro r[MM];
    tipoApontador p[MM +1];
}


TipoChave Pesquisa(TipoRegistro* x, TipoApontador* Ap){
    int i;
    TipoApontador Pag = *Ap;
    if((*Ap)->Pt == Interna){
        i = 1;
        while(Pag->UU.U0.ni > i && Pag->UU.U0.ri[i-1].chave < x->Chave &&)
            i++;
        if(x->Chave < Pag->UU.U0.ri[i-1].chave)
            Pesquisa(x, &Pag->UU.U0.pi[i-1]);
        else
            Pesquisa(x, &Pag->UU.U0.pi[i]);
        return;
    }
    i=1;
    while(Pag->UU.U1.ne > i && Pag->UU.U1.re[i-1].Chave < x->Chave)
        i++;
    if(Pag->UU.U1.ne[i-1] == x->Chave)
        *x = Pag->UU.U1.ne[i-1];
    
    
}
TipoChave PesquisaSucessor(TipoRegistro* x, TipoApontador* Ap){
    int i;
    TipoApontador Pag = *Ap;
    if((*Ap)->Pt == Interna){
        i = 1;
        while(Pag->UU.U0.ni > i && Pag->UU.U0.ri[i-1].chave < x->Chave &&)
            i++;
        if(x->Chave < Pag->UU.U0.ri[i-1].chave)
            Pesquisa(x, &Pag->UU.U0.pi[i-1]);
        else
            Pesquisa(x, &Pag->UU.U0.pi[i]);
        return;
    }
    i=1;
    while(Pag->UU.U1.ne > i && Pag->UU.U1.re[i-1].Chave <= x->Chave)
        i++;
    if(Pag->UU.U1.ne[i-1] > x->Chave)
        *x = Pag->UU.U1.ne[i-1];
}
void imprimeMaiores(TipoRegistro* x, TipoApontador* Ap){
    int i;
    TipoApontador Pag = *Ap;
    if(Pag->Pt == Interna){
        i = 1;
        while(Pag->UU.U0.ni > i && Pag->UU.U0.ri[i-1].chave < x->Chave)
            i++;
        imprimeMaiores(x,&Pag->UU.U0.pi[i]);
        return;
    }
    i = 1;
    while(Pag->UU.U1.ne > i){
        if(Pag->UU.U1.re[i-1].Chave > x->Chave)
            std::cout<<Pag->UU.U1.re[i-1].Chave;
        i++;
    }
}
void Maximo(TipoRegistro* x, TipoApontador* Ap){
    int i = 1;
    TipoApontador Pag = *Ap;
    if((*Ap)->Pt == Interna){
        while(i < Pag->UU.U0.ni &&)i++;
        if(Pag->UU.U0.pi[i] != NULL)
            Maximo(x, Pag->.UU.U0.pi[i]);
        else
            Maximo(x, Pag->.UU.U0.pi[i-1]);
        return;
    }
    *x = Pag->UU.U1.re[Pag->UU.U1.ne -1];
}
int Quantidade(tipoApontador Ap){
    if(!Ap)
        return 0;
    int itensNo = Ap->n;
    for(int i = 0; i < Ap->n; i++){
        itensNo += Quantidade(Ap->p[i]);
    }
    return itensNo;
}
int Sucessor(TipoChave ch, TipoApontador ap, TipoRegistro* x){
    int i;
    if((*ap).Pt == Interna){
        i = 1;
        while(i < (*ap).UU.U0.ni && ch > ap->UU.U0.ri[i-1])i++;
        if( ch < ap->UU.U0.ri[i-1])
            return Sucessor(ch, ap,ap->UU.U0.pi[i-1]);
        else
            return Sucessor(ch, ap, ap->UU.U0.pi[i]);
    }
    i = 1;
    while(i < (*ap).UU.U1.ne && ch > ap->UU.U1.re[i-1].Chave)i++;
    if(ch == ap->UU.U1.re[i-1].Chave){
        if(i < ap->UU.U1.ne){
            *x = ap->UU.U1.re[i].Chave;
            return 1;
        }
        return 0;
    }
    return 0;
}
void Intervalo(tipoApontador no, int min, int max){
    if (no == NULL) return;

    int i = 0;

    // Avança pelas chaves do nó enquanto forem menores que 'min'
    while (i < no->n && min > no->r[i].Chave) {
        i++;
    }

    // Se não for folha, descemos no filho à esquerda da primeira chave potencialmente válida
    if (!ehFolha(no)) {
        imprimirIntervalo(no->p[i], min, max);
    }

    // Processa as chaves do nó que pertencem ao intervalo [min, max]
    while (i < no->n && no->r[i].Chave <= max) {
        if (no->r[i].Chave >= min) {
            printf("%d ", no->r[i].Chave);
        }

        // Se não for folha, descemos no filho à direita da chave atual
        if (!ehFolha(no)) {
            imprimirIntervalo(no->p[i + 1], min, max);
        }

        i++;
    }
}

void BStarIntervalo(TipoApontador Ap, TipoChave min, TipoChave max){
    if(Ap == NULL)
        return;
    int i = 0;
    if(Ap->Pt == Interna){
        while(Ap->UU.U0.ri[i].Chave < min && i < Ap->UU.U0.ni)
            i++;
        if(Ap->UU.U0.ri[i].Chave >= min && Ap->UU.U0.ri[i].Chave < max)
            BStarIntervalo(Ap->UU.U0.pi[i], min, max);
        return;
    }
    int i = 0;
    while(i < Ap->UU.U1.ne){
        if(Ap->UU.U1.re[i].Chave >= min && Ap->UU.U1.re[i].Chave <= max)
            std::cout<<Ap->UU.U1.re[i].Chave;
    }
}