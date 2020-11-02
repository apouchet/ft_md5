/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:16:59 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:52:55 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s || !(a = (char**)ft_memalloc(sizeof(char*) *
			(ft_count_word_char(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		i = ft_while_char(s, i, c);
		if (!s[i])
			break ;
		len = ft_while_not_char(s, i, c) - i;
		a[j++] = ft_strsub(s, i, len);
		a[j] = NULL;
		i += len;
	}
	return (a);
}
