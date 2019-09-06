NAME = bruteforce
CC = gcc
CFLAGS = -Wall -Wextra
SRC = bf_bruteforce.c bf_debug.c bf_init.c bf_op.c bf_main.c bf_recursive_bruteforce.c
OBJ = $(SRC:.c=.o)
INC = ../../inc

all : $(NAME)

clean:
	rm *.o

$(NAME) : $(OBJ)
	$(CC) -I $(INC) -o $@ $^

%.o: %.c
	$(CC) -I $(INC) -o $@ -c $< $(CFLAGS)
