#include <stdio.h>
#include <stdlib.h>
#include "FilaEncadeada.h"

void teste(){
	Fila* f = fila_criar();
	fila_inserir(f, 10);
	fila_inserir(f, 20);
	fila_inserir(f, 30);
	fila_inserir(f, 40);
	fila_inserir(f, 50);
	//fila_remover1(f);
	fila_imprimir(f);
	fila_destruir(f);
}

void main(){
	teste();
}
