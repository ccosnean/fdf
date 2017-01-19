/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:17:33 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/26 20:24:12 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_lstadditer(t_list **begin, t_list **iterator, t_list *node)
{
	if (*begin == NULL)
		*begin = node;
	else
		(*iterator)->next = node;
	*iterator = node;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *node))
{
	t_list		*new;
	t_list		*iter;

	new = NULL;
	iter = NULL;
	while (lst != NULL)
	{
		ft_lstadditer(&new, &iter, (*f)(lst));
		lst = lst->next;
	}
	return (new);
}
