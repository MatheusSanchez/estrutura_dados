#ifndef OPERACOES_H
#define OPERACOES_H
	
	double select_op(char op, double num, double num2);  // faz a operação desejada entre dois numeros

	void empilha(pilha * p_op, pilha* p_num, char *operacao);	// executa o algoritmo "shunting-yard", responsavel por 
																// transformar a expressao em notação infixa para notação posfixa (Polonesa Reversa);	
#endif															// desde modo executar as opeações fica mais facil;