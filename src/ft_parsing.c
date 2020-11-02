/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:19:34 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:07 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	get_verbose(char **av, int ac, t_ssl *ssl, int *flag)
{
	int i;
	int j;

	i = 0;
	while (av[++i] || i == 1)
		if (av[ssl->arg][0] == '-')
		{
			j = -1;
			while (av[i][++j])
				if (av[i][j] == 'v')
					*flag = *flag | 32;
		}
}

static int	ft_get_flags(char c, int *flag)
{
	int j;
	int find;

	j = -1;
	find = 0;
	while (FLAGS[++j])
	{
		if (FLAGS[j] == c)
		{
			*flag = *flag | (int)ft_pow(2, j);
			find++;
		}
	}
	if (*flag & Q)
		*flag = *flag & ~R;
	if (c == 's')
		return (1);
	else if (find == 0)
	{
		ft_printf("Invalid flag : -%c\n", c);
		ft_exit(-1, NULL, 0);
	}
	return (0);
}

static char	*ft_get_string(char **av, int ac, int i, t_ssl *ssl)
{
	ssl->flag = ssl->flag | SS;
	if (!av[ssl->arg][i])
	{
		(ssl->arg)++;
		i = 0;
	}
	if (ssl->arg == ac)
	{
		ft_printf("%s\n%s\n", "md5: option requires an argument -- s",
			"usage: md5 [-pqrlv] [-s string] [files ...]");
		exit(0);
	}
	ssl->size = ft_strlen(&av[ssl->arg][i]);
	return (ft_strdup(&av[ssl->arg][i]));
}

static void	ft_parsing_flags(int ac, char **av, t_ssl *ssl, int i)
{
	char *str;

	while (av[ssl->arg][++i] || i == 1)
	{
		ft_get_flags(av[ssl->arg][i], &ssl->flag);
		if (av[ssl->arg][i] == 's')
		{
			if (!(str = ft_get_string(av, ac, ++i, ssl)))
				ft_exit(ERR_MALLOC, "ft_get_string", ssl->type);
			ft_print(ssl->algo(str, ssl->size, ssl->flag & V), str, ssl);
			break ;
		}
		else if (av[ssl->arg][i] == 'p')
		{
			ssl->flag = ssl->flag | STDIN;
			if ((ssl->flag & PP))
			{
				if (!(str = ft_strdup("\0")))
					ft_exit(ERR_MALLOC, "ft_parsing_flags", ssl->type);
			}
			else
				str = ft_read(0, ssl);
			ft_print(ssl->algo(str, ssl->size, ssl->flag & V), str, ssl);
		}
	}
}

void		ft_parsing(int ac, char **av, t_ssl *ssl)
{
	char *str;

	ssl->arg = 2;
	get_verbose(av, ac, ssl, &ssl->flag);
	while ((ssl->arg <= ac && !(ssl->flag & STDOUT)) || ssl->arg < ac)
	{
		if (!ssl->file && ssl->arg < ac && av[ssl->arg][0] == '-')
			ft_parsing_flags(ac, av, ssl, 0);
		else if (ssl->arg < ac)
		{
			ssl->file++;
			if (!(str = ft_strdup(av[ssl->arg])))
				ft_exit(ERR_MALLOC, "ft_parsing", ssl->type);
			ssl->read = ft_read(ft_open(av[ssl->arg], ssl), ssl);
			ft_print(ssl->algo(ssl->read, ssl->size, ssl->flag & V), str, ssl);
		}
		else if (!(ssl->flag & STDOUT) && ssl->arg == ac)
		{
			ssl->flag = ssl->flag | STDIN;
			ssl->read = ft_read(0, ssl);
			ft_print(ssl->algo(ssl->read, ssl->size, ssl->flag & V), 0, ssl);
		}
		ssl->arg++;
	}
	ft_flag_p(ssl);
}
