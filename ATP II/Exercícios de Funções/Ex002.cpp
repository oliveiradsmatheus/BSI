#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Fun��o de Leitura
int LeValor(void)
{
	int Valor;
	printf("\nDigite um numero binario:");
	scanf("%d",&Valor);
	
	return Valor;
}

// Fun��o de convers�o
int BinToDec(int Binario)
{
	int mult=1,Decimal=0,aux=0;
	
	while(Binario>0)
	{
		if((Binario-mult)%2==0)
		{
			Decimal+=pow(2,aux);
			Binario-=mult;
			Binario/=10;
		}
		else
		{
			Binario/=10;
		}
		aux++;
	}
	
	return Decimal;
}

// Fun��o de Exibi��o
void ExibeValor (int decimal)
{
	printf("\nValor em decimal: %d",decimal);
	getch();
}

// Fun��o MAIN
int main (void)
{
	ExibeValor(BinToDec(LeValor()));
}
