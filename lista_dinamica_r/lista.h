#ifndef LISTA_ESTAT_H
#define LISTA_ESTAT_H

#define MAXTAM 10
#define INVALIDO -1
#define true 1
#define false 0
	
typedef struct _item{
	int key;
}t_item;

typedef int pointer;

typedef struct _lista{

	t_item *item;
	pointer last;

}t_lista;



void cria(t_lista **lista); // criação da lista
void insere_ultimo(t_lista *lista, t_item item); // inserção no ultimo da lista  O(1);
pointer pesquisa(t_lista *lista, t_item chave); // pesquisa algum item percorrendo o array, O(n);
void remove_posicao(t_lista *lista, pointer pos); // remove de qualquer posição do array, O(n);	
int recupera(t_lista *lista, pointer pos);
int num_elementos(t_lista *lista);
int lista_vazia(t_lista *lista);
int lista_cheia(t_lista *lista);
void print_lista(t_lista * lista);
int existe_lista(t_lista *lista);
void insere(t_lista *lista, t_item item, pointer pos);

#endif