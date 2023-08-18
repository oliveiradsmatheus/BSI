#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#define TF 10

int main (void)
{
	int TL=0,TL2=0,TL3=0,TLI=0,i,j,k,pos,menor;
	char op,letra,auxnome[30],resp,nomeexc[30],aux[30],lista3[TF*2][30],lista2[TF][30],lista[TF][30],intersec[TF*4][30];
	
	do
	{
		system("cls");
		printf("\n # # # MENU # # #\n\n");
		printf("[A] Inserir nome\n");
		printf("[B] Exibir a lista\n");
		printf("[C] Ordenar lista\n");
		printf("[D] Excluir nome da lista\n");
		printf("[E] Inserir nome na segunda lista\n");
		printf("[F] Inserir nome na terceira lista com uma letra inicial\n");
		printf("[G] Mostrar interseccao das listas\n");
		printf("[ESC] Sair\n");
		printf("\nEscolha uma opcao\n");
		op = toupper(getch());
		printf("\n");
		
		switch(op)
		{
			case 'A':
				system("cls");
				if(TL==TF)
				{
					printf("\nA lista esta cheia!\n");
					getch();
				}
				else
				{
					printf("\n # # # Insirir nome # # # \n\n");
					printf("\nNome [%d]:",TL);
					fflush(stdin);
					gets(auxnome);
					while(TL<TF && strcmp(auxnome,"\0")!=0)
					{
						pos=0;
						while(pos<TL && strcmp(auxnome,lista[pos])!=0)
							pos++;
						if(pos<TL)
						{
							printf("\nO nome ja existe!\n");
						}
						else
						{
							strcpy(lista[TL],auxnome);
							TL++;
						}
						if(TL<TF)
						{
							printf("\nNome [%d]:",TL);
							fflush(stdin);
							gets(auxnome);
						}
						else
						{
							printf("\nA lista esta cheia!\n");
							getch();
						}
					}
				}
				
				break;
			case 'B':
				system("cls");
				if(TL==0)
					printf("\nA lista esta vazia!\n");
				else
					for(i=0;i<TL;i++)
						printf("\Nome [%d]: %s",i,lista[i]);
				getch();
				break;
			case 'C':
				system("cls");
				if(TL==0)
				{
					printf("\nA lista esta vazia!\n");
					getch();
				}
				else
				{
					for(i=0;i<TL-1;i++)
					{
						menor=i;
						for(j=i+1;j<TL;j++)
						{
							if(strcmp(lista[j],lista[menor])<0)
								menor=j;
						}
						if(i!=menor)
						{
							strcpy(aux,lista[i]);
							strcpy(lista[i],lista[menor]);
							strcpy(lista[menor],aux);
						}
					}
					printf("\nA lista foi ordenada!\n");
					getch();
				}
				break;
			case 'D':
				system("cls");
				if(TL==TF)
				{
					printf("\nNao existem nomes para excluir!\n");
					getch();
				}
				else
				{
					if(TL==0)
					{
						printf("\nA lista esta vazia!\n");
						getch();
					}
					else
					{
						printf("\nDigite o nome que deseja excluir:\n");
						fflush(stdin);
						gets(nomeexc);
						while(TL>0 && strcmp(nomeexc,"\0")!=0)
						{
							pos=0;
							while(pos<TL && strcmp(nomeexc,lista[pos])!=0)
								pos++;
							if(pos<TL)
							{
								printf("\nConfirma Exclusao? <S/N>\n");
								fflush(stdin);
								resp=toupper(getch());
								if(resp=='S')
								{
									for(i=pos;i<TL-1;i++)
										strcpy(lista[i],lista[i+1]);
									TL--;
								}
								printf("\nDigite o nome que deseja excluir:\n");
								fflush(stdin);
								gets(nomeexc);
							}
							else
							{
								printf("\nNome nao existente:\n");
								printf("\nDigite o nome que deseja excluir:\n");
								fflush(stdin);
								gets(nomeexc);
							}
						}
					}
				}
				break;
			case 'E':
				system("cls");
				if(TL2==TF)
					printf("\nA lista 2 esta cheia!\n");
				else
				{
					printf("\n # # # Insirir nome # # # \n");
					printf("\nNome [%d]:",TL2);
					fflush(stdin);
					gets(auxnome);
					while(TL2<TF && strcmp(auxnome,"\0")!=0)
					{
						pos=0;
						while(pos<TL2 && strcmp(auxnome,lista2[pos])!=0)
							pos++;
						if(pos<TL2)
						{
							printf("\nO nome ja existe!\n");
						}
						else
						{
							strcpy(lista2[TL2],auxnome);
							TL2++;
						}
						if(TL<TF)
						{
							printf("\nNome [%d]:",TL2);
							fflush(stdin);
							gets(auxnome);
						}
						else
						{
							printf("\nA lista esta cheia!\n");
							getch();
						}
					}
				}
				break;
			case 'F':
				system("cls");
				if(TL>0 || TL2>0)
				{
					printf("\nInsira uma letra para inserir os nomes correspondentes na lista 3!\n");
					fflush(stdin);
					letra = toupper(getche());
					for(i=0;i<TL;i++)
					{
						if(letra==lista[i][0])
						{
							strcpy(lista3[TL3],lista[i]);
							TL3++;
						}
					}
					for(i=0;i<TL2;i++)
					{
						if(letra == lista2[i][0])
						{
							strcpy(lista3[TL3],lista2[i]);
							TL3++;
						}
					}
				}
				system("cls");
				printf("\nNomes com a letra [%c] adicionados a lista 3!\n",letra);
				getch();
				break;
			case 'G':
				system("cls");
				if(TL>0 || TL2>0 || TL3>0)
				{
					for(i=0;i<TL;i++)
					{
						pos=0;
						while(pos<TL2 && strcmp(lista[i],lista2[pos]))
							pos++;
						if(pos<TL2)
						{
							pos=0;
								while(pos<TL3 && strcmp(lista[i],lista3[pos]))
									pos++;
								if(pos<TL3)
								{
									printf("%s\n",lista[i]);
									//pos=0;
									//while(pos<TLI && strcmp(lista[i],intersec[pos]))
										//pos++;
									//if(pos==TLI)
									//{
										//strcpy(intersec[TLI],lista[i]);
										//TLI++;
									//}
								}
						}
					}
					//for(i=0;i<TLI;i++)
						//printf("%s\n",intersec[i]);
				}
				else
					printf("\nNenhum nome na lista\n");
				getch();
		}
	}while(op!=27);
}
