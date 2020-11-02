/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:50 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:13 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int a;

	a = (long)nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a < 10)
		ft_putchar_fd('0' + (int)a, fd);
	if (a >= 10)
	{
		ft_putnbr_fd((int)(a / 10), fd);
		ft_putchar_fd('0' + (int)(a % 10), fd);
	}
}
