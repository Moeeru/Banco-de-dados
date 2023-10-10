///programa que implementa uma lista de duplo encadeamento
#include <stdio.h>
#include <stdlib.h>

///declaracao da estrutura do no
struct no{
	int numero;
	struct no *anterior;
	struct no *proximo;
};

///declaração de variaveis
struct no *cabeca = NULL;

///funcao que insere um no na lista
void inserir(int numero){
	//Alocacao da memoria
	struct no *novoNo = (struct no *)malloc(sizeof(struct no));
	novoNo->numero = numero;
	novoNo->anterior = NULL;
	novoNo->proximo = NULL;
	
	//caso facil, lista vazia
	if (cabeca == NULL){
		cabeca = novoNo;
	}else{
		//caso dificil, lista nao vazia
		struct no *ponteiro = cabeca;
		
		///procura o ultimo no da lista
		while (ponteiro->proximo != NULL){
			ponteiro = ponteiro->proximo;
		}
		
		///configura os apontamentos
		ponteiro->proximo = novoNo;
		novoNo->anterior = ponteiro;
	}
}

//funcao que remove elementos da lista
void remover(int numero){
	//caso facil, lista nao existe
	struct no *ponteiro = cabeca;
		
	while (ponteiro != NULL){
		if (ponteiro->numero==numero){
			if (ponteiro->anterior == NULL){
				//excluir primeiro da lista
				cabeca = cabeca->proximo;
				if (cabeca != NULL){
					cabeca->anterior = NULL;
				}
				free(ponteiro);
				ponteiro = cabeca;
			}else if (ponteiro->proximo == NULL){
				//Excluir o ultimo no da lista
				struct no *temp = ponteiro;
				ponteiro = ponteiro->anterior;
				ponteiro->proximo = NULL;
				free(temp);
			}else{
				//Excluir no meio
				struct no *temp = ponteiro;
				ponteiro = ponteiro->anterior;
				temp->anterior->proximo = temp->proximo;
				temp->proximo->anterior = temp->anterior;
				free(temp);
			}
		}
		
		if(ponteiro != NULL){
			ponteiro = ponteiro->proximo;
		}
	}
}

//funcao imprimir da lista
void imprimir(){
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL){
		printf("%d\n", ponteiro->numero);
		ponteiro = ponteiro->proximo;
	}
	
	printf("===================\n");
}

///fincao principal do programa para execucao
int main(int argc, char *argv[]){
	int opcao = 0;
	int numero = 0;
	
	while (opcao !=4){
		printf("+==============+\n");
		printf("|Menu de opções|\n");
		printf("+==============+\n");
		printf("|1 - Inserir   |\n");
		printf("|2 - Remover   |\n");
		printf("|3 - Imprimir  |\n");
		printf("|4 - sair      |\n");
		printf("+==============+\n");
		printf("Digite sua escolha: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("Digite o numero: ");
				scanf("%d", &numero);
				inserir(numero);
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &numero);
				remover(numero);
				break;
			case 3:
				imprimir();
				break;
			case 4:
				break;	
		}
	}
}
