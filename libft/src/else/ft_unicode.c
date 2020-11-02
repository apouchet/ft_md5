/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:10:06 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:44 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

static int		ft_deca_bas(int *tmp, int c, int octet)
{
	int		base;
	int		i;

	i = 0;
	base = 0x80;
	while (i++ < octet)
		base = (base >> 1) + 0x80;
	c = c >> (6 * (octet));
	*tmp = c << (6 * (octet));
	c = c + base;
	return (c);
}

char			*ft_unicode(char *a, int c)
{
	int		octet;
	int		pos;
	int		save;
	int		tmp;
	int		i;

	i = 0;
	save = c;
	octet = (int)ft_unicode_len(c) - 1;
	pos = 1;
	c = ft_deca_bas(&tmp, c, octet);
	a[i++] = (char)c;
	while (pos <= octet)
	{
		c = save - tmp;
		if (octet - pos != 0)
			c = c >> (6 * (octet - pos));
		if (octet - pos != 0)
			tmp = (c << (6 * (octet - pos))) + tmp;
		pos++;
		a[i++] = (char)c + 0x80;
	}
	a[i] = '\0';
	return (a);
}
