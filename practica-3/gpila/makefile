CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: main.o gpila.o glist.o contacto.o
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

main.o: main.c gpila.h glist.h contacto.h
	$(CC) -c $< $(CFLAGS)

gpila.o: gpila.c gpila.h glist.h contacto.h
	$(CC) -c $< $(CFLAGS)

clear:
	rm *.o