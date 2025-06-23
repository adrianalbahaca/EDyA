CC := gcc
CFLAGS := -Wall -Werror -Wextra

programa: test.o tablahash.o contacto.o utils.o
	$(CC) -g -o $@ $^ $(CFLAGS)
	rm *.o

test.o: test.c tablahash.h contacto.h
	$(CC) -g -c $< $(CFLAGS)

tablahash.o: tablahash.c tablahash.h
	$(CC) -g -c $< $(CFLAGS)

contacto.o: contacto.c contacto.h utils.h
	$(CC) -g -c $< $(CFLAGS)

utils.o: utils.c utils.h
	$(CC) -g -c $< $(CFLAGS)

clean:
	rm *.o