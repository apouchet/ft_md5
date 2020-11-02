/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:16:15 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:23 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *start;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew(f(lst)->content, f(lst)->content_size);
	start = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}
