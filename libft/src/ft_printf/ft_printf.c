/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:03:22 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:39 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		type(char c, t_val *a)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'x' || c == 'X' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'p')
	{
		if (c == 'O' || c == 'o')
			a->base = 8;
		else if (c == 'X' || c == 'x' || c == 'p')
			a->base = 16;
		if (c == 'X' || c == 'O')
			a->maj = 1;
		if (c == 'p')
			a->po = 1;
		if (c == 'D' || c == 'p')
			a->lon = 1;
		if (a->tag == 1 || a->maj == 1 || a->base != 10)
			a->plus = 0;
		return (1);
	}
	if (c == 's' && a->lon == 0)
		return (2);
	if (c == 'c' || c == 'C' || c == '%')
		return (3);
	if (c == 'S' || (c == 's' && a->lon == 1))
		return (4);
	return (0);
}

static int		ft_flag(t_val *a, char *str, int i, va_list ap)
{
	while (str[i] == '+' || str[i] == '-' || str[i] == '#' || str[i] == ' ' ||
		str[i] == '0')
	{
		if (str[i] == '+')
			a->plus = 1;
		else if (str[i] == '-')
			a->moins = 1;
		else if (str[i] == '#')
			a->tag = 1;
		else if (str[i] == '0')
			a->zero = 1;
		else if (str[i] == ' ')
			a->space = 1;
		i++;
	}
	if (str[i] == '*')
		a->ldc = va_arg(ap, int);
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
		i = nb(str, i, a, (str[i] == '*' ? 3 : 1));
	if (str[i] == '.' && str[i + 1] == '*')
		a->prec = va_arg(ap, int);
	if (str[i] == '.')
		i = nb(str, i + 1, a, (str[i + 1] == '*' ? 4 : 2));
	return (i);
}

static int		ft_type_nb(t_val *a, char *str, int i)
{
	if (str[i] == 'l' || str[i] == 'h' || str[i] == 'j' || str[i] == 'z')
	{
		i++;
		if (str[i] == 'l' || str[i] == 'h')
		{
			if (str[i - 1] == 'l')
				a->lonlon = 1;
			else if (str[i - 1] == 'h')
				a->shortshort = 1;
			i++;
		}
		else if (str[i - 1] == 'l' || str[i - 1] == 'j' || str[i - 1] == 'z')
			a->lon = 1;
		else if (str[i - 1] == 'h')
			a->shor = 1;
	}
	return (i);
}

static int		ft_tri_flag(t_val *a, va_list ap, char *str, int i)
{
	i = ft_flag(a, str, i + 1, ap);
	i = ft_type_nb(a, str, i);
	if (a->ldchamp == 1 && a->moins == 1)
		a->ldc = -a->ldc;
	a->type = type(str[i], a);
	if (a->type == 1)
		ft_nombre(a, ap, str[i]);
	else if (a->type == 2)
		ft_str(a, ap);
	else if (a->type == 4)
		ft_str_unicode(a, ap);
	else if (a->type == 3)
		lettre(a, ap, str[i]);
	else
		a->buff[a->b++] = str[i];
	ft_init(a);
	return (i + 1);
}

int				ft_printf(char *str, ...)
{
	t_val	a;
	va_list	ap;
	int		i;

	a.b = 0;
	i = 0;
	a.ldif = 0;
	a.ltotal = 0;
	ft_init(&a);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			a.buff[a.b++] = str[i++];
		else
			i = ft_tri_flag(&a, ap, str, i);
		if (a.b >= 500)
			ft_affich_printf(&a);
	}
	a.buff[a.b] = '\0';
	ft_affich_printf(&a);
	va_end(ap);
	return (a.ltotal);
}
