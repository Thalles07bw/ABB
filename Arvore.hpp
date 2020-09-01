#include <stdio.h>
#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

//Variavel Para armazenamento de informações e apontar os nós filhos da AB
struct No{
    struct No *Esq;
    int Item;
    int Posicao;
    struct No *Dir;
};

//Declaração do tipo No como sendo um ponteiro para alocar a raiz e demais nós da árvore 
typedef No *Arvore;

//Cabeçalho das funções de Árvore Binária
void Insere(Arvore&,int,int);
void ordem (Arvore&);
void mostra (Arvore&,int );
bool Remove(Arvore*);
void Pre (Arvore&);
void Pos (Arvore&);
bool Grau(Arvore&,int);
void Notacao (Arvore);
Arvore busca(Arvore, int); 

#endif // ARVORE_H_INCLUDED
