/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:38 by georgy            #+#    #+#             */
/*   Updated: 2020/12/16 17:05:07 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define ERROR -1
# define READ 1
# define END_OF_FILE 0

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int					get_next_line(int fd, char **line);
char				*ft_getline(char **line, char **current_line);

size_t				ft_strlen(const char *s);
size_t				ft_strcpy(char **dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
#endif
