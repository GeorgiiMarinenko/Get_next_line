/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:35 by georgy            #+#    #+#             */
/*   Updated: 2020/12/16 13:05:25 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char **line, char **memory)
{
	char *endline;

	endline = NULL;
	if (memory)
	{
		if ((endline = ft_strchr(*memory, '\n')))
		{
			*endline++ = '\0';
			free(*line);
			*line = ft_strdup(*memory);
			ft_strcpy(memory, endline);
		}
		else
		{
			free(*line);
			*line = ft_strdup(*memory);
			free(*memory);
			*memory = NULL;
		}
	}
	return (endline);
}

int		get_next_line(int fd, char **line)
{
	static	char	*current_line;
	t_line			list;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (ERROR);
	*line = NULL;
	list.has_been_read = 1;
	while (!(ft_strchr(current_line, '\n')) && list.has_been_read)
	{
		if ((list.has_been_read = read(fd, list.buffer, BUFFER_SIZE)) == -1)
			return (ERROR);
		list.buffer[list.has_been_read] = '\0';
		current_line = ft_strjoin(current_line, list.buffer);
	}
	ft_getline(line, &current_line);
	if (list.has_been_read == 0)
		return (EOF);
	return (READ);
}
