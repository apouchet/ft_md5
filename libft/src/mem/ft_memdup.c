/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:22:36 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:18 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memdup(const void *s1, size_t n)
{
	void *a;

	if (!(a = (void*)ft_memalloc(n)))
		return (NULL);
	a = ft_memcpy(a, s1, n);
	return (a);
}
