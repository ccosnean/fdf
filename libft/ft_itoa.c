/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:33:15 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/20 18:06:34 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_set(int *semn, int *n)
{
	*semn = 1;
	*n *= -1;
}

char		*ft_itoa(int n)
{
	int		len;
	char	*st;
	int		semn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	semn = 0;
	if (n < 0)
		ft_set(&semn, &n);
	st = ft_memalloc(len + 1);
	if (st)
	{
		while (len > 0)
		{
			st[len - 1] = (n % 10) + '0';
			n /= 10;
			len--;
		}
		if (semn > 0)
			st[0] = '-';
	}
	return (st);
}
