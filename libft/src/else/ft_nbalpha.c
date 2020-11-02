/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:45 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:49 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_nbalpha(const char *s)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s[i])
		if (!ft_isspace(s[i++]))
			len++;
	return (len);
}
