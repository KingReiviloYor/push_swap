# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 11:31:34 by oroy              #+#    #+#              #
#    Updated: 2023/06/01 18:39:58 by oroy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVES =	push_swap.a libft/libft.a
CC = gcc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRC = 	main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(ARCHIVES)
	$(CC) $(CFLAGS) main.c $(ARCHIVES)

$(ARCHIVES): $(OBJ)
	cd libft && $(MAKE)
	$(AR) $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
