#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocação encadeada.
 */
typedef struct{
    No* prim;
    No* ult;
    int qtde;
}Fila;

//==========================================================================================
									Fila* fila_criar();

Fila* fila_criar(){
	Fila* new = (Fila*)malloc(sizeof(Fila));
	new->prim = (No*)malloc(sizeof(No));
	new->ult = (No*)malloc(sizeof(No));
	new->prim = NULL;
	new->ult = NULL;
	new->qtde = 0;
}

//==========================================================================================
								void fila_destruir(Fila* f);

void fila_destruir(Fila* f){
/*Reinicializa uma fila existente q como uma fila vazia
removendo todos os seus elementos.*/
	No* aux;
	No* tmp;
	if(f->qtde != 0){
		tmp = f->prim;
		while (tmp != NULL){
			aux = tmp;
			tmp = tmp->prox;
			free(aux);
		}
	}
}

//==========================================================================================
						Boolean fila_inserir(Fila* f, Tipo elemento);

Boolean fila_inserir(Fila* f, Tipo elemento){

	No* aux = (No*)malloc(sizeof(No));
	aux->dado = elemento;
	aux->prox = NULL;
	if (f->qtde == 0){
		f->prim = aux;
		f->ult = aux;
		f->qtde++;
	}else{
		f->ult->prox = aux;
		f->qtde++;
	}
	f->ult = aux;
	return true;
}

//==========================================================================================
								  Tipo* fila_remover1(Fila* f);

Tipo* fila_remover1(Fila* f){
	Tipo* dado;
	No* aux;
	aux = f->prim;
	f->prim = aux->prox;
	*dado = aux->dado;
	free(aux);
	f->qtde--;
	return dado;
}

//==========================================================================================
					Boolean fila_remover2(Fila* f, Tipo* endereco);
					
Boolean fila_remover2(Fila* f, Tipo* endereco){
    No*  aux;
    aux = (No*) malloc (sizeof(No));
	Tipo dado;
    if(endereco == &(f->prim->dado)){
        dado = f->prim->dado;
        f->prim = f->prim->prox;
        f->qtde--;

        return dado;
    }
    else if(endereco == &(f->ult->dado)){
        dado = f->ult->dado;
            while(&(aux->dado) != endereco){
                aux = aux->prox;
            }
        f->ult = aux;

        return dado;
    }
    else{
        while(&(aux->dado) != endereco){
                aux = aux->prox;
        }
        aux = aux->prox->prox;
        f->qtde--;
        dado = *endereco;

        return dado;
    }
}

//==========================================================================================
						  Boolean fila_primeiro(Fila* f, Tipo* endereco);

Boolean fila_primeiro(Fila* f, Tipo* endereco){
	if (f->prim == NULL){
		return false;
	}else{
		*endereco = f->prim->dado;
		return true;
	}
}

//==========================================================================================
									int fila_tamanho(Fila* f);

int fila_tamanho(Fila* f){
	return f->qtde;
}

//==========================================================================================
							int fila_contem(Fila* f, Tipo elemento);

int fila_contem(Fila* f, Tipo elemento){
	Tipo pos = 0;
	No* aux;
	aux = f->prim;
	while(aux->dado != elemento){
		if (aux->dado == elemento){
			return pos;
		}
	pos++;
	aux = aux->prox;
	}
return 0;
}

//==========================================================================================
								void fila_imprimir(Fila* f);

void fila_imprimir(Fila* f){
	No* imp;
	imp = f->prim;
	for (int i = 0; i < f->qtde; i++){
		printf("%d\n",imp->dado );
		imp = imp->prox;
	}
}
//==========================================================================================
