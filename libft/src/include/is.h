/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:15:02 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:35 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# include "../../libft.h"

int		ft_isalpha(int c);

int		ft_isspace(char c);

int		ft_isprint(int c);

int		ft_isalnum(int	c);

int		ft_isdigit(int	c);

int		ft_isascii(int	c);

int		ft_islower(int	c);

int		ft_isupper(int	c);

int		ft_ischar(const char *s, char c);

#endif
