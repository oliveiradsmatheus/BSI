#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>

#define TF 20

struct tpData
{
	int d,m,a;
};

struct tpProduto
{
	int Cod,Estoque;
	tpData Valid;
	char Descr[TF];
	float Preco;
};

void Moldura(int CI,int LI,int CF,int LF,int CorT,int CorF)
{
	int i;
	
	textcolor(CorT);
	textbackground(CorF);
	
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
	
	textcolor(7);
	textbackground(0);
}

void MenuPrincipal(void)
{
	Moldura(2,5,27,21,12,7);
	textcolor(15);
	gotoxy(3,7);
	printf("# #  M E N U  # #");
	gotoxy(3,9);
	printf("[P] Produtos");
	gotoxy(3,10);
	printf("[C] Clientes");
	gotoxy(3,11);
	printf("[P] Fornecedores");
	gotoxy(3,19);
	printf("[Esc] Sair");
}

void Formulario(void)
{
	system("cls");
	Moldura(1,1,80,25,10,5);
	gotoxy(30,3);
	printf("# # #  T I T U L O # # #");
	
	Moldura(2,2,79,4,14,1);
	Moldura(2,5,27,21,12,7);
	MenuPrincipal();
	Moldura(2,22,79,24,11,4);
	gotoxy(4,23);
	textcolor(5);
	printf("Mensagem:");
	Moldura(28,5,79,21,9,6);
}

void OrdenarDescr(tpProduto Tab[TF],int TL)
{
	int i,j,menor;
	tpProduto RegAux;
	
	if(TL==0)
	{
		clrscr();
		printf("\n** Nao Existem Produtos Cadastrados! **");
	}
	else
	{
		for(i=0;i<TL-1;i++)
		{
			menor=i;
			for(j=i+1;j<TL;j++)
			{
				if(stricmp(Tab[i].Descr,Tab[j].Descr)>0)
					menor=j;
			}
			RegAux = Tab[i];
			Tab[i] = Tab[menor];
			Tab[menor] = RegAux;
		}
		clrscr();
		printf("** Ordenacao Concluida! **");
	}
}

int BuscaCod(tpProduto Tab[TF],int TL,int CodProd)
{
	int pos=0;
	
	while(pos<TL && CodProd!=Tab[pos].Cod)
		pos++;
	if(pos<TL)
		return pos;
	else
		return -1;
	
}

void CadProd(tpProduto TabProd[TF],int &TLP)
{
	int AuxCod,pos;
	
	clrscr();
	printf("\n** Cadastro de Produto: **\n");
	printf("\nCodigo do Produto: ");
	scanf("%d",&AuxCod);
		while(TLP<TF && AuxCod>0)
		{
			pos=BuscaCod(TabProd,TLP,AuxCod);
			if(pos==-1)
			{
				TabProd[TLP].Cod=AuxCod;
				printf("\nDescricao do Produto: ");
				fflush(stdin);
				gets(TabProd[TLP].Descr);
				printf("\nQuantidade em Estoque: ");
				scanf("%d",&TabProd[TLP].Estoque);
				printf("\nPreco: ");
				scanf("%f",&TabProd[TLP].Preco);
				printf("\nData de Validade[dd mm aa]: ");
				scanf("%d %d %d",&TabProd[TLP].Valid.d,&TabProd[TLP].Valid.m,&TabProd[TLP].Valid.a);
				printf("\n** Produto Cadastrado! **\n");
				getch();
				TLP++;
			}
			else
			{
				clrscr();
				printf("\nProduto Cadastrado!\n");
				printf("Produto[%d] - Descricao: [%s]\n\n",pos,TabProd[pos].Descr);
				getch();
			}
			if(TLP<TF)
			{
				clrscr();
				printf("\n** Cadastro de Produto: **\n");
				printf("\nCodigo do Produto: ");
				scanf("%d",&AuxCod);
			}
			
		}
}

