/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:37:16 by ccosnean          #+#    #+#             */
/*   Updated: 2017/01/25 16:07:50 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	draw_line(int vect[4], void *mlx, void *window)
{
	int v[6];

	v[0] = abs(vect[2] - vect[0]);
	v[1] = vect[0] < vect[2] ? 1 : -1;
	v[2] = abs(vect[3] - vect[1]);
	v[3] = vect[1] < vect[3] ? 1 : -1;
	v[4] = (v[0] > v[2] ? v[0] : -v[2]) / 2;
	while (1)
	{
		mlx_pixel_put(mlx, window, vect[0], vect[1], 0x00FFFFFF);
		v[5] = v[4];
		if ((vect[0] == vect[2]) && (vect[1] == vect[3]))
			break ;
		if (v[5] > -v[0])
		{
			v[4] -= v[2];
			vect[0] += v[1];
		}
		if (v[5] < v[2])
		{
			v[4] += v[0];
			vect[1] += v[3];
		}
	}
}
