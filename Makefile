# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 11:31:34 by oroy              #+#    #+#              #
#    Updated: 2023/07/03 19:55:49 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

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
RM = rm -r

# ********************************** RULES *********************************** #

# BASIC #

all: $(NAME)

$(NAME): $(LIBFT) $(PS_AR)
	$(CC) $(CFLAGS) $(LIBFT) $(PS_AR) -o $(NAME)

$(LIBFT): $(LIBFT_SRC)
	cd libft && $(MAKE)

$(PS_AR): $(PS_OBJ_DIR) $(PS_OBJ)
	$(AR) $(PS_AR) $(PS_OBJ)

$(PS_OBJ_DIR):
	mkdir $@

$(PS_OBJ_DIR)/%.o: $(PS_SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	cd libft && $(MAKE) clean
	$(RM) $(PS_OBJ_DIR)

fclean: clean
	$(RM) $(LIBFT) $(NAME) $(PS_AR)

re: fclean all

# VALGRIND #

PARAM = 64 39 82 100 68 23 36 86 59 65 50 72 62 81 6 49 19 32 99 97 12 96 18 43

val: $(NAME)
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	./$(NAME) $(PARAM)

# VISUALIZER #

visual: all
	./push_swap_visualizer/build/bin/visualizer

visinstall:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
	cd push_swap_visualizer && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	cd ../..