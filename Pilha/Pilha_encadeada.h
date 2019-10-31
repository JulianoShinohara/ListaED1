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
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
    int qtde;
}Pilha;


//----------------------------------------------------------------

/*
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */

Pilha* pilha_criar(){
	Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
	novo->qtde = 0;
	novo->topo = NULL;
}

//----------------------------------------------------------------
/*
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */

Boolean pilha_push(Pilha* p, Tipo elemento){
	No* tmp = (No*)malloc(sizeof(No));
	tmp->dado = elemento;
	tmp->prox = p->topo;
	p->topo = tmp;
	p->qtde++;
return true;
}

//----------------------------------------------------------------
/*
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
 */

Tipo* pilha_pop1(Pilha* p){
		
	if (p->topo != 0){
		Tipo* n = (Tipo*)malloc(sizeof(Tipo));
		No* ult;
		ult = p->topo;
		p->topo = p->topo->prox;
		p->qtde--;
		*n = *(ult->dado);
		free(ult);
		return n;
	}else{
		return NULL;
	}
}

//----------------------------------------------------------------

/*
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço 
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */

Boolean pilha_pop2(Pilha* p, Tipo* end){
	if (p->topo != 0){
		Tipo* n = (Tipo*)malloc(sizeof(Tipo));
		No* ult = p->topo;
		p->topo = p->topo->prox;
		p->qtde--;
		*end = *(ult->dado);
		free(ult);
		return true;
	}else{
		return false;
	}			
}

//----------------------------------------------------------------
/*
 * Desaloca a pilha <p>.
 */

void pilha_destruir(Pilha* p){
		if (p->topo->prox != NULL){
			for (int i = 0; i < p->qtde; i++){
				No* aux;
				aux = p->topo;
				p->topo = p->topo->prox;
				free(aux);
			}
		}else{
			free(p->topo);
			free(p);
		}
}

//----------------------------------------------------------------

/*
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */

void pilha_imprimir(Pilha* p){
	No* aux;
	aux = p->topo;
	//while(aux->prox != NULL){
	for (int i = 0; i < p->qtde; i++){
		printf("%d , ", aux->dado );
		aux = aux->prox;
	}

}

//----------------------------------------------------------------

/*
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */
int pilha_posicao(Pilha* p, Tipo elemento){
	No* aux;
	aux = p->topo;
	int count = 0;
	while(aux->dado != elemento || aux->prox == NULL){
		count++;
		aux = aux->prox;
	}return count;
	if (aux->dado == elemento){
		return count;
	}else{
		return -1;
	}
}

//----------------------------------------------------------------

/*
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */
int pilha_tamanho(Pilha* p){
	No* aux;
	aux = p->topo;
	int tam = 0;
	while(aux->prox != NULL){
		tam++;
		aux = aux->prox;
	}
	return tam;
}

//----------------------------------------------------------------

//FUNÇÕES ADICIONAIS

//----------------------------------------------------------------

/*
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
	int add = 0;
	for (int i = 0; i < tam; i++){
		//if (vetor[i] != "\0"){
			No* aux = (No*)malloc(sizeof(No));
			aux->dado = vetor[i];
			aux->prox = p->topo;
			p->topo = aux;
			p->qtde++;
			add++;
		//}
	}
	return add;
}

//----------------------------------------------------------------

/*
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 */
void pilha_inverter(Pilha* p){
	Tipo tmp;
    Pilha* auxx = pilha_criar();
    while(p->topo != 0){
        tmp = pilha_pop1(p);
        pilha_push(auxx, tmp);
    }
    p = auxx;
}

//----------------------------------------------------------------

/*
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */
Pilha* pilha_clone(Pilha* p){

}

