# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 14:43:10 by cshingai          #+#    #+#              #
#    Updated: 2024/07/25 20:17:32 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g3
LIBFT = lib/libft
FT_PRINTF = lib/ft_printf
LIBS = $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
HEADERS = -I $(LIBFT)

# source files
SRCS = ${addprefix srcs/, \
			main.c \
			utils.c \
			validation.c \
			swap.c \
			stack_utils.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			sort.c \
			price.c \
			build_list.c \
			target.c \
			target_top.c \
			sort_other.c \
			error.c \
		}

OBJ = $(SRCS:srcs/%.c=obj/%.o)

all: $(NAME)

$(NAME): libft ft_printf ${OBJ}
			@cc $(FLAGS) $(OBJ) $(LIBS) -o $@
			@echo "compiling $(NAME)"

# building libraries
libft:
			@make -C $(LIBFT) all

ft_printf:
			@make -C $(FT_PRINTF) all

# compiling objects files
obj/%.o: srcs/%.c ./include/push_swap.h
			mkdir -p obj
			@cc $(FLAGS) $(HEADERS) -c $< -o $@
			@echo "compiling objects"

# cleanning up objects files
clean:
			@echo "removing objects"
			@rm -rf $(OBJ)
			@make clean -C $(LIBFT)
			@make clean -C $(FT_PRINTF)

# cleanning up executables
fclean:	clean
			@echo "removing executables"
			@rm -rf $(NAME)
			@echo "removing libs"
			@make fclean -C $(LIBFT)
			@make fclean -C $(FT_PRINTF)
			@echo "everthing was removed 🧹🗑️"

re: fclean all

.PHONY: all, libft, ft_printf, clean, fclean, re
