/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:52:57 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/18 15:20:42 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*st;
	unsigned int		r;

	if (s && f)
	{
		if (!(st = (char *)malloc(ft_strlen(s) + 1)))
			return (0);
		r = 0;
		while (s[r])
		{
			st[r] = f(r, s[r]);
			r++;
		}
		st[r] = '\0';
		return (st);
	}
	return (0);
}
