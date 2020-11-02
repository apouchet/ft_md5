/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:49:28 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:59 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_md5
{
	unsigned int	len;
	unsigned int	size;
	unsigned int	nb_block;
	unsigned int	r[64];
	unsigned int	k[64];
	unsigned int	h[4];
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	f;
	unsigned int	g;
	int				vb;
}					t_md5;

/*
**	ft_md5.c
*/

char				*ft_md5(char *src, size_t size, int vb);

/*
**	ft_init_md5.c
*/

void				ft_init_md(t_md5 *md5);

/*
**	ft_tools_md5.c
*/

void				ft_add_size(size_t size, unsigned char *str);
unsigned int		ft_left_rotate(unsigned int y, unsigned int offset);
char				*ft_concat(t_md5 md5);

#endif
