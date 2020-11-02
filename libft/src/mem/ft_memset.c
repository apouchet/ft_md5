/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:00 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:17 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *a;

	a = (unsigned char*)s;
	while (n--)
		a[n] = (unsigned char)c;
	return (a);
}
