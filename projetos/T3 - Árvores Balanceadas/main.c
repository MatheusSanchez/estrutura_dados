/* 	
	USP-ICMC -> Instituto de Ciências Matemáticas e Computação

	Matheus Sanchez nº 9081453
   	SCC202-2017 Algoritmos e Estrutura de Dados - 2º semestre;

   	Trabalho com intuito de implementar a estrutura "Arvore Vermelho e Preto"

*/


#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"



int main(){

	int n;
	int op,val;
	scanf("%d",&n);

	arvore *tree;
	inicia(&tree);

	while(n>0){

		scanf("%d",&op);

		if(op == 1){
			scanf("%d",&val);
			insere(tree, val);
		}else if(op == 2){
			scanf("%d",&val);
			sucessor(tree,val);
		}else if(op == 3){
			scanf("%d",&val);
			predecessor(tree,val);
		}else if(op == 4){
			max(tree);
		}else if(op == 5){
			min(tree);
		}else if(op == 6){
			pre_ordem(tree->raiz);
			printf("\n");
		}else if(op == 7){
			em_ordem(tree->raiz);
			printf("\n");
		}else if(op == 8){
			pos_ordem(tree->raiz);
			printf("\n");
		}

		n--;
	}

	free_tree(tree);
}