/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:38 by georgy            #+#    #+#             */
/*   Updated: 2020/12/15 01:10:22 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define ERROR -1
# define READ 1
#define EOF 0

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_line
{
	int				fd;
	char			*current_line;
	struct s_line	*next;
}					t_line;

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
size_t	ft_strcpy(char **dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_getline(char **line, char **memory);
#endif
