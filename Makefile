# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2019/09/16 08:46:17 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -g

# SOURCES

SRC_PUSH = init_check.c init_errors.c push_swap.c quicksort.c \
	   list_operations.c algorithm.c algo_distances.c \
	   algo_pivot.c algo_swaper.c\
	   op_p_s.c op_r_rr.c op_rrr.c algo_insort.c chain.c

SRC_BF = bf_bruteforce.c bf_debug.c bf_init.c bf_op.c \
		 bf_recursive_bruteforce.c instant.c

SRC_COMMON = init_list_a.c list_commons.c

# PATH

SRC_PATH = src
OBJ_PATH = obj
HEADER_PATH = inc

PUSH_PATH = push_swap
BF_PATH = bf
COMMON_PATH = commons
INC_PATH = inc

# ASSIGNATION

PUSH_SRC_FILES = $(addprefix $(PUSH_PATH)/,$(SRC_PUSH))
PUSH_SRC_FILES += $(addprefix $(BF_PATH)/,$(SRC_BF))
PUSH_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
PUSH_OBJ = $(addprefix $(OBJ_PATH)/,$(PUSH_SRC_FILES:.c=.o))

all : $(NAME1)
	echo "all\n"

lol:
	echo $(SRC)

$(NAME1) : $(PUSH_OBJ)
	echo "lol\n"
	$(CC) $(PUSH_OBJ) -g -o louregni2/$@ $(CFLAGS)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	echo 'compiling $@'
	$(CC) $(CFL_PATH) -g -I $(INC_PATH) -MMD -c $< -o $@

clean :
	echo 'cleaning'
	rm -Rf $(OBJ)
