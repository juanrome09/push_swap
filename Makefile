# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanrome <juanrome@student.42madrid.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 17:21:35 by juanrome          #+#    #+#              #
#    Updated: 2025/05/08 14:36:44 by juanrome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft
LIBFT = $(LIB_DIR)/libft.a

INCLUDE = include/push_swap.h
LIBFT_INCLUDE = libft

RM = rm -f

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE) -I. -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE) -I. -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
