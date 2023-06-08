/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:42:51 by jlimones          #+#    #+#             */
/*   Updated: 2023/06/08 10:13:31 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_search_first(int fd, int height)
{
	char	*line;

	while (height > 1)
	{
		line = get_next_line(fd);
		free(line);
		height--;
	}
}

/**
 * @brief Funcion para encontrar la primera linea del mapa
 * 
 * @param fd fd abierto por la fucion desde la que se llama
 * @return int 
 */
int	first_line_map(int fd, t_map *map)
{
	int		i;
	char	*line;
	int		found;

	map->start_map = 0;
	line = get_next_line(fd);
	found = 0;
	while (line)
	{
		if (!found)
			map->start_map++;
		i = -1;
		while (line[++i])
		{
			if ((line[i] != '1' && line[i] != '\t' && line[i] != ' '))
				break ;
			found = 1;
		}
		free(line);
		line = get_next_line(fd);
		if (found)
			return (free(line), map->start_map);
	}
	return (close(fd), map->start_map);
}

/**
 * @brief Funcion para contar el numero de caracteres de cada linea
 * 
 * @param map estructura del mapa
 * @param map ruta del mapa seleccionado
 */
void	width_map(char *path_map, t_map	*map)
{
	int		fd;
	int		first_line;
	char	*m_map;

	fd = open(path_map, O_RDONLY);
	map->width = 0;
	map->height = 0;
	first_line = first_line_map(fd, map);
	if (map->start_map < 6)
		ft_help_char_elements_map("Error:\n");
	fd = open(path_map, O_RDONLY);
	while (first_line-- > 1)
	{
		m_map = get_next_line(fd);
		free(m_map);
	}
	while (m_map != NULL)
	{
		if (map->width < (int)ft_strlen(m_map))
			map->width = (int)ft_strlen(m_map);
		map->height++;
		m_map = get_next_line(fd);
		free(m_map);
	}
	close(fd);
}

void	search_x_y(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map_fill[++y])
	{
		x = -1;
		while (map->map_fill[y][++x])
		{
			if (map->map_fill[y][x] == map->pj->orientation)
			{
				map->pj->y = y;
				map->pj->x = x;
			}
		}
	}
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
