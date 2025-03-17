# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejagom <alejagom@student.42madird.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 17:21:35 by alejagom          #+#    #+#              #
#    Updated: 2025/03/15 09:35:35 by alejagom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/push_swap.c src/parceo.c
OBJ = $(SRC:.c=.o)
LIB_DIR = libft
LIBFT =	$(LIB_DIR)/libft.a

INCLUDE = include/push_swap.h
CC_FLAGS = -I./include
LIBFT_INCLUDE = libft

AR = ar rcs
RM = rm -f

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ)
 
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(LIBFT_INCLUDE) -I. -c $< -o $@ 
	
clean: 
	$(RM) $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all