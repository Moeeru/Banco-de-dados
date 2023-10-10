//////////////////////////////////////////////////////////////////////////////
///Programa que implementa uma Árvore binária e suas respectivas navegações///
/////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//////////////////////////////
///Declaração de estruturas///
//////////////////////////////
struct no {
int numero;
struct no*esquerda;
struct no *direita;
};
///////////////////////////////////////
///Função que insere um nó na árvore///
//////////////////////////////////////
struct no *inserir(struct no*raiz, int numero){
//caso facil
if (raiz == NULL){
raiz = (struct no *)malloc (sizeof(struct no));
raiz -> numero = numero;
raiz -> esquerda = NULL;
raiz -> direita = NULL;
//caso dificil
}else {
if ((rand()%2)==0) {
raiz -> esquerda = inserir(raiz -> esquerda,numero);
}else {
raiz -> direita = inserir (raiz -> direita, numero);
}
}
return raiz;
}
/////////////////////////////
///Navegação em PRÉ-ORDEM///
///////////////////////////
void navegarPreOrdem (struct no *raiz){
if (raiz!= NULL){
printf("%d\t", raiz -> numero);
navegarPreOrdem(raiz->esquerda);
navegarPreOrdem(raiz->direita);
}
}
////////////////////////////
///Navegação em EM-ORDEM///
///////////////////////////
void navegarEmOrdem (struct no *raiz){
if (raiz!= NULL){
navegarEmOrdem(raiz->esquerda);
printf("%d\t", raiz -> numero);
navegarEmOrdem(raiz->direita);
}
}
/////////////////////////////
///Navegação em PÓS-ORDEM///
///////////////////////////
void navegarPosOrdem (struct no *raiz){
if (raiz!= NULL){
navegarPosOrdem(raiz->esquerda);
navegarPosOrdem(raiz->direita);
printf("%d\t", raiz -> numero);
}
}
///Função principal de execução do programa///
int main (){
//Declaração de variaveis
struct no *raiz = NULL;
//iniciaçização da aleatoriedade
time_t t ;
srand ((unsigned)time (&t));
//prenchimento da árvore
int i = 0;
for (i = 0; i < 10; i ++){
raiz = inserir (raiz,i);
}
//Navegação
printf ("\n======================PRE-ORDEM===================\n");
navegarPreOrdem(raiz);
printf ("\n====================EM-ORDEM======================\n");
navegarEmOrdem(raiz);
printf ("\n=====================POS-ORDEM===================\n");
navegarPosOrdem(raiz);
}
