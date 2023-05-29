#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define WIDTH 900
# define HEIGHT 600

typedef struct s_pj
{
	char	orientation;
	int		y;
	int		x;
}	t_pj;

typedef struct s_map
{
	int			width;
	int			height;
	int			start_map;
	char		**map_fill;
	char		**file_fill;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*c;
	char		*f;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	t_pj		*pj;
}	t_map;

typedef struct s_args
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*back;
	mlx_texture_t	*no_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*ea_text;
	t_map			*map;
}	t_args;

/**/
char	**fill_map(char *_path_map, t_map *map);
void	fill_wall(t_map *map, char *path_map);
int		file_fill( char *path, t_map *map);

/*utils_parse.c*/
void	width_map(char *path_map, t_map	*map);
void	ft_search_first(int fd, int height);
int		first_line_map(int fd, t_map *map);
void	search_x_y(t_map *map);

/*error.c*/
void	ft_help_colors(char *error);
void	ft_help_argv(char *error);
void	ft_help_map(char *error);
void	ft_help_char_elements_map(char *error);

/*checker_map.c*/
int		is_char_valid(char c);
int		checker_char_map(t_map *map, int fd);
int		checker_map(char *path_map, t_map *map);

/*checker_elements.c*/
int		checker_path_map(char *path_map);
int		checker_colors(char *str);

void	init_map(t_map *map, char *path);

// RAYCASTER
void	init_args_mlx(t_args *args);
void	init_args(t_args *args, t_map *map);
void	hook(void *param);
void	print_back(t_args *args, t_map *map);
void	mlx_load_text(t_args *args, t_map *map);
void	exit_cub(t_args *args);

#endif 