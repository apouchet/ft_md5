/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:06:11 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:01 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;

	if (!s || !f || !(a = (char*)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		a[i] = f(i, s[i]);
		i++;
	}
	return (a);
}
