/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:11:47 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static unsigned int	ft_printf_var(t_v *d, char *str, int i)
{
	if (d->vb)
	{
		str == NULL ? ft_printf("%4u - ", i) : ft_printf("\ninit ");
		ft_printf("a = %8.8x b = %8.8x c = %8.8x d = %8.8x ",
			d->a, d->b, d->c, d->d);
		ft_printf("e = %8.8x f = %8.8x g = %8.8x h = %8.8x\n",
			d->e, d->f, d->g, d->h);
	}
	return ((unsigned int)i + 1);
}

void				ft_algo_2_sha256(t_v *d, unsigned int s[2],
	unsigned int tmp[2])
{
	int				i;
	unsigned int	maj;
	unsigned int	ch;

	i = ft_printf_var(d, "init", -1);
	while (i < 64)
	{
		s[1] = right_rot(d->e, 6) ^ right_rot(d->e, 11) ^ right_rot(d->e, 25);
		ch = (d->e & d->f) ^ ((~d->e) & d->g);
		tmp[0] = (d->h + s[1] + ch + d->k[i] + d->w[i])
			% (size_t)(ft_pow(2, 32));
		s[0] = right_rot(d->a, 2) ^ right_rot(d->a, 13) ^ right_rot(d->a, 22);
		maj = (d->a & d->b) ^ (d->a & d->c) ^ (d->b & d->c);
		tmp[1] = (s[0] + maj) % (size_t)(ft_pow(2, 32));
		d->h = d->g;
		d->g = d->f;
		d->f = d->e;
		d->e = (d->d + tmp[0]) % (size_t)(ft_pow(2, 32));
		d->d = d->c;
		d->c = d->b;
		d->b = d->a;
		d->a = (tmp[0] + tmp[1]) % (size_t)(ft_pow(2, 32));
		i = ft_printf_var(d, NULL, i);
	}
}

void				ft_algo_1_sha256(unsigned int *tab, t_v *data)
{
	unsigned int	tmp[2];
	unsigned int	s[2];
	unsigned int	i;

	i = 0;
	while (i < 64)
	{
		if (i > 15)
		{
			s[0] = right_rot(data->w[i - 15], 7) ^ right_rot(data->w[i - 15],
			18) ^ (data->w[i - 15] >> 3);
			s[1] = right_rot(data->w[i - 2], 17) ^ right_rot(data->w[i - 2],
			19) ^ (data->w[i - 2] >> 10);
			data->w[i] = (data->w[i - 16] + s[0] + data->w[i - 7] + s[1])
			% (u_int64_t)(ft_pow(2, 32));
		}
		else
			data->w[i] = tab[i];
		i++;
	}
	ft_algo_2_sha256(data, s, tmp);
}

void				ft_loop_sha256(unsigned int *tab, t_v *data)
{
	data->a = data->var_h[0];
	data->b = data->var_h[1];
	data->c = data->var_h[2];
	data->d = data->var_h[3];
	data->e = data->var_h[4];
	data->f = data->var_h[5];
	data->g = data->var_h[6];
	data->h = data->var_h[7];
	ft_algo_1_sha256(tab, data);
	data->var_h[0] = data->var_h[0] + data->a;
	data->var_h[1] = data->var_h[1] + data->b;
	data->var_h[2] = data->var_h[2] + data->c;
	data->var_h[3] = data->var_h[3] + data->d;
	data->var_h[4] = data->var_h[4] + data->e;
	data->var_h[5] = data->var_h[5] + data->f;
	data->var_h[6] = data->var_h[6] + data->g;
	data->var_h[7] = data->var_h[7] + data->h;
}

char				*ft_sha256(char *src, size_t size, int vb)
{
	unsigned int	*tab;
	t_v				data;
	unsigned int	i;

	init_sha256(&data);
	data.vb = vb;
	tab = ft_cut_sha256(ft_padding_sha256(src, &data, size), &data);
	i = 0;
	while (i < data.nb_block)
	{
		if (data.vb)
			ft_printf("\nBlock [ %u / %u ]\t str = %.55s\n", i + 1,
				data.nb_block, src + (i * 55));
		ft_loop_sha256(&tab[i * 16], &data);
		i++;
	}
	free(tab);
	return (ft_concat_sha256(data));
}
