/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:05:48 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:58 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_v
{
	unsigned int	var_h[8];
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	k[64];
	unsigned int	w[64];
	unsigned int	nb_block;
	unsigned int	padding;
	size_t			size;
	int				vb;
}					t_v;

/*
**	ft_sha256.c
*/

char				*ft_sha256(char *src, size_t size, int vb);
void				ft_loop_sha256(unsigned int *tab, t_v *data);
void				ft_algo_1_sha256(unsigned int *tab, t_v *data);
void				ft_algo_2_sha256(t_v *d, unsigned int s[2]
, unsigned int tmp[2]);

/*
**	ft_tools_sha256.c
*/

char				*ft_concat_sha256(t_v data);
unsigned int		right_rot(unsigned int x, unsigned int offset);
void				ft_add_size_big(size_t size, unsigned char *str);
unsigned int		*ft_cut_sha256(unsigned char *src, t_v *data);
unsigned char		*ft_padding_sha256(char *src, t_v *data, size_t len);

/*
** ft_init_sha256.c
*/
void				init_sha256(t_v *data);

#endif
