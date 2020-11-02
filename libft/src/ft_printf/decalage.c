/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decalage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:57:29 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:41 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len(int c)
{
	int octet;

	octet = 0;
	if (c <= 127)
		octet = -1;
	if (c > 127)
		octet++;
	if (c > 2047)
		octet++;
	if (c > 65535)
		octet++;
	if (c > 2097151)
		octet++;
	if (octet == 0)
		octet = 1;
	return (octet);
}

static int	ft_deca_bas(t_val *a, int c, int octet)
{
	int base;
	int i;

	i = 0;
	base = 0x80;
	while (i++ < octet)
		base = (base >> 1) + 0x80;
	c = c >> (6 * (octet));
	a->tmp = c << (6 * (octet));
	c = c + base;
	return (c);
}

void		ft_decalage(t_val *a, int c)
{
	int		octet;
	int		pos;
	int		save;

	save = c;
	octet = ft_len(c);
	a->ldif += octet;
	if (octet == -1)
	{
		a->buff[a->b++] = (char)c;
		return ;
	}
	pos = 1;
	c = ft_deca_bas(a, c, octet);
	a->buff[a->b++] = (char)c;
	while (pos <= octet)
	{
		c = save - a->tmp;
		if (octet - pos != 0)
			c = c >> (6 * (octet - pos));
		if (octet - pos != 0)
			a->tmp = (c << (6 * (octet - pos))) + a->tmp;
		pos++;
		a->buff[a->b++] = (char)c + 0x80;
	}
}
