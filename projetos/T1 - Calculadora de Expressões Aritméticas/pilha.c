#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void exibe(pilha *p){
	for (int i = p->topo; i>= 0; i--){
		printf("%lf %c\n", p->pont[i].n_item,p->pont[i].c_item);
	}	
}

pilha* cria_p(){

	pilha *p = malloc(sizeof(pilha)); // aloca um ponteiro para a estrutura "pilha"
	p->topo = -1;			
	p->max_elem = 10;
	p->pont = malloc((sizeof(item)*p->max_elem));
	return p;

}

void aumenta_pont(pilha *p){

	p->max_elem += 10;  
	p->pont = realloc(p->pont,(sizeof(item)*p->max_elem)); // aumentando a capacidade do array em +10 itens

}

void push_num(pilha *p, double novo){

	if(p->topo + 1 == p->max_elem){ //caso a pilha encher, alocaremos mais memória
		aumenta_pont(p);			
	}

	p->pont[++p->topo].n_item = novo; //incremente um no topo e coloque o novo item 
	p->pont[p->topo].c_item = '=';	// sinal padrao para indicar que aquele item é um número
	
}

void push_char(pilha *p, char novo){

	if(p->topo + 1 == p->max_elem){ //caso a pilha encher, alocaremos mais memória
		aumenta_pont(p);
	}

	p->pont[++p->topo].c_item = novo;  //incremente um no topo e coloque o novo item 
	
}

void pop(pilha *p){

	if(p->topo >= 0){ // se a pilha tem algum elemento
		p->topo--; 	// decremente o topo, fazendo com que o elemento continue no topo
	}				// mas é ignorado;	

}



void free_pilha(pilha* p){
	
	
	if(p->max_elem > 0){
		free(p->pont);	// liberação de memória do array	
	}
	free(p);		// depois liberamos a estrutura "pilha"

}
