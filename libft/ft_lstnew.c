/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:04:02 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/26 19:50:19 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		if ((ret->content = (void *)malloc(content_size)) == NULL)
		{
			ret->content = NULL;
			return (NULL);
		}
		ft_memcpy(ret->content, (void *)content, content_size);
		ret->content_size = content_size;
	}
	ret->next = NULL;
	return (ret);
}
