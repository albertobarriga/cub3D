/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:16:00 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/21 04:30:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param haynode (pajar) string en la que buscar la aguja
 * @param needle (agujar) string que hay que buscar
 * @param n numero de caracteres de needle
 * @return char* 
 */
char	*ft_strnstr(const char *haynode, const char *needle, int n)
{
	int	i;
	int	j;

	i = 0;
	if (!needle[i])
		return ((char *)haynode);
	while (i < n && haynode[i] != '\0')
	{
		j = 0;
		while (i + j < n && haynode[i + j] == needle[j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)haynode + i);
		i++;
	}
	return (0);
}
