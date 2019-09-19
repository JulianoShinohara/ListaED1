#include <stdio.h>
#include <string.h>

//Escreva um algoritmo que calcule e mostre a potência de um determinado número somente usando o operador de multiplicação.

void potencia(int num , int potencia , int*result){
int resultado = 1;
for (int i = 0; i < potencia+1; i++){
resultado = resultado * num;
}
*result = resultado;
}

// Escreva um algoritmo que dado um número inteiro positivo mostre sua ordem inversa
void invertido(int num , intinv){
if(num > 100){
int centena = num / 100;
int dezena = (num % 100) / 10;
int unidade = (num % 100) % 10;
int invertido = (unidade100) + (dezena * 10) + centena;
inv = invertido;
}else if(num < 100 && num > 10){
int dezena = num / 10;
int unidade = num % 10;
int invertido = (unidade10) + dezena;
*inv = invertido;
}else{
int invertido = num;
*inv = invertido;
}
}

//Escreva um algoritmo que dado uma nota, converta e mostre o seu conceito equivalente.
void nota(int nota , char*resulta){
char resultad;
if(nota >= 9 && nota <= 10){
resultad = 'A';
}else if (nota >= 7 && nota < 9){
resultad = 'B';
}else if (nota >= 6 && nota < 7){
resultad = 'C';
}else if (nota < 6){
resultad = 'I';
}else{
return 0;
}
*resulta = resultad;
}

// Escreva um algoritmo que leia 3 inteiros positivos correspondente ao Dia, mês e ano de uma determinada
// data e a mostre por extenso. Somente o Dia e o mês deve ser escrito por extenso.

void data(int diaa , int mes , int ano , char*date){
char Dia[20];
char Mes[20];
char Ano[20];
switch(diaa){
case 1:
strcpy(Dia,"Um de ");
break;
case 2:
strcpy(Dia,"Dois de ");
break;
case 3:
strcpy(Dia,"Tres de ");
break;
case 4:
strcpy(Dia,"Quatro de ");
break;
case 5:
strcpy(Dia,"Cinco de ");
break;
case 6:
strcpy(Dia,"Seis de ");
break;
case 7:
strcpy(Dia,"Sete de ");
break;
case 8:
strcpy(Dia,"Oito de ");
break;
case 9:
strcpy(Dia,"Nove de ");
break;
case 10:
strcpy(Dia,"Dez de ");
break;
case 11:
strcpy(Dia,"Onze de ");
break;
case 12:
strcpy(Dia,"Doze de ");
break;
case 13:
strcpy(Dia,"Treze de ");
break;
case 14:
strcpy(Dia,"Quatorze de ");
break;
case 15:
strcpy(Dia,"Quinze de ");
break;
case 16:
strcpy(Dia,"Dezesseis de ");
break;
case 17:
strcpy(Dia,"Dezessete de ");
break;
case 18:
strcpy(Dia, "Dezoito de ");
break;
case 19:
strcpy(Dia,"Dezenove de ");
break;
case 20:
strcpy(Dia,"Vinte de ");
break;
case 21:
strcpy(Dia,"Vinte e um de ");
break;
case 22:
strcpy(Dia,"Vinte e dois de ");
break;
case 23:
strcpy(Dia,"Vinte e tres de ");
break;
case 24:
strcpy(Dia,"Vinte e quatro de ");
break;
case 25:
strcpy(Dia,"Vinte e cinco de ");
break;
case 26:
strcpy(Dia,"Vinte e seis de ");
break;
case 27:
strcpy(Dia,"Vinte e sete de ");
break;
case 28:
strcpy(Dia,"Vinte e oito de ");
break;
case 29:
strcpy(Dia,"Vinte e nove de ");
break;
case 30:
strcpy(Dia,"Trita de ");
break;
case 31:
strcpy(Dia,"Trinta e um de ");
break;
}
switch(mes){
case 1:
strcpy(Mes, "Janeiro de ");
break;
case 2:
strcpy(Mes, "Fevereiro de ");
break;
case 3:
strcpy(Mes, "Março de ");
break;
case 4:
strcpy(Mes, "Abril de ");
break;
case 5:
strcpy(Mes, "Maio de ");
break;
case 6:
strcpy(Mes, "Junho de ");
break;
case 7:
strcpy(Mes, "Julho de ");
break;
case 8:
strcpy(Mes, "Agosto de ");
break;
case 9:
strcpy(Mes, "Setembro de ");
break;
case 10:
strcpy(Mes, "Outubro de ");
break;
case 11:
strcpy(Mes, "Novembro de ");
break;
case 12:
strcpy(Mes, "Dezembro de ");
break;
}
sprintf(Ano , "%i" , ano);
strcat(Dia , Mes);
strcat(Dia , Ano);
strcpy(date , Dia);
}

// Escreva um algoritmo para um caixa eletrônico que dado um valor a ser sacado calcule o menor número de
// cédular possível. Considere que sempre haverá quantidade suficiente de cédulas para efetuar o saque
void caixa(int valor , int* notaa){
int notas[6] = {2,2,2,2,2,2};
int nota;
int resto;

if (valor == 1 || valor == 3){
	printf("========== VALOR INDISPONÍVEL!!!!! ==========\n");
	return 0;
}
nota = valor / 100;
notas[0] = nota;
resto = valor % 100;
nota = resto / 50;
notas[1] = nota;
resto = resto % 50;
nota = resto / 20;
notas[2] = nota;
resto = resto % 20;
nota = resto / 10;
notas[3] = nota;
resto = resto % 10;
if (resto > 5 && resto%2 == 0){
	notas[4] = 0;
	nota = resto / 2;
	notas[5] = nota;
}else if (resto == 1 || resto == 3){
		notas[4]++;
		notas[3]--;
	for (int i = 3; -1 == notas[i]; i--){
		notas[i]+=2;
		notas[i-1]--;
		if (i == 2){
			notas[i]++;
			notas[i+1]--;
		}
	}
	resto = resto + 5;
	nota = resto / 2;
	notas[5] = nota;
}else{	
nota = resto / 5;
notas[4] = nota;
resto = resto % 5;
nota = resto / 2;
notas[5] = nota;
resto = resto % 2;
}
notaa[0] = notas[0];
notaa[1] = notas[1];
notaa[2] = notas[2];
notaa[3] = notas[3];
notaa[4] = notas[4];
notaa[5] = notas[5];
}
int main(){

//Potencia
int valo;
potencia(2 , 3 , &valo);
printf("resultado da potencia: %d\n\n",valo);

// Numero invertido
int inv;
invertido(123 , &inv);
printf("numero: \t123 \ninvertido: \t%d\n\n", inv);

// Conceito das notas
char result;
nota(9 , &result);
printf("Conceito: %c\n\n",result);

//Data por extenso
char date[50];
data(16 , 9 , 1999 , &date);
printf("%s\n\n",date);

// Notas do Saque
int cedulas[6] = {1,1,1,1,1,1};
caixa(53,&cedulas);
printf("%d R$100.00\n%d R$50.00\n%d R$20.00\n%d R$10.00\n%d R$5.00\n%d R$2.00\n",cedulas[0], cedulas[1], cedulas[2], cedulas[3], cedulas[4], cedulas[5]);

return 0;
}