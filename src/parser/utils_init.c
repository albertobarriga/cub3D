/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 06:55:19 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/22 18:17:33 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief reserva memoria y rellena una matriz guardando un punto
 * donde hay un espacio
 * 
 * @param map estructura de dimesiones del mapa
 * @param fd file descriptor abierto
 * @return char** devuelve el mapa relleno
 */
char	**loop_fill_map(t_map *map, int fd)
{
	char	**map_fill;
	int		width;
	int		height;
	char	*line;

	height = -1;
	
	map_fill = malloc(sizeof(char*) * map->height);
	while (++height < map->height - 1)
	{
		map_fill[height] = ft_calloc(sizeof(char), map->width);
		line = get_next_line(fd);
		width = 0;
		while (width < map->width - 1)
		{
			if (ft_isalnum(line[width]) && width <= ft_strlen(line))
				map_fill[height][width] = line[width];
			else
				map_fill[height][width] = '.';
			width++;
		}
		free(line);
	}
	return (close(fd), map_fill);
}

/**
 * @brief Funcion para contar el numero de lineas
 * 
 * @param map estructura del mapa
 * @param path_map ruta del mapa seleccionado
 */
char **fill_map(char *path_map, t_map *map)
{
	char	**map_fill;
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ft_search_first(fd, map->start_map);
	map_fill = loop_fill_map(map, fd);
	return (map_fill);
}

int count_letters(t_map *map)
{
    int i;
    int j;

    i = map->start_map - 1;
    while (++i <= map->height)
    {
        j = -1;
        while (j <= map->width)
    }
    
}