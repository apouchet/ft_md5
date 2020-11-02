/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:20:51 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:04 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void			ft_add_size(size_t size, unsigned char *str)
{
	unsigned int i;

	i = 0;
	while (i < 8)
	{
		str[i] = size & 0xFF;
		size = size >> 8;
		i++;
	}
}

unsigned int	ft_left_rotate(unsigned int y, unsigned int offset)
{
	return (y << offset) | (y >> (32 - offset));
}

char			*ft_concat(t_md5 md5)
{
	char		*str;
	char		*tmp;
	int			i;
	u_int8_t	*p;

	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 33)))
		return (NULL);
	if (md5.vb)
		ft_printf("\nh0 = %8.8x h1 = %8.8x h2 = %8.8x h3 = %8.8x\n",
			__builtin_bswap32(md5.h[0]), __builtin_bswap32(md5.h[1]),
			__builtin_bswap32(md5.h[2]), __builtin_bswap32(md5.h[3]));
	while (i < 16)
	{
		p = (u_int8_t*)&md5.h[i / 4];
		tmp = ft_itoa_base(p[i % 4], 16, 0);
		str = ft_strcat((ft_strlen(tmp) == 1) ? ft_strcat(str, "0") : str, tmp);
		free(tmp);
		i++;
	}
	return (str);
}
