
CFLAGS = -Wall -Werror -Wextra -g

CFLAGS = -Wall -Werror -Wextra -g

NAME = so_long

LIBFT_DIR = ../lib/libft/src
LIBFT_EXEC = ../lib/libft/bin/libft.a

MLX_DIR = ../lib/minilibx/

SRCS = ${wildcard *.c}

OBJS = $(SRCS:.c=.o)

LINKS = -I $(LIBFT_DIR) -L $(LIBFT_DIR) \
    -I $(MLX_DIR) -L $(MLX_DIR)\
    -l mlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(LIBFT_EXEC) $(OBJS)
		mkdir -p ../bin && gcc $(CFLAGS) $(LIBFT_EXEC) $(OBJS) -o $(NAME) $(LINKS) && mv $(NAME) ../bin
		@echo "Ready to use!"

$(LIBFT_EXEC):
		@echo "Compiling libft"
		cd $(LIBFT_DIR) && make

clean:
	rm -rf $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean:
	rm -rf $(OBJS) ../bin/$(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY:	all clean fclean re