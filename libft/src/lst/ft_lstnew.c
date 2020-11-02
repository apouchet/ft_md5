/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:16:22 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:22 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	if (content && content_size)
	{
		list->content = ft_memdup(content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	return (list);
}
