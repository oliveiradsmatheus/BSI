#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

// Por Referência

/*void Leitura(int &num)
{
	printf("\nDigite um numero:");
	scanf("%d",&num);
}

void Fatorial(int &fatorial)
{
	int num;
	num=fatorial;
	while(num>1)
	{
		num--;
		fatorial*=num;
	}
}

void ExibeValor(int fatorial)
{
	printf("\nFatorial: %d",fatorial);
	getch();
}

int main(void)
{
	int num;
	Leitura(num);
	Fatorial(num);
	ExibeValor(num);
	
	return 0;
}*/

// Por Parâmetro

int Leitura(void)
{
	int num;
	
	printf("\nDigite um numero:");
	scanf("%d",&num);
	
	return num;
}

int Fatorial(int num)
{
	int fatorial;
	
	fatorial=num;
	while(num>1)
	{
		num--;
		fatorial*=num;
	}
	
	return fatorial;
}

void ExibeValor(int fatorial)
{
	printf("\nFatorial: %d",fatorial);
	getch();
}

int main(void)
{
	ExibeValor(Fatorial(Leitura()));
	
	return 0;
}

