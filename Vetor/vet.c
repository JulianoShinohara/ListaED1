#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct{
 int* vetor;
 int size;
 int length;
} Vetor;

typedef DataType (int);

typedef enum {false, true} Boolean;

//=========================== Funções ===========================

Vetor* vetor_new(){
	Vetor* a1 = (Vetor*)malloc(sizeof(Vetor));
	a1->vetor = (int*)malloc(N*sizeof(int));
	a1->size = 0;
	a1->length = N;
}

void vetor_free(Vetor* v){
	free(v->size);
	free(v->length);
	free(v->vetor);
}

void vetor_print(Vetor* m){
	for (int i = 0; i < m->size; i++){
		printf("Vetor[%d] = %d\n", i , m->vetor[i]);
	}
}

Boolean vetor_insert(Vetor* v, DataType element, int index){
	if (index < 0){
		return false;
	}
	if (index > v->length){
		return false;
	}
	int tmp = v->length - index;
    memcpy(v->vetor+index+1, v->vetor+index, tmp*sizeof(DataType));
    v->vetor[index] = element;
    v->size++;
	vetor_dobra(Vetor* v);
    return true;
}

Boolean vetor_add(Vetor* v, DataType element){
	v->vetor[size] = element;
	v->size++;
	
	vetor_dobra(Vetor* v);		
	return true;
}

DataType vetor_remove1(Vetor* v, int index){
	int tmp = v->length - index;
	v->vetor[index] = NULL;
	memcpy(v->vetor+index , v->vetor+index-1 , tmp*sizeof(DataType));
	v->size--; 
	vetor_divide(Vetor* v);
}

Boolean vetor_remove2(Vetor* v, int index, Datatype* ptr){

}

DataType vetor_shift1(Vetor* v){
	v->vetor[v->size-1] = NULL;
	vetor_divide(Vetor* v);
}
//----------------------------------------
Boolean vetor_shift2(Vetor* v, Datatype* ptr){
}
Datatype vetor_get1(Vetor* v, int index){
	int valor = v->vetor[index];
	return valor;
}
//-------------------------
Boolean vetor_get2(Vetor* v, int index, DataType *ptr){
}
Datatype* vetor_get3(Vetor* v, int index){
	int valor = v->vetor[index];
	int &valor;
}

void vetor_set(Vetor* v, int index, DataType valor){
	v->vetor[index] = valor;
}
//-------------
void vetor_map(Vetor* v, void (*funcao)(DataType*)){

}
Vetor* vetor_sub1(Vetor* v, int index){
	subVetor = (int*)malloc((v->size+index)*sizeof(int));
	memcpy(subvetor , v->vetor+index, (v->size+index)*sizeof(Datatype));
}
Vetor* vetor_sub2(Vetor* v, int start, int end){
	int tam = (end - start) + 1	
	int	subVetor = (int*)malloc(tam*sizeof(int));
    memcpy(subVetor, v->vetor+start, tam*sizeof(DataType));
	
}

void agenda_verificaReduzTamanho(Agenda* agenda){

}

int agenda_consultaPorEstado(Agenda* agenda, char* estado, Telefone** referencia){

}

void agenda_inserirPessoa(Agenda* agenda, Pessoa* p){

}

Pessoa* agenda_removerPessoa(Agenda* agenda, char* email){

}

void pessoa_desalocar(Pessoa* p){

}
//=========================== Complementos ===========================

void vetor_dobra(Vetor* v){
	if (v->size < v->length){
		return;
	}
	int* tmp = (int*)malloc((2*v->length)*sizeof(int));
	memcpy(tmp , v->vetor , v->size*sizeof(int));
	free(v->vetor);
	v->vetor = tmp;
	v->length *= 2;
}

void vetor_divide(Vetor* v){
	if (v->size <= (v->length/4)){
		int*temp = (int*)malloc((v->length/2)*sizeof(int));
		memcpy(temp , v->vetor , v->size*sizeof(int));
		free(v->vetor);
		v->vetor = temp;
		v->length /= 2;
	}else{
		return;
	}
}

//=========================== Main ===========================

void main(){
	Vetor* v1 = vetor_new();
	Vetor* v2 = vetor_new();
	Vetor* v3 = vetor_new();

	vetor_add(v1 , 10);
	vetor_add(v1 , 20);
	vetor_add(v1 , 30);
	vetor_add(v1 , 40);
	vetor_add(v1 , 50);
	vetor_add(v1 , 60);
}



int comparaPreco(int* a , int* b){
	if (a->preco > b->preco){
		return 1;
	}else if(a->preco < b->preco){
		return -1;
	}else{
		return 0;
	}
}

int comparaCod(int* a , int* b){
	if (a->codigo > b->codigo){
		return 1;
	}else if(a->codigo < b->codigo){
		return -1;
	}else{
		return 0;
	}
}

int comparaDesc(){
	return strcmp(a->descricao , b->descricao);
}

void vetor_genericSort(Vetor* v , int pfuncao()){
		if(v->vetor[i] >= v->vetor[i+1]){
			if (pfuncao(&v->vetor[i] , v->vetor + i + 1) >= 0){
				

			}
		}
}