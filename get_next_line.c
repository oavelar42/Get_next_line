/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:30:45 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 15:16:35 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char			*j;
	int				b;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, ptr, 0) < 0)
		return (-1);
	if (!next[fd])
		next[fd] = ft_strndup("", 1);
	j = NULL;
	b = 1;
	while (!j && (b > 0))
	{
		b = read(fd, ptr, BUFFER_SIZE);
		ptr[b] = 0;
		if (next[fd])
			j = ft_strjoin(next[fd], ptr);
		else
			j = ft_strndup(ptr, b);
		if (next[fd])
			free(next[fd]);
		next[fd] = j;
		j = ft_strchr(next[fd], '\n');
	}
	return (ft_ret(line, &next[fd], j));
}
