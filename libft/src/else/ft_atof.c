/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:09:26 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:56 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

float	ft_atof(char *s)
{
	int	i;
	int	a;
	int	neg;

	i = 0;
	neg = 1;
	while (*s && (ft_isspace(*s) || (*s == '+' && (ft_isdigit(s[1]) ||
		s[1] == '.')) || (*s == '-' && (ft_isdigit(s[1]) || s[1] == '.'))))
		if (*(s++) == '-')
			neg = -1;
	if (!ft_isdigit(*s) && *s != '.')
		return (0);
	while (*s == '0')
		s++;
	a = ft_atoi(s);
	while (*s && ft_isdigit(*s))
		s++;
	if (*s && *s != '.')
		return ((float)(a * neg));
	while (ft_isdigit(s[i + 1]))
		i++;
	return ((float)(a + (ft_atoi(&s[1]) / ft_pow(10, i))) * neg);
}
