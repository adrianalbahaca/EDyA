CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o btree.o
	$(CC) -g -o $@ $^ $(CFLAGS) 
	rm *.o

test.o: test.c btree.h 
	$(CC) -g -c $< $(CFLAGS)

btree.o: btree.c btree.h
	$(CC) -g -c $< $(CFLAGS)