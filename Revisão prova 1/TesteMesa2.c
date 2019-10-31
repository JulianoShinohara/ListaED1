#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int linhas;
	int colunas;
	int**matriz;
}Matriz;


Matriz *matriz_criar(int linhas, int colunas){
    Matriz* mat = (Matriz *)malloc(sizeof(Matriz));
    mat->matriz = (int **)calloc(linhas, sizeof(int *));
    int i;
    for (i = 0; i < linhas; i++){
        mat->matriz[i] = (int *)calloc(colunas, sizeof(int));
    }
    mat->linhas = linhas;
    mat->colunas = colunas;

    return mat;
}


void main(){
	Matriz* m = matriz_criar(3,3);

m->matriz[0][2] = 20;
(*((*m).matriz+1))[1] = 10;
*(*(m->matriz+2)+2) = 30;
*(*((*m).matriz)) = 40;
//((*m).matriz+0)[2] = 10;
*(m->matriz[(*m).linhas-1]) = 50;
//m->matriz[(*m).linhas - 2] = 60;

for (int i = 0; i < m->linhas; i++){
	for (int j = 0; j < m->colunas; j++){
		printf("%d\t" , m->matriz[i][j]);
	}
	printf("\n");
}
}