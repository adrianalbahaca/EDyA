# Crear archivo programa usando el comando 'make'
CC := gcc
CFLAGS := -Wall -Wextra -Werror

programa: main.o pila.o arregloenteros.o
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

main.o: main.c pila.h arregloenteros.h
	$(CC) -c $< $(CFLAGS)

pila.o: pila.c pila.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o

