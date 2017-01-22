/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:45:44 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/20 15:18:05 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(x) x < 0 ? -x : x
#include "mlx.h"
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

t_map		*ft_fill_values(t_map *map, char **sp)
{
	int 	i;
	t_map	*new;

	new = ft_new_struct();
	new->z = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	new->x = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	new->y = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	i = -1;
	while (sp[++i])
	{
		new->z[i] = ft_atoi(sp[i]);
		new->x[i] = i + 5;
		new->y[i] = ft_list_len(map) + 5;
	}
	new->z[i] = 0;
	new->x[i] = i + 5;
	new->y[i] = ft_list_len(map) + 5;
	new->len = i;
	new->dist = 10;
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

int			mouse_hook(int	key, int x, int y, t_wind *w)
{
	if (key == 1)
		printf("Click!");
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
	if (w)
		return (0);
	return (0);
}

int			key_hook(int key, t_wind *w)
{
	if (key == 53) // ESC
		exit(1);
	if (w)
		return (0);
	return (0);
}

void		draw_map(t_wind *w, t_map *map)
{
	int		i;
	int		point[4];
	int		d;

	mlx_clear_window(w->mlx, w->window);
	d = map->dist;
	while (map)
	{
		i = 0;
		while (i <= map->len)
		{
			if (i < map->len)
			{
				point[0] = d * (map->x[i]);
				point[1] = d * (map->y[i]) - map->z[i];
				point[2] = d * (map->x[i + 1]);
				point[3] = d * (map->y[i + 1]) - map->z[i + 1];
				draw_line(point, w->mlx, w->window);
			}
			if (map->next != NULL)
			{
				point[0] = d * (map->x[i]);
				point[1] = d * (map->y[i]) - map->z[i];
				point[2] = d * (map->next->x[i]);
				point[3] = d * (map->next->y[i]) - map->next->z[i];
				draw_line(point, w->mlx, w->window);
			}

			i++;
		}
		map = map->next;
	}
}

void		rotate_z(t_map **map)
{
	int 	i;
	t_map	*h;
	double 	angle;
	int 	d;

	h = *map;
	angle = 0.02;
	d = h->dist;
	while (h)
	{
		i = -1;
		while (++i <= h->len)
		{
			h->x[i] =(h->x[i] * cos(angle) - h->y[i] * sin(angle));
			h->y[i] =(h->x[i] * sin(angle) + h->y[i] * cos(angle));
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
	angle = 0.02;
	d = h->dist;
	while (h)
	{
		i = -1;
		while (++i <= h->len)
		{
			h->x[i] = (h->x[i] * cos(angle) + h->y[i] * sin(angle));
			h->y[i] = (h->x[i] * (-sin(angle)) + h->y[i] * cos(angle));
		}
		h = h->next;
	}
}

void		set_center(t_map **map)
{
	t_map	*h;

	h = *map;
	while (h)
	{
		h->center[0] = h->x[h->len - 1] - h->x[0];
		h->center[1] = h->y[ft_list_len(*map) - 1] - h->y[0];
		h = h->next;
	}
	return ;
}

void		set_initial(t_map **map)
{
	//rotate_z(map);
	rotate_y(map);


}

void		ft_create_window(t_map *map)
{
	t_wind	w;

	w.width = map->len * 50;
	w.height = ft_list_len(map) * 50;
	w.mlx = mlx_init();
	w.window = mlx_new_window(w.mlx, w.width, w.height, 
			"-+- Fdf project -+-");
	mlx_key_hook(w.window, key_hook, &w);
	mlx_mouse_hook(w.window, mouse_hook, &w);
	set_initial(&map);
	draw_map(&w, map);
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
	ft_create_window(map);
}
