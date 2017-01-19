/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:53:25 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/26 19:15:57 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cr;
	unsigned char	*sr;

	sr = (unsigned char *)s;
	cr = (unsigned char)c;
	while (n--)
	{
		if (*sr == cr)
			return (sr);
		sr++;
	}
	return (NULL);
}
