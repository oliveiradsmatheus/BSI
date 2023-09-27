#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TF 100

void Frequencia(int Vetor[TF], int TL, int &Valor, int &QtdeVezes) // Todo vetor (Toda variável indexada) na linguagem C é passado por referência (Não usar &) - (Vetor é uma variável de Endereços)
{
	int a,b,cont;
	
	QtdeVezes=0;
	
	for(a=0;a<TL-1;a++)
	{
		cont=1;
		for(b=a+1;b<TL;b++)
			if(Vetor[a]==Vetor[b])
				cont++;
		if(QtdeVezes<cont)
			{
				QtdeVezes=cont;
				Valor=Vetor[a];
			}
	}
}

void SomaVetor(int Vetor[TF], int &TL, int &Soma)
{
	int i;
	Soma=0;
	
	for(i=0;i<TL;i++)
	{
		Soma+=Vetor[i];
	}
}

void LeVetor(int Vet[TF], int &TL)
{
	int aux;
	printf("\nInserir numeros no vetor:\n");
	printf("Vetor[%d]: ",TL);
	scanf("%d",&aux);
	while(TL<TF && aux>0)
	{
		Vet[TL]=aux;
		TL++;
		if(TL<TF)
		{
			printf("Vetor[%d]: ",TL);
			scanf("%d",&aux);
		}
	}
}

void ExibeVetor(int Vetor[], int Qtde)
{
	int i;

	printf("\n### Conteudo do Vetor ###\n");
	if(Qtde==0)
		printf("\nVetor Vazio!\n");
	for(i=0;i<Qtde;i++)
		printf("\nVetor[%d]: %d",i,Vetor[i]);
	getch();
}

void OrdenaVetor(int Vetor[TF], int TL)
{
	int i, j, menor,aux;
	for(i=0;i<TL;i++)
	{
		menor=i;
		for(j=i;j<TL;j++)
		{
			if(Vetor[j]<Vetor[menor])
				menor=j;
			aux=Vetor[i];
			Vetor[i]=Vetor[menor];
			Vetor[menor]=aux;
		}
	}
	printf("\n### Vetor Ordenado! ###\n");
}

int BuscaExaustiva(int Vetor[],int TL, int Valor)
{
	int i=0;
	while (i<TL && Valor!=Vetor[i])
		i++;
	if(i<TL)
		return i;
	else
		return -1;
}

void Consultar(int Vet[TF],int Qtde)
{
	int pos, Elemento;
	
	clrscr();
	printf("\n### Consulta no Vetor ###\n");
	if(Qtde==0)
		printf("\nVetor Vazio!\n");
	else
	{
		printf("\nConsultar por: ");
		scanf("%d",&Elemento);
		while(Elemento>0)
		{
			pos=BuscaExaustiva(Vet,Qtde,Elemento);
			if(pos==-1)
				printf("\nElemento nao encontrado!\n");
			else
				printf("\nElemento [%d] encontrado na posicao [%d]\n",Vet[pos],pos);
			getch();
			printf("\n\nConsultar por: ");
			scanf("%d",&Elemento);
		}
	}
}

void ExcluirElemento(int Vetor[TF], int &TL)
{
	int i,j,num,xpos,pos=0,cont=0;
	char OP,CONF;
	
	clrscr();
	printf("\n[A] Excluir Numero:");
	printf("\n[B] Excluir Posicao:");
	OP=toupper(getche());	
	switch(OP)
	{
		case 'A':
			clrscr();
			printf("\nInforme um Numero para Excluir:\n");
			scanf("%d",&num);
			while(num>0)
			{
				pos = BuscaExaustiva(Vetor,TL,num);
				if(pos==-1)
				{
					clrscr();
					printf("\nElemento [%d] Nao Encontrado!\n",num);
				}
				else
				{
					clrscr();
					printf("\nElemento [%d] encontrado na posicao [%d]!\n",Vetor[pos],pos);
					printf("\nConfirma a Exclusao <S/N>?\n");
					if(toupper(getche())=='S');
					{
						for(i=pos;i<TL;i++)
							Vetor[i]=Vetor[i+1];
						TL--;
						printf("\nElemento Excluido!\n");
					}
				}
				if(TL>0)
				{
					printf("\nInforme um Numero para Excluir:\n");
					scanf("%d",&num);
				}
			}
			break;
	
		case 'B':
			if(OP=='B')
			{
				clrscr();
				printf("\nInforme a Posicao para Excluir:\n");
				scanf("%d",&xpos);
				if(xpos>=TL)
				{
					clrscr();
					printf("\nPosicao Invalida!\n");
				}
				else
				{
					clrscr();
					for(i=xpos;i<TL-1;i++)
						Vetor[i]=Vetor[i+1];
					TL--;
					printf("\nElemento da Posicao [%d] Excluido!\n",xpos);
				}
				if(TL>0)
				{
					printf("\nInforme a Posicao para Excluir:\n");
					scanf("%d",&xpos);
				}
			}
			else
				printf("\nOpcao invalida!\n");
			break;
	}
}

