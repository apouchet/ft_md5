/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:09:36 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:52 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_find_space(const char *a, size_t i)
{
	size_t	save;

	save = i;
	if (!a)
		return (0);
	while (a[i] && !ft_isspace(a[i]))
		i++;
	if (ft_isspace(a[i]))
		return (i);
	return (save);
}
