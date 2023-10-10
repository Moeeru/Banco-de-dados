///////////////////////////////////////////////////////////////
///////Programa que implementa uma �rvore de ordem 5//////////
/////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//////////////////////////////////
/////Declara��o de estrutura//////
/////////////////////////////////

struct no {
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

//////////////////////////////////////////////
///////Fun��o que insere um no na �rvore//////
/////////////////////////////////////////////

struct no *inserir (struct no *raiz,int numero){
	if (raiz == NULL){
		//caso facil,a �rvore esta vazia
		raiz = (struct no *) malloc (sizeof (struct no));
		raiz -> numero = numero;
		raiz -> filho1 = NULL;
		raiz -> filho2 = NULL;
		raiz -> filho3 = NULL;
		raiz -> filho4 = NULL;
		raiz -> filho5 = NULL;
	
	}else {
		//caso dif�cul, a �rvore n�o est� vazia 
		int sorteio = (rand()%5);
		
		if (sorteio == 0){
			raiz -> filho1 = inserir(raiz -> filho1,numero);	
		}else if (sorteio == 1){
			raiz -> filho2 = inserir(raiz -> filho2, numero);
		}else if (sorteio == 2){
			raiz -> filho3 = inserir(raiz -> filho3, numero);
		}else if (sorteio == 3){
			raiz -> filho4 = inserir(raiz -> filho4, numero);
		}else if (sorteio == 4){
			raiz -> filho5 = inserir(raiz -> filho5, numero);
		}
	}
	return raiz ;
}

///////////////////////////////////
/////Fu��o que imprime a �rvore////
//////////////////////////////////

void imprimir (struct no *raiz, char *endentacao) {
	if (raiz != NULL) {printf("%s%d",endentacao, raiz -> numero);
		char *temp = (char *) malloc (1024 * sizeof(char));
		strcpy(temp, "-----");
		strcat(temp, endentacao);
	
		imprimir (raiz -> filho1, temp);
		imprimir (raiz -> filho2, temp);
		imprimir (raiz -> filho3, temp);
		imprimir (raiz -> filho4, temp);
		imprimir (raiz -> filho5, temp); 
	}
}

////////////////////////////////////////////////////
/////fun��o principal de execu��o do programa///////
///////////////////////////////////////////////////

int main () {
	//inicializa��o da aleatoriedade
	time_t t;
	srand((unsigned) time (&t));
	
	//declara��o da raiz 
	struct no *raiz = NULL;
	
	//declara��o do endentador 
	char *endentador = (char *) malloc (1024 * sizeof(char));
	strcpy (endentador, "");
	
	//menu de op��es
	int opcao = 0;
	
	while (opcao != 3){
		printf("+================+ \n");
		printf("| Menu de op��es | \n");
		printf("+================+ \n");
		printf("|   1- Inserir   | \n");
		printf("|   2- Imprimir  | \n");
		printf("|   3- Sair      | \n");
		printf(" +================+ \n");
		printf("Digite sua op��o : ");
		scanf("%d", &opcao);
		
		if (opcao == 1){
			int numero = 0;
			printf("Digite o numero: ");
			scanf ("%d", &numero);
			raiz = inserir (raiz, numero);	
		}else if (opcao == 2){
			imprimir (raiz, endentador);
		}
	}
}



