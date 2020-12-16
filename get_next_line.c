/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:35 by georgy            #+#    #+#             */
/*   Updated: 2020/12/16 17:05:40 by aarlena          ###   ########.fr       */
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
	char			buffer[BUFFER_SIZE + 1];
	int				has_been_read;
	char			*temp;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (ERROR);
	*line = NULL;
	has_been_read = 1;
	while (!(ft_strchr(current_line, '\n')) && has_been_read)
	{
		if ((has_been_read = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (ERROR);
		buffer[has_been_read] = '\0';
		temp = current_line;
		current_line = ft_strjoin(current_line, buffer);
		free(temp);
	}
	ft_getline(line, &current_line);
	if (has_been_read == 0)
		return (END_OF_FILE);
	return (READ);
}
