/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nombre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:06:10 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:39 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_value(t_val *a, char *tab, char flag)
{
	if (flag == 'd' || flag == 'D' || flag == 'i')
	{
		if (!(tab = ft_itoa_base(a->nb, a->base, a->maj)))
			return (NULL);
		if (a->nb == 0 && a->precision == 1 && a->prec == 0)
			tab[0] = '\0';
	}
	else
	{
		if (!(tab = ft_itoa_unsigned_base(a->nbr, a->base, a->maj)))
			return (NULL);
		if (a->nbr == 0 && a->precision == 1 && a->prec == 0)
			tab[0] = '\0';
		if ((a->tag == 1 && flag != 'D' && flag != 'd') || a->po == 1)
		{
			if ((!(a->precision == 1 && a->prec == 0 && a->base != 8) &&
				tab[0] != '0') || a->po == 1)
				a->len++;
			if ((a->base == 16 && (a->nb != 0 || a->nbr != 0)) || a->po == 1)
				a->len++;
		}
	}
	return (tab);
}

static int		ft_gestion(t_val *a, int j, char flag)
{
	if (a->precision == 0 && a->zero == 1)
		a->prec = a->ldc - a->signe;
	if (a->prec > 0)
		a->prec -= a->len;
	if ((a->base == 16 && (a->nb != 0 || a->nbr != 0) && a->precision == 1)
		&& a->po == 0 && a->tag == 1)
		a->prec += 2;
	if (a->ldc > 0)
		a->ldc -= a->len;
	if (a->prec < 0)
		a->prec = 0;
	if (a->ldc > a->prec)
		j = largeur_champ(j + a->prec + a->signe, a);
	if (a->nb < 0 && a->base == 10)
		a->buff[a->b++] = '-';
	if (a->space == 1 && a->plus == 0 && a->ldc >= a->prec &&
		(flag == 'd' || flag == 'D' || flag == 'i') && a->nb >= 0)
		a->buff[a->b++] = ' ';
	if (a->plus == 1 && a->nb >= 0 && flag != 'u' && flag != 'U')
		a->buff[a->b++] = '+';
	return (j);
}

static void		ft_genre(t_val *a, char *tab, char flag, int j)
{
	j = ft_gestion(a, j, flag);
	if ((a->tag == 1 && flag != 'D' && flag != 'd') || a->po == 1)
	{
		if ((!(a->precision == 1 && a->prec == 0 && a->base != 8) &&
			tab[0] != '0') || a->po == 1)
			a->buff[a->b++] = '0';
		if ((a->base == 16 && (a->nb != 0 || a->nbr != 0)) || a->po == 1)
		{
			if (a->maj == 1)
				a->buff[a->b++] = 'X';
			else
				a->buff[a->b++] = 'x';
		}
	}
	j = precision(0, a);
	ft_buff_str(tab, a, a->len);
	if (a->ldc < 0)
		j = largeur_champ(j + a->len + a->signe, a);
}

void			ft_nombre(t_val *a, va_list ap, char flag)
{
	char	*tab;

	tab = NULL;
	if (flag == 'd' || flag == 'D' || flag == 'i')
		a->nb = signe(a, ap);
	else
		a->nbr = unsigne(a, ap, flag);
	tab = ft_value(a, tab, flag);
	if (tab == NULL)
		return ;
	a->len += ft_strlen(tab);
	if (a->nb < 0 && a->base == 10)
		a->signe++;
	if ((a->plus == 1 && a->nb >= 0 && flag != 'u' && flag != 'U') ||
		(a->space == 1 && a->ldc >= a->prec && a->nb >= 0 && a->plus == 0))
		a->signe++;
	ft_genre(a, tab, flag, 0);
	a->buff[a->b] = '\0';
	if (tab != NULL)
		free(tab);
}
