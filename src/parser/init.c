/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/25 19:28:33 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_color(t_map *map)
{
	char			**colors;
	int				i;
	unsigned char	rgb[3];

	colors = ft_split(map->c, ',');
	i = -1;
	while (colors[++i])
	{
		rgb[i] = (unsigned char)ft_atoi(colors[i]);
		free(colors[i]);
	}
	map->ceiling_color = (rgb[0] << 24) | (rgb[1] << 16) | (rgb[2] << 8) | 255;
	free(colors);
	colors = ft_split(map->f, ',');
	i = -1;
	while (colors[++i])
	{
		rgb[i] = (unsigned char)ft_atoi(colors[i]);
		free(colors[i]);
	}
	free(colors);
	map->floor_color = (rgb[0] << 24) | (rgb[1] << 16) | (rgb[2] << 8) | 255;
}

void	init_map(t_map *map, char *path)
{
	width_map(path, map);
	map->map_fill = fill_map(path, map);
	fill_wall(map, path);
	map->floor_color = 0;
	map->ceiling_color = 0;
	init_color(map);
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
			map->no = save_struct_walls(line);
		else if (ft_strnstr(line, "SO", 2))
			map->so = save_struct_walls(line);
		else if (ft_strnstr(line, "WE", 2))
			map->we = save_struct_walls(line);
		else if (ft_strnstr(line, "EA", 2))
			map->ea = save_struct_walls(line);
		else if (ft_strnstr(line, "F", 1))
			map->f = save_struct_walls(line);
		else if (ft_strnstr(line, "C", 1))
			map->c = save_struct_walls(line);
		free(line);
	}
}
