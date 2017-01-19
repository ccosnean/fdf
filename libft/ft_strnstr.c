/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:35:50 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/26 19:50:52 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (!*little)
		return ((char*)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			i = len;
			s1 = (char*)big + 1;
			s2 = (char*)little + 1;
			while (i-- && *s1 && *s2 && *s1 == *s2)
			{
				++s1;
				++s2;
			}
			if (!*s2)
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
