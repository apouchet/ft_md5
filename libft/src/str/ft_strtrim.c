/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:17:12 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:52:52 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*a;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) && i > 0)
		i--;
	if (!i && ft_isspace(s[i]))
		return ((char*)ft_memalloc(1));
	i++;
	j = ft_while_space(s, 0);
	if (!(a = (char*)ft_memalloc(sizeof(char) * (i - j + 1))))
		return (NULL);
	a = ft_strncpy(a, &s[j], i - j);
	return (a);
}
