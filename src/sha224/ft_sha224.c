/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:18:35 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:03 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha224.h"

char		*ft_concat_sha224(t_v data)
{
	char		*str;
	char		*tmp;
	int			i;
	u_int8_t	*p;

	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 61)))
		return (NULL);
	if (data.vb)
	{
		ft_printf("\nh0 = %8.8x h1 = %8.8x h2 = %8.8x h3 = %8.8x ",
			data.var_h[0], data.var_h[1], data.var_h[2], data.var_h[3]);
		ft_printf("h4 = %8.8x h5 = %8.8x h6 = %8.8x h7 = %8.8x\n",
			data.var_h[4], data.var_h[5], data.var_h[6], data.var_h[7]);
	}
	while (i < 28)
	{
		p = (u_int8_t*)&data.var_h[i / 4];
		tmp = ft_itoa_base(p[3 - i % 4], 16, 0);
		str = ft_strcat((ft_strlen(tmp) == 1) ? ft_strcat(str, "0") : str, tmp);
		free(tmp);
		i++;
	}
	return (str);
}

static void	init_sha224(t_v *data)
{
	int				i;
	static size_t	tmp[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
		0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
		0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa,
		0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
		0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138,
		0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624,
		0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
		0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f,
		0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

	ft_bzero(data, sizeof(t_v));
	data->var_h[0] = 0xc1059ed8;
	data->var_h[1] = 0x367cd507;
	data->var_h[2] = 0x3070dd17;
	data->var_h[3] = 0xf70e5939;
	data->var_h[4] = 0xffc00b31;
	data->var_h[5] = 0x68581511;
	data->var_h[6] = 0x64f98fa7;
	data->var_h[7] = 0xbefa4fa4;
	i = -1;
	while (++i < 64)
		data->k[i] = (unsigned int)tmp[i];
}

char		*ft_sha224(char *src, size_t size, int vb)
{
	unsigned int	*tab;
	t_v				data;
	unsigned int	i;

	init_sha224(&data);
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
	return (ft_concat_sha224(data));
}
