/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:56:10 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:37 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELSE_H
# define ELSE_H

# include "../../libft.h"

void	ft_bzero(void *s, size_t n);

char	*ft_unicode(char *a, int c);

size_t	ft_unicode_len(int c);

size_t	ft_nbrlen(long nb);

size_t	ft_nbrlen_unsigned(size_t nb);

char	*ft_itoa(int nb);

char	*ft_itoa_unsigned(size_t nb);

char	*ft_itoa_base(ssize_t nb, size_t base, int maj);

char	*ft_itoa_unsigned_base(size_t nb, size_t base, int maj);

size_t	ft_nbalpha(const char *s);

size_t	ft_find_space(const char *a, size_t i);

size_t	ft_while_space(const char *a, size_t i);

size_t	ft_while_char(const char *a, size_t i, int c);

size_t	ft_count_word_char(const char *s, int c);

size_t	ft_count_word(const char *s);

size_t	ft_nbrlen_base(long nb, unsigned int base);

size_t	ft_nbrlen_base_unsigned(size_t nb, unsigned int base);

int		ft_tolower(int c);

int		ft_toupper(int c);

int		ft_atoi(const char *str);

long	ft_atol(const char *str);

size_t	ft_while_not_char(const char *a, size_t i, int c);

ssize_t	ft_pow(ssize_t x, ssize_t y);

double	ft_pow_double(double x, double y);

float	ft_atof(char *s);

size_t	ft_atost(const char *s);

char	*ft_ulltoa(unsigned long long int n);

#endif
