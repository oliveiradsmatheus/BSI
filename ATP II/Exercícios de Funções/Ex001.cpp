#include <conio2.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Protótipos: Declaração de Funções
int IntToBin(int Decimal);
int LeValor(void);
void ExibeValor(int N);

//Função main
int main(void)
{
	ExibeValor(IntToBin(LeValor()));
	return 0;
}

//Módulos do Programa
int LeValor(void)
{
	int Valor;
	printf("\nDigite um numero em Decimal:");
	scanf("%d",&Valor);
	
	return Valor;
}

void ExibeValor(int N)
{
	printf("\nValor em Binario: %d",N);
	getch();
}

int IntToBin(int Decimal)
{
	int Binario=0,mult=1;
	
	//Converter INT para Binário
	
	while(Decimal>0)
	{
		Binario+=(Decimal%2)*mult;
		mult*=10;
		Decimal/=2;
	}
	
	return Binario;
}
