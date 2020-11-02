/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:15:45 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:26 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_list_push_front(t_list **begin_list, void *data, size_t len)
{
	t_list *tmp;

	if (*begin_list)
	{
		tmp = ft_lstnew(data, len);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_lstnew(data, len);
}
