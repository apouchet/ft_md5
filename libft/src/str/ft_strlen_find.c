/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:15:59 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlen_find(const char *s, int c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
	{
		if (s[len] == (char)c)
			return (len);
		len++;
	}
	return (0);
}
