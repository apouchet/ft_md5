/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:16:24 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:52:58 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strndup_free(char **s1, size_t n)
{
	char *a;

	if (n > ft_strlen(*s1))
		n = ft_strlen(*s1);
	if (!(a = (char*)ft_memalloc(sizeof(char) * (n + 1))))
		return (NULL);
	a = ft_strncpy(a, *s1, n);
	ft_strdel(s1);
	return (a);
}
