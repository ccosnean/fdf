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

void	draw_line(int vect[4], void *mlx, void *window);

typedef struct		s_map{
	int				*z;
	int				*x;
	int				*y;
	int				center[2];
	int				len;
	struct s_map	*next;
}					t_map;

typedef struct		s_wind{
	int				width;
	int				height;
	void			*window;
	void			*mlx;
}					t_wind;

#endif