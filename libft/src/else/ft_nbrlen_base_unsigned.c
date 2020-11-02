/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:51 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:48 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_nbrlen_base_unsigned(size_t nb, unsigned int base)
{
	size_t	len;

	len = 0;
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	return (len + 1);
}
