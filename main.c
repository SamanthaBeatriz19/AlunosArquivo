#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz {
int li,co,**m;
}Matriz;

//EXERCICIO 01 - ok
Matriz* criaMatriz(int li, int co){

	Matriz *aux= (Matriz *) malloc(sizeof (Matriz));
	aux->li= li;
	aux->co= co;
	aux->m = (int **)malloc(li * sizeof(int*));
	for (int i = 0; i < li; i++){
		
		aux->m[i] = (int*) malloc(co * sizeof(int));
		for (int j = 0; j < co; j++){ 
            aux->m[i][j] = 0; 
       }
	}
	return aux;
}

//EXERCICIO 02 - ok
void freeMatriz(Matriz *ma){
	for (int i=0; i<ma->li; i++) free (ma->m[i]);
	free (ma->m);
	printf("matriz liberada\n");
}

//EXERCICIO 03 - ok
void imprime(Matriz *m){
	for(int i = 0;i<m->li;i++){
		for(int k = 0;k<m->co;k++){
			printf("%d ",m->m[i][k]);	
		}
		printf("\n");
	}
}

//EXERCICIO 04
Matriz * multiplica(Matriz *a, Matriz *b){
	if ((a->co != b->li)) {
        printf("Incompativeis");
        exit(EXIT_FAILURE);
    }
	Matriz * nova = criaMatriz(a->li, b->co);
	int soma;
	for (int lin = 0; lin< a->li; lin++) {
        for (int col = 0; col < a->co; col++) {
			soma=0;
			for(int i=0;i<a->li;i++)soma+=a->m[lin][i]*b->m[i][col];
            nova->m[lin][col] = soma;
        }
    }
    return nova;
}

//EXERCICIO 05
Matriz* criaMatrizUns(int li, int co){

	Matriz *aux= (Matriz *) malloc(sizeof (Matriz));
	aux->li= li;
	aux->co= co;
	aux->m = (int **)malloc(li * sizeof(int*));
	for (int i = 0; i < li; i++){
		
		aux->m[i] = (int*) malloc(co * sizeof(int));
		for (int j = 0; j < co; j++){ 
            aux->m[i][j] = 1; 
       }
	}
	return aux;
}

void persiste(Matriz *ma, char * fname){
    FILE *fp = fopen(fname,"w");
    fprintf(fp,"%d %d\n",ma->li,ma->co);
    for (int lin = 0; lin < ma->li; lin++) {
        for (int col = 0; col < ma->co; col++) {
            fprintf(fp,"%d ", ma->m[lin][col]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    
}
Matriz * carrega(char *fname){
    FILE *fp = fopen(fname,"r");
    int lin,col;
    Matriz * Mat;
    fscanf(fp,"%d %d\n",&lin,&col);
    Mat = criaMatriz(lin,col);
     for (int i = 0; i < Mat->li; i++) {
        for (int j = 0; j < Mat->co; j++) {
            fscanf(fp,"%d ", &Mat->m[i][j]);
        }        
    }
    return Mat;
}
	
int main(){
	Matriz *m = criaMatriz(4,2);
	m->m[0][0]=7;
	m->m[1][0]=m->m[2][0]=m->m[3][0]=5;
	printf("--m--\n");
	imprime(m);
	Matriz *a = criaMatrizUns(3,3);
	Matriz *b = criaMatrizUns(3,3);
	a->m[0][1]=7;
	a->m[0][2]=5;
	printf("--a--\n");
	imprime(a);
	printf("--b--\n");
	imprime(b);
	printf("--a*a--\n");
	imprime(multiplica(a,a));
	persiste(a,"a.txt");
	printf("--a.txt--\n");
	imprime(carrega("a.txt"));
	return 0;
}
