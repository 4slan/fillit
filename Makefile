# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2018/12/04 20:10:01 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=src/main.c				\
	src/checks.c			\
	src/fill_tetri_coo.c
OBJ=$(SRC:.c=.o) 
NAME=fillit
HEADER=fillit/fillit.h
LIBFT=libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIBFT)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER)

do: $(NAME)
	./fillit samples/valid_samples/valid_26
