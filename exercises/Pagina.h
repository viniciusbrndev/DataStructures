#ifndef PAGINA_H
#define PAGINA_H

#include <iostream>
#include <cstring>
#include <cstdint>
#include <fstream>

#define ITENSPAG 5

// Estrutura do Item (Dado do arquivo)
typedef struct typeItem {
    int chave;          // Chave primária (usada na busca binária)
    char titulo[31]; 
    float preco;
} Item;

// Estrutura da Moldura (Cabeçalho da Página)
typedef struct typeMoldura {
    int idPagina;            // ID ou número da página no arquivo
    int quantidadeRegistros; // Quantos itens válidos estão guardados nesta página
    int chaveAncora;         // Primeira chave da página (menor chave)
} Moldura;

class Pagina {
    Item itens[ITENSPAG];    // Os registros guardados na página
    int n;

    public:
        Pagina();
        ~Pagina();
        bool lePagina(fstream&, int) const;
        Item buscarItemLocal(int) const;
};

#endif