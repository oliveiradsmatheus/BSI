#include <conio2.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//Prot�tipos: Declara��o de Fun��es
int IntToBin(int Decimal);
int LeValor(void);
void ExibeValor(int N);

//Fun��o main
int main(void)
{
	ExibeValor(IntToBin(LeValor()));
	return 0;
}

//M�dulos do Programa
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
	
	//Converter INT para Bin�rio
	
	while(Decimal>0)
	{
		Binario+=(Decimal%2)*mult;
		mult*=10;
		Decimal/=2;
	}
	
	return Binario;
}
