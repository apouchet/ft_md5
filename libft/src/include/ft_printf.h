/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:09:28 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:36 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "../../libft.h"

typedef struct				s_val
{
	char					buff[1000];
	ssize_t					nb;
	size_t					nbr;
	size_t					base;
	int						b;
	int						prec;
	int						precision;
	int						ldc;
	int						ldchamp;
	int						len;
	int						type;
	int						maj;
	int						tmp;
	int						ltotal;
	int						ldif;
	int						lon;
	int						lonlon;
	int						shortshort;
	int						shor;
	int						plus;
	int						moins;
	int						zero;
	int						tag;
	int						space;
	int						signe;
	int						po;
}							t_val;

int							ft_printf(char *str, ...);

void						ft_decalage(t_val *a, int c);

void						ft_init(t_val *a);

int							ft_len(int c);

void						ft_affich_printf(t_val *a);

int							largeur_champ(int j, t_val *a);

int							precision(int j, t_val *a);

void						ft_buff_str(char *str, t_val *a, int len);

void						ft_str(t_val *a, va_list ap);

void						ft_str_unicode(t_val *a, va_list ap);

void						lettre(t_val *a, va_list ap, int flag);

int							nb(char *str, int i, t_val *a, int mode);

void						ft_nombre(t_val *a, va_list ap, char flag);

long long int				signe(t_val *a, va_list ap);

unsigned long long			unsigne(t_val *a, va_list ap, int flag);

#endif
