/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:16:20 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:52:59 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	len;

	len = 0;
	while (*src && len < n)
		dst[len++] = *(src)++;
	ft_bzero(&dst[len], n - len);
	return (dst);
}
