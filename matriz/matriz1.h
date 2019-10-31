#include <stdio.h>
#include <stdlib.h>


// DADOS
typedef struct{
    int **m;
    int linhas;
    int colunas;
} Matriz;


//OPERAÇÕES (PROTÓTIPOS)

Matriz *matriz_cria(int linhas, int colunas);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_imprime(Matriz *m);
void matriz_destroi(Matriz *m);


//OPERAÇÕES (IMPLEMENTAÇÃO)

Matriz *matriz_cria(int linhas, int colunas){
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    mat->m = (int **)calloc(linhas, sizeof(int *));
    int i;
    for (i = 0; i < linhas; i++){
        mat->m[i] = (int *)calloc(colunas, sizeof(int));
    }
    mat->linhas = linhas;
    (*mat).colunas = colunas;

    return mat;
}

void matriz_atribui(Matriz *matriz, int lin, int col, int valor){
    matriz->m[lin][col] = valor;
    printf("m[%d][%d] = %d -- Adicionado\n", lin, col, matriz->m[lin][col]);
}

int matriz_acessa1(Matriz *matriz, int lin, int col){
    int acess;
    acess = matriz->m[lin][col];
    return acess;
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end){
    *end = m->m[lin][col];
}

void matriz_imprime(Matriz *m){
    printf("Matriz\nLinhas: %d\nColunas: %d\n\n", m->linhas , m->colunas);
    for (int i = 0; i < m->linhas; i++){
        for (int j = 0; j < m->colunas; j++){
            printf("%d\t", m->m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");

}

void matriz_destroi(Matriz *m){
    free(m->linhas);
    free(m->colunas);
    free(m);
}