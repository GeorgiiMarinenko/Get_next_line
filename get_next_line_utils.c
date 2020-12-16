/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 23:18:32 by georgy            #+#    #+#             */
/*   Updated: 2020/12/15 01:07:34 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strcpy(char **dst, const char *src)
{
	unsigned int	i;

	if (!dst || !src)
		return ((size_t)NULL);
	i = 0;
	while (src[i])
	{
		(*dst)[i] = src[i];
		i++;
	}
	(*dst)[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	char symbol;
	char *src;

	src = (char*)s;
	symbol = (char)c;
	while (src && *src)
	{
		if (*src == symbol)
			return (src);
		src++;
	}
	if (src && *src == symbol)
		return (src);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char			*new_str;
	unsigned int	i;

	if (!(new_str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long long	i;
	char				*str;
	unsigned int		j;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
