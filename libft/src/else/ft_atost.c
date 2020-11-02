/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:47:11 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:54 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_atost(const char *s)
{
	size_t	len;
	size_t	nb;
	size_t	i;

	nb = 0;
	len = 0;
	i = 0;
	while (s[i] && (ft_isspace(s[i]) || (s[i] == '+' && ft_isdigit(s[i + 1]))))
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i] == '0')
		s++;
	while (ft_isdigit(s[len]))
		len++;
	if (len > 20)
		return (0);
	while (ft_isdigit(s[i]))
		nb = (nb * 10) + (size_t)(s[i++] - '0');
	return (nb);
}
