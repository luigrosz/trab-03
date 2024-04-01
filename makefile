# APAGAR
test:
	mkdir -p output
	gcc main.c -o ./output/programa
	./output/programa

all: pilha.o
	mkdir -p output
	gcc main.c ./output/pilha.o -o ./output/programa
	./output/programa

pilha.o: ./libraries/pilha.c
	mkdir -p output
	gcc -c ./libraries/pilha.c -o ./output/pilha.o

clean:
	rm -rf ./output
	clear
