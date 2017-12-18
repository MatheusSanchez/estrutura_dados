#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "operacoes.h"

int main(){

	pilha * p_op = cria_p(); // pilha para as operações
	pilha * p_num = cria_p(); // pilha para os numeros

	char exp[1000];			// vetor que armazena a expressao
	fgets(exp,1000,stdin);	
	exp[strlen(exp)] = '\0';
	
	while(exp[strlen(exp)-1] != ','){ // enquanto o ultimo caracter for diferente de ,
		
		empilha(p_op,p_num,exp); 		// empilha a expressão de modo calculável
		fgets(exp,1000,stdin);	 		// pega a próxima expressão
		exp[strlen(exp)] = '\0';	
	
		p_op->topo = -1;			// limpa ambas as pilhas para a próxima iteração
		p_num->topo = -1;			// observe que os elementos da iteração anterior continuam na pilha
	}								// contudo são ignorados;

	empilha(p_op,p_num,exp);   // executa o empilhamento para a ultima expressão;
	
	free_pilha(p_op);		// liberação de memória das duas pilhas
	free_pilha(p_num);			
}	