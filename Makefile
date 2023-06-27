# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 11:31:34 by oroy              #+#    #+#              #
#    Updated: 2023/06/21 19:30:15 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES #

NAME = push_swap
PS_AR = push_swap.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRC_DIR = $(LIBFT_DIR)/src
LIBFT_SRC = $(wildcard $(LIBFT_SRC_DIR)/*.c)

PS_SRC_DIR = src
PS_OBJ_DIR = obj
PS_SRC = $(wildcard $(PS_SRC_DIR)/*.c)
PS_OBJ = $(patsubst $(PS_SRC_DIR)/%.c, $(PS_OBJ_DIR)/%.o, $(PS_SRC))

AR = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# RULES #

all: $(NAME)

$(NAME): $(LIBFT) $(PS_AR) main.c
	$(CC) $(CFLAGS) main.c $(LIBFT) $(PS_AR) -o $(NAME)

$(LIBFT): $(LIBFT_SRC)
	cd libft && $(MAKE)

$(PS_AR): $(PS_OBJ)
	$(AR) $(PS_AR) $(PS_OBJ)
	
$(PS_OBJ_DIR)/%.o: $(PS_SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	cd libft && $(MAKE) clean
	$(RM) $(PS_OBJ)

fclean: clean
	$(RM) $(LIBFT) $(NAME) $(PS_AR)

re: fclean all
