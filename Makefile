# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 14:43:10 by cshingai          #+#    #+#              #
#    Updated: 2024/06/07 15:15:12 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
LIBFT = lib/libft
FT_PRINTF = lib/ft_printf
LIBS = $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
HEADERS = -I $(LIBFT)

# source files
SRCS = {addprefix src/, \
		main.c \}

OBJ = $(SRCS:src/%.c=obj/%.o)

all = $(NAME)

$(NAME): libft ft_printf $(OBJ)
			cc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
			@echo "compiling $(NAME)"

# building libraries
libft: @make all

ft_printf: @make all

# compiling objects files
obj/%o.: src/%c. ./includes/push_swap.h
			mkdir -p obj
			@cc $(FLAGS) -HEADERS
