#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cadastro{
	char nome[20];
	char cpf[15];
	char codigo[15];
}cadastro;

void struct_to_arquivo(FILE *arquivo,cadastro *cad,int a);
void arquivo_to_struct(FILE *arquivo,cadastro *cad,int a);
void imp_alunos(cadastro *cad,int a);
int contar_alunos(cadastro *cad);
int contar_linhas(FILE *arquivo);
void inserir_aluno(cadastro **cad,int *n);


int main()
{
	int a;
	int n;
	int *pn;
	pn=&n;
	int opcao=0;
	FILE *arqr;
	cadastro *p_alunos;
	cadastro l_alunos;
	p_alunos = &l_alunos;
	p_alunos = (cadastro*)malloc(5*sizeof(cadastro));
	arqr = fopen("testeestrutura.txt","r");
	a = contar_linhas(arqr);
	arquivo_to_struct(arqr,p_alunos,a);	
	a = contar_alunos(p_alunos);
	n = contar_alunos(p_alunos);
	imp_alunos(p_alunos,a);
	printf("\n%d\n",a);
	while (opcao!=9) {
		printf("1-Inserir Aluno\n");
		printf("2-Sair\n");
		printf("Digite a opcao\n");
		scanf("%d",&opcao);
	switch (opcao) {
		case 1:
			inserir_aluno(&p_alunos,pn);
			break;
		case 2:
			imp_alunos(p_alunos,a+2);
			break;
		case 3:
			printf("\n%d\n",*pn);
			break;
		case 9:
			break;
		}
	}
	struct_to_arquivo(arqr,p_alunos,a);
//	printf("%ld",(sizeof(*p_alunos)/sizeof(cadastro*)));
	return 0;
}
//salva os arquivos da estrutura no arquivo
void struct_to_arquivo(FILE *arquivo,cadastro *cad,int a){
	arquivo = fopen("testeestrutura.txt","w");
	for (int i = 0 ; i < a ; i++){
	fprintf(arquivo,"%s\n",cad[i].nome);
	fprintf(arquivo,"%s\n",cad[i].cpf);
	fprintf(arquivo,"%s\n",cad[i].codigo);
	}	
}
//passa os dados do arquivo para estrutura
void arquivo_to_struct(FILE *arquivo,cadastro *cad,int a){	
	arquivo = fopen("testeestrutura.txt","r");
	for (int i = 0 ; i < a/3 ; i++){
	fscanf(arquivo,"%s",cad[i].nome);
	fscanf(arquivo,"%s",cad[i].cpf);
	fscanf(arquivo,"%s",cad[i].codigo);
}
	fclose(arquivo);
}
//imprime os alunos na estrutura
void imp_alunos(cadastro *cad,int a){
	//a = contar_alunos(cad);
	for (int i = 0 ; i < a ; i++){
	printf("%s (%d)\n",cad[i].nome,i);
	printf("%s\n",cad[i].cpf);
	printf("%s\n",cad[i].codigo);
	}	
}

//conta a quantidade de alunos na estrutura
int contar_alunos(cadastro *cad){
	int n = 0;
	while ( cad[n].nome[0] == 'N'){
		n++;	
	} 
	return n;
}
//conta a quantidade de estruturas
int contar_estrut_arq(FILE *arquivo){
	char c;
	int linhas=0;
	while(c!=EOF){
		fscanf(arquivo,"%c",&c);
		if (c == '\n')
			linhas++;
	}
	return linhas/3;
	
}
//conta a quantidade de linhas do arquivo
int contar_linhas(FILE *arquivo){
	arquivo = fopen("testeestrutura.txt","r");
	char a;
	int cont=-1;
	while(!feof(arquivo)){
	fscanf(arquivo,"%c",&a);
	if (a == '\n')
		cont++;
}
	fclose(arquivo);
return cont;
}

//adiciona aluno na estrutura
void inserir_aluno(cadastro **cad,int *pn){
	printf("Dentro da funcao contamos %d alunos\n",(*pn));
	cad = (cadastro **)realloc(cad,((*pn)+1)*sizeof(cadastro));
	printf("Qual o nome do aluno?\n");
	scanf("%s",cad[0]->nome);
	printf("Qual o cpf do aluno?\n");
	scanf("%s",cad[(*pn)]->cpf);
	printf("Qual o codigo do aluno?\n");
	scanf("%s",cad[(*pn)]->codigo);
	printf("%s (%d)\n",cad[(*pn)]->nome,(*pn));
	printf("%s\n",cad[(*pn)]->cpf);
	printf("%s\n",cad[(*pn)]->codigo);
	*pn=*pn+1;
}
