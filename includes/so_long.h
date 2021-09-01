
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../libs/libft/inc/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_window(t_vars *mlx_vars, t_data* img);

char**		parse_map(char* ber);
int 		get_next_line(int fd, char **line);

#endif
