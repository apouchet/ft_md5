/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:14:29 by apouchet          #+#    #+#             */
/*   Updated: 2020/11/02 16:53:37 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	ssize_t		rd;
	char		*buff;

	rd = 1;
	if (fd < 0 || !line || (*line = NULL))
		return (-1);
	if (!(buff = (char*)ft_memalloc(BUFF_SIZE + 1)) ||
		(save && !(*line = ft_strdup_free(&save))))
		return (-1);
	else if (!(*line) && ((rd = read(fd, buff, BUFF_SIZE)) < 0 ||
		!(*line = ft_strdup(buff))))
		return (-1);
	while (rd > 0 && ft_ischar(*line, '\n') == -1)
		if ((rd = read(fd, buff, BUFF_SIZE)) < 0 ||
			(buff[rd] = '\0') ||
			!(*line = ft_strjoin_free(line, &buff, 1)))
			return (-1);
	if (rd > 0 && (!(save = ft_strsub(*line, (size_t)ft_ischar(*line, '\n') + 1,
		ft_strlen(*line) - (size_t)ft_ischar(*line, '\n') - 1)) ||
			!(*line = ft_strndup_free(line, (size_t)ft_ischar(*line, '\n')))))
		return (-1);
	(rd > 0 || *line[0]) ? ft_strdel(&buff) : ft_strdel(&save);
	ft_strdel(&buff);
	return ((rd > 0 || *line[0]) ? 1 : 0);
}
