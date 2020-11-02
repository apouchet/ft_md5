/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:18:35 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:00 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

static unsigned long int	ft_printf_var(t_var *d, const char *str, int i)
{
	if (d->vb)
	{
		str == NULL ? ft_printf("%4u - ", i) : ft_printf("\ninit ");
		ft_printf("a = %16.16lx b = %16.16lx c = %16.16lx d = %16.16lx ",
			d->a, d->b, d->c, d->d);
		ft_printf("e = %16.16lx f = %16.16lx g = %16.16lx h = %16.16lx\n",
			d->e, d->f, d->g, d->h);
	}
	return (i + 1);
}

void						ft_algo_2_sha512(t_var *d, unsigned long s[2],
	unsigned long tmp[2])
{
	int				i;
	unsigned long	maj;
	unsigned long	ch;

	i = ft_printf_var(d, "init", -1);
	while (i < 80)
	{
		s[1] = right_rot_64(d->e, 14) ^ right_rot_64(d->e, 18)
			^ right_rot_64(d->e, 41);
		ch = (d->e & d->f) ^ ((~d->e) & d->g);
		tmp[0] = (d->h + s[1] + ch + d->k[i] + d->w[i]);
		s[0] = right_rot_64(d->a, 28) ^ right_rot_64(d->a, 34)
			^ right_rot_64(d->a, 39);
		maj = (d->a & d->b) ^ (d->a & d->c) ^ (d->b & d->c);
		tmp[1] = (s[0] + maj);
		d->h = d->g;
		d->g = d->f;
		d->f = d->e;
		d->e = (d->d + tmp[0]);
		d->d = d->c;
		d->c = d->b;
		d->b = d->a;
		d->a = (tmp[0] + tmp[1]);
		i = ft_printf_var(d, NULL, i);
	}
}

void						ft_algo_1_sha512(unsigned long *tab,
	t_var *data)
{
	unsigned long	tmp[2];
	unsigned long	s[2];
	unsigned long	i;

	i = 0;
	while (i < 80)
	{
		if (i > 15)
		{
			s[0] = right_rot_64(data->w[i - 15], 1)
				^ right_rot_64(data->w[i - 15], 8) ^ (data->w[i - 15] >> 7);
			s[1] = right_rot_64(data->w[i - 2], 19)
				^ right_rot_64(data->w[i - 2], 61) ^ (data->w[i - 2] >> 6);
			data->w[i] = data->w[i - 16] + s[0] + data->w[i - 7] + s[1];
		}
		else
			data->w[i] = tab[i];
		i++;
	}
	ft_algo_2_sha512(data, s, tmp);
}

void						ft_loop_sha512(unsigned long *tab, t_var *data)
{
	data->a = data->var_h[0];
	data->b = data->var_h[1];
	data->c = data->var_h[2];
	data->d = data->var_h[3];
	data->e = data->var_h[4];
	data->f = data->var_h[5];
	data->g = data->var_h[6];
	data->h = data->var_h[7];
	ft_algo_1_sha512(tab, data);
	data->var_h[0] = data->var_h[0] + data->a;
	data->var_h[1] = data->var_h[1] + data->b;
	data->var_h[2] = data->var_h[2] + data->c;
	data->var_h[3] = data->var_h[3] + data->d;
	data->var_h[4] = data->var_h[4] + data->e;
	data->var_h[5] = data->var_h[5] + data->f;
	data->var_h[6] = data->var_h[6] + data->g;
	data->var_h[7] = data->var_h[7] + data->h;
}

char						*ft_sha512(char *src, size_t size, int vb)
{
	unsigned long	*tab;
	t_var			data;
	unsigned long	i;

	init_sha512(&data);
	data.vb = vb;
	tab = ft_cut_sha512(ft_padding_sha512(src, &data, size), &data);
	i = 0;
	while (i < data.nb_block)
	{
		if (data.vb)
			ft_printf("\nBlock [ %u / %u ]\t str = %.128s\n", i + 1,
				data.nb_block, src + (i * 128));
		ft_loop_sha512(&tab[i * 32], &data);
		i++;
	}
	free(tab);
	return (ft_concat_sha512(data));
}
