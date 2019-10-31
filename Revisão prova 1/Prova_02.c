#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
typedef struct{
	char cod[6];
	char* desc;
	float* preco;
	int qtde;		//qtde de produtos no estoque
	int qtdePrecos; //qtde de precos
}Produto;

typedef struct{
	char* nome;
	Produto** produtos;
	int qtde;   //qtde de produtos
	int tam;	//tamanho do vetor
}Empresa;

Produto* novoProduto(char* cod, char* desc, float* preco, int qtde){
	Produto* new = (Produto*)malloc(sizeof(Produto));
	strcpy(new->cod , cod);
	new->desc = (char*)malloc(strlen(desc)*sizeof(char));
	strcpy(new->desc , desc);
	new->preco = (float*)malloc(sizeof(float));
	new->preco = preco;
	new->qtde = qtde;
	new->qtdePrecos++;
	return new;
}

float mediaDePreco(Empresa* e){
	float mediaProd = 0;
	float mediaFinal[e->qtde];
	for (int i = 0; i < e->qtde; i++){
		for (int j = 0; j < e->produtos[i]->qtdePrecos; j++){
			mediaProd += e->produtos[i]->preco[j];
		}
		mediaProd /= e->produtos[i]->qtdePrecos;
		mediaFinal[i] = mediaProd;
		mediaProd = 0;
	}
	for (int i = 0; i < e->qtde; i++){
		mediaProd += mediaFinal[i];
		mediaProd /= e->qtde;
	}
}

int buscaRemoveDuplicados(Empresa* e, char* cod){
	int qtdeRemove = 0;

	for (int i = 0; i < e->qtde; i++){
		if (e->produtos[i]->cod == cod){
			free(e->produtos[i]->preco);
			free(e->produtos[i]->desc);
			free(e->produtos[i]);
			qtdeRemove++;
			for (int j = i; j < e->qtde; j++){
				e->produtos[j] = e->produtos[j++];
			}
		}
	}
	return qtdeRemove;
}
*/


typedef struct{
	char cep[11];
	int num;
	char estado[3];
}Endereco;

typedef struct{
	char celular[15];
	char whatsapp[2];
}Contato;

typedef struct{
	char* nome;
	int idade;
	char* email;
	Endereco endereco;
	Contato** contatos;
	int contatoTam;
	int contatoQtde;
}Pessoa;


Pessoa* pessoa_novo(char* nome , int idade , char* email){
	Pessoa* new = (Pessoa*)malloc(sizeof(Pessoa));
	new->nome = (char*)malloc(strlen(nome)*sizeof(char));
	strcpy(new->nome , nome);
	new->idade = idade;
	new->email = (char*)malloc(strlen(email)*sizeof(char));
	strcpy(new->email , email);
	new->contatoQtde = 0;
}

void pessoa_defineEndereco(Pessoa* p , char* rua , int num , char* estado){
	strcpy(p->endereco.cep , rua);
	p->endereco.num = num;
	strcpy(p->endereco.estado , estado);
}

void pessoa_cadastrarContato(Pessoa* p , char* celular , char* flagWhats){
	strcpy(p->contatos[p->contatoQtde]->celular , celular);
	strcpy(p->contatos[p->contatoQtde]->whatsapp , flagWhats);
	p->contatoQtde++;
}

typedef struct{
	char descricao[20];
	Pessoa** pessoas;
	int pessoasTam;
	int pessoasQtde;
}Agenda;

void agenda_verificaReduzTamanho(Agenda* agenda){
	if (agenda->pessoasTam >= agenda->pessoasQtde*2){
		agenda->pessoas[agenda->pessoasTam] = agenda->pessoas[agenda->pessoasTam/2];
		agenda->pessoasTam /= 2;
	}else{
		printf("Tamanho da Agenda não reduzida\n");
	}
}

int agenda_consultaPorEstado(Agenda* agenda , char* estado , Contato** referencia){
	int g=0;
	for (int i = 0; i < agenda->pessoasQtde; i++){
		if (strcmp(agenda->pessoas[i]->endereco.estado , estado) == 0){
			for (int j = 0; j < agenda->pessoas[i]->contatoQtde; j++){
			strcpy(referencia[g]->celular , agenda->pessoas[i]->contatos[j]->celular);
			g++;
			}
		}
	}
}

void main(){
	
	printf("a\n");
}














