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

void ExibeVetor(int Vetor[TF], int Qtde)
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
	for(i=0;i<TL-1;i++)
	{
		menor=i;
		for(j=i;j<TL;j++)
		{
			if(Vetor[j]<menor)
				menor=j;
			aux=Vetor[i];
			Vetor[i]=Vetor[menor];
			Vetor[menor]=aux;
		}
	}	
}

int BuscaExaustiva(int Vetor[TF],int TL, int Valor)
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
			pos = BuscaExaustiva(Vetor,TL,pos);
			/*while(i<TL)
			{
				if(Vetor[i]==Vetor[pos])
				{
					for(i=)
				}
			}*/
				printf("\nElemento Nao Encontrado!\n");
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
					printf("\nElemento da Posicao Excluido!\n");
				}
			}
			else
				printf("\nOpcao invalida!\n");
			break;
	}
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
	printf("\n[ESC] Sair:");
	printf("\n\nInforme a opcao desejada: ");
	
	fflush(stdin);		
	return toupper(getche());
}

void Executar(void)
{
	int i, V[TF], TL=0, NrMais, Soma, Qtde,Elemento;
	char op;
	do
	{
		op = Menu();
		switch(op)
		{
			case 'A':
				clrscr();
				if(TL==TF)
					printf("\nVetor Cheio!\n");
				else
				{
					LeVetor(V,TL);
					printf("\nElementos inseridos!\n");
				}
				getch();
				break;
				
			case 'B':
				clrscr();
				ExibeVetor(V,TL);
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
				printf("\nVetor Ordenado!\n");
				getch();
				break;
		
			case 'G':
				clrscr;
				ExcluirElemento(V,TL);
				getch();
				
				break;
		}
	}while(op!=27);
}

int main(void)
{
	char op;
	
	Executar();
	getch();
	
	return 0;
}
