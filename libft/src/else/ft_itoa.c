/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:39 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:51 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

char	*ft_itoa(int nb)
{
	size_t	len;
	char	*a;

	len = ft_nbrlen(nb);
	if (!(a = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	len--;
	a[0] = '-';
	if (nb < 0 && nb <= -10)
	{
		a[len--] = (char)((nb % 10) * -1) + '0';
		nb = (nb / 10) * -1;
	}
	else if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		a[len--] = nb % 10 + '0';
		nb /= 10;
	}
	a[len] = (char)nb + '0';
	return (a);
}
