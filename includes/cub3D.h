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
	int		width; //ancho del mapa
	int		height; //alto del mapa
	int		start_map; //linea en la que empieza el mapa en el archivo
	char	**map_fill; //matriz que contiene el mapa
	char	*NO; //contiene ruta a la imagen a cargar
	char	*SO; //contiene ruta a la imagen a cargar
	char	*WE; //contiene ruta a la imagen a cargar
	char	*EA; //contiene ruta a la imagen a cargar
	char	*C; //contiene los colores del techo
	char	*F; // contiene los collores del suelo
	char	orientation; // Falta por rellenar
}	t_map;

typedef struct s_args
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_args;

void	width_map(char *path_map, t_map	*map);
char	**fill_map(char *_path_map, t_map *map);
void    height_map(char *path_map, t_map *map);/*Funcion para revisar map->height lo guarda la funcion anterior*/
int		first_line_map(int fd, t_map *map);
void	fill_wall(t_map *map, char *path_map);

/*utils_parse.c*/
void 	ft_search_first(int fd, int height);

void	init_map(t_map *map, char *path);


void	init_args_mlx(t_args *args);
void	init_args(t_args *args);
void	hook(void *param);

#endif 