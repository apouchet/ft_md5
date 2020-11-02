/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:51:31 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:38 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p(t_val *a)
{
	int p;

	p = 0;
	if (a->prec < a->len && a->precision == 1)
		p = a->prec;
	else
		p = a->len;
	return (p);
}

void		ft_buff_str(char *str, t_val *a, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		a->buff[a->b] = str[i];
		if (a->b > 500)
			ft_affich_printf(a);
		a->b++;
		i++;
	}
	a->buff[a->b] = '\0';
}

void		ft_str(t_val *a, va_list ap)
{
	char			*str;
	int				p;

	str = va_arg(ap, char *);
	if (str != NULL)
		a->len = (int)ft_strlen(str);
	else
		a->len = 6;
	p = ft_p(a);
	if (a->ldc > 0)
		largeur_champ(p, a);
	if (str == NULL)
		ft_buff_str("(null)", a, p);
	else
		ft_buff_str(str, a, p);
	if (a->ldc < 0)
		largeur_champ(p, a);
}

void		ft_str_unicode(t_val *a, va_list ap)
{
	int		*nbr;
	int		j;
	int		p;
	int		l;

	l = 0;
	j = 0;
	nbr = va_arg(ap, wchar_t*);
	p = a->prec;
	while (nbr != NULL && ((nbr[a->len] != 0 && a->len < p && p != 0) ||
		(nbr[a->len] != 0 && p == 0 && a->precision == 0)))
		if (nbr[a->len++] > 127)
			l += ft_len(nbr[a->len - 1]);
	if (nbr == NULL)
		a->len = 6;
	p = ft_p(a);
	if (a->ldc > 0)
		largeur_champ(p + l, a);
	while (nbr != NULL && j < p)
		ft_decalage(a, nbr[j++]);
	if (nbr == NULL)
		ft_buff_str("(null)", a, p);
	if (a->ldc < 0)
		largeur_champ(p + l, a);
}

void		lettre(t_val *a, va_list ap, int flag)
{
	if (a->zero != 0)
		a->prec = a->ldc;
	if (a->ldc > 0 && a->zero == 0)
		largeur_champ(1, a);
	if (a->ldc > 0 && a->zero != 0)
		precision(1, a);
	if (flag == 'C' || flag == 'S' || a->lon == 1)
		ft_decalage(a, va_arg(ap, wchar_t));
	else if (flag == 'c')
		a->buff[a->b++] = (char)va_arg(ap, int);
	else
		a->buff[a->b++] = (char)flag;
	if (a->ldc < 0 && a->zero == 0)
		largeur_champ(1, a);
	if (a->ldc < 0 && a->zero != 0)
		precision(1, a);
	return ;
}
