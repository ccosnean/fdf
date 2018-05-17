/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:40:30 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/27 18:08:28 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_wind{
	int				width;
	int				height;
	void			*window;
	void			*mlx;
}					t_wind;

typedef struct		s_map{
	int				*z;
	int				*x;
	int				*y;
	int				*col1;
	int				*col2;
	int				*z_i;
	int				*x_i;
	int				*y_i;
	int				center[2];
	int				ax;
	int				ay;
	int				az;
	int				dist;
	int				len;
	struct s_map	*next;
	void			*window;
	void			*mlx;
	int				h;
	int				w;
}					t_map;

void				draw_line(int vect[4], t_map *m, int col);
void				draw_map(t_map *map);
void				rotate_z(t_map **map);
int					ft_list_len(t_map *map);
int					ft_usage(void);
int					ft_open(char *file);
int					ft_bi_len(char **sp);
t_map				*ft_new_struct(char **sp);
t_map				*ft_fill_values(t_map *map, char **sp);
void				ft_map_push(t_map **map, char **sp);
void				set_center(t_map **map);
void				translate(t_map **map, int key);
void				set_initial(t_map *map);
void				set_colors(t_map **map);
void				ft_mlx_rect(int x, int y, int color, t_map *map);
void				draw_map(t_map *map);
void				link_wind_to_map(t_wind w, t_map **map);
void				ft_create_window(t_map **h);
void				reinit_map(t_map **map, int xyz, int val);
void				translate_to_center(t_map **map);
void				rotate_x(t_map **map);
void				rotate_y(t_map **map);
void				rotate_z(t_map **map);
void				toogle_help(t_map *map);
int					key_hook(int key, t_map *map);

#endif
