///////////////////////////////////////////////////
///PROGRAMA QUE IMPLEMENTA UMA LISTA///
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////
///declara��o de estrutura do no///
///////////////////////////////////////

struct no {
  int numero;
  struct no *proximo;
};

//////////////////////////////////
//////declara��o de variaveis/////
//////////////////////////////////

struct no *cabeca = NULL;

///////////////////////////////////////
///fun��o que insere um no nq fila///
/////////////////////////////////////

void inserir (int numero){
  struct no *novoNo = (struct no *) malloc (sizeof(struct no ));
  novoNo -> numero = numero;
  novoNo -> proximo = cabeca; 
  cabeca = novoNo;
}

///////////////////////////////////////
///fun��o que remove um no na fila////
/////////////////////////////////////

int remover (){
  int retorno = -1;
  
  if (cabeca != NULL){
    if (cabeca -> proximo == NULL){
      // a fila tem s� 1 no 
      retorno = cabeca -> numero;
      free(cabeca),
      cabeca = NULL;
    } else {
      //a fila tem mais de 1 no 
      struct no *ponteiroAnterior = cabeca;
      
      //procua do penultimo no da fila
      while (ponteiroAnterior -> proximo -> proximo != NULL){
        ponteiroAnterior = ponteiroAnterior -> proximo;

      }
      //remo��o do ultimo no da fila 
      retorno = ponteiroAnterior -> proximo -> numero;
      free(ponteiroAnterior -> proximo);
      ponteiroAnterior -> proximo = NULL;
      
    }
    
  }
  return retorno;
}

////////////////////////////////////
/////fun��o qu imprime a fila//////
/////////////////////////////////

void imprimir (){
  struct no *ponteiro = cabeca; 
  
  printf ("============FILA=============\n");
  while (ponteiro != NULL){
    printf("%d\t", ponteiro->numero);
    ponteiro = ponteiro -> proximo; 
  }
  printf("\n");
}


////////////////////////////////////////////////
/////fun��o principal de execu��o do progrma////
///////////////////////////////////////////////


int main () {
  int opcao =0;
  int numero = 0;
  
  while (opcao != 4){
    printf("+====================+\n");
    printf("|   Menu de Opcoes   |\n");
    printf("+====================+\n");
    printf("|      1 - Inserir   |\n");
    printf("|      2 - Remover   |\n");
    printf("|      3 - Imprimir  |\n");
    printf("|      4 - Sair      |\n");
    printf("+====================+\n");
    printf("Digite sua opcao: ");
    scanf("%d",&opcao);
    
    switch(opcao) {
      case 1:
        printf("Digite um numero : ");
        scanf("%d", &numero);
        inserir(numero);
        break;
      case 2 :
        printf("Removi o numero %d da fila\n", remover ());
        break;
      case 3 : 
      imprimir ();
      break;
    }
  }
}