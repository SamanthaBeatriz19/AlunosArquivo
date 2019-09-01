#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* Atividade
*
* Tarefa em dupla. Plágios serão penalizados
* de maneira severa e exemplar.
*
* Prazo: ver no moodle
*
* Nesta tarefa você deve criar um registro Disciplina.
* O nome da discplina e do professor devem ser digitados
* pelo usuário na primeira execução do programa.
*
* Os dados serão salvos em arquivo. Na segunda vez que
* for executado, o nome da disciplina e do professor
* virão diretamente do arquivo.
*
* Você deve fazer um menu com opções.
* 1 - adicionar aluno.
* 2 - remover aluno.
* 3 - Listar alunos.
* 4 - salvar (salva todos os dados em arquivo)
* 5 - sair.
*
* Ao abrir, os dados serão carregados do arquivo.
*
*
*
*
*/
//registro aluno.
typedef struct Aluno{
	char nome[200];
	long int ra;
	int idade;
	float CR;
}Aluno;
typedef struct Disciplina{
	char nome[200];
	char professor[200];
	Aluno v[200];
	int top;//numero de alunos. começa com zero.
}Disciplina;
//criando o buffer como variavel global
char buffer[10000]; 


void ADDaluno(Disciplina *x){
	char nome2[200];
	int idade;
	long int ra;
	float CR;
	
	fgets(nome2,sizeof(nome2),stdin);
	fgets(nome2,sizeof(nome2),stdin);
	scanf("%ld",&ra);
	scanf("%d",&idade);
	scanf("%f",&CR);
	x->v[x->top].idade = idade;
	x->v[x->top].ra = ra;
	x->v[x->top].CR = CR;
	strcpy(x->v[x->top].nome,nome2);
}
void imprimeA(Aluno a1){
	printf("~~~~~~~~~~~~~~~~~~~~~~");
	printf("NOME: %s\n",a1.nome);
	printf("RA: %ld\n",a1.ra);
	printf("IDADE: %d\n",a1.idade);
	printf("CR: %f\n",a1.CR);
}


void abreDisc(){
	FILE * fp;
	fp = fopen ("dados.txt", "r");
	if(fp==NULL){
        printf("arquivo vazio\n");
    }else{
		
	}

}
int main(){
	Disciplina x;
	x.top = 0;
	int control = 0;
	
	abreDisc();	
	
	do{
		printf("* 1 - adicionar aluno.\n");
		printf("* 2 - remover aluno.\n");
		printf("* 3 - Listar alunos.\n");
		printf("* 4 - salvar\n ");
		printf("* 5 - sair.\n");
		scanf("%d",&control);

		switch(control){
			case 1:
				ADDaluno(&x);
				x.top++;
			break;
			case 2:
			break;
			case 3:
				for(int i=0; i<x.top; i++){
					imprimeA(x.v[i]);
				}
			break;
			default:
				printf("opcao invalida");
			break;
		}
	}while(control!=5);

	printf("tamanho registro %lu\n",sizeof(Aluno));
	printf("tamanho long int %lu\n",sizeof(long int));
	printf("tamanho int %lu\n",sizeof(int));
	printf("tamanho float %lu\n",sizeof(float));
	printf("tamanho char 200*%lu\n",sizeof(char));
return 0;
}
