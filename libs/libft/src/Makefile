# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 20:38:48 by fmeira            #+#    #+#              #
#    Updated: 2021/08/29 22:59:19 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME = libft.a
SRC = ${wildcard *.c}
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	@mkdir -p ../bin
	@ar -rs ${NAME} ${OBJ}
	@mv $(NAME) ../bin

%.o: %.c
	@gcc ${FLAGS} -c -o $@ $<

all: ${NAME}

bonus: ${NAME}

clean:
	@rm -f ${OBJ}

.PHONY: clean
fclean: clean
	@rm -f ../bin/${NAME}
	@echo "Libft cleaned"

re: fclean all


