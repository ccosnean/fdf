/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:40:30 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/25 14:38:24 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx/mlx.h"
# include "libft/libft.h"


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
    int             *col1;
    int             *col2;
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


#endif
