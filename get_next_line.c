/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:35 by georgy            #+#    #+#             */
/*   Updated: 2020/12/16 17:00:45 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char **line, char **current_line)
{
	char *endline;

	endline = NULL;
	if (current_line)
	{
		if ((endline = ft_strchr(*current_line, '\n')))
		{
			*endline++ = '\0';
			free(*line);
			*line = ft_strdup(*current_line);
			ft_strcpy(current_line, endline);
		}
		else
		{
			free(*line);
			*line = ft_strdup(*current_line);
			free(*current_line);
			*current_line = NULL;
		}
	}
	return (endline);
}

int		get_next_line(int fd, char **line)
{
	static	char	*current_line;
	t_line			list;
	char			*temp;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (ERROR);
	*line = NULL;
	list.has_been_read = 1;
	while (!(ft_strchr(current_line, '\n')) && list.has_been_read)
	{
		if ((list.has_been_read = read(fd, list.buffer, BUFFER_SIZE)) == -1)
			return (ERROR);
		list.buffer[list.has_been_read] = '\0';
		temp = current_line;
		current_line = ft_strjoin(current_line, list.buffer);
		free(temp);
	}
	ft_getline(line, &current_line);
	if (list.has_been_read == 0)
		return (END_OF_FILE);
	return (READ);
}