void VendaProd(tpProduto Tab[TF], int TL)
{
	int i,AuxCod,Qtde,pos;
	
	clrscr();
	printf("\n** Venda de Produtos **\n");
	printf("\nCodigo do Produto: ");
	scanf("%d",&AuxCod);
	while(TL>0 && AuxCod>0)
	{
		pos=BuscaCod(Tab,TL,AuxCod);
		if(pos==-1)
		{
			clrscr();
			printf("\n** Produto Nao Cadastrado! **");
			getch();
		}
		else
		{
			if(Tab[pos].Estoque>0)
			{
				printf("\nProduto [%d]: %s\nQuantidade Disponivel: %d",Tab[pos].Cod,Tab[pos].Descr,Tab[pos].Estoque);
				printf("\nInforme a Quantidade: ");
				scanf("%d",&Qtde);
				if(Tab[pos].Estoque>=Qtde)
				{
					clrscr();
					printf("\n** Quantidade Disponivel! **");
					printf("\nConfirma a Venda (S/N)?");
					if(toupper(getche())=='S')
					{
						Tab[pos].Estoque-=Qtde;
						clrscr();
						printf("\n** Venda Realizada! **\n");
						printf("\nProduto[%d]: %s",Tab[pos].Cod,Tab[pos].Descr);
						printf("\nQuantidade Vendida: %d",Qtde);
						printf("\nEstoque Restante: %d",Tab[pos].Estoque);
						
						getch();
					}
				}
				else
				{
					clrscr();
					printf("** Quantidade Indisponivel no Estoque! **");
					getch();
				}
			}
			else
			{
				clrscr();
				printf("\n** Produto com Estoque Zerado! **");
				getch();
			}
			if(TL>0)
			{
				clrscr();
				printf("\n** Venda de Produtos **\n");
				printf("\nCodigo do Produto: ");
				scanf("%d",&AuxCod);
			}
		}
	}
}

void InserirDados(tpProduto TabProd[TF],int &TL)
{
	TabProd[TL].Cod = 265;
	strcpy(TabProd[TL].Descr,"Arroz");
	TabProd[TL].Estoque = 16;
	TabProd[TL].Preco = 25.90;
	TabProd[TL].Valid.d = 25;
	TabProd[TL].Valid.m = 11;
	TabProd[TL].Valid.a = 2025;
	TL++;
	
	TabProd[TL].Cod = 344;
	strcpy(TabProd[TL].Descr,"Feijao");
	TabProd[TL].Estoque = 25;
	TabProd[TL].Preco = 15.90;
	TabProd[TL].Valid.d = 25;
	TabProd[TL].Valid.m = 11;
	TabProd[TL].Valid.a = 2023;
	TL++;
	
	TabProd[TL].Cod = 217;
	strcpy(TabProd[TL].Descr,"Macarrao");
	TabProd[TL].Estoque = 26;
	TabProd[TL].Preco = 9.90;
	TabProd[TL].Valid.d = 25;
	TabProd[TL].Valid.m = 03;
	TabProd[TL].Valid.a = 2025;
	TL++;
	
	TabProd[TL].Cod = 192;
	strcpy(TabProd[TL].Descr,"Refrigerante");
	TabProd[TL].Estoque = 99;
	TabProd[TL].Preco = 7.29;
	TabProd[TL].Valid.d = 18;
	TabProd[TL].Valid.m = 01;
	TabProd[TL].Valid.a = 2025;
	TL++;
	
	TabProd[TL].Cod = 481;
	strcpy(TabProd[TL].Descr,"Frango");
	TabProd[TL].Estoque = 20;
	TabProd[TL].Preco = 12.90;
	TabProd[TL].Valid.d = 12;
	TabProd[TL].Valid.m = 05;
	TabProd[TL].Valid.a = 2025;
	TL++;
	
	TabProd[TL].Cod = 255;
	strcpy(TabProd[TL].Descr,"Leite");
	TabProd[TL].Estoque = 40;
	TabProd[TL].Preco = 4.49;
	TabProd[TL].Valid.d = 18;
	TabProd[TL].Valid.m = 06;
	TabProd[TL].Valid.a = 2024;
	TL++;
	
	clrscr();
	printf("\n** Produtos Inseridos **");
	getch();
}

