# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <louregni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2019/09/21 20:12:28 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -g

# SOURCES

SRC_PUSH = push_swap.c algorithm.c algo_distances.c algo_pivot.c algo_swaper.c \
		   algo_insort.c 

SRC_BF = bf_bruteforce.c bf_debug.c bf_init.c bf_op.c \
		 bf_recursive_bruteforce.c instant.c

SRC_COMMON = init_list_a.c list_commons.c quicksort.c init_check.c\
			 init_errors.c op_p_s.c op_r_rr.c op_rrr.c  list_operations.c \
			 chain.c free_struct.c

SRC_CHECK = checker.c

# PATH

SRC_PATH = src
OBJ_PATH = obj
HEADER_PATH = inc

PUSH_PATH = push_swap
BF_PATH = bf
COMMON_PATH = commons
CHECK_PATH = checker
INC_PATH = inc

# ASSIGNATION

PUSH_SRC_FILES = $(addprefix $(PUSH_PATH)/,$(SRC_PUSH))
PUSH_SRC_FILES += $(addprefix $(BF_PATH)/,$(SRC_BF))
PUSH_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))
CHECK_SRC_FILES = $(addprefix $(CHECK_PATH)/,$(SRC_CHECK))
CHECK_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))

PUSH_OBJ = $(addprefix $(OBJ_PATH)/,$(PUSH_SRC_FILES:.c=.o))
CHECK_OBJ = $(addprefix $(OBJ_PATH)/,$(CHECK_SRC_FILES:.c=.o))

all : $(NAME1) $(NAME2)

$(NAME1) : $(PUSH_OBJ)
	$(CC) $(PUSH_OBJ) -g -o $@ $(CFLAGS)

$(NAME2) : $(CHECK_OBJ)
	$(CC) $(CHECK_OBJ) -g -o $@ $(CFLAGS)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	echo 'compiling $@'
	$(CC) $(CFL_PATH) -g -I $(INC_PATH) -MMD -c $< -o $@

clean :
	echo 'cleaning'
	rm -Rf $(OBJ)
