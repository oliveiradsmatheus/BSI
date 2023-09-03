#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>

int main (void)
{
	int i,T,LT,CT,CI,CF,LI,LF,C,L;
	char mov,tiro='.',direcao;
	
	printf("Digite a coluna inicial:<1 a 80>");
	scanf("%d",&CI);
	printf("Digite a linha inicial:<1 a 25>");
	scanf("%d",&LI);
	printf("Digite a coluna final:<1 a 80>");
	scanf("%d",&CF);
	printf("Digite a linha final:<1 a 25>");
	scanf("%d",&LF);
	
	textbackground(5);
	clrscr();
	textcolor(15);	
	
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
	
	gotoxy(CF/2,LF/2);
	printf("%c",1);
	C=CF/2;
	L=LF/2;
	mov=1;
	
	getch();
	clrscr();
	
	do
	{
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
			gotoxy(i,LF);
			printf("%c",205);
		}
		for(i=LI+1;i<LF;i++)
		{
			gotoxy(CI,i);
			printf("%c",186);
			gotoxy(CF,i);
			printf("%c",186);
		}
		
		mov = getch();
		switch(mov)
		{
			case (59):
				tiro = '.';
				break;
			case (60):
				tiro = '*';
				break;
			case (61):
				tiro = '#';
				break;
			case(77):
				direcao='D';
				if(C<CF-1)
					C++;
				else
					C=CI+1;
				CT=C+1;
				break;
			case(80):
				direcao='B';
				if(L<LF-1)
					L++;
				else
					L=LI+1;
				LT=L+1;
				break;
			case(72):
				direcao='C';
				if(L>LI+1)
					L--;
				else
					L=LF-1;
				LT=L-1;
				break;
			case(75):
				direcao='E';
				if(C>CI+1)
					C--;
				else
					C=CF-1;
				CT=C-1;
				break;
			case(32):
				switch(direcao)
				{
					case ('C'):
						for(T=LT;T>LI;T--)
						{
							gotoxy(C,L);
							printf("%c",1);
							gotoxy(C,T);
							printf("%c",tiro);
							gotoxy(C,T+1);
							printf("%c",32);
							Sleep(30);
						}
						gotoxy(C,T+1);
						printf("%c",32);
						break;
					case ('B'):
						for(T=LT;T<LF;T++)
						{
							gotoxy(C,L);
							printf("%c",1);
							gotoxy(C,T);
							printf("%c",tiro);
							gotoxy(C,T-1);
							printf("%c",32);
							Sleep(30);
						}
						gotoxy(C,T-1);
						printf("%c",32);
						break;
					case ('D'):
						for(T=CT;T<CF;T++)
						{
							gotoxy(C,L);
							printf("%c",1);
							gotoxy(T,L);
							printf("%c",tiro);
							gotoxy(T-1,L);
							printf("%c",32);
							Sleep(30);
						}
						gotoxy(T-1,L);
						printf("%c",32);
						break;
					case ('E'):
						for(T=CT;T>CI;T--)
						{
							gotoxy(C,L);
							printf("%c",1);
							gotoxy(T,L);
							printf("%c",tiro);
							gotoxy(T+1,L);
							printf("%c",32);
							Sleep(30);
						}
						gotoxy(T+1,L);
						printf("%c",32);
						break;
				}
		}
		clrscr();
		gotoxy(C,L);
		printf("%c",1);	
	}while(mov!=27);
	
	return 0;
}
