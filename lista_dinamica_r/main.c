#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void menu(){
	printf("\n");
	printf("Menu:\n");
	printf("1-> Cria Lista\n");
	printf("2-> Insere Na ultima posição\n");
	printf("3-> Busca Na lista\n");
	printf("4-> Recupera alguem elemento\n");
	printf("5-> Print Lista\n");
	printf("6-> Retira um item da Lista (Por Posição)\n");
	printf("7-> Insere Na posição desejada\n");
	printf("0 -> Sai do Programa\n");
	printf("Digite uma opção: ");
}


int main(){

	int n,k;
	t_item aux;
	t_lista *lista = NULL;


	menu();

	scanf("%d",&n);

	while(n != -1){

		switch(n){

			case 1:
				printf("\n");
				cria(&lista);
				break;
			case 2:
				printf("\n");
				printf("Numero a ser inserido: ");
				scanf("%d",&(aux.key));
				insere_ultimo(lista,aux);
				break;
			case 3:
				printf("\n");
				printf("Numero a ser buscado: ");
				scanf("%d",&(aux.key));
				k = pesquisa(lista,aux);
				if(k != INVALIDO){
					printf("Achei o numero na posição %d \n", k+1);
				}
				break;
			case 4:
				printf("item número: ");
				scanf("%d",&(aux.key));
				printf("\n");
				k = recupera(lista,aux.key);	
				if(k!=INVALIDO){
					printf("nº %d\n", k);
				}else{
					printf("Posição Invalida\n");
				}

			case 5:
				printf("\n");
				printf("Lista: ");	
				print_lista(lista);
				break;

			case 6:
				printf("\n");
				printf("item número: ");
				scanf("%d",&(aux.key));
				printf("\n");
				remove_posicao(lista,aux.key);	
				break;

			case 7:
				printf("\n");
				printf("Numero a ser inserido: ");
				scanf("%d",&(aux.key));
				printf("\n");
				printf("Posição a ser inserido: ");
				scanf("%d",&(k));
				insere(lista,aux,k);
				break;	

			default:
				printf("Numero Inválido !!!!!!\n");						
				break;
		}


		menu();
		scanf("%d",&n);
	}







}