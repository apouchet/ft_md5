/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:16:31 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:34 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "../../libft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_list_push_front(t_list **begin_list, void *data,
	size_t len);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

#endif
