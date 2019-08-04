NAME = bruteforce
CC = gcc
CFLAGS = -Wall -Wextra
SRC = bf_bruteforce.c bf_debug.c bf_init.c bf_op.c main.c bf_recursive_bruteforce.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

clean:
	rm *.o

$(NAME) : $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
