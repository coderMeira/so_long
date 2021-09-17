# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 20:38:48 by fmeira            #+#    #+#              #
#    Updated: 2021/09/17 01:51:03 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

MAKEFLAGS	+= -s

NAME = libft.a
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	mkdir -p ../bin
	@ar -rcs ${NAME} ${OBJ}
	mv $(NAME) ../bin

%.o: %.c
	gcc ${FLAGS} -c -o $@ $<

all: ${NAME}

bonus: ${NAME}

clean:
	rm -f ${OBJ}

.PHONY: clean
fclean: clean
	rm -f ../bin/${NAME}
	echo "Libft cleaned"

re: fclean all


