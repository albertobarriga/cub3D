/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:45:14 by jlimones          #+#    #+#             */
/*   Updated: 2023/05/21 04:30:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len)
	{
		ptr[len -1] = c;
		len--;
	}
	return (b);
}
