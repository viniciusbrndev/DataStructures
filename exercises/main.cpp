#include "Pagina.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#define MAX_PAGINAS 10


using namespace std;

int main(){
    int key;
    Pagina pag;
    fstream arq("arquivos.bin", ios::in);
    int v[MAX_PAGINAS];
    if(!arq.open()){
        cout<<"ARQUIVO NÃO PODE SER ABERTO"<<endl;
        return 1;
    }
    int i = 0;
    while(i < MAX_PAGINAS || !arq.eof()){
        arq.read(reinterpret_cast<char>(v[i]), sizeof(int));
        arq.seekg(sizeof(Item)*(ITENSPAG) -sizeof(int), ios::cur);
        i++;
    }
    cout<<"Digite a chave desejada: "<<endl;
    cin<<key;
    if(key < v[0]){
        cout<<"Chave não existe no arquivo!"<<endl;
        arq.close();
        return 1;
    }
    i = 0;
    while (i < MAX_PAGINAS && v[i] <= key){
        if(key < v[i+1])
            break;
        i++;
    }
    pag.lePagina(arq, i);
    Item x = pag.buscarItemLocal(key);


}