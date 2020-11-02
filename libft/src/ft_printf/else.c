/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:46:29 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:40 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_val *a)
{
	a->prec = 0;
	a->ldc = 0;
	a->precision = 0;
	a->ldchamp = 0;
	a->len = 0;
	a->base = 10;
	a->maj = 0;
	a->lon = 0;
	a->lonlon = 0;
	a->shortshort = 0;
	a->shor = 0;
	a->plus = 0;
	a->space = 0;
	a->moins = 0;
	a->tag = 0;
	a->zero = 0;
	a->signe = 0;
	a->nb = 0;
	a->nbr = 0;
	a->po = 0;
}

void	ft_affich_printf(t_val *a)
{
	write(1, a->buff, (size_t)a->b);
	a->ltotal += a->b;
	a->b = 0;
}

int		largeur_champ(int j, t_val *a)
{
	if (a->ldc < 0)
		a->ldc = -a->ldc;
	while (j < a->ldc)
	{
		a->buff[a->b++] = ' ';
		if (a->b > 500)
			ft_affich_printf(a);
		j++;
	}
	return (j);
}

int		precision(int j, t_val *a)
{
	while (j < a->prec)
	{
		a->buff[a->b++] = '0';
		if (a->b > 500)
			ft_affich_printf(a);
		j++;
	}
	return (j);
}
