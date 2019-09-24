# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2019/09/24 19:52:13 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -g

# SOURCES

SRC_PUSH = push_swap.c algorithm.c algo_distances.c algo_pivot.c \
		   algo_insort.c algo_rotations.c

SRC_BF = bf_init.c bf_op.c bf_op_rotations.c bf_op_dbl.c \
		 bf_recursive_bruteforce.c instant.c

SRC_COMMON = init_list_a.c list_commons.c quicksort.c init_check.c\
			 init_errors.c op_p_s.c op_r_rr.c op_rrr.c  list_operations.c \
			 chain.c free_struct.c ft_bzero.c

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
	@echo "\tLinking $@'s files"
	@$(CC) $(PUSH_OBJ) -g -o $@ $(CFLAGS)
	@echo "\tDone !"

$(NAME2) : $(CHECK_OBJ)
	@echo "\tLinking $@'s files"
	@$(CC) $(CHECK_OBJ) -g -o $@ $(CFLAGS)
	@echo "\tDone !"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@echo "\tCompiling $@"
	@$(CC) $(CFL_PATH) -g -I $(INC_PATH) -MMD -c $< -o $@

clean :
	@echo "\tCleaning..."
	@rm -Rf $(PUSH_OBJ) $(CHECK_OBJ)
	@echo "\tDone !"

fclean : clean
	@rm -Rf $(NAME1) $(NAME2)

re :
	$(MAKE) fclean
	$(MAKE)
