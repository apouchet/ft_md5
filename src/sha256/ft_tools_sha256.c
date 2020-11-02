/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_sha256.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:06:23 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

char			*ft_concat_sha256(t_v data)
{
	char		*str;
	char		*tmp;
	int			i;
	u_int8_t	*p;

	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 65)))
		return (NULL);
	if (data.vb)
	{
		ft_printf("\nh0 = %8.8x h1 = %8.8x h2 = %8.8x h3 = %8.8x ",
			data.var_h[0], data.var_h[1], data.var_h[2], data.var_h[3]);
		ft_printf("h4 = %8.8x h5 = %8.8x h6 = %8.8x h7 = %8.8x\n",
			data.var_h[4], data.var_h[5], data.var_h[6], data.var_h[7]);
	}
	while (i < 32)
	{
		p = (u_int8_t*)&data.var_h[i / 4];
		tmp = ft_itoa_base(p[3 - i % 4], 16, 0);
		str = ft_strcat((ft_strlen(tmp) == 1) ? ft_strcat(str, "0") : str, tmp);
		free(tmp);
		i++;
	}
	return (str);
}

unsigned int	right_rot(unsigned int x, unsigned int offset)
{
	return (x >> offset % 32) | (x << (32 - offset) % 32);
}

unsigned char	*ft_padding_sha256(char *src, t_v *data, size_t len)
{
	unsigned char	*str;

	data->nb_block = (unsigned int)(len / 64);
	if (len - (64 * data->nb_block) > 55)
		data->nb_block++;
	data->nb_block++;
	data->size = data->nb_block * 64;
	if (!(str = (unsigned char *)ft_memalloc(data->size)))
		return (NULL);
	ft_memcpy((char*)str, src, len);
	str[len] = (unsigned char)128;
	ft_add_size_big((unsigned int)(len * 8), &str[data->size - 8]);
	return (str);
}

/*
**	ft_printf("[%u]%u\n",i, tab[i]);
**
**	ft_printf("tab[%u] - %u = -|%c%c%c%c|- --- -%u- -%u- -%u- -%u-\n",
**		i, strlen((char *)tab[i]), (unsigned int)tab[i][0], tab[i][1],
**		tab[i][2], tab[i][3], tab[i][0], tab[i][1], tab[i][2], tab[i][3]);
*/

unsigned int	*ft_cut_sha256(unsigned char *src, t_v *data)
{
	unsigned int	*tab;
	unsigned int	size;
	unsigned int	i;

	size = (unsigned int)(data->size / 4);
	i = 0;
	if (!(tab = (unsigned int *)ft_memalloc(sizeof(unsigned int) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = ((unsigned int)src[i * 4 + 0] << 24 |
		(unsigned int)src[i * 4 + 1] << 16 |
		(unsigned int)src[i * 4 + 2] << 8 |
		(unsigned int)src[i * 4 + 3]);
		i++;
	}
	free(src);
	return (tab);
}
