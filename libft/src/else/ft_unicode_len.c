/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:10:09 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:44 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "else.h"

size_t	ft_unicode_len(int c)
{
	size_t octet;

	octet = 1;
	if (c > 127)
		octet++;
	if (c > 2047)
		octet++;
	if (c > 65535)
		octet++;
	if (c > 2097151)
		octet++;
	if (octet == 0)
		octet = 1;
	return (octet);
}
