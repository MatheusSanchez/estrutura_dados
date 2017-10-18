#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void menu(){
	printf("Menu:\n");
	printf("1-> Cria Lista\n");
	printf("2-> Insere Na ultima posição\n");
	printf("3-> Busca Na lista\n");
	printf("4-> Recupera o ultimo item da lista\n");
	printf("5-> Print Lista\n");
	printf("-1 -> Sai do Programa\n");
	printf("Digite uma opção: \n");
}


int main(){

	int n;
	t_item aux;
	t_lista *lista;

	menu();

	scanf("%d",n);

	while(n != -1){

		switch(n){

			case 1:
				cria(lista);
			case 2:
				printf("Numero a ser inserido: ");
				scanf("%d",&(aux->key));
				insere_ultimo(lista,aux);
			case 3:
				printf("Numero a ser pesquisado: ");
				scanf("%d",&(aux->key));
				insere_ultimo(lista,aux);
			case 1:
				cria(lista);
			case 1:
				cria(lista);
			case 1:
				cria(lista);
			default:
				printf("Numero Inválido !!!!!!\n");						

		}


		menu();
		scanf("%d",n);
	}







}