/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:43:23 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:07 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			ft_open(char *name, t_ssl *ssl)
{
	int fd;

	if ((fd = open(name, O_RDONLY)) < 0)
		ft_exit(ERR_OPEN, name, ssl->type);
	ssl->file_name = name;
	return (fd);
}

static char	*ft_join(t_ssl *ssl, char *buff, char *ret, ssize_t rd)
{
	char	*tmp;

	ssl->size += (size_t)rd;
	if (!(tmp = (char*)malloc(sizeof(char) * (ssl->size + 1))))
		ft_exit(ERR_MALLOC, "ft_read", ssl->type);
	ft_memcpy(tmp, ret, ssl->size - (size_t)rd);
	ft_memcpy(&tmp[ssl->size - (size_t)rd], buff, (size_t)(rd));
	tmp[ssl->size] = '\0';
	free(ret);
	return (tmp);
}

static char	*ft_quick_read(int fd, t_ssl *ssl)
{
	char	*ret;
	ssize_t	rd;

	ssl->size = (size_t)lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(ret = (char *)malloc(sizeof(char) * (ssl->size + 1))))
		ft_exit(ERR_MALLOC, "ft_quick_read", ssl->type);
	if ((rd = read(fd, ret, ssl->size)) < 0)
		ft_exit(ERR_READ, ssl->file_name, ssl->type);
	ret[ssl->size] = '\0';
	close(fd);
	return (ret);
}

char		*ft_read(int fd, t_ssl *ssl)
{
	char	*buff;
	char	*ret;
	ssize_t	rd;

	rd = 1;
	ret = NULL;
	if (fd != 0 && ssl->flag & L)
		return (ft_quick_read(fd, ssl));
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFSIZE + 1)))
		|| !(ret = ft_strdup("")))
		ft_exit(ERR_MALLOC, "ft_read", ssl->type);
	while (rd > 0)
	{
		if ((rd = read(fd, buff, BUFFSIZE)) < 0)
			ft_exit(ERR_READ, ssl->file_name, ssl->type);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		ret = ft_join(ssl, buff, ret, rd);
	}
	free(buff);
	if (fd != 0)
		close(fd);
	ssl->file_name = NULL;
	return (ret);
}

void		ft_flag_p(t_ssl *ssl)
{
	char *str;

	if (!ssl->file && ssl->flag & PP && !(ssl->flag & SS) &&
		(ssl->flag & R || ssl->flag & Q))
	{
		if (!(str = ft_strdup("\0")))
			ft_exit(ERR_MALLOC, "ft_parsing_flags", ssl->type);
		ft_print(ssl->algo(str, ssl->size, ssl->flag & V), str, ssl);
	}
}
