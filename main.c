/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:45:44 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/23 13:17:43 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void		ft_print_list(t_map *map);

int			ft_list_len(t_map *map)
{
	int len;

	len = 0;
	while (map)
	{
		len++;
		map = map->next;
	}
	return (len);
}

int			ft_usage(void)
{
	ft_putstr("usage: try ./fdf file\n");
	return (0);
}

int			ft_open(char *file)
{
	int 	fd;

	fd = open(file, O_RDONLY);
	if (fd < 2)
	{
		ft_putstr("Wrong file!\n");
		exit (0);
	}
	else
		return (fd);
}

t_map		*ft_new_struct(void)
{
	t_map	*ret;

	ret = (t_map *)malloc(sizeof(t_map));
	ret->next = NULL;
	ret->len = 0;
	return (ret);
}

int			ft_bi_len(char **sp)
{
	int		i;

	i = 0;
	while (sp[i])
		i++;
	return (i + 1);
}

void		translate(t_map **map, char dir)
{
	t_map 	*h;
	int	i;

	h = *map;
	while (h)
	{
		i = -1;
		while (++i <= h->len)
		{
			if (dir == 'r')
				h->x[i] += 5;
			else if (dir == 'l')
				h->x[i] -= 5;
			else if (dir == 'u')
				h->y[i] -= 5;
			else if (dir == 'd')
				h->y[i] += 5;
		}
		h = h->next;
	}
}

t_map		*ft_fill_values(t_map *map, char **sp)
{
	int 	i;
	t_map	*new;

	new = ft_new_struct();
	new->z = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	new->x = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	new->y = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	i = -1;
	new->dist = 10;
	while (sp[++i])
	{
		new->z[i] = ft_atoi(sp[i]);
		new->x[i] = i * new->dist + 5;
		new->y[i] = (ft_list_len(map) * new->dist + 5) - new->z[i];
	}
	new->z[i] = 0;
	new->x[i] = i * new->dist + 5;
	new->y[i] = (ft_list_len(map) * new->dist + 5) - new->z[i];
	new->len = i;
	return (new);
}

void		ft_map_push(t_map **map, char **sp)
{
	t_map	*h;
	t_map	*new;

	new = ft_fill_values(*map, sp);
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

void		ft_print_list(t_map *map)
{
	int i;
	t_map *h;

	h = map;
	while (h->next != NULL)
	{
		i = 0;
		while (i < h->len)
		{
			printf("z=%i,", h->z[i]);
			printf("x=%i,y=%i | ",h->x[i], h->y[i]);
			i++;
		}
		printf("\n");
		h = h->next;
	}
}

int		mouse_hook(int	key, int x, int y, t_map *map)
{
	if (key == 1)
	{
		printf("Click!");
	}
	else if (key == 2)
		printf("Right click!");
	else if (key == 3)
		printf("Middle click!");
	else if (key == 4)
		printf("Scroll down!");
	else if (key == 5)
		printf("Scroll UP!");
	else if (key == 6)
		printf("Scroll right!");
	else if (key == 7)
		printf("Scroll left!");
	printf("(%d, %d)\n", x, y);
	if (map)
		return (0);
	return (0);
}

void		set_center(t_map **map)
{
	t_map	*h;

	h = *map;
	while (h)
	{
		h->center[0] = (h->x[h->len] + h->x[0]) / 2;
		h->center[1] = (h->y[ft_list_len(*map)] + h->y[0]) / 2;
		h = h->next;
	}
	return ;
}

void		rotate_z(t_map **map)
{
	int 	i;
	t_map	*h;
	double 	angle;
	int 	d;

	h = *map;
	angle = 0.1;
	d = h->dist;
	set_center(map);
	h->dist = 1;
	while (h)
	{
		i = -1;
		while (++i <= h->len)
		{
			h->x[i] -= h->center[0];
			h->y[i] -= h->center[1];
			h->x[i] = h->x[i] * cos(angle) - h->y[i] * sin(angle);
			h->y[i] = h->x[i] * sin(angle) + h->y[i] * cos(angle);
			h->x[i] += h->center[0];
			h->y[i] += h->center[1];
		}
		h = h->next;
	}
}

void		rotate_y(t_map **map)
{
	int 	i;
	t_map	*h;
	double 	angle;
	int 	d;

	h = *map;
	angle = 0.1;
	set_center(map);
	d = h->dist;
	while (h)
	{
		i = -1;
		while (++i <= h->len)
		{
			h->x[i] -= h->center[0];
			h->x[i] = (h->x[i] * cos(angle) + h->z[i] * sin(angle));
			h->z[i] = (h->x[i] * sin(angle) - h->z[i] * cos(angle));
			h->x[i] += h->center[0];
		}
		h = h->next;
	}
}

int			key_hook(int key, t_map *map)
{
	printf("key: %i\n", key);
	if (key == 53) // ESC
		exit(1);
	if (key == 6)
	{
		rotate_z(&map);
		draw_map(map);
	}
	if (key == 16)
	{
		rotate_y(&map);
		draw_map(map);
	}
	if (key == 124)
	{
		translate(&map, 'r');
		draw_map(map);
	}
	if (key == 123)
	{
		translate(&map, 'l');
		draw_map(map);
	}
	if (key == 126)
	{
		translate(&map, 'u');
		draw_map(map);
	}
	if (key == 125)
	{
		translate(&map, 'd');
		draw_map(map);
	}
	if (map)
		return (0);
	return (0);
}

void		draw_map(t_map *map)
{
	int		i;
	int		point[4];
	int		d;

	mlx_clear_window(map->mlx, map->window);
	d = map->dist;
	while (map)
	{
		i = 0;
		while (i <= map->len)
		{
			if (i < map->len)
			{
				point[0] = (map->x[i]);
				point[1] = (map->y[i]);
				point[2] = (map->x[i + 1]);
				point[3] = (map->y[i + 1]);
				draw_line(point, map->mlx, map->window);
			}
			if (map->next != NULL)
			{
				point[0] = (map->x[i]);
				point[1] = (map->y[i]);
				point[2] = (map->next->x[i]);
				point[3] = (map->next->y[i]);
				draw_line(point, map->mlx, map->window);
			}
			i++;
		}
		map = map->next;
	}
}



void		set_initial(t_map **map)
{
	//	rotate_z(map);
}

void		link_wind_to_map(t_wind w, t_map **map)
{
	t_map *h;

	h = *map;
	while (h)
	{
		h->mlx = w.mlx;
		h->window = w.window;
		h = h->next;
	}
}

void		ft_create_window(t_map **h)
{
	t_wind	w;
	t_map 	*map;

	map = *h;
	w.width = map->len * (map->dist + 6);
	w.height = ft_list_len(map) * (map->dist + 6);
	w.mlx = mlx_init();
	w.window = mlx_new_window(w.mlx, w.width, w.height, 
			"-+- Fdf project -+-");
	link_wind_to_map(w, h);
	mlx_key_hook(w.window, key_hook, map);
	mlx_mouse_hook(w.window, mouse_hook, map);
	set_initial(h);
	draw_map(map);
	mlx_loop(w.mlx);
}

int			main(int argc, char **argv)
{
	char 	*line = NULL;
	t_map	*map;
	char 	**sp;
	int 	fd;

	if (argc != 2)
		return (ft_usage());
	fd = ft_open(argv[1]);
	map = NULL;
	while (get_next_line(fd, &line))
	{
		sp = ft_strsplit(line, ' ');
		ft_map_push(&map, sp);
	}
	ft_map_push(&map, sp);
	//ft_print_list(map);
	ft_create_window(&map);
}
