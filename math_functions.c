/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:48:38 by ccosnean          #+#    #+#             */
/*   Updated: 2017/02/28 14:02:31 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_z(t_map **map)
{
	int			i;
	t_map		*h;
	double		angle;
	int			d,x,y;

	h = *map;
	angle = h->az * M_PI / 180;
	d = h->dist;
	set_center(map);
	h->dist = 1;
	while (h)
	{
		i = -1;
		while (++i < h->len)
		{
			x = h->x[i];
			y = h->y[i];
			h->x[i] = (x * cos(angle) - y * sin(angle));
			h->y[i] = (x * sin(angle) + y * cos(angle));
		}
		h = h->next;
	}
}

void			rotate_y(t_map **map)
{
	int			i;
	t_map		*h;
	double		angle;

	h = *map;
	angle = h->ay * M_PI / 180;
	set_center(map);
	while (h)
	{
		i = -1;
		while (++i < h->len)
		{
			h->x_i[i] -= h->center[0];
			h->x[i] = (h->x_i[i] * cos(angle) + h->z_i[i] * sin(angle));
			h->z[i] = (h->x_i[i] * -sin(angle) + h->z_i[i] * cos(angle));
			h->x_i[i] += h->center[0];
		}
		h = h->next;
	}
}

void			rotate_x(t_map **map)
{
	int			i;
	t_map		*h;
	double		angle;
	int			d;

	h = *map;
	angle = h->ax * M_PI / 180;
	set_center(map);
	d = h->dist;
	while (h)
	{
		i = -1;
		while (++i < h->len)
		{
			h->y_i[i] -= h->center[1];
			h->y[i] = (h->y_i[i] * cos(angle) + h->z_i[i] * -sin(angle));
			h->z[i] = (h->y_i[i] * sin(angle) + h->z_i[i] * cos(angle));
			h->y_i[i] += h->center[1];
		}
		h = h->next;
	}
}

void			translate_to_center(t_map **map)
{
	t_map		*h;
	int			i;

	set_center(map);
	h = *map;
	while (h)
	{
		i = -1;
		while (++i < h->len)
		{
			h->x[i] = h->x[i] + h->w / 2;
			h->y[i] = h->y[i] + h->h / 2;
		}
		h = h->next;
	}
}

void			reinit_map(t_map **map, int xyz, int val)
{
	t_map		*h;

	h = *map;
	if (xyz == 1)
		h->az += val;
	else if (xyz == 2)
		h->ax += val;
	else
		h->ay += val;
	rotate_y(map);
	rotate_x(map);
	rotate_z(map);
	translate_to_center(map);
	draw_map(*map);
}
