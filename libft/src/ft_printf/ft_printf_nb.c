/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:51:40 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:38 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						nb(char *str, int i, t_val *a, int mode)
{
	char	val[50];
	int		j;

	j = 0;
	if (str[i] == '.' || str[i] == '*')
		i++;
	while (str[i] == '-' || str[i] == '+')
		val[j++] = str[i++];
	if (str[i] == '0' && mode == 1)
		a->zero = 1;
	while (str[i] >= '0' && str[i] <= '9')
		val[j++] = str[i++];
	val[j] = '\0';
	if (mode == 1 || mode == 3)
		a->ldchamp = 1;
	if (mode == 1)
		a->ldc = ft_atoi(val);
	if (mode == 2 || mode == 4)
		a->precision = 1;
	if (mode == 2)
		a->prec = ft_atoi(val);
	if (a->prec < 0)
		a->prec = 0;
	return (i);
}

long long int			signe(t_val *a, va_list ap)
{
	long long int	nb;

	if (a->lonlon == 1)
		nb = va_arg(ap, long long int);
	else if (a->lon == 1)
		nb = va_arg(ap, long int);
	else if (a->shortshort == 1)
		nb = (char)va_arg(ap, int);
	else if (a->shor == 1)
		nb = (short)va_arg(ap, long int);
	else
		nb = va_arg(ap, int);
	return (nb);
}

unsigned long long		unsigne(t_val *a, va_list ap, int flag)
{
	unsigned long long int	nb;

	if (a->lon == 1 || flag == 'U' || flag == 'O')
		nb = va_arg(ap, unsigned long int);
	else if (a->lonlon == 1)
		nb = va_arg(ap, unsigned long long int);
	else if (a->shortshort == 1 && flag != 'U')
		nb = (unsigned char)va_arg(ap, unsigned int);
	else if (a->shor == 1 && flag != 'U')
		nb = (unsigned short)va_arg(ap, unsigned int);
	else
		nb = va_arg(ap, unsigned int);
	return (nb);
}
