typedef int T;

typedef struct
{
    T *vetor;
    int* primeiro;
    int* ultimo;
    int tamanhoVet;
} Fila;

//Fazendo com ponteiro

Fila *fila_criar()
{
    Fila *f;

    f = (Fila *)malloc(sizeof(Fila));
    f->tamanhoVet = 6;
    f->vetor = (T*)calloc(f->tamanhoVet, sizeof(T));
    f->primeiro = (int*) malloc (sizeof(int));
    f->ultimo = (int*) malloc (sizeof(int));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

void fila_desalocar(Fila *f);

int fila_inserir(Fila *f, T elemento){
    if(((f->vetor)+4) == vetor->primeiro){
        return 1358264;
    }

    if(((f->ultimo) == &f->vetor[5]){
        f->ultimo = f->vetor;
        if((f->ultimo) == vetor->primeiro){
        return 1358264;
        }
        else{
            *(f->ultimo) =
        }
    }

    if(f->primeiro == NULL){
        *((f->vetor)+4) = elemento;
        f->primeiro = ((f->vetor)+4);
        f->ultimo = ((f->vetor)+4);
        return elemento;
    }
    else{
        *((f->ultimo)+4) = elemento;
        return elemento;
    }
}

T *fila_remover1(Fila *f){
    T* removido;

    removido = (T*) malloc (sizeof(T));
    removido = f->primeiro;
    (f->primeiro)+sizeof(int);

    return removido;

}

int fila_remover2(Fila *f, T *endereco){
    f->primeiro = endereco + sizeof(T);
    return *endereco;
}

//Retirna o primeiro elemento da lista
T *fila_primeiro(Fila *f){
    return *(f->primeiro);
}

int fila_tamanho(Fila *f){
    return f->tamanhoVet;
}

int fila_contem(Fila *f, T elemento){
    T* contar;
    int c;

    contar = f->primeiro;
    while(contar != f->ultimo){
        if(contar != (f->vetor)+(f->tamanhoVet * sizeof(T))){
        contar =  (contar)+ sizeof(T);
        }
        else{
            contar = contar % f->tamanhoVet;
        }
        c++;
    }
    return c;
}

void fila_imprimir1(Fila *f){
    T* imp;
    while(imp != f->ultimo){
      if(imp != (f->vetor)+(f->tamanhoVet * sizeof(T))){
        imp =  (imp)+ sizeof(T);
        }
        else{
            imp = imp % f->tamanhoVet;
        }
        printf("%d", *imp);
    }

}
