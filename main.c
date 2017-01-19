/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:45:44 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/19 13:28:20 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ABS(x) x < 0 ? -x : x
#include "mlx.h"
#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void		ft_print_list(t_map *map);

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

void		ft_map_push(t_map **map, char **sp)
{
	t_map	*h;
	t_map	*new;
	int		i;

	new = ft_new_struct();
	new->z_coords = (int *)malloc(sizeof(int) * ft_bi_len(sp));
	i = -1;
	while (sp[++i])
		new->z_coords[i] = ft_atoi(sp[i]);
	new->len = i;
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
			printf("%i ", h->z_coords[i]);
			i++;
		}
		printf("\n");
		h = h->next;
	}
}

int			ft_list_len(t_map *map)
{
	int len;

	len = 1;
	while (map)
	{
		len++;
		map = map->next;
	}
	return (len);
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
	printf(" (%d, %d)\n", x, y);
	if (w)
		return (0);
	return (0);
}

int			key_hook(int key, t_wind *w)
{
	//	printf("key: %i\n", key);
	if (key == 53) // ESC
		exit(1);
	if (w)
		return (0);
	return (0);
}

void		draw_map(t_wind *w, t_map *map)
{
	int		i;
	int		j;
	int		point[4];
	int		dist;

	i = 40;
	if (map)
		dist = 10;
	while (++i < w->width + 40)
	{
		j = 40;
		while (++j < w->height + 40)
		{
			point[0] = i + dist;
			point[1] = j + dist;
			point[2] = i + dist;
			point[3] = j + dist;
			draw_line(point, w->mlx, w->window);
		}
	}
}

void		ft_create_window(t_map *map)
{
	t_wind	*w;

	w = (t_wind *)malloc(sizeof(t_wind));
	w->width = map->len;
	w->height = ft_list_len(map);
	w->mlx = mlx_init();
	w->window = mlx_new_window(w->mlx, w->width * 30, w->height * 30, 
			"-+- Fdf project -+-");
	mlx_key_hook(w->window, key_hook, &w);
	mlx_mouse_hook(w->window, mouse_hook, &w);
	draw_map(w, map);
	mlx_loop(w->mlx);
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
	ft_print_list(map);
	ft_create_window(map);
	/*	mlx = mlx_init();
		window = mlx_new_window(mlx, 300, 300, "Dialog");
		mlx_loop(mlx);
		*/
}
