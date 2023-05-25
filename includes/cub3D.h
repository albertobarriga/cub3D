#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_pj
{

	char	orientation;
	int		y;
	int		x;
}	t_pj;

typedef struct s_map
{
	int		width;
	int		height;
	int		start_map;
	char	**map_fill;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
}	t_map;

void	width_map(char *path_map, t_map	*map);
char	**fill_map(char *_path_map, t_map *map);
void    height_map(char *path_map, t_map *map);/*Funcion para revisar map->height lo guarda la funcion anterior*/
int		first_line_map(int fd, t_map *map);
void	fill_wall(t_map *map, char *path_map);

/*utils_parse.c*/
void	ft_search_first(int fd, int height);

void	init_map(t_map *map, char *path);


void	ft_help_argv(char *error);
#endif 