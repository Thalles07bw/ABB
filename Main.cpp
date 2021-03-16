#include<iostream>
#include<cstdlib>
#include "arvore.hpp" //importando arvore binária para utilizar na resolução
using namespace std;

void geradorDeAmostras (int vet[]){//gera a uma amostra pseudo-aleatória para simular o que é pedido no problema
    for (int i = 0; i < 4096; i++){
        vet[i] = 10000 + rand() % 10001;
    }
}
void mostraAmostra (int vet[]){
    for (int i = 0; i < 4096; i++){
        cout<<vet[i]<<'\n'; 
    }
}

//Principal

int main(){
    int vbusca = 0,vet[4096]; //Buscar o valor G = Maior e o Valor P = Menor
    Arvore a = NULL;
    Arvore procurado = NULL;
    geradorDeAmostras(vet);
    mostraAmostra(vet);
    for (int i = 0; i < 4096; i++){
        Insere(a,vet[i],i);
    }
    mostra(a,0);
    cout<<"Digite a chave para a busca:";
    cin>>vbusca;
    procurado = busca(a,vbusca);
    if(procurado != NULL)
        cout<<endl<<vet[procurado->Posicao]<<" -> Encontrado na posição: "<<procurado->Posicao<<endl;
    else 
        cout<<"Nao foi possivel encontrar a key"<<endl;
    return 0;
}

