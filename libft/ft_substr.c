/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:44:56 by jlimones          #+#    #+#             */
/*   Updated: 2023/06/08 12:06:27 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copia y guarda en memoria el numero de caracteres pasados en len
 * a partir de start.
 * @param start Indice a partir del cual copiar
 * @return Puntero al substring
*/
char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	int		i;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) - start < (unsigned int)len)
		len = (unsigned int)ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
