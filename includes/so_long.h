#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../libs/libft/inc/libft.h"

# define IMG_HEIGHT	100
# define IMG_WIDTH	100
# define ESC			53
# define W		 		13
# define S		 		1
# define D			 	2
# define A				0

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	t_vars	mlx_vars;
}				t_img;

typedef struct s_envirownment
{
	char		**map;
	void		*mlx;
	void		*win;
	int			p_count;
	int			e_count;
	int			c_count;
	int			mov_count;
	int			x_size;
	int			y_size;
	int			p_x;
	int			p_y;
	int			new_p_x;
	int			new_p_y;
	int			e_x;
	int			e_y;
	t_img		i_1;
	t_img		i_0;
	t_img		i_p;
	t_img		i_e;
	t_img		i_c;
}				t_environment;

//INITS
t_environment	*init_env(void);
void			init_window(t_environment *env);

//FREE
void			die(t_environment *env, char *message);
int				finish(t_environment *env);

//PARSE_BER
void			parse_map(char *ber, t_environment *env);
int				get_next_line(int fd, char **line);

//WINDOW
void			start_window(t_environment *env);
int				move(int key_code, t_environment *env);

#endif
