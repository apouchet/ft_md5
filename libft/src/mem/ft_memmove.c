/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:12:29 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:17 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

static void	*ft_rev(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char *b;

	a = (unsigned char*)dest;
	b = (const unsigned char*)src;
	while (n--)
		a[n] = b[n];
	return (a);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		dest = ft_rev(dest, src, n);
	if (dest < src)
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
