CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o BinaryHeap.o
	$(CC) -g -o $@ $^ $(CFLAGS)
	rm *.o

test.o: test.c BinaryHeap.h 
	$(CC) -g -c $< $(CFLAGS)

BinaryHeap.o: BinaryHeap.c BinaryHeap.h 
	$(CC) -g -c $< $(CFLAGS)