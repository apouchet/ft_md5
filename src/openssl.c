/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openssl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:55:11 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:06 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_exit(int err, char *msg, char *type)
{
	if (err == -2)
		ft_printf("./ft_ssl : '%s' is an invalid command\n", msg);
	if (err <= -2)
	{
		ft_printf("Usage: ./ft_ssl [Message Digest commands] [flags] [file]\n");
		ft_printf("\nMessage Digest commands:\nmd5\tsha224\tsha256%s",
			"\tsha384\tsha512\n\n");
	}
	if (err < 0)
		ft_printf("Flags:\n[-pqrlv] [-s string]\n");
	else if (err == ERR_MALLOC || err == ERR_OPEN)
	{
		ft_printf("%s: %s: %s\n", type, msg, strerror(errno));
		exit(1);
	}
	else if (err == ERR_READ)
		ft_printf("%s: %s: %s\n", type, msg, strerror(errno));
	exit(0);
}

static void	ft_get_algo(char *entry, char *(**algo)(char *, size_t, int),
	t_ssl *ssl)
{
	ssl->type = entry;
	if (!ft_strcmp(entry, "md5") || !ft_strcmp(entry, "MD5"))
	{
		*algo = &ft_md5;
	}
	else if (!ft_strcmp(entry, "sha224") || !ft_strcmp(entry, "SHA224"))
		*algo = &ft_sha224;
	else if (!ft_strcmp(entry, "sha256") || !ft_strcmp(entry, "SHA256"))
		*algo = &ft_sha256;
	else if (!ft_strcmp(entry, "sha384") || !ft_strcmp(entry, "SHA384"))
		*algo = &ft_sha384;
	else if (!ft_strcmp(entry, "sha512") || !ft_strcmp(entry, "SHA512"))
		*algo = &ft_sha512;
	else
		ft_exit(-2, entry, ssl->type);
}

int			main(int ac, char **av)
{
	t_ssl ssl;

	ft_bzero(&ssl, sizeof(t_ssl));
	if (ac == 1)
		ft_exit(-3, NULL, 0);
	ft_get_algo(av[1], &ssl.algo, &ssl);
	ft_parsing(ac, av, &ssl);
	if (ssl.read)
		free(ssl.read);
	return (0);
}
