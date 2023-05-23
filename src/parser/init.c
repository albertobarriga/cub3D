/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/22 17:59:44 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_map(t_map *map, char *path)
{
	width_map(path, map);
	map->map_fill = fill_map(path, map);
    fill_wall(map, path);
}

/**
 * @brief recoge la ruta de la imagen a cargar
 * 
 * @param wall 
 * @param line 
 * @return char* 
 */
char	*save_struct_walls(char *line)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;

	while (line[i] != '.' && !ft_isdigit(line[i]))
		i++;
	path = calloc(sizeof(char), (ft_strlen(line) - i));
	while (line[i] && line[i] != '\n')
	{
		path[j] = line[i];
		j++;
		i++;
	}
	return (path);
}

void	fill_wall(t_map *map, char *path_map)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		return ;
	while (++i <= map->height)
	{
		line = get_next_line(fd);
		if (ft_strnstr(line, "NO", 2))
			map->NO = save_struct_walls(line);
		else if (ft_strnstr(line, "SO", 2))
			map->SO = save_struct_walls(line);
		else if (ft_strnstr(line, "WE", 2))
			map->WE = save_struct_walls(line);
		else if (ft_strnstr(line, "EA", 2))
			map->EA = save_struct_walls(line);
		else if (ft_strnstr(line, "F", 1))
			map->F = save_struct_walls(line);
		else if (ft_strnstr(line, "C", 1))
			map->C = save_struct_walls(line);
		free(line);
	}
}