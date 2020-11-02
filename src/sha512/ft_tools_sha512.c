/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_sha512.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:28:55 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:00 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

char			*ft_concat_sha512(t_var data)
{
	char		*str;
	char		*tmp;
	int			i;
	u_int8_t	*p;

	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 129)))
		return (NULL);
	if (data.vb)
	{
		ft_printf("\nh0 = %16.16lx h1 = %16.16lx h2 = %16.16lx h3 = %16.16lx ",
			data.var_h[0], data.var_h[1], data.var_h[2], data.var_h[3]);
		ft_printf("h4 = %16.16lx h5 = %16.16lx h6 = %16.16lx h7 = %16.16lx\n",
			data.var_h[4], data.var_h[5], data.var_h[6], data.var_h[7]);
	}
	while (i < 64)
	{
		p = (u_int8_t*)&data.var_h[i / 8];
		tmp = ft_itoa_base(p[7 - i % 8], 16, 0);
		str = ft_strcat((ft_strlen(tmp) == 1) ? ft_strcat(str, "0") : str, tmp);
		free(tmp);
		i++;
	}
	return (str);
}

unsigned long	right_rot_64(unsigned long x, unsigned long offset)
{
	return (x >> offset % 64) | (x << (64 - offset) % 64);
}

void			ft_add_size_big(size_t size, unsigned char *str)
{
	unsigned long i;

	i = 8;
	while (i > 0)
	{
		i--;
		str[i] = size & 0xFF;
		size = size >> 8;
	}
}

unsigned char	*ft_padding_sha512(char *src, t_var *data, size_t len)
{
	unsigned char	*str;

	data->nb_block = (unsigned long)(len / 128);
	if (len - (128 * data->nb_block) > 119)
		data->nb_block++;
	data->nb_block++;
	data->size = data->nb_block * 128;
	if (!(str = (unsigned char *)ft_memalloc(data->size)))
		return (NULL);
	ft_memcpy((char*)str, src, len);
	str[len] = (unsigned char)128;
	ft_add_size_big((unsigned long)(len * 8), &str[data->size - 8]);
	return (str);
}

unsigned long	*ft_cut_sha512(unsigned char *src, t_var *data)
{
	unsigned long	*tab;
	unsigned long	size;
	unsigned long	i;

	size = (unsigned long)(data->size / 8);
	i = 0;
	if (!(tab = (unsigned long *)ft_memalloc(sizeof(unsigned long) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = (
			(unsigned long)src[i * 8 + 0] << 56 |
			(unsigned long)src[i * 8 + 1] << 48 |
			(unsigned long)src[i * 8 + 2] << 40 |
			(unsigned long)src[i * 8 + 3] << 32 |
			(unsigned long)src[i * 8 + 4] << 24 |
			(unsigned long)src[i * 8 + 5] << 16 |
			(unsigned long)src[i * 8 + 6] << 8 |
			(unsigned long)src[i * 8 + 7]);
		i++;
	}
	free(src);
	return (tab);
}
