/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:15:12 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/21 07:02:34 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_map(t_map *map, char *path)
{
	width_map(path, map);
	map->map_fill = fill_map(path, map);
    fill_wall(map, path);
}
