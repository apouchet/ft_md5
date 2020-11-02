/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:05:48 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:58 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_var
{
	unsigned long	var_h[8];
	unsigned long	a;
	unsigned long	b;
	unsigned long	c;
	unsigned long	d;
	unsigned long	e;
	unsigned long	f;
	unsigned long	g;
	unsigned long	h;
	unsigned long	k[80];
	unsigned long	w[80];
	unsigned long	nb_block;
	unsigned long	padding;
	ssize_t			size;
	int				vb;
}					t_var;

/*
**	ft_sha512.c
*/

char				*ft_sha512(char *src, size_t size, int vb);
void				ft_loop_sha512(unsigned long *tab, t_var *data);
void				ft_algo_1_sha512(unsigned long *tab, t_var *data);
void				ft_algo_2_sha512(t_var *d, unsigned long s[2]
					, unsigned long tmp[2]);

/*
**	ft_init_sha512.c
*/

void				init_sha512(t_var *data);

/*
**	ft_tools_sha512.c
*/

unsigned long		*ft_cut_sha512(unsigned char *src, t_var *data);
unsigned char		*ft_padding_sha512(char *src, t_var *data, size_t len);
void				ft_add_size_big(size_t size, unsigned char *str);
unsigned long		right_rot_64(unsigned long x, unsigned long offset);
char				*ft_concat_sha512(t_var data);

#endif
