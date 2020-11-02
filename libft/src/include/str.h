/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:15:20 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:32 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "../../libft.h"

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strncpy(char *dst, const char *src, size_t n);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strndup(const char *s1, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strcat(char *restrict s1, const char *restrict s2);

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);

size_t	ft_strlcat(char *restrict s1, const char *restrict s2, size_t n);

char	*ft_strwellspace(const char *s);

char	*ft_strtrim(char const *s);

size_t	ft_strlen_find(const char *s, int c);

char	**ft_strsplit(char const *s, char c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strstr(const char *s1, const char *s);

char	*ft_strnstr(const char *s1, const char *s, size_t n);

char	*ft_strnew(size_t size);

void	ft_strdel(char **as);

void	ft_strclr(char *s);

void	ft_striter(char *s, void (*f)(char *));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strmap(char const *s, char (*f)(char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strequ(char const *s1, char const *s2);

int		ft_strnequ(char const *s1, char const *s2, size_t n);

char	*ft_strsub(char const *s, size_t start, size_t len);

size_t	ft_strnbstr(const char *s1, const char *s);

char	*ft_str_replace(const char *src, const char *find, const char *rep);

char	*ft_strsub_free(char **s, size_t start, size_t len);

char	*ft_strjoin_free(char **s1, char **s2, int f);

char	*ft_strndup_free(char **s1, size_t n);

char	*ft_strdup_free(char **s1);

#endif
