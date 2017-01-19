/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:34:07 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/18 11:49:37 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	ld;
	unsigned int	ls;
	unsigned int	i;

	ld = 0;
	while (dst[ld])
		ld++;
	i = ld;
	ls = 0;
	while (src[ls])
		ls++;
	while (*src && i < size - 1)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return ((ld > size) ? size + ls : ld + ls);
}
