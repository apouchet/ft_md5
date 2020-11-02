/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:49:05 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:57 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

# include "ft_md5.h"
# include "ft_sha224.h"
# include "ft_sha256.h"
# include "ft_sha384.h"
# include "ft_sha512.h"

# define BUFFSIZE 50

# define ERR_MALLOC 1
# define ERR_OPEN 2
# define ERR_READ 4

/*
**	flags
*/

# define P 1
# define Q 2
# define R 4
# define S 8
# define L 16
# define V 32
# define PP 64
# define SS 128
# define STDIN 256
# define STDOUT 512
# define FLAGS "pqrslv"

typedef struct	s_ssl
{
	int			arg;
	int			file;
	int			flag;
	size_t		size;
	char		*type;
	char		*read;
	char		*file_name;
	char		*(*algo)(char *, size_t, int);

}				t_ssl;

/*
**	ft_print.c
*/

void			ft_print(char *str, char *src, t_ssl *ssl);

/*
**	ft_parsing.c
*/

void			ft_parsing(int ac, char **av, t_ssl *ssl);

/*
**	ft_tools.c
*/

int				ft_open(char *name, t_ssl *ssl);
char			*ft_read(int fd, t_ssl *ssl);
void			ft_flag_p(t_ssl *ssl);

/*
** openssl.c
*/

void			ft_exit(int err, char *msg, char *type);

#endif
