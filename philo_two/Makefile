# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 00:49:57 by user42            #+#    #+#              #
#    Updated: 2021/04/23 01:11:34 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo_two

CC				= gcc

SRCS_DIR		=	$(shell find srcs -type d) \
					$(shell find ../philo_shared/srcs -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

INC_DIR			=	$(shell find includes/ -type d) \
					$(shell find ../philo_shared/includes/ -type d)

OBJ_DIR			= objs/

SHARED_SRCS		=	p_len.c p_convert.c p_put_timestamp.c p_putnbr.c time_management.c \
					p_clean_free.c philosophers_parsing.c p_hunger_check.c

SRCS			=	philo_two.c p_routine_two.c philo_two_engine.c \
					p_check_vitals_two.c $(SHARED_SRCS)

OBJ				= $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

CFLAGS			= -Wall -Wextra -Werror -g3

DEBUG =
ifdef DEBUG
    CFLAGS += -fsanitize=address
endif

IFLAGS			= $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS			= -lpthread

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all:			$(NAME)

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME): 		$(INC_DIR) $(OBJ) Makefile
				@echo "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
				
re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)obj$(_WHITE) ... \c"
				@rm -rf objs
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binaries Files $(_YELLOW)$(NAME)$(_WHITE)... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all re clean flcean show
