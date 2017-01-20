/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosnean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:59:26 by ccosnean          #+#    #+#             */
/*   Updated: 2016/10/20 15:06:15 by ccosnean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 10 || n <= -10)
		ft_putnbr(n / 10);
	if (n < 0 && n > -10)
		ft_putchar_fd('-', 1);
	n = n % 10;
	if (n > 0)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd(-n + '0', 1);
}