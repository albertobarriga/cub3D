/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:10:54 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/27 13:22:43 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_help_argv(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("help: ./cub3D [xxxx.cub]\n", 2);
	exit(0);
}

void	ft_help_map(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("help: supported characters:\n", 2);
	ft_putstr_fd("				[1]\n", 2);
	ft_putstr_fd("				[0]\n", 2);
	ft_putstr_fd("				[S] * 1\n", 2);
	ft_putstr_fd("				[N] * 1\n", 2);
	ft_putstr_fd("				[E] * 1\n", 2);
	ft_putstr_fd("				[W] * 1\n", 2);
	exit(0);
}