void ExcProd(tpProduto Tab[TF], int &TL)
{
	int i, AuxCod, pos;
	
	clrscr();
	printf("\n** Exclusao de Produtos **\n");
	printf("\nCodigo do Produto a excluir: ");
	scanf("%d",&AuxCod);
	while(TL>0 && AuxCod>0)
	{
		pos = BuscaCod(Tab,TL,AuxCod);
		if(pos==-1)
		{
			clrscr();
			printf("\n** Produto Nao Cadastrado! **");
			getch();
		}
		else
		{
			printf("\n** Detalhes do Produto: **\n");
			printf("\nCodigo do Produto: [%d]",Tab[pos].Cod);
			printf("\nDescricao do Produto: %s",Tab[pos].Descr);
			printf("\nQuantidade em Estoque: %d",Tab[pos].Estoque);
			printf("\nPreco: %f",Tab[pos].Preco);
			printf("\nData de Validade: %d/%d/%d",Tab[pos].Valid.d,Tab[pos].Valid.m,Tab[pos].Valid.a);
			
			printf("\n\nConfirma a Exclusao? (S/N)?\n");
			if(toupper(getche())=='S')
			{
				for(i=pos;i<TL;i++)
					Tab[i]=Tab[i+1];
				TL--;
				clrscr();
				printf("\n** Produto [%d] Excluido com Sucesso! **\n",AuxCod);
				getch();
			}
			else
			{
				clrscr();
				printf("** Exclusao Cancelada! **");
				getch();
			}	
		}
		if(TL>0)
		{
			printf("\n** Exclusao de Produtos **\n");
			printf("\nCodigo do Produto a excluir: ");
			scanf("%d",&AuxCod);
		}
	}
}



void Relatorio(tpProduto Tab[TF],int TL)
{
	int i;
	
	if(TL==0)
	{
		system("cls");
		printf("\n** Nao Existem Produtos Cadastrados! **");
		getch();
	}
	else
	{
		system("cls");
		printf("\n** Produtos Cadastrados: **\n");
		for(i=0;i<TL;i++)
		{
			printf("\nCodigo do Produto: %d",Tab[i].Cod);
			printf("\nQuantidade em Estoque: %d",Tab[i].Estoque);
			printf("\nDescricao do Produto: %s",Tab[i].Descr);
			printf("\nPreco: %.2f",Tab[i].Preco);
			printf("\nValidade: %d/%d/%d\n",Tab[i].Valid.d,Tab[i].Valid.m,Tab[i].Valid.a);
		}
		getch();
	}
}


char Menu(void)
{
	clrscr();
	printf("\n# # #  M E N U # # # \n");
	printf("\n[A] Cadastrar Produtos");
	printf("\n[B] Relatorio de Produtos");
	printf("\n[C] Ordenar Produtos");
	printf("\n[D] Excluir Produtos");
	printf("\n[E] Vender Produtos:");
	printf("\n[F] Comprar Produtos");
	printf("\n[G] Exibir Produtos que comecam com uma determinada letra");
	printf("\n[H] Ordenar Produtos pelo preco - Maior para Menor");
	printf("\n[I] Inserir Dados Automaticamente");
	printf("\n[ESC] Sair\n");
	printf("\n\nOpcao Desejada: ");
	
	return toupper(getche());
}

int main(void)
{
	tpProduto Prods[TF];
	int TL=0, CI=1,LI=1,CF=80,LF=20,CorT=15,CorF=1;
	char op;
	
	Formulario();
	
	do
	{
		getch();
		op = Menu();
		switch(op)
		{
			case 'A':
				CadProd(Prods,TL);
				break;
			case 'B':
				Relatorio(Prods,TL);
				break;
			case 'C':
				OrdenarDescr(Prods,TL);
				getch();
				break;
			case 'D':
				ExcProd(Prods,TL);
				break;
			case 'E':
				VendaProd(Prods,TL);
				break;
			case 'F':
				break;
			case 'G':
				break;
			case 'H':
				break;
			case 'I':
				InserirDados(Prods,TL);
				break;
		} 
	}while(op!=27);
	
	return 0;
}
