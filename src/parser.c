/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:00:16 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/18 18:50:11 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// void	ft_read_map(char *map)
// {
// 	int		fd;
// 	int		i;
// 	char	**m_map;

// 	i = 0;
// 	fd = open(map, O_RDONLY);
// 	m_map[i] = get_next_line(fd);
// 	while (m_map[i] != NULL)
// 		m_map[++i] = get_next_line(fd);
// }

/**
 * @brief Funcion para contar el numero de caracteres de cada linea
 * 
 * @param map mapa o archivo del que leer
 * @return int devuelve la linea con mas caracters
 */
int    longest_line(char *map)
{
    int		fd;
	int		max;
	char	*m_map;

	max = 0;
	fd = open(map, O_RDONLY);
	m_map = get_next_line(fd);
	while (m_map != NULL)
	{
		if (max < (int)ft_strlen(m_map))
			max = (int)ft_strlen(m_map);
		free(m_map);
		m_map = get_next_line(fd);
	}
	free(m_map);
	return (max - 1);
}

// int parser_map()
// {
    
// }