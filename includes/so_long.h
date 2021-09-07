
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../libs/libft/inc/libft.h"

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
	int			map_size;
	t_img		player;
	t_img		exit;
	t_img		consumable;
	t_img		wall;
	t_img		floor;
}				t_environment;

//INITS
t_environment	*init_env(void);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			init_window(t_vars *mlx_vars, t_data* img);

//FREE
void			die(t_environment *env, char *message);
void			free_struct(t_environment *env);

//PARSE_BER
void			parse_map(char* ber, t_environment*	env);
int 			get_next_line(int fd, char **line);

#endif
