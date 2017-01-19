/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:52:57 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/20 15:28:21 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*st;
	char	*ret;

	if (s && f)
	{
		if (!(st = (char *)malloc(ft_strlen(s) + 1)))
			return (0);
		ret = st;
		while (*s)
		{
			*st = f(*s);
			st++;
			s++;
		}
		*st = '\0';
		return (ret);
	}
	return (0);
}
