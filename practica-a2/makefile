CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o ordenamiento.o
	$(CC) -g -o $@ $^ $(CFLAGS)
	rm *.o

test.o: test.c ordenamiento.h
	$(CC) -g -c $< $(CFLAGS)

bstree.o: ordenamiento.c ordenamiento.h
	$(CC) -g -c $< $(CFLAGS)