/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:29:53 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/26 19:17:23 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	k;

	if (dest == src || n == 0)
		return (dest);
	d = dest;
	s = src;
	k = 0;
	while (k < n)
	{
		d[k] = s[k];
		k++;
	}
	return (dest);
}
