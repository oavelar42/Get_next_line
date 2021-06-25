/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:28:00 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 15:10:50 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_ret(char **line, char **next, char *aux_ptr)
{
	char			*aux;

	if (aux_ptr)
	{
		*line = ft_strndup(*next, aux_ptr - *next);
		aux = ft_strndup(aux_ptr + 1, ft_strlen(aux_ptr + 1));
		free(*next);
		*next = aux;
		return (1);
	}
	if (*next)
	{
		*line = *next;
		*next = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*next[OPEN_MAX];
	char			ptr[BUFFER_SIZE + 1];
	char			*aux_ptr;
	int				b;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, ptr, 0) < 0)
		return (-1);
	if (!next[fd])
		next[fd] = ft_strndup("", 1);
	aux_ptr = NULL;
	b = 1;
	while (!aux_ptr && (b > 0))
	{
		b = read(fd, ptr, BUFFER_SIZE);
		ptr[b] = 0;
		if (next[fd])
			aux_ptr = ft_strjoin(next[fd], ptr);
		else
			aux_ptr = ft_strndup(ptr, b);
		if (next[fd])
			free(next[fd]);
		next[fd] = aux_ptr;
		aux_ptr = ft_strchr(next[fd], '\n');
	}
	return (ft_ret(line, &next[fd], aux_ptr));
}
