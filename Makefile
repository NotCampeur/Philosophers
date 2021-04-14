# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 11:13:40 by ldutriez          #+#    #+#              #
#    Updated: 2021/04/14 14:05:44 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ONE		= philo_one
NAME_TWO		= philo_two
NAME_THREE		= philo_three

CC =		gcc

SRCS_DIR = $(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

INC_ONE_DIR =	$(shell find includes/philo_one -type d) \
				$(shell find includes/common_part -type d)
INC_TWO_DIR		= $(shell find includes/philo_two -type d) \
				$(shell find includes/common_part -type d)
INC_THREE_DIR	= $(shell find includes/philo_three -type d) \
				$(shell find includes/common_part -type d)

OBJ_ONE_DIR = objs/philo_one
OBJ_TWO_DIR		= objs/philo_two
OBJ_THREE_DIR	= objs/philo_three

SRCS_ONE		=	philo_one.c routine.c philo_one_parsing.c philo_one_engine.c \
					p_nbr_len.c p_convert.c p_put_timestamp.c p_putnbr.c p_gettime.c \
					p_clean_free.c

SRCS_TWO		=	philo_two.c

SRCS_THREE		=	philo_three.c


OBJ_ONE = $(addprefix $(OBJ_ONE_DIR)/, $(SRCS_ONE:%.c=%.o))
OBJ_TWO			= $(addprefix $(OBJ_TWO_DIR)/, $(SRCS_TWO:%.c=%.o))
OBJ_THREE		= $(addprefix $(OBJ_THREE_DIR)/, $(SRCS_THREE:%.c=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror -g3

DEBUG =
ifdef DEBUG
    CFLAGS += -fsanitize=address
endif

IFLAGS_ONE =	$(foreach dir, $(INC_ONE_DIR), -I$(dir))
IFLAGS_TWO		= $(foreach dir, $(INC_TWO_DIR), -I$(dir))
IFLAGS_THREE	= $(foreach dir, $(INC_THREE_DIR), -I$(dir))

LFLAGS =	-lpthread


# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME_ONE) $(NAME_TWO) $(NAME_THREE)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(PUSH_SWAP_SRC) || $(SRCS_ONE)$(_WHITE)"
				@echo "$(_BLUE)SRC_DIR :\n$(_YELLOW)$(PUSH_SWAP_SRC_DIR) || $(SRCS_ONE_DIR)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(PUSH_SWAP_OBJ) || $(OBJ_ONE)$(_WHITE)"
				@echo "$(_BLUE)OBJ_DIR :\n$(_YELLOW)$(PUSH_SWAP_OBJ_DIR) || $(OBJ_ONE_DIR)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS_ONE :\n$(_YELLOW)$(IFLAGS_ONE)$(_WHITE)"
				@echo "$(_BLUE)PUSH_SWAP_IFLAGS :\n$(_YELLOW)$(PUSH_SWAP_IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)BONUS_IFLAGS :\n$(_YELLOW)$(BONUS_IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LIB_DIR:\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
				@echo "$(_BLUE)INC_ONE_DIR :\n$(_YELLOW)$(INC_ONE_DIR)$(_WHITE)"
				@echo "$(_BLUE)PUSH_SWAP_INC_DIR :\n$(_YELLOW)$(PUSH_SWAP_INC_DIR)$(_WHITE)"
				@echo "$(_BLUE)BONUS_INC_DIR :\n$(_YELLOW)$(BONUS_INC_DIR)$(_WHITE)"

#OBJECTS 

$(OBJ_ONE_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(OBJ_ONE_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS_ONE) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(OBJ_TWO_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(OBJ_TWO_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS_TWO) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(OBJ_THREE_DIR)/%.o : %.c
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(OBJ_THREE_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS_THREE) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

#EXECUTABLE 

$(NAME_ONE): 	$(INC_ONE_DIR) $(OBJ_ONE) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(OBJ_ONE) $(LFLAGS) -o $(NAME_ONE)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(NAME_TWO):	$(INC_TWO_DIR) $(OBJ_TWO) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(OBJ_TWO) $(LFLAGS) -o $(NAME_TWO)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(NAME_THREE):	$(INC_THREE_DIR) $(OBJ_THREE) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(OBJ_THREE) $(LFLAGS) -o $(NAME_THREE)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

#USUAL RULES

re:				fclean all

clean:
				@echo -n "$(_WHITE)Deleting Objects Directory $(_YELLOW)obj$(_WHITE) ... "
				@rm -rf objs
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo -n "Deleting Binaries Files $(_YELLOW)$(NAME_ONE)" \
				"$(_WHITE), $(_YELLOW)$(NAME_TWO)$(_WHITE) & $(_YELLOW)$(NAME_THREE)$(_WHITE)... "
				@rm -f $(NAME_ONE) $(NAME_TWO) $(NAME_THREE)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all re clean flcean show
