/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:48:13 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:55 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

long	ft_atol(const char *s)
{
	long	nb;
	int		neg;

	nb = 0;
	neg = 1;
	while (*s && (ft_isspace(*s) || (*s == '+' && ft_isdigit(s[1])) ||
		(*s == '-' && ft_isdigit(s[1]))))
		if (*(s++) == '-')
			neg = -1;
	if (!ft_isdigit(*s))
		return (0);
	while (ft_isdigit(*s))
		nb = (nb * 10) + (*(s++) - '0') * neg;
	return (nb);
}
