/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:55:44 by abarriga          #+#    #+#             */
/*   Updated: 2023/06/08 11:55:51 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	exit_cub(t_args *args)
{
	if (args->no_text)
		mlx_delete_texture(args->no_text);
	if (args->so_text)
		mlx_delete_texture(args->so_text);
	if (args->we_text)
		mlx_delete_texture(args->we_text);
	if (args->ea_text)
		mlx_delete_texture(args->ea_text);
	exit(1);
}

void	free_structs(t_args	*args)
{
	free(args->map->player);
}

void	free_cube(t_args *args)
{
	mlx_delete_texture(args->no_text);
	mlx_delete_texture(args->so_text);
	mlx_delete_texture(args->we_text);
	mlx_delete_texture(args->ea_text);
	mlx_delete_image(args->mlx, args->img);
	mlx_delete_image(args->mlx, args->back);
	mlx_delete_image(args->mlx, args->walls);
	free_structs(args);
	mlx_terminate(args->mlx);
}
