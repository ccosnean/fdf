/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:49:30 by ccosnean          #+#    #+#             */
/*   Updated: 2017/02/28 14:00:38 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			set_colors(t_map **map)
{
	int			i;
	t_map		*h;

	h = *map;
	while (h)
	{
		i = -1;
		while (++i < h->len)
		{
			if (h->z_i[i] != h->z_i[i + 1])
				h->col1[i] = 0x00993333 >> (h->z_i[i] > h->z_i[i + 1] ?
						h->z_i[i] : h->z_i[i + 1]);
			else
				h->col1[i] = 0x00FFFFFF;
			if (h->next && (h->z_i[i] != h->next->z_i[i]))
				h->col2[i] = 0x00993333 >> (h->z_i[i] > h->next->z_i[i] ?
						h->z_i[i] : h->next->z_i[i]);
			else
				h->col2[i] = 0x00FFFFFF;
		}
		h = h->next;
	}
}

void			ft_mlx_rect(int x, int y, int color, t_map *map)
{
	int			i;
	int			j;

	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
			mlx_pixel_put(map->mlx, map->window, i, j, color);
	}
	i = 3;
	while (++i < x - 3)
	{
		j = 3;
		while (++j < y - 3)
			mlx_pixel_put(map->mlx, map->window, i, j, 0x00000000);
	}
}

void			set_points(int point[4], t_map *map, int i, int param)
{
	if (param == 1)
	{
		point[0] = (map->x[i]);
		point[1] = (map->y[i]);
		point[2] = (map->x[i + 1]);
		point[3] = (map->y[i + 1]);
	}
	else
	{
		point[0] = (map->x[i]);
		point[1] = (map->y[i]);
		point[2] = (map->next->x[i]);
		point[3] = (map->next->y[i]);
	}
}

void			draw_map(t_map *map)
{
	int			i;
	int			point[4];

	mlx_clear_window(map->mlx, map->window);
	while (map)
	{
		i = -1;
		while (++i < map->len)
		{
			if (i < map->len - 1)
			{
				set_points(point, map, i, 1);
				draw_line(point, map, map->col1[i]);
			}
			if (map->next != NULL)
			{
				set_points(point, map, i, 0);
				draw_line(point, map, map->col2[i]);
			}
		}
		map = map->next;
	}
}

void			link_wind_to_map(t_wind w, t_map **map)
{
	t_map		*h;

	h = *map;
	while (h)
	{
		h->mlx = w.mlx;
		h->window = w.window;
		h->w = w.width;
		h->h = w.height;
		h = h->next;
	}
}
