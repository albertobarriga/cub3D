/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:52:53 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/21 04:30:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, int size)
{
	unsigned long	y;

	y = ft_strlen(src);
	if (size <= 0)
		return (y);
	while ((size-- > 1) && (*src))
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (y);
}
