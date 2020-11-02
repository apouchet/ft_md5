/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:12:19 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:19 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	a = (unsigned char*)dst;
	b = (const unsigned char*)src;
	i = 0;
	while (i++ < n)
		a[i - 1] = b[i - 1];
	return (dst);
}
