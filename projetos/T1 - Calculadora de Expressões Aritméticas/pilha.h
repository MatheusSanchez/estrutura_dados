#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

typedef struct _item{
  char c_item;
  double n_item;		// item da lista 
}item;


typedef struct _pilha{
	int topo;	// int que indica o topo da pilha no array
	int max_elem;		
	item *pont;	//	array com todos os itens 		
}pilha;	

typedef pilha* t_apontador;	

pilha* cria_p();	
void push_num(pilha *p, double item);	//coloca um numero na pilha
void push_char(pilha *p, char item);	//coloca um char na pilha
void pop(pilha *p);		//retira o último elemento da pilha
void free_pilha(pilha *p);  // liberação de memória da estrutura como um todo
void exibe(pilha *p);		// função de debug para exibir a pilha
void aumenta_pont(pilha *p);	// aumenta a capacidade de itens que o array(pilha) suporta

#endif