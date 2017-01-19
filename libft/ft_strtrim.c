/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 16:05:00 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/20 13:22:06 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_ltrim(char const *s)
{
	int i;

	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	return (i);
}

static int			ft_rtrim(char const *s)
{
	int l;
	int p;

	p = 1;
	l = ft_strlen(s);
	l--;
	while (s[l] == '\t' || s[l] == ' ' || s[l] == '\n')
	{
		p++;
		l--;
	}
	return (p);
}

static char			*ft_func(char const *s)
{
	int		i;
	int		p;
	int		m;
	int		t;
	char	*temp1;

	m = 0;
	i = ft_ltrim(s);
	p = ft_rtrim(s);
	t = ft_strlen(s) - i - p;
	if (t < 0)
		t = 0;
	temp1 = (char*)malloc(sizeof(char) * (t + 2));
	if (!temp1)
		return (NULL);
	while (m <= t)
	{
		temp1[m] = (char)s[i];
		i++;
		m++;
	}
	temp1[m] = '\0';
	return (temp1);
}

char				*ft_strtrim(char const *s)
{
	if (s)
	{
		return (ft_func(s));
	}
	else
		return (NULL);
}
