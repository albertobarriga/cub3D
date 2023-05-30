/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:53:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/30 12:22:09 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief pinta todas las casillas accesibles con una x y asi comprobar que 
 * hay un camino posible
 * 
 * @param p_map  recibe las variables inicializadas
 * @param y recibe la posicion y del personaje
 * @param x recibe la posicion x del personaje
 */
static void	ft_print_x_map(t_map *map, int y, int x)
{
	char	c;

	c = map->map_fill[y][x];
	if (c == '.')
		ft_help_map("Error:\n");
	if (c != map->pj->orientation && c != '1' && c != '0')
		return ;
	if (c == 'x')
		return ;
	if (c != '1' && map->map_fill[y] != 0)
	{
		map->map_fill[y][x] = 'x';
		ft_print_x_map(map, y, x + 1);
		ft_print_x_map(map, y, x - 1);
		ft_print_x_map(map, y + 1, x);
		ft_print_x_map(map, y - 1, x);
	}
}

void	checker_ext(t_map *map)
{
	int	i;

	i = -1;
	while (map->map_fill[0][++i])
	{
		if (map->map_fill[0][i] != '1' && map->map_fill[0][i] != '.')
			ft_help_map("Error:\n");
	}
	i = -1;
	while (map->map_fill[++i])
	{
		if (map->map_fill[i][0] != '1' && map->map_fill[i][0] != '.')
			ft_help_map("Error:\n");
	}
	i = -1;
	while (++i < map->width && map->map_fill[map->height - 2][i])
	{
		if (map->map_fill[map->height - 2][i] != '1' &&
			map->map_fill[map->height - 2][i] != '.')
			ft_help_map("Error:\n");
	}
}

/**
 * @brief busca caracteres diferentes a 'x' y '1'
 * 
 * @param p_map recibe las variables inicializadas
 * @return int 
 */
int	ft_free_road(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	checker_ext(map);
	ft_print_x_map(map, map->pj->y, map->pj->x);
	while (y < map->height && map->map_fill[y][x] != '\0')
	{
		x = 0;
		while (x < map->width && map->map_fill[y][x] != '\0')
		{
			if (map->map_fill[y][x] != '1' && map->map_fill[y][x] != 'x'
				&& map->map_fill[y][x] != map->pj->orientation)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
