CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: main.o gcola.o glist.o contacto.o
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

main.o: main.c gcola.h glist.h contacto.h
	$(CC) -c $< $(CFLAGS)

gcola.o: gcola.c gcola.h glist.h
	$(CC) -c $< $(CFLAGS)