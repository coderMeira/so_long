
CFLAGS		= -Wall -Werror -Wextra -g

NAME		= so_long

LIBFT_DIR	= libs/libft/src
LIBFT_EXEC	= libs/libft/bin/libft.a

MLX_DIR		= libs/minilibx/

SRCS		= ${wildcard srcs/*.c}

OBJS		= $(SRCS:.c=.o)

LINKS 		= -I $(LIBFT_DIR) -L $(LIBFT_DIR) \
              -I $(MLX_DIR) -L $(MLX_DIR)\
              -l mlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(LIBFT_EXEC) $(OBJS)
		@echo "Compiling ${NAME}"
		@gcc $(CFLAGS) $(LIBFT_EXEC) $(OBJS) -o $(NAME) $(LINKS)
		@mkdir -p obj
		@mv ${OBJS} obj
		@echo "Ready to use!"

$(LIBFT_EXEC):
		@echo "Compiling libft"
		${MAKE} -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	${MAKE} -C $(LIBFT_DIR) fclean

fclean:
	rm -rf $(OBJS) $(NAME)
	${MAKE} -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re
