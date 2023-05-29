/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/29 18:54:48 by jlimones         ###   ########.fr       */
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
	map->so = 0;
	map->no = 0;
	map->we = 0;
	map->ea = 0;
	map->c = 0;
	map->f = 0;
	map->pj = ft_calloc(sizeof(t_pj), 1);
	width_map(path, map);
	map->map_fill = fill_map(path, map);
	fill_wall(map, path);
	map->floor_color = 0;
	map->ceiling_color = 0;
	file_fill(path, map);
	if (map->no == 0 || map->ea == 0 || map->we == 0 || map->so == 0 
		| map->f == 0 || map->c == 0)
		ft_help_char_elements_map("Error:\n");
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

char	*is_char_no_valid(int fd)
{
	int		i;
	int		j;
	char	*line;
	char	*line_new;

	i = -1;
	j = -1;
	line = get_next_line(fd);
	line_new = calloc(sizeof(char), ft_strlen(line));
	while (line[++i])
	{
		if ((line[i] != ' ' || line[i] != '\t'))
			line_new[++j] = line[i];
	}
	line_new[++j] = '\0';
	free(line);
	return (line_new);
}

int	error_elements(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO ", 3) && map->no != 0)
		ft_help_char_elements_map("Error:\n");
	else if (ft_strnstr(line, "SO ", 3) && map->so != 0)
		ft_help_char_elements_map("Error:\n");
	else if (ft_strnstr(line, "WE ", 3) && map->we != 0)
		ft_help_char_elements_map("Error:\n");
	else if (ft_strnstr(line, "EA ", 3) && map->ea != 0)
		ft_help_char_elements_map("Error:\n");
	else if (ft_strnstr(line, "F ", 3) && map->f != 0)
		ft_help_char_elements_map("Error:\n");
	else if (ft_strnstr(line, "C ", 3) && map->c != 0)
		ft_help_char_elements_map("Error:\n");
	return (0);
}

void	fill_wall(t_map *map, char *path_map)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	fd = open(path_map, O_RDONLY);
	while (++i < map->start_map - 1)
	{
		line = get_next_line(fd);
		if (ft_strnstr(line, "NO .", 4) && !error_elements(map, line))
			map->no = save_struct_walls(line);
		else if (ft_strnstr(line, "SO .", 4) && !error_elements(map, line))
			map->so = save_struct_walls(line);
		else if (ft_strnstr(line, "WE .", 4) && !error_elements(map, line))
			map->we = save_struct_walls(line);
		else if (ft_strnstr(line, "EA .", 4) && !error_elements(map, line))
			map->ea = save_struct_walls(line);
		else if (ft_strnstr(line, "F ", 2) && !error_elements(map, line))
			map->f = save_struct_walls(line);
		else if (ft_strnstr(line, "C ", 2) && !error_elements(map, line))
			map->c = save_struct_walls(line);
		else if (line[0] != '\n')
			ft_help_char_elements_map("Error: en final\n");
		free(line);
	}
}
