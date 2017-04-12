/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:45:44 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/31 17:28:37 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			ft_create_window(t_map **h)
{
	t_wind		w;
	t_map		*map;

	map = *h;
	w.width = 1200;
	w.height = 800;
	w.mlx = mlx_init();
	w.window = mlx_new_window(w.mlx, w.width, w.height, "-+- Fdf project -+-");
	link_wind_to_map(w, h);
	mlx_key_hook(w.window, key_hook, map);
	set_colors(&map);
	set_initial(map);
	mlx_loop(w.mlx);
}

void			toogle_help(t_map *map)
{
	static int	boo = 1;

	if (boo)
	{
		ft_mlx_rect(205, 190, 0x00cc6600, map);
		mlx_string_put(map->mlx, map->window, 60, 10,
				0x00cc6600, "+ Help +");
		mlx_string_put(map->mlx, map->window, 10, 35,
				0x00FFFFFF, "z,a:for z rotation");
		mlx_string_put(map->mlx, map->window, 10, 55,
				0x00FFFFFF, "x,s:for x rotation");
		mlx_string_put(map->mlx, map->window, 10, 75,
				0x00FFFFFF, "y,t:for y rotation");
		mlx_string_put(map->mlx, map->window, 10, 95,
				0x00FFFFFF, "arrows to move");
		mlx_string_put(map->mlx, map->window, 10, 115,
				0x00FFFFFF, "c: bring to center");
		mlx_string_put(map->mlx, map->window, 10, 135,
				0x00FFFFFF, "+, -: zoom map");
		mlx_string_put(map->mlx, map->window, 10, 155,
				0x00FFFFFF, "h: toogle menu");
	}
	else
		draw_map(map);
	boo = !boo;
}

void 			zoom(t_map *map, int z)
{
	int 	i;
	int 	k;
	t_map 	*m;

	m = map;
	k = 0;
	while (m)
	{
		i = 0;
		while (i < m->len)
		{
			m->x_i[i] += i * z;
			m->y_i[i] += k * z;
			i++;
		}
		k++;
		m = m->next;
	}
	reinit_map(&map, 0, 0);
}

int				key_hook(int key, t_map *map)
{
	if (key == 53)
		exit(1);
	if (key == 6)
		reinit_map(&map, 1, 10);
	if (key == 0)
		reinit_map(&map, 1, -10);
	if (key == 7)
		reinit_map(&map, 2, 10);
	if (key == 1)
		reinit_map(&map, 2, -10);
	if (key == 16)
		reinit_map(&map, 3, 10);
	if (key == 17)
		reinit_map(&map, 3, -10);
	if (key == 124 || key == 123 || key == 126 || key == 125)
		translate(&map, key);
	if (key == 8)
		reinit_map(&map, 1, 0);
	if (key == 4)
		toogle_help(map);
	if (key == 24)
		zoom(map, 5);
	if (key == 27)
		zoom(map, -5);
	return (0);
}

int				main(int argc, char **argv)
{
	char		*line;
	t_map		*map;
	char		**sp;
	int			fd;

	line = NULL;
	if (argc != 2)
		return (ft_usage());
	fd = ft_open(argv[1]);
	map = NULL;
	while (get_next_line(fd, &line))
	{
		sp = ft_strsplit(line, ' ');
		ft_map_push(&map, sp);
	}
	ft_create_window(&map);
}
