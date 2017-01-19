/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:16:59 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/18 14:21:39 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*st;

	st = (char *)malloc(size + 1);
	if (st != 0)
	{
		ft_bzero(st, size + 1);
		return (st);
	}
	else
	{
		return (0);
	}
}
