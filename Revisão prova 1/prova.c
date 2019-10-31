#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char cod[6];
	char* nome;
	float* preco;
	int qtde;  //qtde de produtos no estoque
	int qtdePrecos; //qtde de precos
}Produto;

typedef struct{
	char* nome;
	Produto** produtos;
	int qtde;
	int tam;
}Empresa;

//Escreva uma função que crie dinamicamente e devolva o endereço de um novo Produto. Faça as validações básicas. 
//Analise cuidadosamente todos os atributos da struct e os manipule da forma apropriada. 
//Todos os atributos devem ser inicializados corretamente pela função.

Produto* novoProduto(char* cod, char* desc, float preco, int qtde){
	Produto* novo = (Produto*)malloc(sizeof(Produto*));
	strcpy(novo->cod , cod);
	novo->nome = (char*) malloc (strlen(desc)*sizeof(char));
	strcpy(novo->desc , desc);
	novo->preco = (float*) malloc (*sizeof(float));
	novo->preco = preco;
	novo->qtde = qtde;
	novo->qtdePrecos++;
}

//Escreva uma função que dado uma empresa, devolva a média de preço de todos os produtos existentes. 
//Percebam que cada produto possui um conjunto dos últimos preços praticados. 
//Portanto, o preço do produto é obtido pela média dos seus preços.

float mediaDePreco(Empresa* e){
	float media[e->qtde];
	float prod = 0;
	float mediatotal = 0;
	for (int i = 0; i < e->qtde; i++){
		for (int j = 0; j < e->Produto[i].qtdePrecos; j++){
			prod += e->Produto[j].preco;
		}
		media[i] = prod/e->Produto[i].qtdePrecos;
	}
	for (int i = 0; i < e->qtde; i++){
		mediatotal += media[i];
	}
	prod = mediatotal/e->qtde;
	return prod;
}

//Escreva uma função que dado um código de produto, realize uma busca no vetor e remova todas as ocorrências do produto. 
//A função deve manter os produtos armazenados de forma contígua na memória. 
//Portanto, não deve haver “buracos” no vetor. O gerenciamento da memória faz parte da avaliação.
//A função devolve a quantidade de ocorrências removidas. 

int buscaRemoveDuplicados(Empresa* e, char* cod){
	int remove = 0;
	for (int i = 0; i < e->qtde; i++){
		if (cod == e->Produto[i].cod){
			free(e->Produto[i].preco);
			free(e->Produtos[i].nome);
			free(e->Produto[i]);
			int pos = i;
			remove++;
			for (int j = i; j < e->qtde; j++){
				e->Produto[j] = e->produto[j+1];
			}
		}
	}
	return remove;
}