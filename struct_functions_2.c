/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:48:03 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/31 17:28:02 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*ft_fill_values(t_map *map, char **sp)
{
	int			i;
	t_map		*new;

	new = ft_new_struct(sp);
	i = -1;
	new->dist = ft_bi_len(sp) > 20 ? 10 : ft_bi_len(sp);
	while (sp[++i])
	{
		new->z_i[i] = ft_atoi(sp[i]) * (new->dist / 2);
		new->x_i[i] = i * new->dist;
		new->y_i[i] = ft_list_len(map) * new->dist;
	}
	new->z_i[i] = 0;
	new->x_i[i] = i * new->dist;
	new->y_i[i] = ft_list_len(map) * new->dist;
	new->len = i;
	return (new);
}

void			ft_map_push(t_map **map, char **sp)
{
	t_map		*h;
	t_map		*new;

	new = ft_fill_values(*map, sp);
	new->ax = 40;
	new->ay = 10;
	new->az = 20;
	if (*map == NULL)
	{
		*map = new;
		return ;
	}
	h = *map;
	while (h->next != NULL)
		h = h->next;
	h->next = new;
}

void			set_center(t_map **map)
{
	t_map		*h;
	int			y2;
	int			y1;

	h = *map;
	while (h)
	{
		y2 = h->y_i[ft_list_len(*map)];
		h = h->next;
	}
	h = *map;
	y1 = h->y_i[0];
	while (h)
	{
		h->center[0] = (h->x_i[h->len - 1] + h->x_i[0]) / 2;
		h->center[1] = (y2 + y1) / 2;
		h = h->next;
	}
	return ;
}

void			set_initial(t_map *map)
{
	rotate_y(&map);
	rotate_x(&map);
	rotate_z(&map);
	translate_to_center(&map);
	draw_map(map);
	toogle_help(map);
}

void			translate(t_map **map, int key)
{
	t_map		*h;
	int			i;

	h = *map;
	while (h)
	{
		i = -1;
		while (++i <= h->len)
		{
			if (key == 124)
				h->x[i] += 5;
			else if (key == 123)
				h->x[i] -= 5;
			else if (key == 126)
				h->y[i] -= 5;
			else if (key == 125)
				h->y[i] += 5;
		}
		h = h->next;
	}
	draw_map(*map);
}
