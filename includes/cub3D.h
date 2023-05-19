#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	int		width;
	int		height;
}	t_map;

typedef struct s_args
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_args;

void	width_map(char *path_map, t_map	*map);
char	**fill_map(char *_path_map, t_map *map);
void	height_map(char *path_map, t_map *map);
void	init_args_mlx(t_args *args);
void	init_args(t_args *args);
void	hook(void *param);

#endif 