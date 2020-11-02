/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:29 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:53 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_count_word(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	if (!ft_isspace(s[i]))
		count = 1;
	while (s[i])
	{
		if (ft_isspace(s[i]))
		{
			i = ft_while_space(s, i);
			if (s[i])
				count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}
