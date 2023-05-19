/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/19 11:15:40 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/**
 * @brief Funcion para contar el numero de caracteres de cada linea
 * 
 * @param map estructura del mapa
 * @param map mapa o archivo del que leer
 * @return int devuelve la linea con mas caracters
 */
void    width_map(char *path_map, t_map	*map)
{
    int		fd;
	char	*m_map;

	fd = open(path_map, O_RDONLY);
	map->width = 0;
	if (fd < 0 || !path_map)
		return ;
	m_map = get_next_line(fd);
	while (m_map != NULL)
	{
		if (map->width < (int)ft_strlen(m_map))
			map->width = (int)ft_strlen(m_map);
		free(m_map);
		m_map = get_next_line(fd);
	}
	close(fd);
	free(m_map);
}

void    height_map(char *path_map, t_map *map)
{
	int		fd;
	char	*m_map;

	fd = open(path_map, O_RDONLY);
	map->height = 0;
	if (fd < 0 || !path_map)
		return ;
	m_map = get_next_line(fd);
	while (m_map)
	{
		free(m_map);
		m_map = get_next_line(fd);
		printf("height = %i\n", map->height++);
	}
	close(fd);
}