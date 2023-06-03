# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 11:31:34 by oroy              #+#    #+#              #
#    Updated: 2023/06/02 19:28:56 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES #

NAME = push_swap
LIBFT = libft/libft.a
SRC = main.c
# OBJ = $(SRC:.c=.o)

AR = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# RULES #

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) main.c $(LIBFT) -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)
	
# %.o: %.c
# 	$(CC) -c $(CFLAGS) $< -o $@

clean:
	cd libft && $(MAKE) clean

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all
