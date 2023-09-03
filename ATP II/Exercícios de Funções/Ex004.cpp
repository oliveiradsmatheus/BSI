#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>

void Leitura(int &HI, int &HF, int &MI, int &MF, int &SI, int &SF)
{
	printf("\nDigite a Hora Inicial:");
	scanf("%d",&HI);
	printf("\nDigite a Hora Final:");
	scanf("%d",&HF);
	printf("\nDigite o Minuto Inicial:");
	scanf("%d",&MI);
	printf("\nDigite o Minuto Final:");
	scanf("%d",&MF);
	printf("\nDigite o Segundo Inicial:");
	scanf("%d",&SI);
	printf("\nDigite o Segundo Final:");
	scanf("%d",&SF);
}

void diftempo(int HI, int HF, int MI, int MF, int SI, int SF)
{
	int dif;
	if(HF<HI)
	{
		24-(HI-HF);
	}
}

int main(void)
{
	int HI,HF,MI,MF,SI,SF;
	Leitura(HI,HF,MI,MF,SI,SF);
	
	
	
	return 0;
}
