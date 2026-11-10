#include "Pagina.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool Pagina::lePagina(fstream& file, int pos){
    if(!file.is_open())
        return false;
    file.seekg(sizeof(Item)*ITENSPAG*pos);
    file.read(reinterpret_cast<char*>(this->itens), sizeof(Item)*ITENSPAG);
    streamsize size = file.gcount() / sizeof(Item);
    this->n = size;
}
Item Pagina::buscarItemLocal(int key){
    int i = 0;
    while(i < this->n){
        if(this->itens[i].chave == key)
            return itens[i];
        i++;
    }
    return NULL;
}