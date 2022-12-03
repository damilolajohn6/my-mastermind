CC=gcc
CFLAGS=-I.
DEPS = headers.h
OBJ = my_mastermind.o

%.o: %.c $(DEPS)
	$(CC) -Wall -Wextra -Werror -c -o $@ $< $(CFLAGS)

my_mastermind: $(OBJ)
	$(CC) -Wall -Wextra -Werror -o $@ $^ $(CFLAGS)

fclean:
	rm -f *.o my_mastermind
