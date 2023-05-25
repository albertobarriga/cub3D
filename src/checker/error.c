/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:10:54 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/22 10:18:09 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    ft_help_argv(char *error)
{
    ft_putstr_fd(error, 2);
    ft_putstr_fd("help: ./cub3D [xxxx.cub]\n", 2);
    exit(0);
}