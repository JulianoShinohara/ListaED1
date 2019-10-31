#include <stdio.h>
#include<string.h>

struct Produto{
  int produto;
  char descricao
};

bubble_generico (void* v, int n, int tamElemento, int (*funcao)(void*,void*));

void bubble_generico (void* v, int n, int tamElemento, int (*compara)(void*,void*)){
  int aux;
  for (int k = 1; k < n; k++) {
    void* enderecoElemento = v+(k*tamElemento);
    for (int j = 0; j < n - 1; j++) {
      void* enderecoElemento2 = v+(j*tamElemento);
      compara(enderecoElemento, enderecoElemento2);
    }
  }
  printf("[");
  for(int i=0; i < n; i++){
    void* enderecoElemento = v + (i * tamElemento);    
    //printVetor_generico(v, n, tam, enderecoElemento);
  }
   printf("]");
}
// outras funções auxiliares poderão ser necessárias


void printVetor_generico(void* v, int n, int tam, void (*printElemento)(void*)){
  int i;
  printf("[");
  for(i=0; i < n; i++){
    void* enderecoElemento = v + (i * tam);
    printElemento(enderecoElemento);
    if(i < n-1) printf(",");
  }
  printf("]\n");
}

comparaInt(void* a , void* b){
  int* x = (int*)a;
  int* y = (int*)b;
  if (*x > *y){
    return 1;
  }else if(*x < *y){
    return -1;
  }else{
    return 0;
  }
}

comparaChar(void* a , void* b){
  int* x = (char*)a;
  int* y = (char*)b;
  if (*x > *y){
    return 1;
  }else if(*x < *y){
    return -1;
  }else{
    return 0;
  }
}


comparaProdutoPreco(void* a , void* b){
  int* x = (Produto*)a;
  int* y = (Produto*)b;
  if (*x > *y){
    return 1;
  }else if(*x < *y){
    return -1;
  }else{
    return 0;
  }
}
int main(){
  int v1[8] = {25,48,37,12,57,86,33,92}

  Produto vp[5] = {
    {5 , "555" , 5.5},
    {1 , "111" , 1.1},
    {4 , "444" , 4.4},
    {3 , "333" , 3.3},
    {2 , "222" , 2.2},
  }

  char vet_char[5] = {'x' , 'd' , 'e' , 'a' , 'r'};

  bubble_generico(v1)
}