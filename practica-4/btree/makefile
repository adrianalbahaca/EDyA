CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o btree.o
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

test.o: test.c btree.h
	$(CC) -c $< $(CFLAGS)

btree.o: btree.c btree.h
	$(CC) -c $< $(CFLAGS)