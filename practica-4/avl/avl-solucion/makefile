CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o avl.o
	$(CC) -g -o $@ $^ $(CFLAGS)
	rm *.o

test.o: test.c avl.h
	$(CC) -g -c $< $(CFLAGS)

avl.o: avl.c avl.h
	$(CC) -g -c $< $(CFLAGS)