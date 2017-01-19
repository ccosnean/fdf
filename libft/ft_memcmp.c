/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:24:30 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/17 18:02:51 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*d;

	if (s1 == s2 || n == 0)
		return (0);
	s = (const unsigned char *)s1;
	d = (const unsigned char *)s2;
	while (n--)
	{
		if (*s != *d)
			return (*s - *d);
		if (n)
		{
			s++;
			d++;
		}
	}
	return (*s - *d);
}
