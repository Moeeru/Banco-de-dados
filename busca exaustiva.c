// programa de busca exaustiva
#include <stdio.h>
#include <stdlib.h>

//declaração de variaveis
int vetor[10000];
int i = 0;
int achei = 0;
int busca = 0;

//funcao princiapl
int main(){
	//preenchendo a lista| Inicialização da memoria
	for (i = 0 ; i < 10000 ; i++){
		vetor[i] = (rand() % 10000);
	}
	
	// perguntar parametro de busca
	printf("Digite o valor da busca: ");
	scanf("%d", &busca);
	
	//busca propriamente dita
	achei = -1;
	for (i = 0 ; i < 10000 ; i++){
		if ( vetor[i] == busca){
			achei = i;
		}
	}
	
	if (achei == -1){
		printf("Se fodeu! Não exite");
	}else{
		printf("ACHEI PORRA!!! Na posição %d\n", achei);
	}

}
