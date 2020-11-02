/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:17:46 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:52:56 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strnstr(const char *s1, const char *s, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!*s)
		return ((char*)((size_t)s1));
	len = ft_strlen(s);
	while (s1[i] && i < n)
	{
		if (s1[i] == *s)
		{
			if (i + len > n)
				return (NULL);
			if (ft_strncmp(&s1[i], s, len) == 0)
				return ((char*)((size_t)&s1[i]));
		}
		i++;
	}
	return (NULL);
}
