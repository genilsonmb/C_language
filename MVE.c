#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct alun {
	char al_nome[50];
	int al_codigo;
	double al_cpf;
}alun;

typedef struct disciplina {
	int disc_codigo;
	char disc_nome[40];
	char disc_professor[50];
	int disc_creditos;
}disciplina;

void imprimir_tudo(FILE *arquivo);
void inscrever_aluno(FILE *arquivo);
void menu(FILE *arquivo);
void estrut_aluno(FILE *arquivo,alun *lista_alunos);

int main()
{
	int i=0;
	printf("Inicio MAIN\n");
	FILE *arqw;
	alun *alunos;
	arqw = fopen("arquivoMVE.txt", "r");
	alunos = (alun*)malloc(2*sizeof(alun));
	fclose(arqw);
	estrut_aluno(arqw,alunos);
	menu(arqw);
	printf("\n\n\nFim do menu inicio do loop.\n\n\n");
	for (i = 0 ; i < 6 ; i++) {
		printf("%d ",alunos[i].al_codigo);
		printf("%.lf ",alunos[i].al_cpf);
		printf("%s\n",alunos[i].al_nome);
	}
	printf("Fim do loop.\n\n\n");
	//inscrever_aluno(arqw);
	//imprimir_tudo(arqw);
	printf("Aluno[3].al_nome: %s\n",alunos[3].al_nome);
	
	return 0;
}
void inscrever_aluno(FILE *arquivo) {
	int a;
	double b=0;
	char c[50];
	arquivo = fopen("arquivoMVE.txt", "a");
	printf("Digite o nome do aluno: \n");
	scanf("%s",c);
	printf("Digite o codigo do aluno: \n");
	scanf("%d",&a);
	printf("Digite o cpf do aluno: \n");
	scanf("%lf",&b);
	fprintf(arquivo,"%d \n",a);
	fprintf(arquivo,"%s \n",c);
	fprintf(arquivo,"%.lf \n",b);
	fclose(arquivo);
}
void imprimir_tudo(FILE *arquivo){
	int a;
	double b;
	char c[50];
	arquivo = fopen("arquivoMVE.txt", "r");	
	printf("Informações lidas no arquivo:\n");
	printf("Cod Aluno\tCPF\t\tNome\n");
	//enquanto feof for falso
	while(!feof(arquivo)) {
		fscanf(arquivo,"%d",&a);
		fscanf(arquivo,"%s",c);
		fscanf(arquivo,"%lf",&b);
		if ( feof(arquivo) ) 
			break;
		printf("%d %.lf \t\t%s\t\n",a,b,c);
		
	}
	fclose(arquivo);
}
void menu(FILE *arquivo) {
	int opcao=100;
	printf("1 - Adicionar aluno\n");
	printf("2 - Imprimir tudo\n");
	printf("Digite a opcao:\n");
	scanf("%d",&opcao);
	switch (opcao) {
		case 1:
			inscrever_aluno(arquivo);
			break;
		case 2:
			imprimir_tudo(arquivo);
			break;
		default:
			printf("Operacao invalida.\n");
			break;
	}	
}

void estrut_aluno(FILE *arquivo,alun *lista_alunos){
	//printf("Inicio do while de copia de estrutura\n");
	int a;
	int n=0;
	double b;
	char c[50];
	arquivo = fopen("arquivoMVE.txt", "r");	
	lista_alunos = (alun*)malloc(2*sizeof(alun));
	while(!feof(arquivo)) {
	//	printf("dentro do while no estrut aluno\n");
		fscanf(arquivo,"%d",&a);
		fscanf(arquivo,"%s",c);
		fscanf(arquivo,"%lf",&b);
		lista_alunos[n].al_codigo = a;
		lista_alunos[n].al_cpf = b;
		strcpy(lista_alunos[n].al_nome,c);
		n++;
		//printf("%d\n",n);
		lista_alunos = (alun *)realloc(lista_alunos,(n+1)*sizeof(alun));	
		if ( feof(arquivo) ) 
			break;
	}
	fclose(arquivo);
	
}
