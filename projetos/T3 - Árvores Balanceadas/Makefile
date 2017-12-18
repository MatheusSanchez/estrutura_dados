# Compilador gcc
CP = gcc
# Parâmetros de compilação
P_CO = -c -lm -Wall -pedantic -g 

all: main.o arvore.o
	$(CP) main.o arvore.o -o main -lm

main: main.o arvore.o
	$(CP) main.o arvore.o -o main -lm

arvore.o: arvore.c 
	$(CP) $(P_CO) arvore.c	

main.o: main.c 
	$(CP) $(P_CO) main.c

run_teste: main 
	./main < entrada.txt 
	make clean

zip:
	zip arvore.zip arvore.h arvore.c main.c Makefile nome

run: main
	./main
	make clean

clean: 
	rm -rf *o main

valgrind: main
	valgrind --leak-check=full --track-origins=yes ./main < entrada.txt