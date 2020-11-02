/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:56 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:45 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

char	*ft_ulltoa(unsigned long long int n)
{
	size_t	i;
	char	*str;

	i = ft_nbrlen_unsigned(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[i] = (n % 10) + '0';
	return (str);
}
