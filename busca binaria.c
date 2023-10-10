// programa de busca binária
#include <stdio.h>

//declaração de variaveis
int vetor[10000];
int i = 0;
int achei = 0;
int busca = 0;
int inicio = 0;
int fim = 0;
int meio = 0;


//funcao princiapl
int main(){
	//preenchendo a lista| Inicialização da memoria
	for (i = 0 ; i < 10000 ; i++){
		vetor[i] = i;
	}
	
	// perguntar parametro de busca
	printf("Digite o valor da busca: ");
	scanf("%d", &busca);
	
	//busca propriamente dita
	inicio = 0;
	fim = 9999;
	while (fim >= inicio){
		meio = ((inicio + fim) / 2);
		
		if (busca == vetor[meio]){
			achei = meio;
			printf("ACHEI PORRA!!! Na posição %d\n", achei);
			return 0; 
		}else if (busca > vetor[meio]){
			inicio = (meio + 1);
		}else {
			fim = (meio -1);
		}
	}
	printf("Se fodeu! Não exite");
}
