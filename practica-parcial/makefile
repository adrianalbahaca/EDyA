CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: main.o garray.o glist.o contacto.o
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

main.o: main.c garray.h glist.h contacto.h
	$(CC) -c $< $(CFLAGS)

garray.o: garray.c garray.h glist.h contacto.h
	$(CC) -c $< $(CFLAGS)

clear:
	rm *.o