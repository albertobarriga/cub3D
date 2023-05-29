/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:09:11 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/29 18:25:15 by jlimones         ###   ########.fr       */
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
		|| c == 'E' || c == '\n')
		return (1);
	return (0);
}

int	is_char_valid_player(char c)
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
int	checker_char_map(t_map *map, int fd)
{
	int		i;
	int		j;
	int		count;
	char	*line;

	count = 0;
	j = -1;
	line = get_next_line(fd);
	while (++j < map->height - 1)
	{
		i = -1;
		while (line[++i])
		{
			if (!is_char_valid(line[i]) || count > 1)
				return (free(line), 0);
			if (is_char_valid_player(line[i]))
			{
				map->pj->orientation = line[i];
				count++;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	if (count == 0)
		return (close(fd), free(line), 0);
	return (close(fd), free(line), 1);
}

int	checker_map(char *path_map, t_map *map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);

	ft_search_first(fd, map->start_map);
	if (checker_char_map(map, fd))
		return (0);
	return (1);
}
