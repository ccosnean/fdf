/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:59:26 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/20 15:33:06 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0 && n > -10)
		ft_putchar_fd('-', fd);
	n = n % 10;
	if (n > 0)
		ft_putchar_fd(n + '0', fd);
	else
		ft_putchar_fd(-n + '0', fd);
}
