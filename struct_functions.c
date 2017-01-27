/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:47:45 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/27 17:47:47 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_list_len(t_map *map)
{
	int			len;

	len = 0;
	while (map)
	{
		len++;
		map = map->next;
	}
	return (len);
}

int				ft_usage(void)
{
	ft_putstr("usage: try ./fdf file\n");
	return (0);
}

int				ft_open(char *file)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 2)
	{
		ft_putstr("Wrong file!\n");
		exit(0);
	}
	else
		return (fd);
}

int				ft_bi_len(char **sp)
{
	int			i;

	i = 0;
	while (sp[i])
		i++;
	return (i + 1);
}

t_map			*ft_new_struct(char **sp)
{
	t_map		*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	ret->next = NULL;
	ret->z = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->x = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->y = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->col1 = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->col2 = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->z_i = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->x_i = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	ret->y_i = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	return (ret);
}
