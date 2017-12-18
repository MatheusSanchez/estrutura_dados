
#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

void inicia(arvore** tree){ // malocando a estrutura
	*tree = malloc(sizeof(arvore));
	(*tree)->raiz = NULL; 	
}

void cria_no(no **raiz, int item, no* pai){ 

	(*raiz) = malloc(sizeof(no)); // malocando o nó e setando os valores padrões
	(*raiz)->esq = NULL;
	(*raiz)->pai = pai;
	(*raiz)->dir = NULL;
	(*raiz)->item = item;
	(*raiz)->cor = red;
}

void insere(arvore *tree, int item){ // inserção em arvore binária

	no** aux = &(tree->raiz);
	no* pai = NULL;

	while(*aux != NULL){	 //achando a posição certa
		pai = *aux;
		if(item < (*aux)->item){
			aux = 	&((*aux)->esq);
		}else if (item > (*aux)->item){	
			aux = &((*aux)->dir);
		}else{
			printf("item existente\n");
			return;
		}
	}
	cria_no(aux,item,pai); // criando o nó, ja setando o pai
	arruma_rb(tree,*aux); // rebalanceamento da arvore vermelho e preto	
}

void arruma_rb(arvore* tree, no* novo){
	no* y;
	while(novo->pai != NULL && novo->pai->cor == red){
		if(novo->pai == novo->pai->pai->esq){
			y = novo->pai->pai->dir;
			if(y != NULL && y->cor == red){
				novo->pai->cor = black;
				y->cor = black;
				novo->pai->pai->cor = red;
				novo = novo->pai->pai;
			}else{
				if(novo != NULL && novo->pai->dir != NULL && novo->item == novo->pai->dir->item){
					novo = novo->pai;
					rotacao_esq(tree, novo);
				}
				novo->pai->cor = black;
				novo->pai->pai->cor = red;
				rotacao_dir(tree, novo->pai->pai);
			}
		}else{
			y = novo->pai->pai->esq;
			if(y != NULL && y->cor == red){
				novo->pai->cor = black;
				y->cor = black;
				novo->pai->pai->cor = red;
				novo = novo->pai->pai;
			}else{
				if(novo != NULL && novo->pai->esq != NULL && novo->item == novo->pai->esq->item){
					novo = novo->pai;
					rotacao_dir(tree, novo);
				}
				novo->pai->cor = black;
				novo->pai->pai->cor = red;
				rotacao_esq(tree, novo->pai->pai);
			}
		}
	}
	tree->raiz->cor = black;
}


void pre_ordem(no* raiz){ // impressão pré ordem
	if(raiz != NULL){
		visita(raiz);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);

	}
}

void em_ordem(no * raiz){ // impressão em ordem
	if(raiz != NULL){
		em_ordem(raiz->esq);
		visita(raiz);
		em_ordem(raiz->dir);
	}
}

void pos_ordem(no * raiz){ // impressão pos ordem
	if(raiz != NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		visita(raiz);
	}
}

void visita(no *raiz){ 
	if(raiz != NULL){
		printf("%d ", raiz->item);
	}
}


void rotacao_esq(arvore* tree, no* atual){ // rotação esquerda do nó

	no* aux = atual->dir; //guardando a referencia do filho da direita
	atual->dir = aux->esq;	// o no atual adota o neto direita->esquerda

	if(aux->esq != NULL) 
		aux->esq->pai = atual; // arrumando o ponteiro "pai" do neto direita->esquerda do atual

	

	if(atual->pai == NULL){ // se o atual não tem pai, ele é raiz
		tree->raiz = aux;		// entao colocaremos a referencia lá

	}else if(atual == atual->pai->esq){ // se o atual era filho esquerdo de seu pai
		atual->pai->esq = aux;	// o filho esquerdo sera a referencia
	}else {			//se não
		atual->pai->dir = aux;	// o filho direito sera a referencia
	}

	aux->pai = atual->pai; // o pai da referencia vai ser o avo (pai do atual);
	aux->esq = atual; //filho esquerdo da referencia passa a ser o atual; 
	atual->pai = aux;	// e o pai do atual passa a ser a referencia

}

void rotacao_dir(arvore* tree, no* atual){

	no* aux = atual->esq;   // agora nossa referencia é o filho esquerdo
	atual->esq = aux->dir;  // o no atual adota o neto esquerdo->direito

	if(aux->dir != NULL) {  // arrumando o ponteiro "pai" do neto esquerda->direita do atual
		aux->dir->pai = atual;
	}
	
	if(atual->pai == NULL) { // se o atual não tem pai, ele é raiz
		tree->raiz = aux;
	}
	else if(atual == atual->pai->dir) { // se o atual era filho direito de seu pai
		atual->pai->dir = aux; // o filho direito sera a referencia
	}else{ 
		atual->pai->esq = aux;  // o filho esquerdo sera a referencia
	}

	aux->pai = atual->pai; // o pai da referencia vai ser o avo (pai do atual);
	aux->dir = atual;  //filho direito da referencia passa a ser o atual; 
	atual->pai = aux; // e o pai do atual passa a ser a referencia

}

void min(arvore *tree){ // acha o menor valor da árvore
	
	no* aux = tree->raiz;

	while(aux->esq != NULL){  // o menor valor é o mais a esquerda possível
		aux = aux->esq;
	}

	printf("%d\n", aux->item);

}

void max(arvore *tree){  // acha o maior valor da árvore
	no* aux = tree->raiz;

	while(aux->dir != NULL){ // o maior valor é o mais a direita possível
		aux = aux->dir;
	}

	printf("%d\n", aux->item);

}

void predecessor(arvore *tree, int k){ // para achar o predecessor temos duas opçõe

	no* query = busca(tree->raiz,k);

	if(query != NULL){ // se o nó existe na arvore

		if(query->esq != NULL){ // se o nó tem filho a esquerda
			query = query->esq; // va para esquerda

			while(query->dir != NULL){ // desça tudo para direita
				query = query->dir;
			}
			printf("%d\n", query->item);

		}else{ // caso o nó nao tenha filho a esquerda

			if(query == query->pai->dir){  // seu predecessor é seu pai, caso o nó for filho direito
				printf("%d\n", query->pai->item);
			}else{
				printf("erro\n");
			}
		}

	}
}

void sucessor(arvore *tree, int k){

	no* query = busca(tree->raiz,k);

	if(query != NULL){ // se o nó existe na arvore

		if(query->dir != NULL){ // se o nó tem filho a direita
			query = query->dir;  // va para direita

			while(query->esq != NULL){ // desça tudo para esquerda
				query = query->esq;
			}
			printf("%d\n", query->item);

		}else{ // caso o nó nao tenha filho a direita

			if(query == query->pai->esq){ // seu sucessor é seu pai, caso o nó for filho esquerdo
				printf("%d\n", query->pai->item);
			}else{
				printf("erro\n");
			}

		}
	}

}

no* busca(no* raiz, int item){ // busca em arvore binaria normal
	if(raiz != NULL){

		if(raiz->item == item){
			return raiz;	
		}else if(raiz->item > item){ 
			return busca(raiz->esq, item);
		}else if(raiz->item < item){ 
			return busca(raiz->dir, item);
		}

	}	

	printf("erro\n");
	return raiz;
}

void pos_ordem_free(no *raiz){ // free nos nós
	if(raiz != NULL){
		pos_ordem_free(raiz->esq);
		pos_ordem_free(raiz->dir);
		free(raiz);
	}
}

void free_tree(arvore* tree){ // free estrutura arvore
	pos_ordem_free(tree->raiz);
	free(tree);
}