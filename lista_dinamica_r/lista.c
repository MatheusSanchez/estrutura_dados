#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int existe_lista(t_lista *lista){
	if(lista != NULL){
		return true;
	}else{
		printf("A lista Não foi criada !\n");
		return false;
	}
}

void cria(t_lista **lista){
	*lista = malloc(sizeof(lista));
	(*lista)->item = malloc(sizeof(t_item) * MAXTAM); // alocando o array de itens
	(*lista)->last = -1;					// ultimo item da lista com um valor inválido
	printf("Lista Alocada Com sucesso !\n");
}

void insere_ultimo(t_lista *lista, t_item item){	
	if(existe_lista(lista)){
		if(lista_cheia(lista)){
			lista->item = realloc(lista->item, (((lista->last/10) * MAXTAM) + MAXTAM)*sizeof(item));
		}

		lista->item[++lista->last] = item;
	}
}

pointer pesquisa(t_lista *lista, t_item pesquisado){
	if(existe_lista(lista)){
		for (int i = 0; i < lista->last; ++i){
			if(lista->item[i].key == pesquisado.key){		// compara as 
				return i;
			}
		}
	}
	return INVALIDO;
}

void remove_posicao(t_lista *lista, pointer pos){
	if(existe_lista(lista)){

		if(pos < 0 || pos > lista->last){ // se a posição for menor que 0 ou maior que o ultimo, remoção inválida
			printf("%d não é uma posição válida !\n",pos);
			return;
		}

		for (int i = pos; i < lista->last; ++i){
		lista->item[i] = lista->item[i+1]; 		// deslocando os itens para uma posição anterior;
	}	

		lista->last--;
		printf("Numero na posição %d retirado.\n", pos);
		return;

	}
}



int recupera(t_lista *lista, pointer pos){
	if(pos <= lista->last && pos >= 0){
		return lista->item[pos].key	;
	}else{
		return INVALIDO;
	}
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

void print_lista(t_lista * lista){
	for (int i = 0; i <= lista->last; i++){
		printf("%d ", lista->item[i].key);
	}
	printf("\n");
}

int lista_cheia(t_lista *lista){
	if(lista->last%10  == MAXTAM - 1){
		return true;
	}else{
		return false;
	}

}

void insere(t_lista *lista, t_item item, pointer pos){	
	if(existe_lista(lista)){
		if(pos < lista->last && pos >= 0){
			if(lista_cheia(lista)){
				lista->item = realloc(lista->item, (((lista->last/10) * MAXTAM) + MAXTAM)*sizeof(item));
			}
			for (int i = lista->last; i > pos; i--){
				lista->item[i] = lista->item[i-1]; 
			}	

			lista->item[pos] = item;
			lista->last++;
		}else{
			printf("Posição Invalida\n");
		}
	}
}
