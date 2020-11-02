/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:35:12 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:05 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static unsigned char	*ft_padding(char *src, t_md5 *md5, size_t len)
{
	unsigned char	*str;

	md5->nb_block = (unsigned int)(len / 64);
	if (len - (64 * md5->nb_block) > 55)
		md5->nb_block++;
	md5->nb_block++;
	md5->size = md5->nb_block * 64;
	if (!(str = (unsigned char *)ft_memalloc(md5->size)))
		return (NULL);
	ft_memcpy((char*)str, src, len);
	str[len] = (unsigned char)128;
	ft_add_size((unsigned int)(len * 8), &str[md5->size - 8]);
	return (str);
}

static unsigned int		*ft_cutter(unsigned char *src, t_md5 *md5)
{
	unsigned int	*tab;
	unsigned int	size;
	unsigned int	i;

	size = md5->size / 4;
	i = 0;
	if (!(tab = (unsigned int *)ft_memalloc(sizeof(unsigned int) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = ((unsigned int)src[i * 4 + 3] << 24 |
		(unsigned int)src[i * 4 + 2] << 16 |
		(unsigned int)src[i * 4 + 1] << 8 |
		(unsigned int)src[i * 4 + 0]);
		if (md5->vb)
			ft_printf("w[%2u] = %8.8x\n", i,
				__builtin_bswap32((unsigned int)tab[i]));
		i++;
	}
	free(src);
	return (tab);
}

static void				ft_loop_statements(unsigned int i, t_md5 *md5)
{
	if (i < 16)
	{
		md5->f = (md5->b & md5->c) | ((~md5->b) & md5->d);
		md5->g = i;
	}
	else if (i < 32)
	{
		md5->f = (md5->d & md5->b) | ((~md5->d) & md5->c);
		md5->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		md5->f = md5->b ^ md5->c ^ md5->d;
		md5->g = (3 * i + 5) % 16;
	}
	else
	{
		md5->f = md5->c ^ (md5->b | (~md5->d));
		md5->g = (7 * i) % 16;
	}
}

static void				ft_loop(unsigned int *tab, t_md5 *md5)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	if (md5->vb)
		ft_printf("\ninit a = %8.8x b = %8.8x c = %8.8x d = %8.8x\n"
		, (md5->a), (md5->b), (md5->c), (md5->d));
	while (i < 64)
	{
		ft_loop_statements(i, md5);
		tmp = md5->d;
		md5->d = md5->c;
		md5->c = md5->b;
		md5->b = ft_left_rotate((md5->a + md5->f + md5->k[i] + tab[md5->g]),
			md5->r[i]) + md5->b;
		md5->a = tmp;
		if (md5->vb)
			ft_printf("%4u a = %8.8x b = %8.8x c = %8.8x d = %8.8x\n",
				i, md5->a, md5->b, md5->c, md5->d);
		i++;
	}
	md5->h[0] = md5->h[0] + md5->a;
	md5->h[1] = md5->h[1] + md5->b;
	md5->h[2] = md5->h[2] + md5->c;
	md5->h[3] = md5->h[3] + md5->d;
}

char					*ft_md5(char *src, size_t size, int vb)
{
	t_md5			md5;
	unsigned int	*tab;
	unsigned int	i;

	ft_init_md(&md5);
	md5.vb = vb;
	tab = ft_cutter(ft_padding(src, &md5, size), &md5);
	i = 0;
	while (i < md5.nb_block)
	{
		if (md5.vb)
			ft_printf("\nBlock [ %u / %u ]\t str = %.55s\n", i + 1,
				md5.nb_block, src + (i * 55));
		md5.a = md5.h[0];
		md5.b = md5.h[1];
		md5.c = md5.h[2];
		md5.d = md5.h[3];
		ft_loop(&tab[i * 16], &md5);
		i++;
	}
	free(tab);
	return (ft_concat(md5));
}
