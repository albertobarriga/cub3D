/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:09:11 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/25 19:25:30 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief Chequea que sea un carater valido
 * 
 * @param c caracter a chequear
 * @return int 0 si no es valido 1 si lo es
 */
int	is_char_valid(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'S' || c == 'N' || c == 'W'
		|| c == 'E')
		return (1);
	return (0);
}

int	is_char_valid_pj(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

/**
 * @brief Chequea que los caracteres introduciodos en el mapa son validos
 * 
 * @param path_map ruta al archivo del mapa
 * @return int 1 si es valido, 0 si no lo es
 */
int	checker_char_map(char *path_map, t_map *map)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	count = map->start_map;
	fd = open(path_map, O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0 || !path_map)
		return (0);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (!is_char_valid(line[i]) || count > 1)
				return (0);
			if (is_char_valid_pj(line[i]))
				count++;
		}
		printf("line: %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), free(line), 1);
}

int	checker_map(char *path_map, t_map *map)
{
	if (!checker_char_map(path_map, map))
		return (0);
	return (1);
}
