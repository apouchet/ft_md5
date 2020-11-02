/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:33 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:53 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_count_word_char(const char *s, int c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (!(s[i] == c))
		count = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			i = ft_while_char(s, i, c);
			if (s[i])
				count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}
