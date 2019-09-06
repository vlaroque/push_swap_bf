# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2019/06/29 13:05:48 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -g

# SOURCES

SRC_PUSH = init.c init_check.c init_errors.c push_swap.c quicksort.c \
	   list_commons.c list_operations.c algorithm.c algo_distances.c \
	   algo_pivot.c algo_swaper.c\
	   op_p_s.c op_r_rr.c op_rrr.c algo_insort.c

SRC_BF = bf_bruteforce.c bf_debug.c bf_init.c bf_op.c \
		 bf_recursive_bruteforce.c

# PATH

SRC_PATH = src
OBJ_PATH = obj
HEADER_PATH = inc

PUSH_PATH = push_swap
BF_PATH = bf
INC_PATH = inc

# ASSIGNATION

SRC_FILES_ONLY = $(SRC_PUSH) $(SRC_BF)
SRC_FILES = $(addprefix $(PUSH_PATH)/,$(SRC_PUSH))
SRC_FILES += $(addprefix $(BF_PATH)/,$(SRC_BF))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

all : $(NAME1)
	echo "all\n"

lol:
	echo $(SRC)

$(NAME1) : $(OBJ)
	echo "lol\n"
	$(CC) $(OBJ) -o $@ $(CFLAGS)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	echo 'compiling $@'
	$(CC) $(CFL_PATH) -I $(INC_PATH) -MMD -c $< -o $@

clean :
	echo 'cleaning'
	rm -Rf $(OBJ)
