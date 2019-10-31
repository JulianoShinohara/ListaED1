typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tamVetor;
    int qtde; //topo
}Pilha;

Pilha* pilha_criar(){
    Pilha* p;

    p = (Pilha*) malloc (sizeof(Pilha));
    p->tamVetor = 4;
    p->vetor = (Tipo*) calloc (4, sizeof(Tipo));
    p->qtde = 0;

return p;
}


void pilha_desalocar(Pilha* p){
    while(p->qtde != 0){

    p->vetor[ p->qtde ] = NULL;
    p->qtde--;   
    }
}

int pilha_push(Pilha* p, Tipo elemento){
    Tipo* novo;

    if(p->tamVetor <= p->qtde){
        p->vetor[ p->qtde ] = elemento;
    }
    else{
        novo = (Tipo*) calloc ((2*p->tamVetor), sizeof(Tipo));
        for(int i=0; i< p->tamVetor; i++){
            novo[i] = p->vetor[i];
        }
    int novoTam = 2*p->tamVetor;
        p->tamVetor = novoTam;
        p->vetor[ p->qtde ] = elemento;

    }
    p->qtde++;
return elemento;
}

//retornar o valor que foi retirado da pilha
Tipo* pilha_pop1(Pilha* p){
    int retirado;
    //Precisa atribuir o valor onde ele estava como NULL?
    retirado = p->vetor [ p->qtde ];
    p->qtde--;

return retirado;    
}

int pilha_pop2(Pilha* p, Tipo* endereco){
    int retirado;
    int pos;

    pos = (p->vetor) - (endereco);
    pos = pos/4;

    retirado = *endereco;
    if( p->qtde == pos+1 ){
        p->vetor[pos] = NULL;
    }
    else{
        p->qtde--;
        for(int i=pos+1; i< p->qtde; i++){
            p->vetor[i-1] = p->vetor[i];
        }
    }
    p->qtde--;

return retirado;
}

//O que é para fazer?
//int pilha_topo(Pilha* p, Tipo* endereco);

int pilha_tamanho(Pilha* p){
    return p->qtde;
}

//void pilha_imprimir(Pilha* p, void (*printElemento)(void*));