/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:45:44 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/26 14:33:50 by ccosnean         ###   ########.fr       */
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

int			ft_bi_len(char **sp)
{
	int		i;

	i = 0;
	while (sp[i])
		i++;
	return (i + 1);
}

t_map		*ft_new_struct(char **sp)
{
	t_map	*ret;

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

int			ft_divide(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (a / b);
}

int         ft_max(t_map *h, int i)
{
	int     max;

	max = h->z_i[i];
	while (i--)
	{
		if (max < h->z_i[i])
			max = h->z_i[i];
	}
	return (max);
}

void        set_colors(t_map **map)
{
	int     i;
	t_map   *h;

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
				h->col2[i] =  0x00993333 >> (h->z_i[i] > h->next->z_i[i] ?
						h->z_i[i] : h->next->z_i[i]);
			else
				h->col2[i] = 0x00FFFFFF;
		}
		h = h->next;
	}
}

t_map		*ft_fill_values(t_map *map, char **sp)
{
	int 	i;
	t_map	*new;

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

void		ft_map_push(t_map **map, char **sp)
{
	t_map	*h;
	t_map	*new;

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
	int		y2;
	int		y1;

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

void		rotate_z(t_map **map)
{
	int 	i;
	t_map	*h;
	double 	angle;
	int 	d;

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
			h->x_i[i] -= h->center[0];
			h->y_i[i] -= h->center[1];
			h->x[i] = (h->x[i] * cos(angle) - h->y[i] * sin(angle));
			h->y[i] = (h->x[i] * sin(angle) + h->y[i] * cos(angle));
			h->x_i[i] += h->center[0];
			h->y_i[i] += h->center[1];
		}
		h = h->next;
	}
}

void		rotate_y(t_map **map)
{
	int 	i;
	t_map	*h;
	double 	angle;

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

void		rotate_x(t_map **map)
{
	int 	i;
	t_map	*h;
	double 	angle;
	int 	d;

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

void		translate_to_center(t_map **map)
{
	t_map	*h;
	int		i;

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

void        ft_mlx_rect(int x, int y, int color, t_map *map)
{
	int     i;
	int     j;

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

void        toogle_help(t_map *map)
{
	static int boo = 1;

	if (boo)
	{
		ft_mlx_rect(205, 170, 0x00cc6600, map);
		mlx_string_put(map->mlx, map->window, 60, 10, 0x00cc6600, "+ Help +");
		mlx_string_put(map->mlx, map->window, 10, 35, 0x00FFFFFF, "z,a:for z rotation");
		mlx_string_put(map->mlx, map->window, 10, 55, 0x00FFFFFF, "x,s:for x rotation");
		mlx_string_put(map->mlx, map->window, 10, 75, 0x00FFFFFF, "y,t:for y rotation");
		mlx_string_put(map->mlx, map->window, 10, 95, 0x00FFFFFF, "arrows to move");
		mlx_string_put(map->mlx, map->window, 10, 115, 0x00FFFFFF, "c: bring to center");
		mlx_string_put(map->mlx, map->window, 10, 135, 0x00FFFFFF, "h: toogle menu");
	}
	else
		draw_map(map);
	boo = !boo;
}

int			key_hook(int key, t_map *map)
{
	//printf("key: %i\n", key);
	if (key == 53) 
		exit(1);
	if (key == 6) //z
	{
		map->az += 10; 
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
		draw_map(map);
	}
	if (key == 0) //a
	{
		map->az -= 10; 
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
		draw_map(map);
	}
	if (key == 7) //x
	{
		map->ax += 10;
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
		draw_map(map);
	}
	if (key == 1) //s
	{
		map->ax -= 10;
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
		draw_map(map);
	}
	if (key == 16) //y
	{
		map->ay += 10;
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
		draw_map(map);
	}
	if (key == 17) //t
	{
		map->ay -= 10;
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
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
	if (key == 8) //c
	{
		rotate_y(&map);
		rotate_x(&map);
		rotate_z(&map);
		translate_to_center(&map);
		draw_map(map);
	}
	if (key == 4) //h
		toogle_help(map);
	return (0);
}

void		draw_map(t_map *map)
{
	int		i;
	int		point[4];

	mlx_clear_window(map->mlx, map->window);
	while (map)
	{
		i = 0;
		while (i < map->len)
		{
			if (i < map->len - 1)
			{
				point[0] = (map->x[i]);
				point[1] = (map->y[i]);
				point[2] = (map->x[i + 1]);
				point[3] = (map->y[i + 1]);
				draw_line(point, map, map->col1[i]);
			}
			if (map->next != NULL)
			{
				point[0] = (map->x[i]);
				point[1] = (map->y[i]);
				point[2] = (map->next->x[i]);
				point[3] = (map->next->y[i]);
				draw_line(point, map, map->col2[i]);
			}
			i++;
		}
		map = map->next;
	}
}

void		set_initial(t_map *map)
{
	rotate_y(&map);
	rotate_x(&map);
	rotate_z(&map);
	translate_to_center(&map);
	draw_map(map);
	toogle_help(map);
}

void		link_wind_to_map(t_wind w, t_map **map)
{
	t_map *h;

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

void		ft_create_window(t_map **h)
{
	t_wind	w;
	t_map 	*map;

	map = *h;
	w.width = 1200;// (map->len > 20 ? 60 : map->len) * (map->dist + 15);
	w.height = 800;//(ft_list_len(map) > 20 ? 40 : ft_list_len(map)) * (map->dist + 15);
	w.mlx = mlx_init();
	w.window = mlx_new_window(w.mlx, w.width, w.height, 
			"-+- Fdf project -+-");
	link_wind_to_map(w, h);
	mlx_key_hook(w.window, key_hook, map);
	mlx_mouse_hook(w.window, mouse_hook, map);
	set_colors(&map);
	set_initial(map);
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
	ft_create_window(&map);
}
