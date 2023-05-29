/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:10:54 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/29 15:55:32 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_help_argv(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0;31m	help: ./cub3D [xxxx.cub]\n", 2);
	exit(0);
}

void	ft_help_colors(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0;31m	help: [F][C] xxx,xxx,xxx\n", 2);
	exit(0);
}

void	ft_help_map(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0;31mhelp: supported characters:\n", 2);
	ft_putstr_fd("				[1]\n", 2);
	ft_putstr_fd("				[0]\n", 2);
	ft_putstr_fd("				[S] * 1\n", 2);
	ft_putstr_fd("				[N] * 1\n", 2);
	ft_putstr_fd("				[E] * 1\n", 2);
	ft_putstr_fd("				[W] * 1\n", 2);
	exit(0);
}

void	ft_help_char_elements_map(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\033[0;31mhelp: supported characters:\n", 2);
	ft_putstr_fd("				[SO] /path/\n", 2);
	ft_putstr_fd("				[NO] /path/\n", 2);
	ft_putstr_fd("				[EA] /path/\n", 2);
	ft_putstr_fd("				[WE] /path/\n", 2);
	exit(0);
}
