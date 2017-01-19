/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:35:50 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/18 11:55:32 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int	i;
	unsigned int	j;
	char			*b;
	short			boo;

	b = (char *)big;
	if (ft_strlen(little) == 0)
		return (b);
	i = -1;
	boo = 0;
	while (b[++i])
		if (b[i] == little[0])
		{
			j = -1;
			boo = 1;
			while (little[++j])
				if (b[i + j] != little[j])
				{
					boo = 0;
					break ;
				}
			if (boo == 1)
				return (&b[i]);
		}
	return (0);
}
