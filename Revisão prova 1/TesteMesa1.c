#include <stdio.h>

int* funcao(int** r , int* x , int* y){
	*r = y;
	(*x)++;
	(**r)*=3;
	return x;
}
void main(){
	int x , y , *p , *q , **z;
	x = 20;
	y = 25;
	p = &x;
	z = &p;
	q = funcao(z , &x , &y);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("*p = %d\n", *p);
	printf("*q = %d\n", *q);
	printf("**z = %d\n", **z);
}