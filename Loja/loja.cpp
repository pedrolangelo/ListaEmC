#include <iostream>
using namespace std;

int codigo=0;
double totalDoConsumo=0;

struct  produto{
    int codP;
    double valor;
    struct   produto *proxProduto; 
};

typedef  produto * produtoPtr;

struct cliente {
    int codC;
    struct  produto *produto;
    struct cliente * proxC;
};

typedef cliente* clientePtr;

clientePtr inicio = NULL;
clientePtr fim = NULL;

void inserir (){
codigo++;
clientePtr p = new cliente;

p->produto=NULL;

    if (inicio==NULL){
        inicio = p;
        p ->proxC = fim;
        fim = p;
    }else {
        p->proxC = fim ->proxC;
        fim->proxC = p;
        fim = p;
    }

    p->codC = codigo;
    cout << " Cliente cadastrado. "<<endl;
}

void mostrarClientes (){
clientePtr p;
    if (inicio == NULL){
        cout << " Nenhum cliente cadastrado "<< endl;
    }else {
        p=inicio;
        while (p!=NULL){
            cout << "----------------------------"<<endl;
            cout << p->codC<< endl;
            p=p->proxC;
        }
    }
}

clientePtr acharCliente(int x){
clientePtr p=inicio;

    if (inicio == NULL){
        cout << " Nenhum cliente cadastrado "<< endl;
    }else {
        do {
            if (p->codC==x){
                return p;
            }else {
                if (p==NULL) cout << " Nenhum não encontrado "<< endl;
                else p=p->proxC;
            }
        }while(p!=NULL);
    }
    return NULL;
}

void inserirProduto(){
int x;
clientePtr p;
 produtoPtr pConsumo = new  produto;

    cout << "----------------------------"<<endl;
    cout << " Qual codigo do cliente? "<<endl;
    cin >>x;

    p=acharCliente(x);

    if (inicio==NULL){
        cout<<"Nenhum cliente cadastrado"<<endl;
    }else if(p==NULL){
        cout<<"Esse cliente ainda não foi cadastrado"<<endl;
    }else{
        cout << "----------------------------"<<endl;
        cout << "Qual produto o cliente quer?"<<endl;

        do {
            cout << "---------------------------------------------------------------" <<endl;
            cout << "|101) Hamburguer "<< "   102) refeição    |"<<endl;
            cout << "|103) Refrigerante "<< " 104) Batata frita|" << endl;
            cout << "|105) Combo "<< endl;
            cout << "---------------------------------------------------------------"<<endl;
            cin >> pConsumo->codP;
            
            switch (pConsumo->codP){
                case 101:
                    pConsumo->valor=10.90;
                    break;
                case 102:
                    pConsumo->valor=19.90;
                    break;
                case 103:
                    pConsumo->valor=7;
                    break;
                case 104:
                    pConsumo->valor=15.50;
                    break;
                case 105:
                    pConsumo->valor=30;
                    break;
                default:
                    cout<<"Nenhum produto encontrado"<< endl;
                    pConsumo->codP = 0;
            }
        }while (pConsumo->codP==0);
        totalDoConsumo = totalDoConsumo + pConsumo->valor;
        pConsumo->proxProduto=p->produto;
        p->produto=pConsumo;
        cout << "produto cadastrado"<<endl;
    }
}


void produtoCliente (){
int x;
clientePtr p;
produtoPtr pConsumo;

   cout<<"Qual codigo do cliente? "<<endl;
   cin>>x;

   p = acharCliente(x);

   if (p==NULL){
       cout<<"cliente não encontrado"<<endl;
   }else {
    pConsumo = p->produto;
       do {
           cout << "Produto: "<< pConsumo->codP << " R$" << pConsumo->valor<<endl;
           pConsumo=pConsumo->proxProduto;
       }while(pConsumo!=NULL);
   }

}

void apagarCliente(int x){
clientePtr aux = inicio->proxC, p = acharCliente(x);

if (p==inicio){
    inicio = p->proxC;
    delete(p);
}else {
    do{
        if (aux->proxC==p){
            fim=aux;
            aux->proxC = p->proxC;
            delete(p);
        }else aux=aux->proxC;
    }while(fim!=aux);
}

}

void fecharConta(){
int x;
double conta=0;

clientePtr p;
produtoPtr pConsumo;


cout<<"Qual codigo do cliente? "<< endl;
cin>>x;

p=acharCliente(x);

    if (p==NULL){
        cout << "Cliente não encontrado "<< endl;
    }else if (p->produto==NULL) {
        cout << "Cliente não consumiu nada "<< endl;
        apagarCliente(x);
    }else {
        pConsumo = p->produto;
        do{
            conta += pConsumo->valor;
            pConsumo = pConsumo -> proxProduto;
        }while(pConsumo!=NULL);
        cout << "Total a pagar: R$" << conta << endl;
        apagarCliente(x);
    }

}

void fecharLoja (){
    cout << "Valor recebido no dia: R$"<< totalDoConsumo<<endl;
}

int main(){
int a;

    do {
        cout << endl << "---------------------------------------------------------------" <<endl;
        cout << "|1) Cadastrar cliente "<< "       2) Mostrar codigos dos clientes |"<<endl;
        cout << "|3) Inserir produto "<< "         4) Mostrar produtos do cliente x|" << endl;
        cout << "|5) Fechar conta do cliente "<< " 6) Fechar                       |" << endl;
        cout << "---------------------------------------------------------------"<<endl;
        cin >> a;

        switch (a){
            case 1:
                inserir();
                break;
            case 2:
                mostrarClientes ();
                break;
            case 3:
                inserirProduto();
                break;
            case 4:
                produtoCliente();
                break;
            case 5:
                fecharConta();
                break;
            case 6:
                fecharLoja();
                break;
        }

    }while (a!=6);
return 0;
}