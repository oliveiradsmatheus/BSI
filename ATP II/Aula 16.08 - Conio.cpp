#include <conio2.h> 
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char Nome[30],tecla;
	int i=0,x=1,y=1,cor=1,fundo=0;
	
	do
	{
		textcolor(cor);
		textbackground(fundo);
		gotoxy(x,y);
		printf("%d - %c",i,i);
		i++;
		y++;
		cor++;
		fundo++;
		if(y==27)
		{
			x+=10;
			y=1;
		}
		if(cor==15)
			cor=1;
		if(fundo==7)
			fundo=1;
	}while(i<255);
	
	textcolor(0);
	textbackground(0);
	
	/*do
	{
		tecla=getch();
		if(tecla==-32 || tecla==0)
			tecla=getch();
		printf("Nr.: %d \t Tecla: %c\n",tecla,tecla);
	}while(tecla!=27);
	
	
	textbackground(6);
	clrscr();
	textcolor(13); // Cores de 0 à 15. Quando menor o valor, mais escura é a cor. 0 - Preto, 15-Branco;
	gotoxy(10,7); // Envia o cursor para a coordenada XY na tela DOS.
	printf("Digite um Nome: "); // Não utilizar \n enquanto estiver usando as coordenadas.
	gotoxy(10,8);
	fflush(stdin);
	textcolor(5);
	textbackground(5); // Cores de 0 à 7. Semelhante ao textcolor.
	gets(Nome);
	
	clrscr();
	
	textcolor(7);
	textbackground(0);
	while(1)
	{
		textbackground(i);
		clrscr();
		i++;
		if(i==14)
			i=0;
	}*/
	
	gotoxy(80,30);
	return 0;
}
