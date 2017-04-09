#include <stdio.h>

int main()
{
	char vet[3][3] = {0};
	char ch;
	int cont=0;
	
	for (int i = 0 ; i < 3 ; i++)
		for (int j = 0 ; j <3 ; j++)
			{
				printf("Digite X ou O na coordenada (%d,%d).\n",i,j);
				scanf(" %c",&vet[i][j]);
			}
//Imprime a matriz jogo da velha			
	for (int i = 0 ; i < 3 ; i++)
		for (int j = 0 ; j < 3 ; j++)
			{
			if (j<2) printf("(%c) ", vet[i][j]);	
			else if (j==2) printf("(%c)\n", vet[i][j]);
			}

	while (ch != 'x' && ch != 'o')
		{
			printf("Qual caractere você quer verificar?\n");
			scanf(" %c",&ch);
		}
		

	// verificacao de linhas
	for (int i = 0 ; i < 3 ; i++)
	{
		cont=0;
		for (int j = 0 ; j < 3 ; j++)
			{
			if (vet[i][j] == ch) 
				cont++;
			if (cont == 3) printf("Combanação encontrada na linha %d.\n",i+1);
			}
	}
	// verificacao de colunas
	for (int j = 0 ; j < 3 ; j++)
	{
	cont=0;
		for (int i = 0 ; i < 3 ; i++)
			{
			if (vet[i][j] == ch) 
				cont++;
			if (cont == 3) printf("Combanação encontrada na coluna %d.\n",j+1);
			}
	}	
	cont=0;
	for (int i = 0 ; i < 3 ; i++)
		{
			if (vet[i][i] == ch) 
				{
				cont++;
				if (cont==3) printf("Combinação encontrada na diagonal principal.\n");	
				}				
		}
	cont=0;
	for (int i = 0 ; i < 3 ; i++)
		{
			if (vet[i][2-i] == ch) 
				{
				cont++;
				if (cont==3) printf("Combinação encontrada na diagonal secundaria.\n");	
				}				
		}
		
	return 0;
}

