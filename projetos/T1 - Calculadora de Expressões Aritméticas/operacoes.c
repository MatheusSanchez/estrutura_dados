#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"
#include "operacoes.h"

double select_op(char op, double num, double num2){ // executa a operação desejada entre dois numeros
	double resp;
	switch(op){
		case '+':
		resp = num+num2; //soma
		break;
		case '-':
		resp = num-num2; // subtração
		break;
		case '/':
			resp = num/num2; // divisão
		break;
		case '*':
		resp = num*num2; // multiplicação
		break;

		default:
		printf("Operador Inválido\n");
		resp = -1;
	}
	return resp;
}

void calcula(pilha *p_num){	// calculo da expressão ja na notação posfixa

	pilha *p_calc = cria_p();  // pilha auxiliar para fazer o calculo
	double n1,n2;

	for (int i = 0; i <= p_num->topo; i++){		// percorremos a pilha inteira

		if(p_num->pont[i].c_item == '='){	// enquanto estivermos com numeros na pilha 
			
			push_num(p_calc,p_num->pont[i].n_item);	// fazemos um push na pilha do calculo
			
		}else{		// assim que na pilha entrar um sinal

			n1 = p_calc->pont[p_calc->topo -1].n_item;		// pegamos os dois ultimos numeros
			n2 = p_calc->pont[p_calc->topo].n_item;
			
			pop(p_calc);	// retiramos eles da pilha do calculo
			pop(p_calc);

			if(p_num->pont[i].c_item == '/' && n2 == 0){ // verifica divisão por zero
				printf("Expressao incorreta\n");
				return;
			}

			push_num(p_calc,select_op(p_num->pont[i].c_item,n1,n2));	// fazemos um push na pilha de calculo 
		}																// da operação selecionada na pilha "enviada" por parâmetro
	}																	// e dos dois ultimos numeros da pilha de cálculo			
	printf("%.2lf\n", p_calc->pont[p_calc->topo].n_item);		// ao final apenas printamos o único elemento restante na pilha de calculo
	

	free_pilha(p_calc); // liberamos a pilha de calculo
}


void empilha(pilha * p_op, pilha* p_num, char *operacao){ // algoritmo shunting-yard 
	
	int i = strlen(operacao);

	do{							//retirando os lixos da expressão
								// isto é, ";" "," e tudo que estiver	
		operacao[i] = '\0';		// ao final
		i--;					

	}while(operacao[i] != ',' && operacao[i] != ';');

	operacao[i] = '\0';
	i--;

	for (int k = 0; k <= i; k++){	// para todo caracter da expressao
		
		if(!(operacao[k] == 32)){	// se o caracter nao for espaço
			
			if(operacao[k] >= '0' && operacao[k] <= '9'){ // se o caracter for um numero

				double aux = (double)(operacao[k] - 48);	// numero atual
				k++;	// próximo caracter
				
				//podemos ter numeros com mais de um caracter ou números com pontos flutuantes
				while(operacao[k] != 32 && operacao[k] != ')' 
					&& operacao[k] != '.' && operacao[k] != '\0'){  // equanto existem numeros para serem lidos

					aux = aux * 10.0;					// multiplique o que ja esta acumulado por 10
					aux += (double)(operacao[k] - 48) ;	// e some o proximo numero
					k++;		
				}

				if(operacao[k] == '.'){		// caso achemos um numero com ponto flutuante
					k++;
					int potencia = -1;

					while(operacao[k] != 32 && operacao[k] != ')' && operacao[k] != '\0'){ // vamos ler todos os proximos numeros
						aux +=  (operacao[k]-48)*pow(10,potencia); // multiplicar pela potencia de 10 negativa para formar a parte flutuante do numero
						k++;	
						potencia--;	
					}
				}	
				k--;

				push_num(p_num,aux); // coloque o numero calculado na pilha;

			}else if(operacao[k] == '('){	// caso o caracter seja a abertura de um parenteses	

				push_char(p_op, operacao[k]);	// apenas coloque ele na pilha

			}else if(operacao[k] == ')'){ 	// caso o caracter seja o fechamento de um parenteses	
					
					while(p_op->topo>= 0 && p_op->pont[p_op->topo].c_item != '('){	// pop na pilha de operações
																					// até achar um parenteses abrindo
						push_char(p_num,p_op->pont[p_op->topo].c_item);		// coloque todas os sinais entre os parenteses na pilha de numeros
						pop(p_op);
					}

					if(!(p_op->topo >= 0)){  				// se o topo não estiver >= 0, significa que o laço de cima não achou  '('
						printf("Expressao incorreta\n");	// logo, expressão errada e sai da função
						return;
					}else{
						pop(p_op);	 // tira o parenteses '('
					}
						
			}else{ // aqui o caracter é necessariamente um operador

				// aqui verificamos se o operador atual tem menor precedência do que o operador que esta no topo
				// da pilha de operadores;


				if(p_op->topo >= 0 && 
				(p_op->pont[p_op->topo].c_item == '*' || p_op->pont[p_op->topo].c_item == '/')){  // operadores de maiores precedências '/' '*'

					push_char(p_num,p_op->pont[p_op->topo].c_item); // caso tenha, pop na pilha de operadores
					pop(p_op);										// e este operador entra na pilha de numeros
				}

				push_char(p_op, operacao[k]); // coloque o caracter na pilha de operações
	
			}
				
		}
	}

	// vamos colocar oque sobrou na pilha de operações para a pilha de numeros

	while(p_op->topo >= 0){  

		if(p_op->pont[p_op->topo].c_item == '('){	// se algum parenteses abriu e nao fechou
			printf("Expressao incorreta\n");		// expressao mal formatada	
			return;											
		}	

		push_char(p_num,p_op->pont[p_op->topo].c_item);
		pop(p_op);
	}

	// neste ponto temos uma pilha com a expressao em notação polonesa
	// exibe(p_num);

	calcula(p_num); // faz o calculo da expressão que esta na pilha
}