/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:40:30 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/20 13:47:44 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
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
	int				center[2];
	double			angle;
	int				dist;
	int				len;
	struct s_map	*next;
	void			*window;
	void			*mlx;
}					t_map;

void				draw_line(int vect[4], void *mlx, void *window);
void				draw_map(t_map *map);
void				rotate_z(t_map **map);


#endif
