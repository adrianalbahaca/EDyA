CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o bstree.o
	$(CC) -g -o $@ $^ $(CFLAGS)
	rm *.o

test.o: test.c bstree.h
	$(CC) -g -c $< $(CFLAGS)

bstree.o: bstree.c bstree.h
	$(CC) -g -c $< $(CFLAGS)