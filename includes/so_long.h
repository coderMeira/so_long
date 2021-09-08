
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../libs/libft/inc/libft.h"

# define ASSET_HEIGHT	100
# define ASSET_WIDTH	100

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	t_vars	mlx_vars;
}				t_img;

typedef struct	s_environment
{
	char		**map;
	void		*mlx;
	void		*win;
	int			P_count;
	int			E_count;
	int			C_count;
	int			mov_count;
	int			x_size;
	int			y_size;
	t_img		i_P;
	t_img		i_E;
	t_img		i_C;
	t_img		i_1;
	t_img		i_0;
}				t_environment;

//INITS
t_environment	*init_env(void);
void			init_window(t_environment *env);

//FREE
void			die(t_environment *env, char *message);
void			free_struct(t_environment *env);

//PARSE_BER
void			parse_map(char* ber, t_environment*	env);
int 			get_next_line(int fd, char **line);

#endif
