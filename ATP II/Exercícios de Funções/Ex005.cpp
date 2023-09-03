#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <windows.h>

void Leitura(int &CI,int &CF,int &LI,int &LF)
{
	printf("Digite a coluna inicial:<1 a 80>");
	scanf("%d",&CI);
	printf("Digite a linha inicial:<1 a 25>");
	scanf("%d",&LI);
	printf("Digite a coluna final:<1 a 80>");
	scanf("%d",&CF);
	printf("Digite a linha final:<1 a 25>");
	scanf("%d",&LF);
}

void Exibe(int CI,int CF,int LI,int LF)
{
	int i;
	
	clrscr();
	
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		Sleep(15);
		gotoxy(i,LF);
		printf("%c",205);
	}
	
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		Sleep(15);
		gotoxy(CF,i);
		printf("%c",186);
	}
}

int main(void)
{
	int CI,CF,LI,LF;
	Leitura(CI,CF,LI,LF);
	Exibe(CI,CF,LI,LF);
	getch();
	
	return 0;
}
