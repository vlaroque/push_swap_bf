# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2019/10/09 19:20:11 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -Wextra -Werror -Wall

# SOURCES

SRC_PUSH = push_swap.c algorithm.c algo_distances.c algo_pivot.c \
		   algo_insort.c algo_rotations.c

SRC_BF = bf_init.c bf_op.c bf_op_rotations.c bf_op_dbl.c \
		 bf_recursive_bruteforce.c instant.c

SRC_COMMON = init_list_a.c list_commons.c quicksort.c init_check.c\
			 op_p_s.c op_r_rr.c op_rrr.c  list_operations.c \
			 chain.c free_struct.c ft_bzero.c error.c

SRC_CHECK = checker.c render.c visual_reader.c snap.c events.c

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
DEPENDS = $(PUSH_OBJ:%.o=%.d) 
DEPENDS += $(CHECK_OBJ:%.o=%.d) 

.PHONY: all
all : $(NAME1) $(NAME2)

$(NAME1) : $(PUSH_OBJ)
	@echo "\tLinking $@'s files"
	@$(CC) $(PUSH_OBJ) -o $@ $(CFLAGS)
	@echo "\tDone !"

$(NAME2) : $(CHECK_OBJ)
	@echo "\tLinking $@'s files"
	@$(CC) $(CHECK_OBJ) -I./src/SDL2.framework/Headers -rpath @loader_path/src/ -F ./src -framework SDL2 -o $@ $(CFLAGS)
	@echo "\tDone !"

-include $(DEPENDS)
$(OBJ_PATH)/checker/%.o : $(SRC_PATH)/checker/%.c
	@mkdir -p $(@D)
	@echo "\tCompiling $@"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I./src/SDL2.framework/Headers -F ./src -MMD -c $< -o $@

-include $(DEPENDS)
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@echo "\tCompiling $@"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -MMD -c $< -o $@

.PHONY: clean
clean :
	@echo "\tCleaning..."
	@rm -Rf $(PUSH_OBJ) $(CHECK_OBJ)
	@rm -Rf $(DEPENDS)
	@echo "\tDone !"

.PHONY: fclean
fclean : clean
	@rm -Rf $(NAME1) $(NAME2)

.PHONY: re
re :
	$(MAKE) fclean
	$(MAKE)
