/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:06:07 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	size_t	i;

	if (!s || !f || !(a = (char*)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (*s)
		a[i++] = f(*(s++));
	return (a);
}