void SubConj(int VA[TF],int TLA,int VB[TF], int TLB, int VC[TF*2], int &TLC)
{
	int i;
	
	TLC=0;
	for(i=0;i<TLA;i++)
		if(BuscaExaustiva(VB,TLB,VA[i])==-1)
			if(BuscaExaustiva(VC,TLC,VA[i])==-1)
			{
				VC[TLC]=VA[i];
				TLC++;
			}
	clrscr;
	printf("\n### Subtracao Efetuada! ###\n");
	getch();
	
}

void InterSec(int VA[TF], int TLA, int VB[TF], int TLB, int VC[TF*2], int &TLC)
{
	int i;
	
	TLC=0;
	for(i=0;i<TLA;i++)
		if(BuscaExaustiva(VB,TLB,VA[i])!=-1)
			if(BuscaExaustiva(VC,TLC,VA[i])==-1)
			{
				VC[TLC]=VA[i];
				TLC++;
			}
	clrscr;
	printf("\n### Interseccao Efetuada! ###\n");
	getch();
}

char Menu(void)
{
	clrscr();
	printf("\n   **********   MENU   **********   \n");
	printf("\n[A] Inserir numeros no Vetor:");
	printf("\n[B] Exibir o vetor:");
	printf("\n[C] Verificar frequencia dentro do vetor:");
	printf("\n[D] Soma dos numeros do vetor:");
	printf("\n[E] Consultar Elemento");
	printf("\n[F] Ordenar Vetor:");
	printf("\n[G] Excluir Elemento");
	printf("\n[H] Subtracao de Conjunto");
	printf("\n[J] Interseccao de Conjunto");
	printf("\n[ESC] Sair:");
	printf("\n\nInforme a opcao desejada: ");
	
	return toupper(getch());
}

void Executar(void)
{
	int i, V[TF], V2[TF], TL=0, TL2=0, V3[TF*2], TL3=0, NrMais, Soma, Qtde,Elemento;
	char op,selv;
	do
	{
		op = Menu();
		switch(op)
		{
			case 'A':
				clrscr();
				printf("\n### Selecione o Vetor: ###\n");
				printf("\n[A]Vetor 1\n");
				printf("\n[B]Vetor 2\n");
				selv=toupper(getch());
				switch(selv)
				{
					case 'A':
						if(TL==TF)
							printf("\nVetor Cheio!\n");
						else
						{
							LeVetor(V,TL);
							printf("\nElementos inseridos!\n");
						}
						break;
						
					case 'B':
						if(TL2==TF)
							printf("\nVetor Cheio!\n");
						else
						{
							LeVetor(V2,TL2);
							printf("\nElementos inseridos!\n");
						}
						break;
				}
				getch();
				break;
				
			case 'B':
				clrscr();
				printf("\n### Selecione o Vetor: ###\n");
				printf("\n[A]Vetor 1\n");
				printf("\n[B]Vetor 2\n");
				printf("\n[C]Vetor 3 (Subtracao/Interseccao)\n");
				selv=toupper(getch());
				switch(selv)
				{
					case 'A':
						if(TL==0)
							printf("\nVetor Vazio!\n");
						else
						{
							clrscr();
							ExibeVetor(V,TL);
						}
						break;
						
					case 'B':
						if(TL2==0)
							printf("\nVetor Vazio!\n");
						else
						{
							clrscr();
							ExibeVetor(V2,TL2);
						}
						break;
					case 'C':
						if(TL3==0)
							printf("\nVetor Vazio!\n");
						else
						{
							clrscr();
							ExibeVetor(V3,TL3);
						}
						break;
				}
				break;
				
			case 'C':
				clrscr();
				if(TL==0)
					printf("\nVetor Vazio!\n");
				else
				{
					Frequencia(V,TL,NrMais,Qtde);
					printf("\nNumero de maior frequencia: %d\n",NrMais);
					printf("\nQuantidade de vezes: %d\n",Qtde);
				}
				getch();
				break;
				
			case 'D':
				clrscr();
				SomaVetor(V,TL,Soma);
				printf("\nSoma dos numeros do vetor: %d\n",Soma);
				getch();
				break;
				
			case 'E':
				clrscr();
				Consultar(V,TL);
				break;
			case 'F':
				clrscr();
				OrdenaVetor(V,TL);
				getch();
				break;
		
			case 'G':
				clrscr();
				ExcluirElemento(V,TL);
				break;
			case 'H':
				clrscr();
				SubConj(V,TL,V2,TL2,V3,TL3);
				break;
			case 'J':
				clrscr();
				InterSec(V,TL,V2,TL2,V3,TL3);
				break;
				
		}
	}while(op!=27);
}

int main(void)
{
	char op;
	
	textcolor(10);
	Executar();
	
	return 0;
}
