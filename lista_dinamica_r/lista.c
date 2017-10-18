#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void cria(t_lista *lista){
	lista->item = malloc(sizeof(t_item) * MAXTAM); // alocando o array de itens
	lista->last = -1;					// ultimo item da lista com um valor inválido
}


void insere_ultimo(t_lista *lista, t_item item){	

	if(lista_cheia(lista)){
		lista->item = realloc(lista->item, ((lista->last + 1)%10) * MAXTAM);
	}

	lista->item[++lista->last] = item;
}

pointer pesquisa(t_lista *lista, t_item pesquisado){

	for (int i = 0; i < lista->last; ++i){
		if(lista->item[i].key == pesquisado.key){		// compara as 
			return i;
		}
	}

	return INVALIDO;
}

void remove_posicao(t_lista *lista, pointer pos){

	if(pos < 0 || pos > lista->last){ // se a posição for menor que 0 ou maior que o ultimo, remoção inválida
		printf("%d não é uma posição válida\n",pos);
		return;
	}


	for (int i = pos; i < lista->last; ++i){
		lista->item[i] = lista->item[i+1]; 		// deslocando os itens para uma posição anterior;
	}	

	lista->last--;

	return;
}

t_item recupera(t_lista *lista, pointer pos){

	if(pos < 0 || pos > lista->last){ // se a posição for menor que 0 ou maior que o ultimo, remoção inválida
		printf("%d não é uma posição válida\n",pos);
		exit(EXIT_FAILURE);
	}


	return lista->item[pos];

}

int num_elementos(t_lista *lista){
	return lista->last + 1 ;
}

int lista_vazia(t_lista *lista){
	if (lista->last < 0){
		return true;
	}else{
		return false;
	}

}


int lista_cheia(t_lista *lista){
	if(lista->last%10  == MAXTAM - 1){
		return true;
	}else{
		return false;
	}

}