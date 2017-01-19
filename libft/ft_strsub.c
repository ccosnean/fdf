/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:27:22 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/26 20:34:42 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (s && start + len <= ft_strlen(s))
	{
		newstr = ft_strnew(len);
		if (newstr)
			return (ft_strncpy(newstr, s + start, len));
	}
	return (0);
}
