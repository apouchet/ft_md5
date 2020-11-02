/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:03:37 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:54:10 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	ft_print_openssl_style(t_ssl *ssl, char *src, char *str)
{
	if (!(ssl->flag & STDIN) && !(ssl->flag & R) && !(ssl->flag & Q))
		ft_printf("%s(%s)= ", ssl->type, src);
	else if ((ssl->flag & STDIN) && !(ssl->flag & R) && !(ssl->flag & Q))
		ft_printf("(stdin)= ");
	ft_printf("%s", str);
	if (!(ssl->flag & PP) && !(ssl->flag & P) && (ssl->flag & R))
		ft_printf(" *%s", ((ssl->flag & STDIN) ? "stdin" : src));
	ft_printf("\n");
	if ((ssl->flag & STDIN) || (ssl->flag & P) || (ssl->flag & S))
		ssl->flag = ssl->flag & ~(STDIN | P | S);
}

static void	ft_print_md5_style(t_ssl *ssl, char *src, char *str)
{
	int tmp;

	tmp = 0;
	if (ssl->flag & S)
		tmp = 1;
	if ((ssl->flag & P) && !(ssl->flag & PP))
	{
		ft_printf("%s", src);
		ssl->flag = ssl->flag | PP;
	}
	if (!(ssl->flag & STDIN) && !(ssl->flag & R) && !(ssl->flag & Q))
		ft_printf("%s (%.*s%s%.*s) = ", ssl->type, tmp, "\"", src, tmp, "\"");
	ft_printf("%s", str);
	if (!(ssl->flag & P) && (ssl->flag & R))
		ft_printf(" %.*s%s%.*s", tmp, "\"",
		((ssl->flag & STDIN) ? "stdin" : src), tmp, "\"");
	ft_printf("\n");
	if ((ssl->flag & STDIN) || (ssl->flag & P) || (ssl->flag & S))
		ssl->flag = ssl->flag & ~(STDIN | P | S);
}

void		ft_print(char *str, char *src, t_ssl *ssl)
{
	ssl->flag = ssl->flag | STDOUT;
	if (ssl->flag & S || ssl->flag & P || ssl->flag & Q)
		ft_print_md5_style(ssl, src, str);
	else
		ft_print_openssl_style(ssl, src, str);
	if (str)
		free(str);
	if (src)
		free(src);
	ssl->size = 0;
}
