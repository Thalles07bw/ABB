#include<iostream>
#include "arvore.hpp"
using namespace std;



//Lista de Funções
void Insere (Arvore& a, int c,int i) {//Função recursiva, cada nó pode ser considerado uma sub-arvore e ser a raiz de uma nova sub-arvore
    if (a == NULL) {//Se é nulo cria-se um novo nó raiz
        a = new No;
        a->Item = c;
        a->Posicao = i;
        a->Dir = NULL;
        a->Esq = NULL;
    }
    else if (c > a->Item)//Item a ser inserido é maior do que a raiz da sub-arvore anterior(fica a direita)
        Insere (a->Dir, c,i);
    else//Item a ser inserido é menor do que a raiz da sub-arvore anterior(fica a esquerda)
        Insere (a->Esq, c, i);
}
void ordem (Arvore& a) { // CAMINHAMENTO EM ORDEM
    if (a!=NULL) {
    ordem (a->Esq);
    cout << a->Item << " " ;
    ordem (a->Dir);
    }
}
void mostra (Arvore& a, int n) { //Função exclisiva para imprimir a arvore
    if (a) {
        int i=0;
        mostra (a->Dir, n+1);
        while( i < n){
            cout << " ";
            i++;
        }
        cout << a->Item << endl;
        mostra (a->Esq, n+1);
    }
}
void Pre (Arvore& a) { // CAMINHAMENTO EM PRE-ORDEM
    if (a!=NULL) {
        cout << a->Item << " " ;
        Pre (a->Esq);
        Pre (a->Dir);
    }
}
void Pos (Arvore& a) { // CAMINHAMENTO EM POS-ORDEM
    if (a!=NULL) {
        Pre (a->Esq);
        Pre (a->Dir);
        cout << a->Item << " " ;
    }
}
bool Grau(Arvore& a, int elemento){ // Grau do elemento é determinado pela quantidade de nós filhos que o mesmo possui
    if(a == NULL){
        return false;
    }
    if(elemento == a->Item){
        if(a->Esq!=NULL&&a->Dir!=NULL){
            cout<<a->Item<<" grau 2 ";
        }else if(a->Esq==NULL&&a->Dir==NULL){
            cout<<a->Item<<" grau 0 ";
        }else
            cout<<a->Item<<" grau 1 ";
            if(elemento < a->Item)
                Grau(a->Esq,elemento);
            else
                Grau(a->Dir,elemento);
     return true;
    }
    else{//Caminho recursivo para achar o elemento
        if(a->Item<elemento)
            Grau(a->Dir,elemento);
        else{
            Grau(a->Esq,elemento);
        }
    }
}
void Notacao (Arvore a) { // CAMINHAMENTO EM PRE-ORDEM PARA GERAR A NOTAÇÃO
    if (a!=NULL) {
        cout << a->Item;
        Notacao(a->Esq);
        Notacao(a->Dir);
    }else{
        cout <<".";
    }
}

Arvore busca (Arvore r, int x) {
    Arvore q;
    q = r; /* inicia q com a raiz */
    
    /* procura na ABB */
    if (q == NULL || q->Item == x)//Se não for encontrado retorna NULL e se for retorna o Nó com as informações
       return q;
    if (q->Item > x)//Se o item atual for maior que o que está sendo buscado, vai para o Nó a esquerda
       return busca ((*q).Esq, x);
    else//Se o item atual for menor que o que está sendo buscado, vai para o Nó a direita
       return busca ((*q).Dir, x);
}


bool Remove(Arvore *a){
    Arvore pai, filho;
    /* se *a é NULL nada a fazer */
    if (*a == NULL) return false;
    pai = *a;
    if ((pai->Dir) == NULL) {
        /* muda o pai e libera */
        *a = pai->Esq;
        delete pai;
        return true;
    }else if (pai->Esq == NULL) {
        /* muda pai e libera */
        *a = pai->Dir;
        delete pai;
    }else{/* um para esquerda e tudo à direita */
    a = &(pai->Esq);
    /* procura primeiro dprox NULL */
    while ((*a)->Dir != NULL)
        a = &((*a)->Dir);
        /* achamos o substituto */
        filho = *a;
        /* altera ponteiro do pai de q */
        *a = filho->Esq;
        /* move as info */
        pai->Item = filho->Item;
        delete filho; // libera o tal nó
        return true;
    }
}
