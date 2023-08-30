#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>

int Leitura(void)
{
	int num;
	printf("\nInforme um numero:");
	scanf("%d",&num);
	
	return num;
}

int Verifica(int perfeito)
{
	int i=1,soma;
	while(soma<=perfeito/2)
	{
		if(perfeito%i==0)
			soma+=i;
		i++;
	}
	
	if(perfeito==soma)
		printf("\nO numero %d e um numero perfeito",perfeito);
	else
		printf("\nO numero %d nao e um numero perfeito",perfeito);
	
	return perfeito;
}

int main (void)
{
	Verifica(Leitura());
	return 0;
}
