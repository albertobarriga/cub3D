/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:53:24 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/29 18:25:35 by jlimones         ###   ########.fr       */
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
	if (c != map->pj->orientation && c != '1' && c != '0')
		return ;
	if (c == 'x')
		return ;
	if (c != '1' && c != 'B' && c != '\0' && map->map_fill[y] != 0)
	{
		map->map_fill[y][x] = 'x';
		ft_print_x_map(map->map_fill, map->pj->y + 1, map->pj->x);
		ft_print_x_map(map->map_fill, map->pj->y - 1, map->pj->x);
		ft_print_x_map(map->map_fill, map->pj->y, map->pj->x + 1);
		ft_print_x_map(map->map_fill, map->pj->y, map->pj->x - 1);
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
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_print_x_map(map->map_fill, map->width, map->height);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_fill[i][j] != '1' && map->map_fill[i][j] != 'x'
				&& map->map_fill[i][j] != map->pj->orentation)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
