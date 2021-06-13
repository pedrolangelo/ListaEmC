#include <iostream>
using namespace std;

struct no {
    int valor;
    struct no *prox;
    struct no *ant;
};


typedef struct no * noPtr;

void inserir (noPtr *inicio){
    noPtr p = new no;
    noPtr aux = * inicio;

    if (aux == NULL){
        p->ant = aux;
        p->prox = aux;
        *inicio = p;
    }else {
        aux->ant = p;
        p->prox = aux;
        *inicio = p;
        p->ant = NULL;
    }

    cout << "Digite um valor:" << endl;
    cin >> p->valor;
}

void mostrarLista (noPtr inicio){
    noPtr p=inicio;

    cout << "Essa lista contem os valores:" << endl;

    do {
            cout << p->valor <<endl;
            p=p->prox;
    }while (p!=NULL);
}

int soma (noPtr inicio1, noPtr inicio2){
    int  soma=0;
    noPtr p=inicio1;
    if (p!=NULL){
        do{
        soma+=p->valor;
        p=p->prox;
    }while (p!=NULL);
    }

p=inicio2;

    if (p!=NULL){
        do{
            soma+=p->valor;
            p=p->prox;
        }while (p!=NULL);
    }

return soma;
}

void maior (noPtr inicio1, noPtr inicio2){
    noPtr p=inicio1;
    int aux1=0, aux2=0;

    if (p!=NULL){
        do{
            aux1+=p->valor;
            p=p->prox;
        }while(p!=NULL);
    }

    p=inicio2;

    if (p!=NULL){
        do{
            aux2+=p->valor;
            p=p->prox;
        }while (p!=NULL);
    }

    if (aux1>aux2){
        cout << "A primeira lista é maior";
    }else if (aux2>aux1){
        cout << "A segunda lista é maior";
    }else cout << "As listas tem o mesmo tamanho";
}

int main (){
    int a=0;

    noPtr lista1 = NULL;
    noPtr lista2 = NULL;

do {
    cout << "Qual lista deseja alterar?" << endl;
    cout << "1) Lista Um | 2) Lista Dois | 0)Fim do programa" << endl;
    cin >> a;

    if (a==1){
        inserir (&lista1);
        mostrarLista (lista1);
    }else if (a==2){
        inserir (&lista2);
        mostrarLista (lista2);
    }
}while (a!=0);

cout << "A soma das listas da: " << soma (lista1, lista2) << endl;
maior (lista1, lista2);

return 0;
}