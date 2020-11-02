/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_md5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:26:15 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:06 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void		ft_tab_r(t_md5 *md5)
{
	static unsigned int	a[16] = {7, 12, 17, 22, 5, 9, 14, 20, 4, 11, 16, 23, 6,
		10, 15, 21};
	int					i;
	int					j;

	i = -1;
	j = 0;
	while (++i < 64)
		md5->r[i] = a[(j++ % 4) + (16 * ((i / 16) % 4)) / 4];
}

void			ft_init_md(t_md5 *md5)
{
	unsigned int i;

	ft_bzero(md5, sizeof(t_md5));
	md5->h[0] = 0x67452301;
	md5->h[1] = 0xEFCDAB89;
	md5->h[2] = 0x98BADCFE;
	md5->h[3] = 0x10325476;
	ft_tab_r(md5);
	i = 0;
	while (i < 64)
	{
		md5->k[i] = (unsigned int)(floor(fabs(sin(i + 1)) * 4294967296));
		i++;
	}
}
