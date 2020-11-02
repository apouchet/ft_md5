/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:18:09 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:00 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char*)s1;
	b = (const unsigned char*)s2;
	i = 0;
	while (i < n && a[i] && b[i] && a[i] == b[i])
		i++;
	return (i == n ? 0 : a[i] - b[i]);
}
