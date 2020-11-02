/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:35:57 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:11 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdio.h>

char	*ft_str_replace(const char *src, const char *find, const char *rep)
{
	size_t	j;
	size_t	i;
	char	*a;

	if (!src)
		return (NULL);
	i = 0;
	j = 0;
	if (!find || !rep || !ft_strnbstr(src, find))
		return (ft_strdup(src));
	if (!(a = (char*)ft_memalloc(ft_strlen(src) -
		(ft_strlen(rep) - ft_strlen(find)) * ft_strnbstr(src, find)) + 1))
		return (NULL);
	while (src[i])
	{
		if (!ft_strncmp(&src[i], find, ft_strlen(find)))
		{
			ft_strcpy(&a[j], rep);
			i += ft_strlen(find);
			j += ft_strlen(rep);
		}
		else
			a[j++] = src[i++];
	}
	return (a);
}
