#include <stdio.h>
#include "matriz1.h"
#include <stdlib.h>
// #include "matriz2.h"

int main(){

    // criar matriz
    // int m[2][2]

    Matriz *m1 = matriz_cria(2, 3);
    Matriz *m2 = matriz_cria(10, 10);
    Matriz *m3 = matriz_cria(2, 2);

    // atribui valores nas celulas
    // m[0][2] = 10;
    matriz_atribui(m1, 0, 1, 10);
    matriz_atribui(m2, 2, 3, 20);
    matriz_atribui(m3, 0, 0, 50);

    // acessar valores das celulas
    // int x = m[1][2]
    int x1 = matriz_acessa1(m1, 0, 1);

    int x2;
    matriz_acessa2(m1, 0, 1, &x2);

    int y = matriz_acessa1(m2, 2, 3);
    int z = matriz_acessa1(m3, 0, 0);
    printf("x1 = %d\n", x1 );
    printf("x2 = %d\n", x2 );
    printf("y = %d\n", y );
    printf("z = %d\n", z );

   // imprimir a matriz
    matriz_imprime(m1);
    matriz_imprime(m2);
    matriz_imprime(m3);

    // destruir matriz
    matriz_destroi(m1);
    matriz_destroi(m2);
    matriz_destroi(m3);

   //    Matriz *m1_transposta = matriz_transposta(m1);
}