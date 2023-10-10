///programa que implementa uma lista circular
#include <stdio.h>
#include <stdlib.h>

///declaracao da estrutura do no
struct no{
	int numero;
    struct no *anterior;
	struct no *proximo;
};

//declaracao de variaveis
struct no *cabeca;

//funcao inserir
void inserir(int numero){
	//alocacao de memoria
	struct no *novoNo = (struct no *)malloc(sizeof(struct no));
	novoNo->numero = numero;
    novoNo->anterior = cabeca;
	novoNo->proximo = cabeca;
	
	if(cabeca == NULL){
		cabeca = novoNo;
        novoNo->anterior= cabeca;
		novoNo->proximo = cabeca;
	}else{
		struct no *ponteiro = cabeca;
		
		while (ponteiro->proximo != cabeca){
			ponteiro = ponteiro->proximo;
		}
		
		ponteiro->proximo = novoNo;
        novoNo->anterior = ponteiro;
	}
}

//funcao remover
void remover(int numero){
	if (cabeca != NULL){
		if (cabeca -> numero == numero){
			if(cabeca->proximo == cabeca){
				//caso facil,so tem 1 elemento na lista
				free(cabeca);
				cabeca = NULL;
			}else{
                cabeca = cabeca->anterior;
				free(cabeca->anterior);
			}
		}else{
			//caso dificil, excluir no meio
			struct no *temp = cabeca;
			
			while ((temp->proximo != cabeca) && (temp->proximo->numero != numero)){
				temp = temp->proximo;
			}
			
			if (temp->proximo != cabeca){
				struct no *ponteiroExcluir = temp->proximo;
                temp = temp->anterior;
				ponteiroExcluir->anterior->proximo = ponteiroExcluir->proximo;
                ponteiroExcluir->proximo->anterior = ponteiroExcluir->anterior;
				free(ponteiroExcluir);
                temp = temp->proximo;
            }
		}
	}
}

///funcao imprimir da lista
void imprimir(){
	struct no *ponteiro = cabeca;
	if (ponteiro != NULL){
		while (1){
			printf("%d\n", ponteiro->numero);
			ponteiro = ponteiro->proximo;
			
			if (ponteiro == cabeca){
				break;
			}
		}	
	}
	
	printf("===================\n");
}



///fincao principal do programa para execucao
int main(int argc, char *argv[]){
	int opcao = 0;
	int numero = 0;
	
	while (opcao !=4){
		printf("+==============+\n");
		printf("|Menu de opcoes|\n");
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