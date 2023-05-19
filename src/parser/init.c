/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/19 17:15:38 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Funcion para encontrar la primera linea del mapa
 * 
 * @param fd fd abierto por la fucion desde la que se llama
 * @return int 
 */
int	first_line_map(int fd)
{
	int		i;
	int		init;
	char	*line;
	int		found;

	init = 0;
	line = get_next_line(fd);
	found = 0;
	while (line)
	{
		if (!found)
			init++;
		i = -1;
		while (line[++i])
		{
			if ((line[i] != '1' && line[i] != '\t'  && line[i] != ' '))
				break ;
			found = 1;
		}
			free(line);
			line = get_next_line(fd);
		if(found)
			return (free(line), init);
	}
	return (close(fd), init);
}

/**
 * @brief Funcion para contar el numero de caracteres de cada linea
 * 
 * @param map estructura del mapa
 * @param map mapa o archivo del que leer
 */
void    width_map(char *path_map, t_map	*map)
{
    int		fd;
    int		first_line;
	char	*m_map;

	fd = open(path_map, O_RDONLY);
	map->width = 0;
	map->height = 0;
	if (fd < 0 || !path_map)
		return ;
	first_line = first_line_map(fd);
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
/**
 * @brief Funcion para contar el numero de lineas
 * 
 * @param map estructura del mapa
 * @param map mapa o archivo del que leer
 */
void    height_map(char *path_map, t_map *map)
{
	int		fd;
	char	*m_map;
	int		first_line;

	fd = open(path_map, O_RDONLY);
	map->height = 0;
	if (fd < 0 || !path_map)
		return ;
	first_line = first_line_map(fd);
	fd = open(path_map, O_RDONLY);
	m_map = get_next_line(fd);
	while (m_map)
	{
		free(m_map);
		m_map = get_next_line(fd);
		map->height++;
	}
	close(fd);
}
