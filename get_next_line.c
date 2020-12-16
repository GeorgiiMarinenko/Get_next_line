/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:35 by georgy            #+#    #+#             */
/*   Updated: 2020/12/15 01:11:18 by aarlena          ###   ########.fr       */
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
	char			buffer[BUFFER_SIZE + 1];
	static	char	*current_line;
	int				has_been_read;
	// t_line			*lst;
	// static t_line	*list;
	// int				i;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (ERROR);
	*line = NULL;
	has_been_read = 1;
	while (!(ft_strchr(current_line, '\n')) && has_been_read)
	{
		if ((has_been_read = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (ERROR);
		buffer[has_been_read] = '\0';
		current_line = ft_strjoin(current_line, buffer);
	}
	ft_getline(line, &current_line);
	if (has_been_read == 0)
		return (EOF);
	return (READ);
}
