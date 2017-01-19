/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:19:46 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/18 11:31:12 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*sr;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
		{
			sr = (char *)s;
			return (sr);
		}
		s++;
	}
	if (ch == '\0')
	{
		sr = (char *)s;
		return (sr);
	}
	return (0);
}
