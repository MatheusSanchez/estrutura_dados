# Compilador gcc
CP = gcc
# Parâmetros de compilação
P_CO = -c -lm -Wall -pedantic -g 


main: operacoes.o main.o pilha.o
	$(CP) main.o operacoes.o pilha.o -o main -lm

all: operacoes.o main.o pilha.o
	$(CP) main.o operacoes.o pilha.o -o main -lm

operacoes.o: operacoes.c pilha.o
	$(CP) $(P_CO) operacoes.c

pilha.o: pilha.c 
	$(CP) $(P_CO) pilha.c	

main.o: main.c 
	$(CP) $(P_CO) main.c

run: main
	./main 

clean: 
	rm -rf *o main